type
  TBooleanHelper = record helper for Boolean
    // NOTE: Despite being "inline" always assume A and B are evaluated.
    function &if<T>(const ATrue, AFalse: T): T; overload; inline;

    function &if(const ATrue, AFalse: Integer):  Integer;  overload; inline;
    function &if(const ATrue, AFalse: Extended): Extended; overload; inline;
    function &if(const ATrue, AFalse: Char):     Char;     overload; inline;
    function &if(const ATrue, AFalse: Pointer):  Pointer;  overload; inline;
    function &if(const ATrue, AFalse: String):   String;   overload; inline;

    class function FromString(const AStr: String; const ADefault: Boolean = False): Boolean; static;
    function ToString(const ATrue: String = 'True'; const AFalse: String = 'False'): String; inline;
  end;
