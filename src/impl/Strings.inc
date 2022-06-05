function TStringHelper.GetChar;
begin
  if (AIndex <= 0) or (AIndex > Length) then
    Result := #0
  else
    Result := Self[AIndex];
end;

procedure TStringHelper.SetChar;
begin
  if (AIndex > 0) and (AIndex <= Length) then
    Self[AIndex] := AChar;
end;

function TStringHelper.GetPChar;
begin
  if (AIndex <= 0) or (AIndex > Length) then
    Result := nil
  else
    Result := @Self[AIndex];
end;

function TStringHelper.GetLength;
begin
  Result := System.Length(Self);
end;

procedure TStringHelper.SetLength;
begin
  System.SetLength(Self, ALength);
end;

function TStringHelper.GetSize;
begin
  Result := Length * SizeOf(Char);
end;

procedure TStringHelper.SetSize;
begin
  Length := ASize div SizeOf(Char);
end;

function TStringHelper.Ansi;
begin
  Result := AnsiString(Self);
end;

function TStringHelper.FirstChar;
begin
  Result := Chars[1];
end;

function TStringHelper.LastChar;
begin
  Result := Chars[Length];
end;

function TStringHelper.IsEmpty;
begin
  Result := Length = 0;
end;

function TStringHelper.IsNotEmpty;
begin
  Result := Length > 0;
end;

procedure TStringHelper.Clear;
begin
  if IsEmpty then
    Exit;

  FillChar(Ptr[1]^, Size, $00);
  Self := '';
end;

function TStringHelper.Pos;
begin
  if AOutOfQuotes then
  begin
    var q: Char := #0;

    for var i := AStart to Length do
      if q <> #0 then
      begin
        if Self.Chars[i] = q then
          q := #0;
      end
      else if System.Pos(Self.Chars[i], CharsQuote) > 0 then
        q  := Self.Chars[i]
      else if Copy(i, AStr.Length).Same(AStr, AIgnoreCase) then
        Exit(i);
  end
  else
    for var i := AStart to Length do
      if Copy(i, AStr.Length).Same(AStr, AIgnoreCase) then
        Exit(i);

  Result := 0;
end;

function TStringHelper.Copy;
begin
  Result := System.Copy(Self, AIndex, (ACount = -1).&if(Length, ACount));
end;

function TStringHelper.Uppercase;
begin
  Result := Self;

  if AEnable then
    CharUpperBuff(Result.Ptr[1], Result.Length);
end;

function TStringHelper.Lowercase;
begin
  Result := Self;

  if AEnable then
    CharLowerBuff(Result.Ptr[1], Result.Length);
end;

function TStringHelper.Compare;
begin
  Result := CompareString(LOCALE_USER_DEFAULT, AIgnoreCase.&if(NORM_IGNORECASE, 0), Ptr[1], Length, AStr.Ptr[1], AStr.Length) - 2;
end;

function TStringHelper.Same;
begin
  Result := Compare(AStr, AIgnoreCase) = 0;
end;

