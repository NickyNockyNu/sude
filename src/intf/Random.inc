type
  {$REGION 'TRandom'}
  TRandom = record
  private
    FSeed:  Integer;

    class constructor Create;

    procedure SetSeed(const ASeed: Integer);
  public
    Value: Integer;

    const RandMod = $08088405;
    const RandTap = $23000001;

    class function SupportsRDSEED: Boolean; static;
    class function SupportsRDRAND: Boolean; static;

    class function RDSEED: Integer; static;
    class function RDRAND: Integer; static;

    class function RAND(const ARange: Integer): Integer; static;

    constructor Create(const ASeed: Integer);

    function Next(const ARange: Integer): Integer;  overload;
    function Next:                        Extended; overload;

    function LFSR:  Cardinal;
    function LFSR0: Boolean; inline;

    function MeanStdDev(const AMean, AStdDev: Extended): Extended;

    procedure Randomize;

    class operator Implicit(var ARandom: TRandom): Extended;

    property Seed: Integer read FSeed write SetSeed;
  end;
  {$ENDREGION}

  {$REGION 'TPerlin'}
  TPerlin = record
  private
    const GradientSize = 255;

    const Permutations: array[0..GradientSize] of Byte = (
      225, 155, 210, 108, 175, 199, 221, 144, 203, 116,  70, 213,  69, 158,  33, 252,
        5,  82, 173, 133, 222, 139, 174,  27,   9,  71,  90, 246,  75, 130,  91, 191,
      169, 138,   2, 151, 194, 235,  81,   7,  25, 113, 228, 159, 205, 253, 134, 142,
      248,  65, 224, 217,  22, 121, 229,  63,  89, 103,  96, 104, 156,  17, 201, 129,
       36,   8, 165, 110, 237, 117, 231,  56, 132, 211, 152,  20, 181, 111, 239, 218,
      170, 163,  51, 172, 157,  47,  80, 212, 176, 250,  87,  49,  99, 242, 136, 189,
      162, 115,  44,  43, 124,  94, 150,  16, 141, 247,  32,  10, 198, 223, 255,  72,
       53, 131,  84,  57, 220, 197,  58,  50, 208,  11, 241,  28,   3, 192,  62, 202,
       18, 215, 153,  24,  76,  41,  15, 179,  39,  46,  55,   6, 128, 167,  23, 188,
      106,  34, 187, 140, 164,  73, 112, 182, 244, 195, 227,  13,  35,  77, 196, 185,
       26, 200, 226, 119,  31, 123, 168, 125, 249,  68, 183, 230, 177, 135, 160, 180,
       12,   1, 243, 148, 102, 166,  38, 238, 251,  37, 240, 126,  64,  74, 161,  40,
      184, 149, 171, 178, 101,  66,  29,  59, 146,  61, 254, 107,  42,  86, 154,   4,
      236, 232, 120,  21, 233, 209,  45,  98, 193, 114,  78,  19, 206,  14, 118, 127,
       48,  79, 147,  85,  30, 207, 219,  54,  88, 234, 190, 122,  95,  67, 143, 109,
      137, 214, 145,  93,  92, 100, 245,   0, 216, 186,  60,  83, 105,  97, 204,  52
    );

    var Gradients: array[0..GradientSize * 3] of Extended;

    function Permutate(const AX: Integer): Integer; inline;
    function Index(const AX, AY, AZ: Integer): Integer; inline;
    function Lattice(const Aix, Aiy, Aiz: Integer; const Afx, Afy, Afz: Extended): Extended;
    function Lerp(const AAlpha, ASource, ADest: Extended): Extended; inline;
    function Smooth(const AX: Extended): Extended; inline;

    function  GetSeed: Integer;
    procedure SetSeed(const ASeed: Integer);

    function GetNoise(const AX, AY, AZ: Extended): Extended;
  public
    Random: TRandom;

    constructor Create(const ASeed: Integer);

    procedure CreateGradients;

    procedure Randomize;

    property Seed: Integer read GetSeed write SetSeed;

    property Noise[const AX, AY, AZ: Extended]: Extended read GetNoise; default;
  end;
  {$ENDREGION}

var
  RNG: TRandom;
