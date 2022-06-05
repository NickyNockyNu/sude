{$REGION 'TVector2fHelper'}
{$IFDEF COMPILER_IS_DUMB}
function CreateSinCos;
{$ELSE}
class function TVector2fHelper.CreateSinCos;
{$ENDIF}
var
{$IF SizeOf(Extended) > SizeOf(Double)}
  S, C: Extended;
{$ELSE}
  S, C: Double;
{$ENDIF}
begin
  SineCosine(Extended(AAngle) * PI / 180, S, C);

  {$IFDEF COMPILER_IS_DUMB}
  with Result do
  {$ENDIF}
  begin
    X := S;
    Y := C;
  end;
end;

function TVector2fHelper.Round;
begin
  Result.X := X.Round;
  Result.Y := Y.Round;
end;

function TVector2fHelper.Trunc;
begin
  Result.X := X.Trunc;
  Result.Y := Y.Trunc;
end;

function TVector2fHelper.Ceil;
begin
  Result.X := X.Ceil;
  Result.Y := Y.Ceil;
end;

function TVector2fHelper.Floor;
begin
  Result.X := X.Floor;
  Result.Y := Y.Floor;
end;

function TVector2fHelper.CeilFloor;
begin
  Result.X := X.CeilFloor;
  Result.Y := Y.CeilFloor;
end;

function TVector2fHelper.Frac;
begin
  Result.X := X.Frac;
  Result.Y := Y.Frac;
end;

function TVector2fHelper.Abs;
begin
  Result.X := X.Abs;
  Result.Y := Y.Abs;
end;

function TVector2fHelper.DotProduct: Float;
begin
  Result := DotProduct(Self);
end;

function TVector2fHelper.DotProduct(const A: TVector2f): Float;
begin
  Result := (X * A.X) + (Y * A.Y);
end;

function TVector2fHelper.CrossProduct: Float;
begin
  Result := CrossProduct(Self);
end;

function TVector2fHelper.CrossProduct(const A: TVector2f): Float;
begin
  Result := (X * A.Y) - (Y * A.X);
end;

function TVector2fHelper.Perp: TVector2f;
begin
  Result.X := -Y;
  Result.Y :=  X;
end;

function TVector2fHelper.PerpDotProduct(const A: TVector2f): Float;
begin
  Result := (X * A.Y) - (Y * A.X);
end;

function TVector2fHelper.Length: Float;
begin
  Result := Sqrt(DotProduct);
end;

function TVector2fHelper.Length(const APos: TVector2f): Float;
begin
  Result := (Self - APos).Length;
end;

function TVector2fHelper.ApproxLength: Float;
var
  DX, DY, DT: Float;
begin
  DX := System.Abs(X);
  DY := System.Abs(Y);

  if DX <= DY then
  begin
    DT := DX;
    DX := DY;
    DY := DT;
  end;

  Result := DX + DY * 0.414213562;
end;

function TVector2fHelper.ApproxLength(const APos: TVector2f): Float;
begin
  Result := (Self - APos).ApproxLength;
end;

function TVector2fHelper.Reflect;
begin
  Result := Self + APos * (-2 * Self.DotProduct(APos));
end;

function TVector2fHelper.Normalize;
var
  Len: Float;
begin
  Len := Length;

  if Len > 0 then
    Result := Self / Len
  else
    Result := Zero;
end;

function TVector2fHelper.Lerp;
begin
  Result.X := X.Lerp(ATarget.X, AAlpha);
  Result.Y := Y.Lerp(ATarget.Y, AAlpha);
end;

function TVector2fHelper.LerpCos;
begin
  Result := Lerp(ATarget, (1 - System.Cos(AAlpha * PI)) * 0.5);
end;

function TVector2fHelper.Rotate(const AAngle: Float): TVector2f;
var
  SC: TVector2f;
begin
  SC := CreateSinCos(AAngle);

  Result.X := SC.Y * X - SC.X * Y;
  Result.Y := SC.X * X + SC.Y * Y
end;

function TVector2fHelper.Rotate(const AAngle: Float; const APos: TVector2f): TVector2f;
begin
  Result := (Self - APos).Rotate(AAngle);
end;

function TVector2fHelper.Direction: Float;
begin
  Result := 0;

  if Y > 0 then
    Result := System.ArcTan(X / Y)
  else if Y < 0 then
  begin
    Result := System.ArcTan(X / Y);

    if X < 0 then
      Result := Result - Pi
    else
      Result := Result + Pi;
  end
  else
  begin
    if X < 0 then
      Result := - Pi / 2
    else if X > 0 then
      Result := Pi / 2;
  end;
end;

function TVector2fHelper.Direction(const APos: TVector2f): Float;
begin
  Result := (Self - APos).Direction;
end;

function TVector2fHelper.CircleMap;
begin
  Result := Create(X * Sqrt(1 - Y * Y / 2), Y * Sqrt(1 - X * X / 2));
end;

function TVector2fHelper.Vector3;
begin
  Result.XY := Self;
  Result.Z  := AZ;
end;

class function TVector2fHelper.FromString;
begin
  // TODO
  Result := Zero;
end;

function TVector2fHelper.ToString;
begin
  Result := 'X:' + X.ToString(APrec) + ';Y:' + Y.ToString(APrec);
end;
{$ENDREGION}

{$REGION 'TVector3fHelper'}
function TVector3fHelper.Round;
begin
  Result.XY := XY.Round;
  Result.Z  :=  Z.Round;
end;

function TVector3fHelper.Trunc;
begin
  Result.XY := XY.Trunc;
  Result.Z  :=  Z.Trunc;
end;

function TVector3fHelper.Ceil;
begin
  Result.XY := XY.Ceil;
  Result.Z  :=  Z.Ceil;
end;

function TVector3fHelper.Floor;
begin
  Result.XY := XY.Floor;
  Result.Z  :=  Z.Floor;
end;

function TVector3fHelper.CeilFloor;
begin
  Result.XY := XY.CeilFloor;
  Result.Z  :=  Z.CeilFloor;
end;

function TVector3fHelper.Frac;
begin
  Result.XY := XY.Frac;
  Result.Z  :=  Z.Frac;
end;

function TVector3fHelper.Abs;
begin
  Result.XY := XY.Abs;
  Result.Z  :=  Z.Abs;
end;

function TVector3fHelper.DotProduct: Float;
begin
  Result := DotProduct(Self);
end;

function TVector3fHelper.DotProduct(const A: TVector3f): Float;
begin
  Result := (X * A.X) + (Y * A.Y) + (Z + A.Z);
end;

function TVector3fHelper.CrossProduct: TVector3f;
begin
  Result := CrossProduct(Self);
end;

function TVector3fHelper.CrossProduct(const A: TVector3f): TVector3f;
begin
  Result.X := (Y * A.Z) - (Z * A.Y);
  Result.Y := (Z * A.X) - (X * A.Z);
  Result.Z := (X * A.Y) - (Y * A.X);
end;

function TVector3fHelper.Length: Float;
begin
  Result := Sqrt(DotProduct);
end;

function TVector3fHelper.Length(const APos: TVector3f): Float;
begin
  Result := (Self - APos).Length;
end;

function TVector3fHelper.Normalize;
var
  Len: Float;
begin
  Len := Length;

  if Len > 0 then
    Result := Self / Len
  else
    Result := Zero;
end;

function TVector3fHelper.ParallelNormal;
begin
  Result := APos * (DotProduct(APos) / Sqr(Length));
end;

function TVector3fHelper.Reflect;
begin
  Result := Self - ASurfaceNormal * DotProduct(ASurfaceNormal) * 2;
end;

function TVector3fHelper.Lerp;
begin
  Result.X := X.Lerp(ATarget.X, AAlpha);
  Result.Y := Y.Lerp(ATarget.Y, AAlpha);
  Result.Y := Z.Lerp(ATarget.Z, AAlpha);
end;

function TVector3fHelper.LerpCos;
begin
  Result := Lerp(ATarget, (1 - System.Cos(AAlpha * PI)) * 0.5);
end;

function TVector3fHelper.Vector4;
begin
  Result.XYZ := Self;
  Result.W   := AW;
end;

class function TVector3fHelper.FromString;
begin
  // TODO:
  Result := Zero;
end;

function TVector3fHelper.ToString;
begin
  Result := XY.ToString(APrec) + ';Z:' + Z.ToString(APrec);
end;
{$ENDREGION}

{$REGION 'TVector4fHelper'}
function TVector4fHelper.Round;
begin
  Result.XYZ := XYZ.Round;
  Result.W   :=   W.Round;
end;

function TVector4fHelper.Trunc;
begin
  Result.XYZ := XYZ.Trunc;
  Result.W   :=   W.Trunc;
end;

function TVector4fHelper.Ceil;
begin
  Result.XYZ := XYZ.Ceil;
  Result.W   :=   W.Ceil;
end;

function TVector4fHelper.Floor;
begin
  Result.XYZ := XYZ.Floor;
  Result.W   :=   W.Floor;
end;

function TVector4fHelper.CeilFloor;
begin
  Result.XYZ := XYZ.CeilFloor;
  Result.W   :=   W.CeilFloor;
end;

function TVector4fHelper.Frac;
begin
  Result.XYZ := XYZ.Frac;
  Result.W   :=   W.Frac;
end;

function TVector4fHelper.Abs;
begin
  Result.XYZ := XYZ.Abs;
  Result.W   :=   W.Abs;
end;
function TVector4fHelper.DotProduct: Float;
begin
  Result := DotProduct(Self);
end;

function TVector4fHelper.DotProduct(const A: TVector4f): Float;
begin
  Result := XYZ.DotProduct(A.XYZ);
end;

function TVector4fHelper.CrossProduct: TVector4f;
begin
  Result := CrossProduct(Self);
end;

function TVector4fHelper.CrossProduct(const A: TVector4f): TVector4f;
begin
  Result.XYZ := XYZ.CrossProduct(A.XYZ);
  Result.W   := 1;
end;

function TVector4fHelper.Length: Float;
begin
  Result := Sqrt(DotProduct);
end;

function TVector4fHelper.Length(const APos: TVector4f): Float;
begin
  Result := (Self - APos).Length;
end;

function TVector4fHelper.Normalize;
var
  Len: Float;
begin
  Len := Length;

  if Len > 0 then
    Result := Self / Len
  else
    Result := Zero;
end;

function TVector4fHelper.ParallelNormal;
begin
  Result.XYZ := Self.XYZ.ParallelNormal(APos.XYZ);
  Result.W   := 1;
end;

function TVector4fHelper.Reflect;
begin
  Result.XYZ := Self.XYZ.Reflect(ASurfaceNormal.XYZ);
  Result.W   := 1;
end;

function TVector4fHelper.Lerp;
begin
  Result.X := X.Lerp(ATarget.X, AAlpha);
  Result.Y := Y.Lerp(ATarget.Y, AAlpha);
  Result.Y := Z.Lerp(ATarget.Z, AAlpha);
  Result.W := W.Lerp(ATarget.W, AAlpha);
end;

function TVector4fHelper.LerpCos;
begin
  Result := Lerp(ATarget, (1 - System.Cos(AAlpha * PI)) * 0.5);
end;

function TVector4fHelper.Width;
begin
  Result := 0;
  // TODO: Result := Right - Left;
end;

function TVector4fHelper.Height;
begin
  Result := 0;
  // TODO: Result := Bottom - Top;
end;

function TVector4fHelper.Center;
begin
  Result := TVector2f.Zero;
  //TODO: Result.X := Left + (Width  / 2);
  //TODO: Result.Y := Top  + (Height / 2);
end;

function TVector4fHelper.Alpha;
begin
  Result.RGB := Self.RGB;
  Result.A   := AAlpha;
end;

class function TVector4fHelper.FromString;
begin
  // TODO:
  Result := Zero;
end;

function TVector4fHelper.ToString;
begin
  Result := XYZ.ToString(APrec) + ';W:' + W.ToString(APrec);
end;
{$ENDREGION}
