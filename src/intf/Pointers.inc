type
  TPointerHelper = record helper for Pointer
    class function Alloc(const ASize: NativeInt): Pointer; static; inline;

    procedure Resize(const ASize: NativeInt);
    procedure Free;

    procedure Inc(const ACount: Integer = 1); inline;
    procedure Dec(const ACount: Integer = 1); inline;

    procedure Read (var   AData; const ASize: Integer; const AIncrement: Boolean = True); overload;
    procedure Write(const AData; const ASize: Integer; const AIncrement: Boolean = True); overload;

    function  Read<T> (                 const AIncrement: Boolean = True): T; overload; inline;
    procedure Write<T>(const AValue: T; const AIncrement: Boolean = True);    overload; inline;

    function Address(const AIndex: Integer): Pointer; inline;

    function  ArrayRead<T> (const AIndex: Integer): T;               inline;
    procedure ArrayWrite<T>(const AIndex: Integer; const AValue: T); inline;

    function IsNil: Boolean; inline;

    function ToString: String;
  end;

