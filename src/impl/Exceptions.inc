procedure ErrorHandler(ErrorCode: Byte; ErrorAddr: Pointer);
var
  SErrorCode: ShortString;
begin
  Str(ErrorCode, SErrorCode);

  raise ERuntime.Create('Runtime error #' + String(SErrorCode)) at ErrorAddr;
end;

procedure SafecallErrorHandler(ErrorCode: HResult; ErrorAddr: Pointer);
var
  SErrorCode: ShortString;
begin
  Str(ErrorCode, SErrorCode);

  raise ESafecall.Create('Safecall error #' + String(SErrorCode)) at ErrorAddr;
end;

procedure AbstractErrorHandler;
begin
  raise EAbstract.Create('Abstract error');
end;

function GetExceptionClass(P: PExceptionRecord): TExceptionClass;
begin
  Result := TException;
end;

function GetExceptionObject(P: PExceptionRecord): IntPtr;
begin
  Result := IntPtr(TException.Create('Access violation'));
end;

procedure ExceptionHandler(ExceptObject: TObject; ExceptAddr: Pointer);
begin
  if ExceptObject is TException then
    TException.Handler(ExceptObject, ExceptAddr)
  else
    Halt;
end;

class constructor TException.Create;
begin
  ErrorProc         := ErrorHandler;
  SafecallErrorProc := SafecallErrorHandler;
  AbstractErrorProc := AbstractErrorHandler;

  ExceptionClass := TException;

  ExceptClsProc := @GetExceptionClass;
  ExceptObjProc := @GetExceptionObject;

  ExceptProc := @ExceptionHandler;
end;

constructor TException.Create;
begin
  inherited Create;

  FDetails  := ADetails;
  FExitCode := AExitCode;
end;

class procedure TException.Handler;
var
  ErrorMessage: String;
begin
  ErrorMessage := ExceptObject.ClassName + ' at ' + ExceptAddr.ToString;

  if Length(TException(ExceptObject).FDetails) > 0 then
    ErrorMessage := ErrorMessage + #13#10 + TException(ExceptObject).FDetails;

  MessageBox(0, PWideChar(ErrorMessage), PWideChar(ParamStr(0)), MB_OK or MB_ICONERROR or MB_TASKMODAL);

  Halt(TException(ExceptObject).FExitCode);
end;

