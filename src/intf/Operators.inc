type
  TOperator<T> = class abstract
  type
    TOperatorProc = reference to function(const ALeft, ARight: T): T;
  class var
    AddProc:      TOperatorProc;
    SubtractProc: TOperatorProc;
    MultiplyProc: TOperatorProc;
    DivideProc:   TOperatorProc;
  private
    class constructor Create;
  public
    class function Add     (const ALeft, ARight: T): T;
    class function Subtract(const ALeft, ARight: T): T;
    class function Multiply(const ALeft, ARight: T): T;
    class function Divide  (const ALeft, ARight: T): T;
  end;

