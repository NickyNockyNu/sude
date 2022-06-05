type
  TFrameBuffer = class
  private
    FHandle: GLuint;

    FTextures: array of TTexture;

    FProjection: TMatrix;

    procedure Draw(const ATexture: Integer);

    function GetDimention(const AIndex: Integer): Integer;
  public
    constructor Create(const AWidth, AHeight: Integer; const ATextures: Integer = 1);
    destructor  Destroy; override;

    procedure Resize(const AWidth, AHeight: Integer; const ATextures: Integer = 1);

          procedure Activate;
    class procedure Deactivate;

    procedure Present(const ATexture: Integer = 0);

    property Handle: GLuint read FHandle;

    property Width:  Integer index 0 read GetDimention;
    property Height: Integer index 1 read GetDimention;
  end;

