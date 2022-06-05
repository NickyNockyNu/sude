type
  Window = class abstract
  const
    Style   = WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_MINIMIZEBOX;
    StyleEx = 0;
  private class var
    FAtom:   ATOM;
    FHandle: HWND;

    FDeviceContext: HDC;
    FRenderContext: HGLRC;

    FClientWidth:  Integer;
    FClientHeight: Integer;

    FVSync:      Boolean;
    FFrequency:  Integer;
    FFrameDelta: Double;

    FUpdateCount: Integer;
    FFrameCount:  Integer;

    FFramesPerSecond: Integer;
    FSecondsPerFrame: Double;

    FElapsed: TTimer;

    FScale: Single;

    FApplication: TApplication;

    FRunning: Boolean;

    FShowFrameDelta:      Boolean;
    FShowFramesPerSecond: Boolean;
    FShowSecondsPerFrame: Boolean;
    FShowElapsed:         Boolean;
  private
    class constructor Create;
    class destructor  Destroy;

    class procedure CtorClass;
    class procedure CtorWindow;
    class procedure CtorOpenGL;

    class procedure DtorClass;
    class procedure DtorWindow;
    class procedure DtorOpenGL;

    class function WindowProc(AWnd: HWND; AMsg: Integer; AwParam: WPARAM; AlParam: LPARAM): LRESULT; stdcall; static;

    class procedure Update(const ADelta: Double);
    class procedure Render;

    class procedure SetScale(const AScale: Single); static;

    class function GetElapsed: Double; static;
  public
    class procedure Run(const AApplication: TApplication);
    class procedure Stop;

    class procedure UpdateTitle;

    class function ProcessMessages(const AWait: Boolean = False): Cardinal;

    class property Handle: HWND read FHandle;

    class property DeviceContext: HDC   read FDeviceContext;
    class property RenderContext: HGLRC read FRenderContext;

    class property Scale: Single read FScale write SetScale;

    class property ClientWidth:  Integer read FClientWidth;
    class property ClientHeight: Integer read FClientHeight;

    class property VSync:     Boolean read FVSync     write FVSync;
    class property Frequency: Integer read FFrequency write FFrequency;

    class property Elapsed: Double read GetElapsed;

    class property Application: TApplication read FApplication;

    class property Running: Boolean read FRunning;

    class property ShowFramesPerSecond: Boolean read FShowFramesPerSecond write FShowFramesPerSecond;
    class property ShowSecondsPerFrame: Boolean read FShowSecondsPerFrame write FShowSecondsPerFrame;
    class property ShowFrameDelta:      Boolean read FShowFrameDelta      write FShowFrameDelta;
    class property ShowElapsed:         Boolean read FShowElapsed         write FShowElapsed;
  end;
