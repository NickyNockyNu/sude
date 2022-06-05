class constructor TOperator<T>.Create;
begin
  {$REGION 'Add'}
  // Unsigned
  TOperator<Byte>.AddProc     := function(const ALeft, ARight: Byte):     Byte     begin Result := ALeft + ARight end;
  TOperator<Word>.AddProc     := function(const ALeft, ARight: Word):     Word     begin Result := ALeft + ARight end;
  TOperator<Cardinal>.AddProc := function(const ALeft, ARight: Cardinal): Cardinal begin Result := ALeft + ARight end;
  TOperator<UInt64>.AddProc   := function(const ALeft, ARight: UInt64):   Uint64   begin Result := ALeft + ARight end;

  // Signed
  TOperator<ShortInt>.AddProc := function(const ALeft, ARight: ShortInt): ShortInt begin Result := ALeft + ARight end;
  TOperator<SmallInt>.AddProc := function(const ALeft, ARight: SmallInt): SmallInt begin Result := ALeft + ARight end;
  TOperator<Integer>.AddProc  := function(const ALeft, ARight: Integer):  Integer  begin Result := ALeft + ARight end;
  TOperator<Int64>.AddProc    := function(const ALeft, ARight: Int64):    Int64    begin Result := ALeft + ARight end;

  // Float
  TOperator<Single>.AddProc   := function(const ALeft, ARight: Single):   Single   begin Result := ALeft + ARight end;
  TOperator<Double>.AddProc   := function(const ALeft, ARight: Double):   Double   begin Result := ALeft + ARight end;
  TOperator<Extended>.AddProc := function(const ALeft, ARight: Extended): Extended begin Result := ALeft + ARight end;

  // String
  TOperator<String>.AddProc        := function(const ALeft, ARight: String):        String        begin Result := ALeft + ARight end;
  TOperator<AnsiString>.AddProc    := function(const ALeft, ARight: AnsiString):    AnsiString    begin Result := ALeft + ARight end;
  TOperator<WideString>.AddProc    := function(const ALeft, ARight: WideString):    WideString    begin Result := ALeft + ARight end;
  TOperator<UTF8String>.AddProc    := function(const ALeft, ARight: UTF8String):    UTF8String    begin Result := ALeft + ARight end;
  TOperator<RawByteString>.AddProc := function(const ALeft, ARight: RawByteString): RawByteString begin Result := ALeft + ARight end;
  {$ENDREGION}

  {$REGION 'Sub'}
  // Unsigned
  TOperator<Byte>.SubtractProc     := function(const ALeft, ARight: Byte):     Byte     begin Result := ALeft - ARight end;
  TOperator<Word>.SubtractProc     := function(const ALeft, ARight: Word):     Word     begin Result := ALeft - ARight end;
  TOperator<Cardinal>.SubtractProc := function(const ALeft, ARight: Cardinal): Cardinal begin Result := ALeft - ARight end;
  TOperator<UInt64>.SubtractProc   := function(const ALeft, ARight: UInt64):   Uint64   begin Result := ALeft - ARight end;

  // Signed
  TOperator<ShortInt>.SubtractProc := function(const ALeft, ARight: ShortInt): ShortInt begin Result := ALeft - ARight end;
  TOperator<SmallInt>.SubtractProc := function(const ALeft, ARight: SmallInt): SmallInt begin Result := ALeft - ARight end;
  TOperator<Integer>.SubtractProc  := function(const ALeft, ARight: Integer):  Integer  begin Result := ALeft - ARight end;
  TOperator<Int64>.SubtractProc    := function(const ALeft, ARight: Int64):    Int64    begin Result := ALeft - ARight end;

  // Float
  TOperator<Single>.SubtractProc   := function(const ALeft, ARight: Single):   Single   begin Result := ALeft - ARight end;
  TOperator<Double>.SubtractProc   := function(const ALeft, ARight: Double):   Double   begin Result := ALeft - ARight end;
  TOperator<Extended>.SubtractProc := function(const ALeft, ARight: Extended): Extended begin Result := ALeft - ARight end;
  {$ENDREGION}

  {$REGION 'Mul'}
  // Unsigned
  TOperator<Byte>.MultiplyProc     := function(const ALeft, ARight: Byte):     Byte     begin Result := ALeft * ARight end;
  TOperator<Word>.MultiplyProc     := function(const ALeft, ARight: Word):     Word     begin Result := ALeft * ARight end;
  TOperator<Cardinal>.MultiplyProc := function(const ALeft, ARight: Cardinal): Cardinal begin Result := ALeft * ARight end;
  TOperator<UInt64>.MultiplyProc   := function(const ALeft, ARight: UInt64):   Uint64   begin Result := ALeft * ARight end;

  // Signed
  TOperator<ShortInt>.MultiplyProc := function(const ALeft, ARight: ShortInt): ShortInt begin Result := ALeft * ARight end;
  TOperator<SmallInt>.MultiplyProc := function(const ALeft, ARight: SmallInt): SmallInt begin Result := ALeft * ARight end;
  TOperator<Integer>.MultiplyProc  := function(const ALeft, ARight: Integer):  Integer  begin Result := ALeft * ARight end;
  TOperator<Int64>.MultiplyProc    := function(const ALeft, ARight: Int64):    Int64    begin Result := ALeft * ARight end;

  // Float
  TOperator<Single>.MultiplyProc   := function(const ALeft, ARight: Single):   Single   begin Result := ALeft * ARight end;
  TOperator<Double>.MultiplyProc   := function(const ALeft, ARight: Double):   Double   begin Result := ALeft * ARight end;
  TOperator<Extended>.MultiplyProc := function(const ALeft, ARight: Extended): Extended begin Result := ALeft * ARight end;
  {$ENDREGION}

  {$REGION 'Div'}
  // Unsigned
  TOperator<Byte>.DivideProc     := function(const ALeft, ARight: Byte):     Byte     begin Result := ALeft div ARight end;
  TOperator<Word>.DivideProc     := function(const ALeft, ARight: Word):     Word     begin Result := ALeft div ARight end;
  TOperator<Cardinal>.DivideProc := function(const ALeft, ARight: Cardinal): Cardinal begin Result := ALeft div ARight end;
  TOperator<UInt64>.DivideProc   := function(const ALeft, ARight: UInt64):   Uint64   begin Result := ALeft div ARight end;

  // Signed
  TOperator<ShortInt>.DivideProc := function(const ALeft, ARight: ShortInt): ShortInt begin Result := ALeft div ARight end;
  TOperator<SmallInt>.DivideProc := function(const ALeft, ARight: SmallInt): SmallInt begin Result := ALeft div ARight end;
  TOperator<Integer>.DivideProc  := function(const ALeft, ARight: Integer):  Integer  begin Result := ALeft div ARight end;
  TOperator<Int64>.DivideProc    := function(const ALeft, ARight: Int64):    Int64    begin Result := ALeft div ARight end;

  // Float
  TOperator<Single>.DivideProc   := function(const ALeft, ARight: Single):   Single   begin Result := ALeft / ARight end;
  TOperator<Double>.DivideProc   := function(const ALeft, ARight: Double):   Double   begin Result := ALeft / ARight end;
  TOperator<Extended>.DivideProc := function(const ALeft, ARight: Extended): Extended begin Result := ALeft / ARight end;
  {$ENDREGION}
end;

class function TOperator<T>.Add(const ALeft, ARight: T): T;
begin
  if Assigned(AddProc) then
    Result := AddProc(ALeft, ARight)
  else
    Result := ALeft;
end;

class function TOperator<T>.Subtract(const ALeft, ARight: T): T;
begin
  if Assigned(SubtractProc) then
    Result := SubtractProc(ALeft, ARight)
  else
    Result := ALeft;
end;

class function TOperator<T>.Multiply(const ALeft, ARight: T): T;
begin
  if Assigned(MultiplyProc) then
    Result := MultiplyProc(ALeft, ARight)
  else
    Result := ALeft;
end;

class function TOperator<T>.Divide(const ALeft, ARight: T): T;
begin
  if Assigned(DivideProc) then
    Result := DivideProc(ALeft, ARight)
  else
    Result := ALeft;
end;

