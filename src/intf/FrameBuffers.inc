type
  TFrameBuffer = class
  const
    ShaderVertex   = '#version 330 core'#13#10'layout(location=0) in vec2 v;out vec2 t;void main(){t=(v+1)/2;gl_Position=vec4(v,0,1);}';
    ShaderFragment = '#version 330 core'#13#10'in vec2 t;out vec4 c;uniform sampler2D b;void main(){c=texture(b,t);}';
  private class var
    FVBO: GLuint;
    FVAO: GLuint;

    FShader: TShader;
  private
    FHandle: GLuint;

    FTextures: array of TTexture;

    FProjection: TMatrix;

    class constructor Create;
    class destructor  Destroy;

    class procedure CreateBuffers;

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

