type
  TVector2i = TVector2<Integer>;
  TVector3i = TVector3<Integer>;
  TVector4i = TVector4<Integer>;

  TIntegerHelper = record Helper for Integer
  const
    Size = SizeOf(Integer);
    Bits = Size shl 3;

    MaxVal  = Integer(Cardinal(-1) shr 1);
    MinVal  = not MaxVal;
  public
    class procedure Swap(var ALeft, ARight: Integer); static;

    function Min(const AValue: Integer): Integer;
    function Max(const AValue: Integer): Integer;

    function Abs: Integer; inline;

    function RInc(ACount: Integer = 1; AMax: Integer = MaxVal): Integer; // i++
    function IncR(ACount: Integer = 1; AMax: Integer = MaxVal): Integer; // ++i
    function RDec(ACount: Integer = 1; AMin: Integer = MinVal): Integer; // i--
    function DecR(ACount: Integer = 1; AMin: Integer = MinVal): Integer; // --i

    function Clamp     (                     AMin: Integer = MinVal; AMax: Integer = MaxVal): Integer;
    function ClampDelta(var AWidth: Integer; AMin: Integer = MinVal; AMax: Integer = MaxVal): Integer;

    class function FromString(const AStr: String; const ADefault: Integer = 0): Integer; static;
    function ToString: String;
  end;

