function TBooleanHelper.&if<T>(const ATrue, AFalse: T): T;
begin
  if Self then Result := ATrue else Result := AFalse;
end;

function TBooleanHelper.&if(const ATrue, AFalse: Integer): Integer;
begin
  if Self then Result := ATrue else Result := AFalse;
end;

function TBooleanHelper.&if(const ATrue, AFalse: Extended): Extended;
begin
  if Self then Result := ATrue else Result := AFalse;
end;

function TBooleanHelper.&if(const ATrue, AFalse: Char): Char;
begin
  if Self then Result := ATrue else Result := AFalse;
end;

function TBooleanHelper.&if(const ATrue, AFalse: Pointer): Pointer;
begin
  if Self then Result := ATrue else Result := AFalse;
end;

function TBooleanHelper.&if(const ATrue, AFalse: String): String;
begin
  if Self then Result := ATrue else Result := AFalse;
end;

class function TBooleanHelper.FromString;
begin
  // TODO
  Result := ADefault;
end;

function TBooleanHelper.ToString;
begin
  Result := &if(ATrue, AFalse);
end;

