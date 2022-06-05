const
  VK_MAX = Word(-1);

  VK_PADA = VK_MAX - 1;
  VK_PADB = VK_MAX - 2;
  VK_PADX = VK_MAX - 3;
  VK_PADY = VK_MAX - 4;

  VK_PADUP    = VK_MAX - 5;
  VK_PADDOWN  = VK_MAX - 6;
  VK_PADLEFT  = VK_MAX - 7;
  VK_PADRIGHT = VK_MAX - 8;

  VK_PADLSTICK = VK_MAX - 9;
  VK_PADRSTICK = VK_MAX - 10;

  VK_PADLSHOULDER = VK_MAX - 11;
  VK_PADRSHOULDER = VK_MAX - 12;

  VK_PADSELECT = VK_MAX - 13;
  VK_PADSTART  = VK_MAX - 14;

  VK_PADFIRST = VK_PADSTART;
  VK_PADLAST  = VK_PADA;

type
  TGamepadID = (None = -1, Pad1, Pad2);

  Input = class abstract
  public type
    Buttons = class abstract
    private class var
      FStates: array[Word] of Boolean;
    private
      class procedure Pressed (const AButton: Word);
      class procedure Released(const AButton: Word);

      class function GetState(const AButton: Integer): Boolean; static;
    public
      class procedure Reset;

      class property States[const AButton: Integer]: Boolean read GetState; default;

      {$REGION 'Common buttons'}
      class property LMouse: Boolean index VK_LBUTTON read GetState;
      class property MMouse: Boolean index VK_MBUTTON read GetState;
      class property RMouse: Boolean index VK_RBUTTON read GetState;

      class property Up:    Boolean index VK_UP    read GetState;
      class property Down:  Boolean index VK_DOWN  read GetState;
      class property Left:  Boolean index VK_LEFT  read GetState;
      class property Right: Boolean index VK_RIGHT read GetState;

      class property GamepadA: Boolean index VK_PADA read GetState;
      class property GamepadB: Boolean index VK_PADB read GetState;
      class property GamepadX: Boolean index VK_PADX read GetState;
      class property GamepadY: Boolean index VK_PADY read GetState;

      class property GamepadUp:    Boolean index VK_PADUP    read GetState;
      class property GamepadDown:  Boolean index VK_PADDOWN  read GetState;
      class property GamepadLeft:  Boolean index VK_PADLEFT  read GetState;
      class property GamepadRight: Boolean index VK_PADRIGHT read GetState;

      class property GamepadLStickButton: Boolean index VK_PADLSTICK read GetState;
      class property GamepadRStickButton: Boolean index VK_PADLSTICK read GetState;

      class property GamepadLShoulder: Boolean index VK_PADLSHOULDER read GetState;
      class property GamepadRShoulder: Boolean index VK_PADLSHOULDER read GetState;

      class property GamepadSelect: Boolean index VK_PADSELECT read GetState;
      class property GamepadStart:  Boolean index VK_PADSTART  read GetState;

      class property Escape: Boolean index VK_ESCAPE read GetState;
      class property Back:   Boolean index VK_BACK   read GetState;
      class property Enter:  Boolean index VK_RETURN read GetState;
      class property Space:  Boolean index VK_SPACE  read GetState;
      class property Tab:    Boolean index VK_TAB    read GetState;

      class property Shift:  Boolean index VK_SHIFT  read GetState;
      class property LShift: Boolean index VK_LSHIFT read GetState;
      class property RShift: Boolean index VK_RSHIFT read GetState;

      class property Ctrl:  Boolean index VK_CONTROL  read GetState;
      class property LCtrl: Boolean index VK_LCONTROL read GetState;
      class property RCtrl: Boolean index VK_RCONTROL read GetState;

      class property Alt: Boolean index VK_MENU read GetState;

      class property Menu: Boolean index VK_APPS read GetState;

      class property Insert: Boolean index VK_INSERT read GetState;
      class property Delete: Boolean index VK_DELETE read GetState;
      class property Home:   Boolean index VK_HOME   read GetState;
      class property &End:   Boolean index VK_END    read GetState;
      class property PgUp:   Boolean index VK_PRIOR  read GetState;
      class property PgDown: Boolean index VK_NEXT   read GetState;

      class property F1:  Boolean index VK_F1  read GetState;
      class property F2:  Boolean index VK_F2  read GetState;
      class property F3:  Boolean index VK_F3  read GetState;
      class property F4:  Boolean index VK_F4  read GetState;
      class property F5:  Boolean index VK_F5  read GetState;
      class property F6:  Boolean index VK_F6  read GetState;
      class property F7:  Boolean index VK_F7  read GetState;
      class property F8:  Boolean index VK_F8  read GetState;
      class property F9:  Boolean index VK_F9  read GetState;
      class property F10: Boolean index VK_F10 read GetState;
      class property F11: Boolean index VK_F11 read GetState;
      class property F12: Boolean index VK_F12 read GetState;
      {$ENDREGION}
    end;

    Mouse = class abstract
    private class var
      FX: Integer;
      FY: Integer;
      FS: Integer;

      FLX: Integer;
      FLY: Integer;

      FOver: Boolean;

      FPosition: TVector2f;
    private
      class procedure Moved   (const AX, AY:  Integer);
      class procedure Scrolled(const AScroll: Integer);
    public
      class procedure Reset;
      class procedure ResetScroll;

      class property X: Integer read FX;
      class property Y: Integer read FY;

      class property Scroll: Integer read FS;

      class property Over: Boolean read FOver;

      class property Position: TVector2f read FPosition;
    end;

    Gamepad = class abstract
    private class var
      FID: TGamepadID;

      FLStick:   TVector2f;
      FRStick:   TVector2f;
      FShoulder: Float;

      FLStickLast:   TVector2f;
      FRStickLast:   TVector2f;
      FShoulderLast: Float;
    private
      class procedure SetID(const AID: TGamepadID); static;

      class function GetStick(const AIndex: Integer): TVector2f; static;
      class function GetShoulder: Float; static;
    public
      class procedure PollButtons(const AEvent: Boolean = False);
      class procedure PollSticks (const AEvent: Boolean = False);

      class procedure Reset;

      class property ID: TGamepadID read FID write SetID;

      class property LStick: TVector2f index 0 read GetStick;
      class property RStick: TVector2f index 1 read GetStick;

      class property Shoulder: Float read GetShoulder;
    end;
  public
    class procedure Reset;
  end;
