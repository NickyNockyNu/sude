class constructor TFrameBuffer.Create;
begin
  FVBO := 0;
  FVAO := 0;
end;

class destructor TFrameBuffer.Destroy;
begin
  glDeleteVertexArrays(1, @FVAO);
  glDeleteBuffers(1, @FVBO);

  FShader.Free;
end;

class procedure TFrameBuffer.CreateBuffers;
const
  Vertices: array[0..11] of Float = (
    -1,  1,
     1, -1,
    -1, -1,

    -1,  1,
     1,  1,
     1, -1
  );
begin
  glGenVertexArrays(1, @FVAO);
  glGenBuffers     (1, @FVBO);

  glBindVertexArray(FVAO);
  glBindBuffer(GL_ARRAY_BUFFER, FVBO);

  glBufferData(GL_ARRAY_BUFFER, SizeOf(Vertices), @Vertices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * SizeOf(Float), nil);

  glBindVertexArray(0);

  FShader := TShader.CreateFromSource(ShaderVertex, ShaderFragment);
end;

procedure TFrameBuffer.Draw;
begin
  if (ATexture >= Length(FTextures)) or (ATexture < 0) then
    Exit;

  if FVBO = 0 then
    CreateBuffers;

  glDisable(GL_DEPTH_TEST);

  FTextures[ATexture].Activate;

  FShader.Activate;

  glBindVertexArray(FVAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);

  TTexture.Deactivate;
  TShader.Deactivate;
end;

function TFrameBuffer.GetDimention;
begin
  if Length(FTextures) = 0 then
    Exit(0);

  case AIndex of
    0: Result := FTextures[0].Width;
    1: Result := FTextures[0].Height;
  else
    Result := 0;
  end;
end;

constructor TFrameBuffer.Create;
begin
  inherited Create;

  FHandle := 0;

  SetLength(FTextures, 0);

  Resize(AWidth, AHeight, ATextures);
end;

destructor TFrameBuffer.Destroy;
begin
  Resize(0, 0);

  inherited;
end;

procedure TFrameBuffer.Resize;
begin
  if FHandle <> 0 then
  begin
    glDeleteFrameBuffers(1, @FHandle);
    FHandle := 0;
  end;

  for var T in FTextures do
    T.Free;

  if (AWidth = 0) or (AHeight = 0) or (ATextures = 0) then
    Exit;

  SetLength(FTextures, ATextures);

  for var i := 0 to ATextures - 1 do
    FTextures[i] := TTexture.Create(AWidth, AHeight);

  glGenFrameBuffers(1, @FHandle);
  glBindFrameBuffer(GL_FRAMEBUFFER, FHandle);

  for var i := 0 to ATextures - 1 do
    glFrameBufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, FTextures[i].FHandle, 0);

  if glCheckFramebufferStatus(GL_FRAMEBUFFER) <> GL_FRAMEBUFFER_COMPLETE then
    raise EFrameBuffer.Create('Failed to create frame buffer');

  FProjection := TMatrix.CreateOrthogonal(0, AWidth, AHeight, 0, 0, 1);

  Deactivate;
end;

procedure TFrameBuffer.Activate;
begin
  if FHandle = 0 then
    Exit;

  glBindFrameBuffer(GL_FRAMEBUFFER, FHandle);
  glViewport(0, 0, Width, Height);

  glMatrixMode(GL_PROJECTION);
  FProjection.Save;
end;

class procedure TFrameBuffer.Deactivate;
begin
  glBindFrameBuffer(GL_FRAMEBUFFER, 0);

  glViewport(0, 0, Window.ClientWidth, Window.ClientHeight);
end;

procedure TFrameBuffer.Present;
begin
  if FHandle = 0 then
    Exit;

  Deactivate;

  Draw(ATexture);
end;
