type
  TTexture = class
  private
    FHandle: GLuint;

    FWidth:  Integer;
    FHeight: Integer;
  public
    constructor Create(const AWidth, AHeight: Integer; const AData: Pointer = nil); overload;
    constructor Create(const AFileName: String); overload;

    destructor Destroy; override;

    procedure Resize(const AWidth, AHeight: Integer; const AData: Pointer = nil);

          procedure Activate  (const AIndex: Integer = 0);
    class procedure Deactivate(const AIndex: Integer = 0);

    procedure Draw(const AX, AY: Integer; const AHint: TVector4f);

    property Handle: GLuint read FHandle;

    property Width:  Integer read FWidth;
    property Height: Integer read FHeight;
  end;
