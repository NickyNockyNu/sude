type
  TFloats = array of Float;

  TVector2f = TVector2<Float>;
  TVector3f = TVector3<Float>;
  TVector4f = TVector4<Float>;

  TFloatHelper = record helper for Float
  const
    Size = SizeOf(Float);
    Bits = Size shl 3;
  public
    class procedure Swap(var ALeft, ARight: Float); static;

    function Min(const AValue: Float): Float;
    function Max(const AValue: Float): Float;

    function Lerp   (const ATarget, AAlpha: Float): Float; inline;
    function LerpCos(const ATarget, AAlpha: Float): Float; inline;

    function Round: Integer; inline;
    function Trunc: Integer; inline;

    function Ceil:  Integer;
    function Floor: Integer;

    function CeilFloor: Integer;

    function Frac: Float; inline;

    function Abs: Float; inline;

    function Map(const AFromLow, AFromHigh, AToLow, AToHigh: Float): Float;

    class function FromString(const AStr: String; const ADefault: Float = 0): Float; static;
    function ToString(const APrec: Integer = 4): String;
  end;

