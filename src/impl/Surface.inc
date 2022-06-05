class constructor Surface.Create;
begin
  FBuffer := nil;
end;

class destructor Surface.Destroy;
begin
  if Assigned(FBuffer) then
    FBuffer.Free;
end;

class procedure Surface.Resize;
begin
  if not Assigned(FBuffer) then
    FBuffer := TFrameBuffer.Create(AWidth, AHeight)
  else
    FBuffer.Resize(AWidth, AHeight);

  FWidth  := AWidth;
  FHeight := AHeight;
end;

class procedure Surface.Prepare;
begin
  FBuffer.Activate;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity;

  TShader.Deactivate;
  TTexture.Deactivate;
end;

class procedure Surface.Present;
begin
  if Assigned(FBuffer) then
    FBuffer.Present;
end;

class procedure Surface.Clear;
begin
  glClearColor(AColour.R, AColour.G, AColour.B, AColour.A);
  glClear(GL_COLOR_BUFFER_BIT or GL_DEPTH_BUFFER_BIT);
end;

class procedure Surface.SetBlendMode;
begin
  if ABlendMode = TBlendMode.Disable then
    glDisable(GL_BLEND)
  else
    glEnable(GL_BLEND);

  case ABlendMode of
    TBlendMode.Alpha:   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    TBlendMode.Lighten: glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    TBlendMode.Darken:  glBlendFunc(GL_ZERO,      GL_ONE_MINUS_SRC_ALPHA);
  end;
end;

class procedure Surface.SetColour;
begin
  glColor(AColour.R, AColour.G, AColour.B, AColour.A);
end;

class procedure Surface.Line;
begin
  SetColour(AColour);

  glBegin(GL_LINES);
    glVertex2i(X1, Y1);
    glVertex2i(X2, Y2);
  glEnd;
end;

