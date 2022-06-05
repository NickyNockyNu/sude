type
  TCompare<T> = class
  type
    TCompareProc = reference to function(const ALeft, ARight: T): Integer;
  class var
    CompareProc: TCompareProc;
  public
    class function Compare      (const ALeft, ARight: T):       Integer; inline;
    class function TypeCompare  (const ALeft, ARight: T):       Integer;
    class function BinaryCompare(const ALeft, ARight: Pointer): Integer;
  end;


