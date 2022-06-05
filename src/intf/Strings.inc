type
  TStringHelper = record helper for String
  private
    function  GetChar(const AIndex: Integer): Char;
    procedure SetChar(const AIndex: Integer; const AChar: Char);

    function GetPChar(const AIndex: Integer): PChar; inline;

    function  GetLength: Integer;                inline;
    procedure SetLength(const ALength: Integer); inline;

    function  GetSize: Integer;              inline;
    procedure SetSize(const ASize: Integer); inline;
  public
    const CharsAlphaUpper   = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    const CharsAlphaLower   = 'abcdefghijklmnopqrstuvwxyz';
    const CharsAlpha        = CharsAlphaUpper + CharsAlphaLower;
    const CharsNumeric      = '0123456789';
    const CharsAlphaNumeric = CharsAlpha + CharsNumeric;

    const CharsHex = '0123456789ABCDEF';

    const CharsQuote = '`"''';

    const CharCR    = #13;
    const CharLF    = #10;
    const CharsCRLF = CharCR + CharLF;

    const CharSpace = #32;
    const CharTab   = #9;

    const CharsWhiteSpace = CharSpace + CharTab + CharsCRLF;

    const CharsBase = CharsNumeric + CharsAlphaUpper; // + CharsAlphaLower;

    const CharsIdentStart = '_' + CharsAlpha;
    const CharsIdent      = CharsIdentStart + CharsNumeric;
    const CharsIdentObj   = CharsIdent + '.';

    function Ansi: AnsiString; inline;

    property Chars[const AIndex: Integer]: Char  read GetChar write SetChar;
    property Ptr  [const AIndex: Integer]: PChar read GetPChar;

    function FirstChar: Char; inline;
    function LastChar:  Char; inline;

    property Length: Integer read GetLength write SetLength;
    property Size:   Integer read GetSize   write SetSize;

    function IsEmpty:    Boolean; inline;
    function IsNotEmpty: Boolean; inline;

    procedure Clear;

    function Pos(const AStr: String; const AStart: Integer = 1; const AIgnoreCase: Boolean = False; const AOutOfQuotes: Boolean = False): Integer;
    function Copy(const AIndex: Integer; const ACount: Integer = -1): String; inline;

    function Uppercase(const AEnable: Boolean = True): String; inline;
    function Lowercase(const AEnable: Boolean = True): String; inline;

    function Compare(const AStr: String; const AIgnoreCase: Boolean = False): Integer; inline;
    function Same   (const AStr: String; const AIgnoreCase: Boolean = False): Boolean; inline;
  end;

