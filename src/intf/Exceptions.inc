type
 TException = class
  private
    class constructor Create;
  private
    FDetails:  String;
    FExitCode: Integer;
  public
    constructor Create(const ADetails: String = ''; const AExitCode: Integer = -1);

    property Details:  String  read FDetails;
    property ExitCode: Integer read FExitCode;

    class procedure Handler(const ExceptObject: TObject; const ExceptAddr: Pointer);
  end;

  TExceptionClass = class of TException;

  ERuntime  = class(TException);
  ESafecall = class(TException);
  EAbstract = class(TException);

  EWindow      = class(TException);
  EOpenGL      = class(TException);
  EFrameBuffer = class(TException);
  ETexture     = class(TException);
  EShader      = class(TException);


