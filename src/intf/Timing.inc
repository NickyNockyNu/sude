const
  msPerSec  = Int64(1000);
  msPerMin  = Int64(msPerSec  * 60);
  msPerHour = Int64(msPerMin  * 60);
  msPerDay  = Int64(msPerHour * 24);
  msPerWeek = Int64(msPerDay  * 7);
  msPerYear = Int64(msPerWeek * 52);

type
  TickService = class abstract
  private class var
    FUsePerformanceCounter: Boolean;
    FTickScale: Double;
  public
    class constructor Create;

    class function Seconds: Double;

    class property UsingPerformanceCounter: Boolean read FUsePerformanceCounter;

    class property TickScale: Double read FTickScale write FTickScale;
  end;

  TTimer = record
    Start: Double;

    function Reset: Double;

    function Elapsed: Double; inline;

    function Split: Double; inline;

    function Expired     (const ASeconds: Double): Boolean;  inline;
    function ExpiredDelta(const ASeconds: Double): Double;
  end;

