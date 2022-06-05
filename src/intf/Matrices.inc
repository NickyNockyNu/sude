type
  PMatrix = ^TMatrix;
  TMatrix = record
  public
    class function Create(const
      m11, m12, m13, m14,
      m21, m22, m23, m24,
      m31, m32, m33, m34,
      m41, m42, m43, m44: Float
    ): TMatrix; overload; static;

    class function Create(const m1, m2, m3, m4: TVector4f): TMatrix; overload; static;

    class function CreateTranslate(const AOffset: TVector3f): TMatrix; static;
    class function CreateScale    (const AScale:  TVector3f): TMatrix; static;

    class function CreateRotate(const AAngle: Float; const AAxis: TVector3f): TMatrix; static;

    class function CreateRotateX(const AAngle: Float): TMatrix; static;
    class function CreateRotateY(const AAngle: Float): TMatrix; static;
    class function CreateRotateZ(const AAngle: Float): TMatrix; static;

    class function CreatePerspective(const AFOV, AAspect, AZNear, AZFar: Float): TMatrix; static;
    class function CreateOrthogonal(const ALeft, ARight, ABottom, ATop, AZNear, AZFar: Float): TMatrix; static;
    class function CreateLookAt(const AEye, ACenter, AUp: TVector3f): TMatrix; static;

    class operator Multiply(const A, B: TMatrix): TMatrix;

    class operator Multiply(const A: TVector3f; const B: TMatrix): TVector3f; inline;
    class operator Multiply(const A: TVector4f; const B: TMatrix): TVector4f; inline;

    class operator Multiply(const A: TMatrix; const B: Float): TMatrix;

    procedure LoadIdentity; inline;
    procedure LoadZero;     inline;

    procedure Translate(const AOffset: TVector3f); inline;
    procedure Scale    (const AScale:  TVector3f); inline;

    procedure Rotate(const AAngle: Float; const AAxis: TVector3f); inline;

    procedure RotateX(const AAngle: Float); inline;
    procedure RotateY(const AAngle: Float); inline;
    procedure RotateZ(const AAngle: Float); inline;

    function Transpose: TMatrix;
    function Adjoint:   TMatrix;
    function Inverse:   TMatrix;

    function Determinant: Float;

    function WorldPos: TVector3f;
    function EyePos:   TVector3f;

    function Lerp   (const ADest: TMatrix; const AAlpha: Float): TMatrix;
    function LerpCos(const ADest: TMatrix; const AAlpha: Float): TMatrix; inline;

    procedure Load(const AMatrix: GLuint = GL_MODELVIEW_MATRIX); inline;
    procedure Save; inline;

    function ToString(const APrec: Integer = 4): String;

  case RecordUnion of
    0: (Data:  array[0..15]      of Float);
    1: (Data2: array[0..3, 0..3] of Float);
    3: (
      m11, m12, m13, m14: Float;
      m21, m22, m23, m24: Float;
      m31, m32, m33, m34: Float;
      m41, m42, m43, m44: Float;
    );
    4: (
      m1: TVector4f;
      m2: TVector4f;
      m3: TVector4f;
      m4: TVector4f;
    );
  end;

  TMatrixHelper = record helper for TMatrix
  public const
    Zero: TMatrix = (
      Data2:(
        (0, 0, 0, 0),
        (0, 0, 0, 0),
        (0, 0, 0, 0),
        (0, 0, 0, 0)
      )
    );

    Identity: TMatrix = (
      Data2:(
       (1, 0, 0, 0),
       (0, 1, 0, 0),
       (0, 0, 1, 0),
       (0, 0, 0, 1)
      )
    );
  end;

