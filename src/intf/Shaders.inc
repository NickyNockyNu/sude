type
  TShaderKind = (Vertex = GL_VERTEX_SHADER, Fragment = GL_FRAGMENT_SHADER);

  TShaderSource = class
  private
    FHandle: GLuint;
    FKind:   TShaderKind;
  public
    constructor Create(const ASource: String; const AKind: TShaderKind);
    destructor  Destroy; override;

    class function CreateFromFile(const AFileName: String; const AKind: TShaderKind): TShaderSource;

    property Handle: GLuint read FHandle;

    property Kind: TShaderKind read FKind;
  end;

  TShader = class
  private
    FHandle: GLuint;

    function GetUniform(const AName: String): TUniform;
  public
    constructor Create(const AVertexShader, AFragmentShader: TShaderSource);
    destructor  Destroy; override;

    class function CreateFromFiles(const AVertexFile, AFragmentFile: String): TShader; overload;
    class function CreateFromFiles(const ABaseFileName:              String): TShader; overload;

    class function CreateFromSource(const AVertexSource, AFragmentSource: String): TShader;

          procedure Activate;
    class procedure Deactivate;

    property Handle: GLuint read FHandle;

    property Uniform[const AName: String]: TUniform read GetUniform; default;
  end;

