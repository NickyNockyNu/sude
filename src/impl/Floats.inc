class procedure TFloatHelper.Swap;
begin
  var Temp: Float := ALeft;

  ALeft  := ARight;
  ARight := Temp;
end;

function TFloatHelper.Min;
begin
  if AValue < Self then
    Result := AValue
  else
    Result := Self;
end;

function TFloatHelper.Max;
begin
  if AValue > Self then
    Result := AValue
  else
    Result := Self;
end;

function TFloatHelper.Lerp;
begin
  Result := Self + (ATarget - Self) * AAlpha;
end;

function TFloatHelper.LerpCos;
begin
  Result := Lerp(ATarget, (1 - System.Cos(AAlpha * PI)) * 0.5);
end;

function TFloatHelper.Round;
begin
  Result := System.Round(Self);
end;

function TFloatHelper.Trunc;
begin
  Result := System.Trunc(Self);
end;

function TFloatHelper.Ceil;
begin
  Result := Trunc;

  if Frac > 0 then
    Inc(Result);
end;

function TFloatHelper.Floor;
begin
  Result := Trunc;

  if Frac < 0 then
    Dec(Result);
end;

function TFloatHelper.CeilFloor;
var
  F: Float;
begin
  Result := Trunc;

  F := Frac;

  if F > 0 then
    Inc(Result)
  else if F < 0 then
    Dec(Result);
end;

function TFloatHelper.Frac;
begin
  Result := System.Frac(Self);
end;

function TFloatHelper.Map;
begin
  Result := (((AToHigh - AToLow) / (AFromHigh - AFromLow)) * Self) + AToLow;
end;

function TFloatHelper.Abs;
begin
  Result := System.Abs(Self);
end;

class function TFloatHelper.FromString;
var
  ErrCode: Integer;
begin
  Val(AStr, Result, ErrCode);

  if ErrCode <> 0 then
    Result := ADefault;
end;

function TFloatHelper.ToString;
var
  Str: ShortString;
begin
  System.Str(Self:APrec:APrec, Str);
  Result := String(Str);
end;

