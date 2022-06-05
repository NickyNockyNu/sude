class function TPointerHelper.Alloc;
begin
  GetMem(Result, ASize);
end;

procedure TPointerHelper.Resize;
begin
  if Self = nil then
    GetMem(Self, ASize)
  else
    ReallocMem(Self, ASize);
end;

procedure TPointerHelper.Free;
begin
  if Self = nil then
    Exit;

  FreeMem(Self);
  Self := nil;
end;

procedure TPointerHelper.Inc;
begin
  Self := Address(ACount);
end;

procedure TPointerHelper.Dec;
begin
  Self := Address(-ACount);
end;

procedure TPointerHelper.Read(var AData; const ASize: Integer; const AIncrement: Boolean = True);
begin
  Move(Self^, AData, ASize);

  if AIncrement then
    Inc(ASize);
end;

procedure TPointerHelper.Write(const AData; const ASize: Integer; const AIncrement: Boolean = True);
begin
  Move(AData, Self^, ASize);

  if AIncrement then
    Inc(ASize);
end;

function TPointerHelper.Read<T>(const AIncrement: Boolean = True): T;
begin
  Read(Result, SizeOf(Result), AIncrement);
end;

procedure TPointerHelper.Write<T>(const AValue: T; const AIncrement: Boolean = True);
begin
  Write(AValue, SizeOf(AValue), AIncrement);
end;

function TPointerHelper.Address;
begin
  Result := Pointer(IntPtr(Self) + AIndex);
end;

function TPointerHelper.ArrayRead<T>;
begin
  Move(Address(SizeOf(T) * AIndex)^, Result, SizeOf(T));
end;

procedure TPointerHelper.ArrayWrite<T>;
begin
  Move(AValue, Address(SizeOf(T) * AIndex)^, SizeOf(T));
end;

function TPointerHelper.IsNil;
begin
  Result := Self = nil;
end;

function TPointerHelper.ToString: String;
const
  HexPrefix = '0x';
  HexChars  = '0123456789ABCDEF';
var
  PtrUInt: UIntPtr;
  PtrSize: Integer;
begin
  Result := '';

  PtrUInt := UIntPtr(Self);

  if PtrUInt = 0 then
    Result := HexChars[1]
  else
    while PtrUInt > 0 do
    begin
      Result := HexChars[(PtrUInt mod 16) + 1] + Result;
      PtrUInt := PtrUInt shr 4;
    end;

  PtrSize := SizeOf(Pointer) shl 1;

  while Length(Result) < PtrSize do
    Result := HexChars[1] + Result;

  Result := HexPrefix + Result;
end;
