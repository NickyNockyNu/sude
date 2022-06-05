{$REGION 'TRandom'}
class constructor TRandom.Create;
begin
  RNG.Randomize;
end;

procedure TRandom.SetSeed(const ASeed: Integer);
begin
  FSeed := ASeed;
  Value := ASeed;
end;

class function TRandom.SupportsRDSEED: Boolean;
{$IF DEFINED(CPUX86)}
asm
  push ecx
  push ebx

  mov ecx, 0
  mov eax, $07
  cpuid

  test ebx, 40000h
  setne al

  pop ebx
  pop ecx
end;
{$ELSEIF DEFINED(CPUX64)}
asm
  push r9
  push rbx
  push rdx

  mov rcx, 0
  mov rax, $07
  cpuid

  test ebx, 40000h
  setne al

  pop rdx
  pop rbx
  pop r9
end;
{$ELSE}
begin
  Result := False;
end;
{$ENDIF}

class function TRandom.SupportsRDRAND: Boolean;
{$IF DEFINED(CPUX86)}
asm
  push ecx
  push ebx

  mov eax, $01
  cpuid

  test ecx, 40000000h
  setne al

  pop ebx
  pop ecx
end;
{$ELSEIF DEFINED(CPUX64)}
asm
  push r9
  push rbx
  push rdx

  mov rax, $01
  cpuid

  test ecx, 40000000h
  setne al

  pop rdx
  pop rbx
  pop r9
end;
{$ELSE}
begin
  Result := False;
end;
{$ENDIF}

class function TRandom.RDSEED: Integer;
{$IF DEFINED(CPUX86) OR DEFINED(CPUX64)}
asm
@retry:
  db $0F, $C7, $F8
  jnc @retry
end;
{$ELSE}
begin
  Result := 0;
end;
{$ENDIF}

class function TRandom.RDRAND: Integer;
{$IF DEFINED(CPUX86) OR DEFINED(CPUX64)}
asm
@retry:
  db $0F, $C7, $F0
  jnc @retry
end;
{$ELSE}
begin
  Result := 0;
end;
{$ENDIF}

class function TRandom.RAND(const ARange: Integer): Integer;
begin
  if SupportsRDRAND then
    Result := (UInt64(Cardinal(ARange)) * UInt64(Cardinal(RDRAND))) shr 32
  else
    Result := RNG.Next(ARange);
end;

constructor TRandom.Create(const ASeed: Integer);
begin
  SetSeed(ASeed);
end;

function TRandom.Next(const ARange: Integer): Integer;
begin
  Value  := Value * RandMod + 1;
  Result := (UInt64(Cardinal(ARange)) * UInt64(Cardinal(Value))) shr 32;
end;

function TRandom.Next: Extended;
const
  Two2Neg32: Double = (1 / $10000) / $10000;
begin
  Value  := Value * RandMod + 1;
  Result := Int64(Cardinal(Value)) * Two2Neg32;
end;

function TRandom.LFSR: Cardinal;
var
  NewBit: Cardinal;
begin
  NewBit := Value xor (Value shr 10) xor (Value shr 30) xor (Value shr 31);
  Value  := Integer(Cardinal(Value shr 1) or ((NewBit and 1) shl 31));

  Result := Cardinal(Value);
end;

function TRandom.LFSR0: Boolean;
begin
  Result := (LFSR and 1) = 1;
end;

function TRandom.MeanStdDev(const AMean, AStdDev: Extended): Extended;
var
  r1, r2: Extended;
begin
  repeat
    r1 := 2 * Next - 1;
    r2 := Sqr(r1) + Sqr(2 * Next - 1);
  until r2 < 1;

  Result := Sqrt(-2 * Ln(r2) / r2) * r1 * AStdDev + AMean;
end;

procedure TRandom.Randomize;
begin
  if SupportsRDSEED then
    FSeed := RDSEED
  else
    FSeed := Integer(GetTickCount);

  FSeed := FSeed + RNG.Next(MaxInt);
  Value := FSeed;
end;

class operator TRandom.Implicit(var ARandom: TRandom): Extended;
begin
  Result := ARandom.Next;
end;
{$ENDREGION}

{$REGION 'TPerlin'}
function TPerlin.Permutate(const AX: Integer): Integer;
begin
  Result := Permutations[AX and GradientSize];
end;

function TPerlin.Index(const AX, AY, AZ: Integer): Integer;
begin
  Result := Permutate(AX + Permutate(AY + Permutate(AZ)));
end;

function TPerlin.Lattice(const Aix, Aiy, Aiz: Integer; const Afx, Afy, Afz: Extended): Extended;
var
  i: Integer;
begin
  i := Index(Aix, Aiy, Aiz) * 3;
  Result := Gradients[i] * Afx + Gradients[i + 1] * Afy + Gradients[i + 2] + Afz;
end;

function TPerlin.Lerp(const AAlpha, ASource, ADest: Extended): Extended;
begin
  Result := ASource + AAlpha * (ADest - ASource);
end;

function TPerlin.Smooth(const AX: Extended): Extended;
begin
  Result := AX * AX * (3 - 2 * AX);
end;

function TPerlin.GetSeed: Integer;
begin
  Result := Random.Seed;
end;

procedure TPerlin.SetSeed(const ASeed: Integer);
begin
  Random.Seed := ASeed;
  CreateGradients;
end;

function TPerlin.GetNoise(const AX, AY, AZ: Extended): Extended;
var
  ix,  iy,  iz:  Integer;
  wx,  wy,  wz:  Extended;
  fx0, fy0, fz0: Extended;
  fx1, fy1, fz1: Extended;
  vx0, vy0, vz0: Extended;
  vx1, vy1, vz1: Extended;
begin
  ix  := Trunc(AX);
  fx0 := AX - ix;
  fx1 := fx0 - 1;
  wx  := Smooth(fx0);

  iy  := Trunc(AY);
  fy0 := AY - iy;
  fy1 := fy0 - 1;
  wy  := Smooth(fy0);

  iz  := Trunc(AZ);
  fz0 := AZ - iz;
  fz1 := fz0 - 1;
  wz  := Smooth(fz0);

  vx0 := Lattice(ix, iy, iz, fx0, fy0, fz0);
  vx1 := Lattice(ix + 1, iy, iz, fx1, fy0, fz0);
  vy0 := Lerp(wx, vx0, vx1);

  vx0 := Lattice(ix, iy + 1, iz, fx0, fy1, fz0);
  vx1 := Lattice(ix + 1, iy + 1, iz, fx1, fy1, fz0);
  vy1 := Lerp(wx, vx0, vx1);

  vz0 := Lerp(wy, vy0, vy1);

  vx0 := Lattice(ix, iy, iz + 1, fx0, fy0, fz1);
  vx1 := Lattice(ix + 1, iy, iz + 1, fx1, fy0, fz1);
  vy0 := Lerp(wx, vx0, vx1);

  vx0 := Lattice(ix, iy + 1, iz + 1, fx0, fy1, fz1);
  vx1 := Lattice(ix + 1, iy + 1, iz + 1, fx1, fy1, fz1);
  vy1 := Lerp(wx, vx0, vx1);

  vz1 := Lerp(wy, vy0, vy1);

  Result := Abs(Lerp(wz, vz0, vz1));
end;

constructor TPerlin.Create(const ASeed: Integer);
begin
  Random := TRandom.Create(ASeed);

  CreateGradients;
end;

procedure TPerlin.CreateGradients;
var
  i:           Integer;
  z, r, Theta: Extended;
begin
  for i := 0 to GradientSize do
  begin
    z     := 1 - 2 * Random.Next;
    r     := Sqrt(1 - z * z);
    Theta := 2 * PI * Random.Next;
    Gradients[i * 3]     := r * Cos(Theta);
    Gradients[i * 3 + 1] := r * Sin(Theta);
    Gradients[i * 3 + 2] := z;
  end;
end;

procedure TPerlin.Randomize;
begin
  Random.Randomize;
  CreateGradients;
end;
{$ENDREGION}
