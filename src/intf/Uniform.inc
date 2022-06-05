type
  TUniform = record
  private
    FName:     String;
    FShader:   GLuint;
    FLocation: GLint;

    FValues: TFloats;
  public
    class operator Assign(var ALeft: TUniform; const [ref] ARight: TUniform);

    class operator Implicit(const AValue: TFloats): TUniform; overload;
    class operator Implicit(const AValue: Float):  TUniform; overload;

    class operator Implicit(const AValue: TVector2f): TUniform; overload;
    class operator Implicit(const AValue: TVector3f): TUniform; overload;
    class operator Implicit(const AValue: TVector4f): TUniform; overload;

    class operator Implicit(const AValue: TMatrix): TUniform; overload;

    procedure Link(const AShader: Gluint; const AName: String);
    procedure Unlink;

    procedure SetValues(const AValues: array of Float);

    procedure SetValue(const AValue: Float); overload;

    procedure SetValue(const AValue: TVector2f); overload;
    procedure SetValue(const AValue: TVector3f); overload;
    procedure SetValue(const AValue: TVector4f); overload;

    procedure SetValue(const AValue: TMatrix); overload;

    procedure SetTexture(const ATexture: TTexture; const AIndex: Integer = 0);

    property Name:     String read FName;
    property Shader:   GLuint read FShader;
    property Location: GLint  read FLocation;
  end;

