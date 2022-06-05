class function TCompare<T>.Compare;
begin
  if Assigned(CompareProc) then
    Result := CompareProc(ALeft, ARight)
  else
    Result := TypeCompare(ALeft, ARight);
end;

class function TCompare<T>.TypeCompare;
var
  PT: Pointer;
begin
  PT := TypeInfo(T);

  // Unsigned
       if PT = TypeInfo(Byte)     then Result := PByte(@ALeft)^     - PByte(@ARight)^
  else if PT = TypeInfo(Word)     then Result := PWord(@ALeft)^     - PWord(@ARight)^
  else if PT = TypeInfo(Cardinal) then Result := PCardinal(@ALeft)^ - PCardinal(@ARight)^
  else if PT = TypeInfo(UInt64)   then Result := PUInt64(@ALeft)^   - PUInt64(@ARight)^

  // Unsigned
  else if PT = TypeInfo(ShortInt) then Result := PShortInt(@ALeft)^ - PShortInt(@ARight)^
  else if PT = TypeInfo(SmallInt) then Result := PSmallInt(@ALeft)^ - PSmallInt(@ARight)^
  else if PT = TypeInfo(Integer)  then Result := PInteger(@ALeft)^  - PInteger(@ARight)^
  else if PT = TypeInfo(Int64)    then Result := PInt64(@ALeft)^    - PInt64(@ARight)^

  // Float
  else if PT = TypeInfo(Single)   then Result := Round(PSingle(@ALeft)^   - PSingle(@ARight)^)
  else if PT = TypeInfo(Double)   then Result := Round(PDouble(@ALeft)^   - PDouble(@ARight)^)
  else if PT = TypeInfo(Extended) then Result := Round(PExtended(@ALeft)^ - PExtended(@ARight)^)

  // String
  else if PT = TypeInfo(String) then Result := PString(@ALeft)^.Compare(PString(@ARight)^)

  else if PT = TypeInfo(AnsiString)    then Result := String(PAnsiString(@ALeft)^).Compare(String(PAnsiString(@ARight)^))
  else if PT = TypeInfo(WideString)    then Result := String(PWideString(@ALeft)^).Compare(String(PWideString(@ARight)^))
  else if PT = TypeInfo(UTF8String)    then Result := String(PUTF8String(@ALeft)^).Compare(String(PUTF8String(@ARight)^))
  else if PT = TypeInfo(RawByteString) then Result := String(PRawByteString(@ALeft)^).Compare(String(PRawByteString(@ARight)^))

  // Assume binary
  else Result := BinaryCompare(@ALeft, @ARight);
end;

class function TCompare<T>.BinaryCompare;
begin
  for var i := 0 to SizeOf(T) - 1 do
  begin
    Result := PByte(ALeft)[i] - PByte(ARight)[i];

    if Result <> 0 then
      Exit;
  end;

  Result := 0;
end;

