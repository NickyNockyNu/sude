procedure TFrameBuffer.Draw;
begin
  if (ATexture >= Length(FTextures)) or (ATexture < 0) then
    Exit;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity;

  glOrtho(0, 1, 0, 1, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity;

  FTextures[ATexture].Activate;

  Surface.SetColour(Colour.White);

  glDisable(GL_DEPTH_TEST);

  glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(0, 0);
    glTexCoord2f(1, 0); glVertex2i(1, 0);
    glTexCoord2f(1, 1); glVertex2i(1, 1);
    glTexCoord2f(0, 1); glVertex2i(0, 1);
  glEnd;

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
