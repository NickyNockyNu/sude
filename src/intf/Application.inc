type
  TApplication = class abstract
  private
    FTitle: String;

    FSpeed: Double;

    procedure SetTitle(const ATitle: String);
  public
    constructor Create;
    destructor  Destroy; override;

    class procedure Run(const AWidth, AHeight: Integer; const AScale: Single = 1; const AVSync: Boolean = True; const AFrequency: Integer = 60);
    procedure Stop; inline;

    procedure OnStart; virtual;
    procedure OnStop;  virtual;

    procedure OnUpdate(const ADelta: Double); virtual;
    procedure OnRender;                       virtual;

    procedure OnButtonPressed (const AButton: Word); virtual;
    procedure OnButtonReleased(const AButton: Word); virtual;

    procedure OnMouseMoved(const ADeltaX, ADeltaY, ADeltaA: Integer); virtual;

    procedure OnGamepadMoved(const ADeltaLStick, ADeltaRStick: TVector2f; const ADeltaShoulder: Float); virtual;

    property Title: String read FTitle write SetTitle;

    property Speed: Double read FSpeed write FSpeed;
  end;
