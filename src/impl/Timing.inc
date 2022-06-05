class constructor TickService.Create;
var
  Frequency: Int64;
begin
  FUsePerformanceCounter := QueryPerformanceFrequency(Frequency);

  if FUsePerformanceCounter then
    FTickScale := 1 / Frequency
  else
    FTickScale := 0.001;
end;

class function TickService.Seconds;
var
  Tick: Int64;
begin
  if FUsePerformanceCounter then
    QueryPerformanceCounter(Tick)
  else
    Tick := GetTickCount64;

  Result := Tick * FTickScale;
end;

function TTimer.Reset;
begin
  Result := Elapsed;
  Start  := TickService.Seconds;
end;

function TTimer.Elapsed;
begin
  Result := TickService.Seconds - Start;
end;

function TTimer.Split;
begin
  Result := Elapsed;
  Reset;
end;

function TTimer.Expired;
begin
  Result := ExpiredDelta(ASeconds) <= 0;
end;

function TTimer.ExpiredDelta;
begin
  Result := ASeconds - Elapsed;

  if Result <= 0 then
    Reset;
end;

