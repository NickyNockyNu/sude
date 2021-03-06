﻿function DwmFlush: HRESULT; stdcall; external 'DWMAPI.DLL';

class constructor Window.Create;
begin
  FApplication := nil;
  FRunning     := False;

  FShowFramesPerSecond := True;
  FShowSecondsPerFrame := False;
  FShowFrameDelta      := True;
  FShowElapsed         := True;

  CtorClass;
  CtorWindow;
  CtorOpenGL;
end;

class destructor Window.Destroy;
begin
  DtorOpenGL;
  DtorWindow;
  DtorClass;
end;

class procedure Window.CtorClass;
var
  WndClass: WNDCLASSEX;
begin
  FillChar(WndClass, SizeOf(WndClass), 0);

  with WndClass do
  begin
    cbSize := SizeOf(WndClass);

    lpfnWndProc   := @WindowProc;
    hInstance     := SysInit.HInstance;
    lpszClassName := PChar('SUDE_WND_CLASS');

    hCursor := LoadCursor(0, IDC_ARROW);
    hIcon   := LoadIcon(hInstance, 'MAINICON');

    if hIcon = 0 then
      hIcon := LoadIcon(0, IDI_APPLICATION);

    hbrBackground := COLOR_BTNFACE + 1;
  end;

  FAtom := RegisterClassEx(WndClass);

  if FAtom = 0 then
    raise EWindow.Create('Failed to register class');
end;

class procedure Window.CtorWindow;
begin
  FHandle := CreateWindowEx(StyleEx, PChar(FAtom), 'sude', Style, 0, 0, 0, 0, 0, 0, HInstance, nil);
  if FHandle = 0 then
    Halt(2);

  FDeviceContext := GetDC(FHandle);
  if FDeviceContext = 0 then
    Halt(3);
end;

class procedure Window.CtorOpenGL;
var
  PixelFormatDesc: PIXELFORMATDESCRIPTOR;
  PixelFormat:     GLint;
begin
  FillChar(PixelFormatDesc, SizeOf(PixelFormatDesc), 0);

  with PixelFormatDesc do
  begin
    nSize      := SizeOf(PixelFormatDesc);
    nVersion   := 1;
    dwFlags    := PFD_DRAW_TO_WINDOW or PFD_SUPPORT_OPENGL or PFD_DOUBLEBUFFER;
    iPixelType := PFD_TYPE_RGBA;
    cColorBits := 32;
    cDepthBits := 16;
    iLayerType := PFD_MAIN_PLANE;
  end;

  PixelFormat := ChoosePixelFormat(FDeviceContext, @PixelFormatDesc);
  if PixelFormat = 0 then
    raise EWindow.Create('Failed to choose pixel format');

  if not SetPixelFormat(FDeviceContext, PixelFormat, @PixelFormatDesc) then
    raise EWindow.Create('Failed to set pixel format');

  FRenderContext := wglCreateContext(FDeviceContext);
  if FRenderContext = 0 then
    raise EOpenGL.Create('Failed to create render context');

  if not wglMakeCurrent(FDeviceContext, FRenderContext) then
    raise EOpenGL.Create('Failed to start OpenGL');

  InitOpenGLext;
end;

class procedure Window.DtorClass;
begin
  if FAtom <> 0 then
  begin
    UnregisterClass(PChar(FAtom), HInstance);
    FAtom := 0;
  end;
end;

class procedure Window.DtorWindow;
begin
  if FHandle <> 0 then
  begin
    if FDeviceContext <> 0 then
    begin
      ReleaseDC(FDeviceContext, FHandle);
      FDeviceContext := 0;
    end;

    DestroyWindow(FHandle);
    FHandle := 0;
  end;
end;

class procedure Window.DtorOpenGL;
begin
  if FDeviceContext <> 0 then
    wglMakeCurrent(FDeviceContext, 0);

  if FRenderContext <> 0 then
  begin
    wglDeleteContext(FRenderContext);
    FRenderContext := 0;
  end;
end;

class function Window.WindowProc;
begin
  case AMsg of
    WM_CLOSE: PostQuitMessage(0);

    WM_KEYDOWN, WM_SYSKEYDOWN: Input.Buttons.Pressed (AwParam);
    WM_KEYUP,   WM_SYSKEYUP:   Input.Buttons.Released(AwParam);

    WM_LBUTTONDOWN: begin Input.Buttons.Pressed(VK_LBUTTON); SetCapture(Handle); end;
    WM_MBUTTONDOWN: begin Input.Buttons.Pressed(VK_MBUTTON); SetCapture(Handle); end;
    WM_RBUTTONDOWN: begin Input.Buttons.Pressed(VK_RBUTTON); SetCapture(Handle); end;

    WM_LBUTTONUP: begin Input.Buttons.Released(VK_LBUTTON); ReleaseCapture; end;
    WM_MBUTTONUP: begin Input.Buttons.Released(VK_MBUTTON); ReleaseCapture; end;
    WM_RBUTTONUP: begin Input.Buttons.Released(VK_RBUTTON); ReleaseCapture; end;

    WM_MOUSEMOVE:  Input.Mouse.Moved(SmallInt(AlParam and $FFFF), SmallInt((AlParam shr 16) and $FFFF));
    WM_MOUSEWHEEL: Input.Mouse.Scrolled(SmallInt((AwParam and $FFFF0000) shr 16) div WHEEL_DELTA);

    MM_JOY1BUTTONDOWN, MM_JOY1BUTTONUP,
    MM_JOY2BUTTONDOWN, MM_JOY2BUTTONUP:
      Input.Gamepad.PollButtons(True);

    MM_JOY1MOVE, MM_JOY1ZMOVE,
    MM_JOY2MOVE, MM_JOY2ZMOVE:
      Input.Gamepad.PollSticks(True);
  end;

  Result := DefWindowProc(AWnd, AMsg, AwParam, AlParam);
end;

class procedure Window.Update;
begin
  if not Assigned(FApplication) then
    Exit;

  FApplication.OnUpdate(ADelta);

  Inc(FUpdateCount);
end;

class procedure Window.Render;
begin
  if not Assigned(FApplication) then
    Exit;

  Surface.Prepare;
  FApplication.OnRender;
  Surface.Present;

  if FVSync then
    DwmFlush;

  SwapBuffers(FDeviceContext);

  Inc(FFrameCount);
end;

class procedure Window.SetScale;
begin
  FScale := AScale;

  if FScale < 1 then
    FScale := 1;

  FClientWidth  := Trunc(Surface.Width  * FScale);
  FClientHeight := Trunc(Surface.Height * FScale);

  var Rect := TRect.Create(0, 0, FClientWidth, FClientHeight);
  AdjustWindowRectEx(Rect, Style, False, StyleEx);

  MoveWindow(FHandle, (GetSystemMetrics(SM_CXSCREEN) shr 1) - (Rect.Width shr 1), (GetSystemMetrics(SM_CYSCREEN) shr 1) - (Rect.Height shr 1), Rect.Width, Rect.Height, True);
end;

class function Window.GetElapsed;
begin
  Result := FElapsed.Elapsed;
end;

class procedure Window.Run;
var
  FPSTimer: TTimer;

  FrameTimer:  TTimer;
  UpdateTimer: TTimer;

  Delta:       Double;
  DeltaTotal:  Double;

  FPSTime: Double;
begin
  if FRunning or (not Assigned(AApplication)) then
    Exit;

  try
    FApplication := AApplication;

    FUpdateCount := 0;
    FFrameCount  := 0;

    DeltaTotal := 0;

    FFramesPerSecond := 0;
    FSecondsPerFrame := 0;
    FFrameDelta      := 1;

    SetScale(FScale);

    Input.Reset;

    ShowWindow(FHandle, SW_SHOW);

    FApplication.OnStart;

    FRunning := True;

    FPSTimer.Reset;
    FrameTimer.Reset;
    UpdateTimer.Reset;
    FElapsed.Reset;

    UpdateTitle;

    wglMakeCurrent(FDeviceContext, FRenderContext);

    repeat
      FSecondsPerFrame := FrameTimer.Reset;

      Delta      := FApplication.Speed * FFrequency * FSecondsPerFrame;
      DeltaTotal := DeltaTotal + Delta;

      Update(Delta);

      Render;

      FPSTime := FPSTimer.Elapsed;

      if FPSTime >= 1 then
      begin
        FPSTimer.Reset;

        FFramesPerSecond := Round(FFrameCount / FPSTime);
        FFrameDelta      := DeltaTotal / FUpdateCount;

        FUpdateCount := 0;
        FFrameCount  := 0;
        DeltaTotal   := 0;

        UpdateTitle;
      end;

      if ProcessMessages(False) = WM_QUIT then
        Stop;
    until not FRunning;

    FApplication.OnStop;

    ShowWindow(FHandle, SW_HIDE);
  finally
    Stop;

    FApplication := nil;
  end;
end;

class procedure Window.Stop;
begin
  FRunning := False;
end;

class procedure Window.UpdateTitle;
var
  Title: String;

  procedure AppendTitle(const AEnable: Boolean; const AValue: Float; const APrefix: String; const APrec: Integer = 0);
  begin
    if AEnable then
      Title := Title + '  ●  ' + AValue.ToString(APrec) + APrefix;
  end;
begin
  if Assigned(FApplication) then
    Title := FApplication.Title
  else
    Title := 'sude';

  if FRunning then
  begin
    AppendTitle(FShowFramesPerSecond, FFramesPerSecond, ' fps',   0);
    AppendTitle(FShowSecondsPerFrame, FSecondsPerFrame, ' spf',   7);
    AppendTitle(FShowFrameDelta,      FFrameDelta,      ' delta', 4);
    AppendTitle(FShowElapsed,         FElapsed.Elapsed,  's',     0);
  end;

  SetWindowText(FHandle, PChar(Title));
end;

class function Window.ProcessMessages;
var
  Msg: TMsg;
begin
  if AWait then
    WaitMessage;

  while PeekMessage(Msg, 0, 0, 0, PM_REMOVE) do
  begin
    if Msg.message = WM_QUIT then
      Break;

    TranslateMessage(Msg);
    DispatchMessage (Msg);
  end;

  Result := Msg.message;
end;
