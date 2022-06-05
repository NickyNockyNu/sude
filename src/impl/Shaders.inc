constructor TShaderSource.Create;
var
  BufferStr: AnsiString;
  BufferPtr: PAnsiChar;
  BufferLen: GLint;

  Status: Byte;
begin
  inherited Create;

  FKind := AKind;

  FHandle := glCreateShader(Ord(FKind));

  BufferStr := ASource.ANSI;
  BufferPtr := PAnsiChar(BufferStr);
  BufferLen := Length(BufferStr);

  glShaderSource(FHandle, 1, @BufferPtr, @BufferLen);
  glCompileShader(FHandle);

  glGetShaderiv(FHandle, GL_COMPILE_STATUS, @Status);

  if Status <> GL_TRUE then
  begin
    var ErrorStr: AnsiString;
    var ErrorLen: GLsizei;

    glGetShaderiv(FHandle, GL_INFO_LOG_LENGTH, @ErrorLen);
    SetLength(ErrorStr, ErrorLen);

    glGetShaderInfoLog(FHandle, ErrorLen, @ErrorLen, PAnsiChar(ErrorStr));

    raise EShader.Create(String(ErrorStr));
  end;
end;

destructor TShaderSource.Destroy;
begin
  if FHandle <> 0 then
    glDeleteShader(FHandle);

  inherited;
end;

class function TShaderSource.CreateFromFile;
var
  SourceFile: TextFile;
  SourceLine: String;
  Source:     String;
begin
  AssignFile(SourceFile, AFileName);
  Reset(SourceFile);

  Source := '';

  while not Eof(SourceFile) do
  begin
    Readln(SourceFile, SourceLine);

    if Length(Source) = 0 then
      Source := SourceLine
    else
      Source := Source + #13#10 + SourceLine;
  end;

  CloseFile(SourceFile);

  Result := TShaderSource.Create(Source, AKind);
end;

function TShader.GetUniform;
begin
  Result.Link(FHandle, AName);
end;

constructor TShader.Create;
begin
  inherited Create;

  FHandle := glCreateProgram;

  glAttachShader(FHandle, AFragmentShader.FHandle);
  glAttachShader(FHandle,   AVertexShader.FHandle);

  glLinkProgram(FHandle);
end;

destructor TShader.Destroy;
begin
  if FHandle <> 0 then
    glDeleteProgram(FHandle);

  inherited;
end;

class function TShader.CreateFromFiles(const AVertexFile, AFragmentFile: String): TShader;
var
  VS, FS: TShaderSource;
begin
  VS := TShaderSource.CreateFromFile(  AVertexFile, TShaderKind.Vertex);
  FS := TShaderSource.CreateFromFile(AFragmentFile, TShaderKind.Fragment);

  try
    Result := TShader.Create(VS, FS);
  finally
    VS.Free;
    FS.Free;
  end;
end;

class function TShader.CreateFromFiles(const ABaseFileName: String): TShader;
begin
  Result := CreateFromFiles(
    ABaseFileName + '.vert',
    ABaseFileName + '.frag'
  );
end;

class function TShader.CreateFromSource;
var
  VS, FS: TShaderSource;
begin
  VS := TShaderSource.Create(  AVertexSource, TShaderKind.Vertex);
  FS := TShaderSource.Create(AFragmentSource, TShaderKind.Fragment);

  try
    Result := TShader.Create(VS, FS);
  finally
    VS.Free;
    FS.Free;
  end;
end;

procedure TShader.Activate;
begin
  glUseProgram(FHandle);
end;

class procedure TShader.Deactivate;
begin
  glUseProgram(0);
end;
