procedure TApplication.SetTitle;
begin
  FTitle := ATitle;

  if Window.Application = Self then
    Window.UpdateTitle;
end;

constructor TApplication.Create;
begin
  inherited;

  FTitle := ClassName;

  FSpeed := 1;
end;

destructor TApplication.Destroy;
begin
  inherited;
end;

class procedure TApplication.Run;
begin
  ReportMemoryLeaksOnShutdown := True;

  Window.Scale := AScale;

  Window.Frequency := AFrequency;
  Window.VSync     := AVSync;

  Surface.Resize(AWidth, AHeight);

  var App := Create;

  try
    Window.Run(App);
  finally
    App.Free;
  end;
end;

procedure TApplication.Stop;
begin
  Window.Stop;
end;

procedure TApplication.OnStart;
begin
  {}
end;

procedure TApplication.OnStop;
begin
  {}
end;

procedure TApplication.OnUpdate;
begin
  {}
end;

procedure TApplication.OnRender;
begin
  {}
end;

procedure TApplication.OnButtonPressed;
begin
  {}
end;

procedure TApplication.OnButtonReleased;
begin
  {}
end;

procedure TApplication.OnMouseMoved;
begin
  {}
end;

procedure TApplication.OnGamepadMoved;
begin
  {}
end;
