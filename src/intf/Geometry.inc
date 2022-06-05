// Remove class constructor (F2084 Internal Error)
{$DEFINE COMPILER_IS_DUMB}

type
  {$REGION 'TVector2fHelper'}
  TVector2fHelper = record helper for TVector2f
  public const
    Zero: TVector2f = (X:0; Y:0);
    One:  TVector2f = (X:1; Y:1);

  public
    {$IFNDEF COMPILER_IS_DUMB}
    class function CreateSinCos(const AAngle: Float): TVector2f;
    {$ENDIF}

    function Round: TVector2i; inline;
    function Trunc: TVector2i; inline;

    function Ceil:  TVector2i; inline;
    function Floor: TVector2i; inline;

    function CeilFloor: TVector2i; inline;

    function Frac: TVector2f; inline;

    function Abs: TVector2f; inline;

    function DotProduct:                     Float; overload; inline;
    function DotProduct(const A: TVector2f): Float; overload; inline;

    function CrossProduct:                     Float; overload; inline;
    function CrossProduct(const A: TVector2f): Float; overload; inline;

    function Perp: TVector2f;
    function PerpDotProduct(const A: TVector2f): Float; inline;

    function Length:                        Float; overload; inline;
    function Length(const APos: TVector2f): Float; overload; inline;

    function ApproxLength:                        Float; overload;
    function ApproxLength(const APos: TVector2f): Float; overload; inline;

    function Reflect(const APos: TVector2f): TVector2f; inline;

    function Normalize: TVector2f;

    function Lerp   (const ATarget: TVector2f; const AAlpha: Float): TVector2f;
    function LerpCos(const ATarget: TVector2f; const AAlpha: Float): TVector2f; inline;

    function Rotate(const AAngle: Float):                        TVector2f; overload;
    function Rotate(const AAngle: Float; const APos: TVector2f): TVector2f; overload; inline;

    function Direction:                        Float; overload;
    function Direction(const APos: TVector2f): Float; overload; inline;

    function CircleMap: TVector2f;

    function Vector3(const AZ: Float = 0): TVector3f;

    class function FromString(const AStr: String): TVector2f;
    function ToString(const APrec: Integer = 4): String; inline;
  end;
  {$ENDREGION}

  {$REGION 'TVector3fHelper'}
  TVector3fHelper = record helper for TVector3f
  public const
    Zero: TVector3f = (X:0; Y:0; Z:0);
    One:  TVector3f = (X:1; Y:1; Z:1);

    Unity: TVector3f = (X:0; Y:0; Z:1);
  public
    function Round: TVector3i; inline;
    function Trunc: TVector3i; inline;

    function Ceil:  TVector3i; inline;
    function Floor: TVector3i; inline;

    function CeilFloor: TVector3i; inline;

    function Frac: TVector3f; inline;

    function Abs: TVector3f; inline;

    function DotProduct:                     Float; overload; inline;
    function DotProduct(const A: TVector3f): Float; overload; inline;

    function CrossProduct:                     TVector3f; overload; inline;
    function CrossProduct(const A: TVector3f): TVector3f; overload; inline;

    function Length:                        Float; overload; inline;
    function Length(const APos: TVector3f): Float; overload; inline;

    function Normalize: TVector3f;

    function ParallelNormal(const APos: TVector3f): TVector3f;

    function Reflect(const ASurfaceNormal: TVector3f): TVector3f;

    function Lerp   (const ATarget: TVector3f; const AAlpha: Float): TVector3f;
    function LerpCos(const ATarget: TVector3f; const AAlpha: Float): TVector3f;

    function Vector4(const AW: Float = 0): TVector4f;

    class function FromString(const AStr: String): TVector3f;
    function ToString(const APrec: Integer = 4): String; inline;
  end;
  {$ENDREGION}

  {$REGION 'TVector4fHelper'}
  TVector4fHelper = record helper for TVector4f
  public const
    Zero: TVector4f = (X:0; Y:0; Z:0; W:0);
    One:  TVector4f = (X:1; Y:1; Z:1; W:1);

    Unity: TVector4f = (X:0; Y:0; Z:0; W:1);
  public
    function Round: TVector4i; inline;
    function Trunc: TVector4i; inline;

    function Ceil:  TVector4i; inline;
    function Floor: TVector4i; inline;

    function CeilFloor: TVector4i; inline;

    function Frac: TVector4f; inline;

    function Abs: TVector4f; inline;

    function DotProduct:                     Float; overload; inline;
    function DotProduct(const A: TVector4f): Float; overload; inline;

    function CrossProduct:                     TVector4f; overload; inline;
    function CrossProduct(const A: TVector4f): TVector4f; overload; inline;

    function Length:                        Float; overload; inline;
    function Length(const APos: TVector4f): Float; overload; inline;

    function Normalize: TVector4f;

    function ParallelNormal(const APos: TVector4f): TVector4f;

    function Reflect(const ASurfaceNormal: TVector4f): TVector4f;

    function Lerp   (const ATarget: TVector4f; const AAlpha: Float): TVector4f;
    function LerpCos(const ATarget: TVector4f; const AAlpha: Float): TVector4f;

    function Width:  Float; inline;
    function Height: Float; inline;

    function Center: TVector2f;

    function Alpha(const AAlpha: Float): TVector4f; inline;

    class function FromString(const AStr: String): TVector4f;
    function ToString(const APrec: Integer = 4): String; inline;
  end;
  {$ENDREGION}

{$IFDEF COMPILER_IS_DUMB}
function CreateSinCos(const AAngle: Float): TVector2f;
{$ENDIF}

