class procedure Input.Buttons.Pressed;
begin
  if FStates[AButton] then
     Exit;

  FStates[AButton] := True;

  if Window.FRunning and Assigned(Window.FApplication) then
    Window.FApplication.OnButtonPressed(AButton);
end;

class procedure Input.Buttons.Released;
begin
  if not FStates[AButton] then
    Exit;

  FStates[AButton] := False;

  if Window.FRunning and Assigned(Window.FApplication) then
    Window.FApplication.OnButtonReleased(AButton);
end;

class function Input.Buttons.GetState;
begin
  case AButton of
    VK_LSHIFT, VK_RSHIFT, VK_LCONTROL, VK_RCONTROL:
      Result := (GetKeyState(AButton) and $8000) > 0;

    VK_PADFIRST..VK_PADLAST:
    begin
      if Input.Gamepad.FID <> TGamepadID.None then
        Input.Gamepad.PollButtons;

      Result := FStates[AButton];
    end;
  else
    Result := FStates[AButton];
  end;
end;

class procedure Input.Buttons.Reset;
begin
  FillChar(FStates, SizeOf(FStates), 0);
end;

class procedure Input.Mouse.Moved;
begin
  FPosition.X := AX / Window.FScale;
  FPosition.Y := AY / Window.FScale;

  FX := Round(FPosition.X);
  FY := Round(FPosition.Y);

  FOver := (FX >= 0) and (FY >= 0) and (FX <= Surface.Width) and (FY <= Surface.Height);

  if Window.FRunning and Assigned(Window.FApplication) then
    Window.FApplication.OnMouseMoved(FX - FLX, FY - FLY, 0);

  FLX := FX;
  FLY := FY;
end;

class procedure Input.Mouse.Scrolled;
begin
  FS := FS + AScroll;

  if Window.FRunning and Assigned(Window.FApplication) then
    Window.FApplication.OnMouseMoved(0, 0, AScroll);
end;

class procedure Input.Mouse.Reset;
begin
  FX := 0;
  FY := 0;

  FLX := FX;
  FLY := FY;

  FPosition.X := FX;
  FPosition.Y := FY;

  FOver := False;

  ResetScroll;
end;

class procedure Input.Mouse.ResetScroll;
begin
  FS := 0;
end;

class procedure Input.Gamepad.SetID;
begin
  if FID <> TGamepadID.None then
    joyReleaseCapture(Ord(FID));

  FID := AID;

  if FID > TGamepadID.None then
    if joySetCapture(Window.FHandle, Ord(FID), 0, True) <> JOYERR_NOERROR then
      FID := TGamepadID.None;
end;

class function Input.Gamepad.GetStick;
begin
  PollSticks(False);

  case AIndex of
    0: Result := FLStick;
    1: Result := FRStick;
  else
    Result := TVector2f.Zero;
  end;
end;

class function Input.Gamepad.GetShoulder;
begin
  PollSticks(False);

  Result := FShoulder;
end;

class procedure Input.Gamepad.PollButtons;
var
  JoyInfo: JOYINFOEX;

  procedure SetButton(const AButton: Word; const AState: Boolean);
  begin
    if AState then
      Input.Buttons.Pressed(AButton)
    else
      Input.Buttons.Released(AButton);
  end;
begin
  if FID = TGamePadID.None then
    Exit;

  JoyInfo.dwSize  := SizeOf(JoyInfo);
  JoyInfo.dwFlags := JOY_RETURNPOV or JOY_RETURNBUTTONS;

  JoyGetPosEx(Ord(FID), @JoyInfo);

  SetButton(VK_PADA, (JoyInfo.wButtons and $0001) > 0);
  SetButton(VK_PADB, (JoyInfo.wButtons and $0002) > 0);
  SetButton(VK_PADX, (JoyInfo.wButtons and $0004) > 0);
  SetButton(VK_PADY, (JoyInfo.wButtons and $0008) > 0);

  SetButton(VK_PADLSHOULDER, (JoyInfo.wButtons and $0010) > 0);
  SetButton(VK_PADRSHOULDER, (JoyInfo.wButtons and $0020) > 0);

  SetButton(VK_PADLSTICK, (JoyInfo.wButtons and $0100) > 0);
  SetButton(VK_PADRSTICK, (JoyInfo.wButtons and $0200) > 0);

  SetButton(VK_PADSELECT, (JoyInfo.wButtons and $0040) > 0);
  SetButton(VK_PADSTART,  (JoyInfo.wButtons and $0080) > 0);

  case JoyInfo.dwPOV of
    JOY_POVLEFT:
    begin
      SetButton(VK_PADLEFT,  True);
      SetButton(VK_PADRIGHT, False);
      SetButton(VK_PADUP,    False);
      SetButton(VK_PADDOWN,  False);
    end;

    JOY_POVRIGHT:
    begin
      SetButton(VK_PADLEFT,  False);
      SetButton(VK_PADRIGHT, True);
      SetButton(VK_PADUP,    False);
      SetButton(VK_PADDOWN,  False);
    end;

    JOY_POVFORWARD:
    begin
      SetButton(VK_PADLEFT,  False);
      SetButton(VK_PADRIGHT, False);
      SetButton(VK_PADUP,    True);
      SetButton(VK_PADDOWN,  False);
    end;

    JOY_POVBACKWARD:
    begin
      SetButton(VK_PADLEFT,  False);
      SetButton(VK_PADRIGHT, False);
      SetButton(VK_PADUP,    False);
      SetButton(VK_PADDOWN,  True);
    end;
  else
    SetButton(VK_PADLEFT,  False);
    SetButton(VK_PADRIGHT, False);
    SetButton(VK_PADUP,    False);
    SetButton(VK_PADDOWN,  False);
  end;
end;

class procedure Input.Gamepad.PollSticks;
var
  JoyInfo: JOYINFOEX;
  DL, DR:  TVector2f;
  DS:      Float;
begin
  if FID = TGamepadID.None then
    Exit;

  JoyInfo.dwSize  := SizeOf(JoyInfo);
  JoyInfo.dwFlags := JOY_RETURNX or JOY_RETURNY or JOY_RETURNZ or JOY_RETURNR or JOY_RETURNU or JOY_RETURNV;

  JoyGetPosEx(Ord(FID), @JoyInfo);

  FLStick.X := Float(JoyInfo.wXpos).Map(0, $FFFF, -1, 1);
  FLStick.Y := Float(JoyInfo.wYpos).Map(0, $FFFF, -1, 1);

  FRStick.X := Float(JoyInfo.dwUpos).Map(0, $FFFF, -1, 1);
  FRStick.Y := Float(JoyInfo.dwRpos).Map(0, $FFFF, -1, 1);

  FShoulder := Float(JoyInfo.wZpos).Map(0, $FFFF, -1, 1);

  DL := FLStick - FLStickLast;
  DR := FRStick - FRStickLast;

  DS := FShoulder - FShoulderLast;

  if Window.FRunning and AEvent and Assigned(Window.FApplication) and ((DL.X <> 0) or (DL.Y <> 0) or (DR.X <> 0) or (DR.Y <> 0) or (DS <> 0)) then
  begin
    Window.FApplication.OnGamePadMoved(DL, DR, DS);

    FLStickLast := FLStick;
    FRStickLast := FRStick;

    FShoulderLast := FShoulder;
  end;
end;

class procedure Input.Gamepad.Reset;
begin
  FLStick := TVector2f.Zero;
  FRStick := TVector2f.Zero;

  FShoulder := 0;

  FLStickLast := FLStick;
  FRStickLast := FRStick;

  FShoulderLast := FShoulder;

  SetID(TGamepadID.None);
end;

class procedure Input.Reset;
begin
  Buttons.Reset;
  Mouse.Reset;
  Gamepad.Reset;
end;
