{$REGION 'TVector2'}
class function TVector2<T>.Create;
begin
  Result.X := X;
  Result.Y := Y;
end;

class operator TVector2<T>.Add(const ALeft, ARight: TVector2<T>): TVector2<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight.Y);
end;

class operator TVector2<T>.Subtract(const ALeft, ARight: TVector2<T>): TVector2<T>;
begin
  Result.X := TOperator<T>.Subtract(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Subtract(ALeft.Y, ARight.Y);
end;

class operator TVector2<T>.Multiply(const ALeft, ARight: TVector2<T>): TVector2<T>;
begin
  Result.X := TOperator<T>.Multiply(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Multiply(ALeft.Y, ARight.Y);
end;

class operator TVector2<T>.Divide(const ALeft, ARight: TVector2<T>): TVector2<T>;
begin
  Result.X := TOperator<T>.Divide(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Divide(ALeft.Y, ARight.Y);
end;

class operator TVector2<T>.Add(const ALeft: TVector2<T>; const ARight: T): TVector2<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight);
end;

class operator TVector2<T>.Subtract(const ALeft: TVector2<T>; const ARight: T): TVector2<T>;
begin
  Result.X := TOperator<T>.Subtract(ALeft.X, ARight);
  Result.Y := TOperator<T>.Subtract(ALeft.Y, ARight);
end;

class operator TVector2<T>.Multiply(const ALeft: TVector2<T>; const ARight: T): TVector2<T>;
begin
  Result.X := TOperator<T>.Multiply(ALeft.X, ARight);
  Result.Y := TOperator<T>.Multiply(ALeft.Y, ARight);
end;

class operator TVector2<T>.Divide(const ALeft: TVector2<T>; const ARight: T): TVector2<T>;
begin
  Result.X := TOperator<T>.Divide(ALeft.X, ARight);
  Result.Y := TOperator<T>.Divide(ALeft.Y, ARight);
end;
{$ENDREGION}

{$REGION 'TVector3'}
class function TVector3<T>.Create;
begin
  Result.X := X;
  Result.Y := Y;
  Result.Z := Z;
end;

class operator TVector3<T>.Add(const ALeft, ARight: TVector3<T>): TVector3<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Add(ALeft.Z, ARight.Z);
end;

class operator TVector3<T>.Subtract(const ALeft, ARight: TVector3<T>): TVector3<T>;
begin
  Result.X := TOperator<T>.Subtract(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Subtract(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Subtract(ALeft.Z, ARight.Z);
end;

class operator TVector3<T>.Multiply(const ALeft, ARight: TVector3<T>): TVector3<T>;
begin
  Result.X := TOperator<T>.Multiply(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Multiply(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Subtract(ALeft.Z, ARight.Z);
end;

class operator TVector3<T>.Divide(const ALeft, ARight: TVector3<T>): TVector3<T>;
begin
  Result.X := TOperator<T>.Divide(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Divide(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Divide(ALeft.Z, ARight.Z);
end;

class operator TVector3<T>.Add(const ALeft: TVector3<T>; const ARight: T): TVector3<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Add(ALeft.Z, ARight);
end;

class operator TVector3<T>.Subtract(const ALeft: TVector3<T>; const ARight: T): TVector3<T>;
begin
  Result.X := TOperator<T>.Subtract(ALeft.X, ARight);
  Result.Y := TOperator<T>.Subtract(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Subtract(ALeft.Z, ARight);
end;

class operator TVector3<T>.Multiply(const ALeft: TVector3<T>; const ARight: T): TVector3<T>;
begin
  Result.X := TOperator<T>.Multiply(ALeft.X, ARight);
  Result.Y := TOperator<T>.Multiply(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Multiply(ALeft.Z, ARight);
end;

class operator TVector3<T>.Divide(const ALeft: TVector3<T>; const ARight: T): TVector3<T>;
begin
  Result.X := TOperator<T>.Divide(ALeft.X, ARight);
  Result.Y := TOperator<T>.Divide(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Divide(ALeft.Z, ARight);
end;
{$ENDREGION}

{$REGION 'TVector4'}
class function TVector4<T>.Create;
begin
  Result.X := X;
  Result.Y := Y;
  Result.Z := Z;
  Result.W := W;
end;

class operator TVector4<T>.Add(const ALeft, ARight: TVector4<T>): TVector4<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Add(ALeft.Z, ARight.Z);
  Result.W := TOperator<T>.Add(ALeft.W, ARight.W);
end;

class operator TVector4<T>.Subtract(const ALeft, ARight: TVector4<T>): TVector4<T>;
begin
  Result.X := TOperator<T>.Subtract(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Subtract(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Subtract(ALeft.Z, ARight.Z);
  Result.W := TOperator<T>.Subtract(ALeft.W, ARight.W);
end;

class operator TVector4<T>.Multiply(const ALeft, ARight: TVector4<T>): TVector4<T>;
begin
  Result.X := TOperator<T>.Multiply(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Multiply(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Subtract(ALeft.Z, ARight.Z);
  Result.W := TOperator<T>.Subtract(ALeft.W, ARight.W);
end;

class operator TVector4<T>.Divide(const ALeft, ARight: TVector4<T>): TVector4<T>;
begin
  Result.X := TOperator<T>.Divide(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Divide(ALeft.Y, ARight.Y);
  Result.Z := TOperator<T>.Divide(ALeft.Z, ARight.Z);
  Result.W := TOperator<T>.Divide(ALeft.W, ARight.W);
end;

class operator TVector4<T>.Add(const ALeft: TVector4<T>; const ARight: T): TVector4<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Add(ALeft.Z, ARight);
  Result.W := TOperator<T>.Add(ALeft.W, ARight);
end;

class operator TVector4<T>.Subtract(const ALeft: TVector4<T>; const ARight: T): TVector4<T>;
begin
  Result.X := TOperator<T>.Subtract(ALeft.X, ARight);
  Result.Y := TOperator<T>.Subtract(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Subtract(ALeft.Z, ARight);
  Result.W := TOperator<T>.Subtract(ALeft.W, ARight);
end;

class operator TVector4<T>.Multiply(const ALeft: TVector4<T>; const ARight: T): TVector4<T>;
begin
  Result.X := TOperator<T>.Multiply(ALeft.X, ARight);
  Result.Y := TOperator<T>.Multiply(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Multiply(ALeft.Z, ARight);
  Result.W := TOperator<T>.Multiply(ALeft.W, ARight);
end;

class operator TVector4<T>.Divide(const ALeft: TVector4<T>; const ARight: T): TVector4<T>;
begin
  Result.X := TOperator<T>.Divide(ALeft.X, ARight);
  Result.Y := TOperator<T>.Divide(ALeft.Y, ARight);
  Result.Z := TOperator<T>.Divide(ALeft.Z, ARight);
  Result.W := TOperator<T>.Divide(ALeft.W, ARight);
end;
{$ENDREGION}

