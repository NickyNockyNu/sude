# 5 - Input

There are currently 3 supported input methods
1. Buttons
2. Mouse
3. Gamepad

The running `TApplication` will receive input events via the following procedures
```Delphi
    procedure OnButtonPressed (const AButton: Word); virtual;
    procedure OnButtonReleased(const AButton: Word); virtual;

    procedure OnMouseMoved(const ADeltaX, ADeltaY, ADeltaA: Integer); virtual;

    procedure OnGamepadMoved(const ADeltaLStick, ADeltaRStick: TVector2f; const ADeltaShoulder: Float); virtual;
```
Both the mouse and the gamepad may also trigger the `OnButtonXXXX` events.

Input states can also be queried at any time via the global `Input` object.
E.g.
```Delphi
procedure TMyApp.OnUpdate(const ADelta: Double);
begin
  if Input.Buttons[VK_ESCAPE] then Stop;
  
  Player.Position := Player.Position + Input.Gamepad.LStick * ADelta; 
end;
```
