class operator TUniform.Assign(var ALeft: TUniform; const [ref] ARight: TUniform);
begin
  if ARight.FName.IsNotEmpty then
  begin
    ALeft.FName     := ARight.FName;
    ALeft.FShader   := ARight.FShader;
    ALeft.FLocation := ARight.FLocation;
  end
  else
    ALeft.SetValues(ARight.FValues);
end;

class operator TUniform.Implicit(const AValue: TFloats): TUniform;
begin
  Result.FValues := AValue;
end;

class operator TUniform.Implicit(const AValue: Float): TUniform;
begin
  Result.FValues := [AValue];
end;

class operator TUniform.Implicit(const AValue: TVector2f): TUniform;
begin
  with AValue do
    Result.FValues := [X, Y];
end;

class operator TUniform.Implicit(const AValue: TVector3f): TUniform;
begin
  with AValue do
    Result.FValues := [X, Y, Z];
end;

class operator TUniform.Implicit(const AValue: TVector4f): TUniform;
begin
  with AValue do
    Result.FValues := [X, Y, Z, W];
end;

class operator TUniform.Implicit(const AValue: TMatrix): TUniform;
begin
  with AValue do
    Result.FValues := [
      m11, m12, m13, m14,
      m21, m22, m23, m24,
      m31, m32, m33, m34,
      m41, m42, m43, m44
    ];
end;

procedure TUniform.Link;
var
  AnsiName: AnsiString;
begin
  Unlink;

  AnsiName := AName.Ansi;

  FName     := AName;
  FShader   := AShader;
  FLocation := glGetUniformLocation(FShader, PAnsiChar(AnsiName));

  SetLength(FValues, 0);

  if (FLocation = GL_INVALID_VALUE) or (FLocation = GL_INVALID_OPERATION) then
  begin
    FLocation := -2;
    raise EShader.Create('Unknown uniform "' + AName + '"');
  end;
end;

procedure TUniform.Unlink;
begin
  FName     := '';
  FShader   := 0;
  FLocation := -2;
end;

procedure TUniform.SetValues;
begin
  if (FLocation < 0) or (Length(AValues) = 0) then
    Exit;

  case Length(AValues) of
    1: glUniform1f(FLocation, AValues[0]);
    2: glUniform2f(FLocation, AValues[0], AValues[1]);
    3: glUniform3f(FLocation, AValues[0], AValues[1], AValues[2]);
    4: glUniform4f(FLocation, AValues[0], AValues[1], AValues[2], AValues[3]);

    9:  glUniformMatrix3fv(FLocation, 1, GL_FALSE, @AValues[0]);
    16: glUniformMatrix4fv(FLocation, 1, GL_FALSE, @AValues[0]);
  end;
end;

procedure TUniform.SetValue(const AValue: Float);
begin
  {}
end;

procedure TUniform.SetValue(const AValue: TVector2f);
begin
  SetValues(AValue.Data);
end;

procedure TUniform.SetValue(const AValue: TVector3f);
begin
  SetValues(AValue.Data);
end;

procedure TUniform.SetValue(const AValue: TVector4f);
begin
  SetValues(AValue.Data);
end;

procedure TUniform.SetValue(const AValue: TMatrix);
begin
  SetValues(AValue.Data);
end;

procedure TUniform.SetTexture;
begin
  if FLocation < 0 then
    Exit;

  ATexture.Activate(AIndex);
  glUniform1i(FLocation, AIndex);
end;

