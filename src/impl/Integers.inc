class procedure TIntegerHelper.Swap;
begin
  var Temp: Integer := ALeft;

  ALeft  := ARight;
  ARight := Temp;
end;

function TIntegerHelper.Min;
begin
  if AValue < Self then
    Result := AValue
  else
    Result := Self;
end;

function TIntegerHelper.Max;
begin
  if AValue > Self then
    Result := AValue
  else
    Result := Self;
end;

function TIntegerHelper.Abs;
begin
  Result := System.Abs(Self);
end;

function TIntegerHelper.RInc;
begin
  Result := Self;

  Inc(Self);

  if Self > AMax then
    Self := AMax;
end;

function TIntegerHelper.IncR;
begin
  Inc(Self);

  if Self > AMax then
    Self := AMax;

  Result := Self;
end;

function TIntegerHelper.RDec;
begin
  Result := Self;

  Dec(Self);

  if Self < AMin then
    Self := AMin;
end;

function TIntegerHelper.DecR;
begin
  Dec(Self);

  if Self < AMin then
    Self := AMin;

  Result := Self;
end;

function TIntegerHelper.Clamp;
begin
  if Self > AMax then
    Result := AMax
  else if Self < AMin then
    Result := AMin
  else
    Result := Self;
end;

function TIntegerHelper.ClampDelta;
begin
  Result := 0;

  if Self < AMin then
  begin
    Result := AMin - Self;
    AWidth := AWidth - Result;
    Self   := AMin;
  end;

  if (Self + AWidth) > AMax then
    AWidth := AMax - Self;

  if AWidth < 0 then
    AWidth := 0;
end;

class function TIntegerHelper.FromString;
var
  ErrCode: Integer;
begin
  Val(AStr, Result, ErrCode);

  if ErrCode <> 0 then
    Result := ADefault;
end;

function TIntegerHelper.ToString;
var
  Str: ShortString;
begin
  System.Str(Self, Str);
  Result := String(Str);
end;

