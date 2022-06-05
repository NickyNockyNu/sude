class function TMatrix.Create(const m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44: Float): TMatrix;
begin
  Result.m11 := m11; Result.m12 := m12; Result.m13 := m13; Result.m14 := m14;
  Result.m21 := m21; Result.m22 := m22; Result.m23 := m23; Result.m24 := m24;
  Result.m31 := m31; Result.m32 := m32; Result.m33 := m33; Result.m34 := m34;
  Result.m41 := m41; Result.m42 := m42; Result.m43 := m43; Result.m44 := m44;
end;

class function TMatrix.Create(const m1, m2, m3, m4: TVector4f): TMatrix;
begin
  Result.m1 := m1;
  Result.m2 := m2;
  Result.m3 := m3;
  Result.m4 := m4;
end;

class function TMatrix.CreateTranslate;
begin
  with AOffset do
    Result := TMatrix.Create(
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      X, Y, Z, 1
    );
end;

class function TMatrix.CreateScale;
begin
  with AScale do
    Result := TMatrix.Create(
      X, 0, 0, 0,
      0, Y, 0, 0,
      0, 0, Z, 0,
      0, 0, 0, 1
    );
end;

class function TMatrix.CreateRotate;
var
  Sine: TVector2f;
  ICos: Float;
begin
  Sine := {$IFNDEF COMPILER_IS_DUMB}TVector2f.{$ENDIF}CreateSinCos(AAngle);

  Result.LoadIdentity;

  with AAxis do
  begin
    ICos := 1 - Sine.Y;

    Result.m11 := (ICos * X * X) + Sine.X;

    Result.m12 := (ICos * X * Y) + (Z * Sine.X);
    Result.m13 := (ICos * Z * X) - (Y * Sine.X);
    Result.m21 := (ICos * X * Y) - (Z * Sine.X);

    Result.m22 := (ICos * Y * Y) + Sine.Y;

    Result.m23 := (ICos * Y * Z) + (X * Sine.X);
    Result.m31 := (ICos * Z * X) + (Y * Sine.X);
    Result.m32 := (ICos * Y * Z) - (X * Sine.X);

    Result.m33 := (ICos * Z * Z) + Sine.Y;
  end;
end;

class function TMatrix.CreateRotateX;
begin
  Result.LoadIdentity;

  with {$IFNDEF COMPILER_IS_DUMB}TVector2f.{$ENDIF}CreateSinCos(AAngle) do
  begin
    Result.m22 :=  Y;
    Result.m23 :=  X;
    Result.m32 := -X;
    Result.m33 :=  Y;
  end;
end;

class function TMatrix.CreateRotateY;
begin
  Result.LoadIdentity;

  with {$IFNDEF COMPILER_IS_DUMB}TVector2f.{$ENDIF}CreateSinCos(AAngle) do
  begin
    Result.m11 :=  Y;
    Result.m13 :=  X;
    Result.m31 := -X;
    Result.m33 :=  Y;
  end;
end;

class function TMatrix.CreateRotateZ;
begin
  Result.LoadIdentity;

  with {$IFNDEF COMPILER_IS_DUMB}TVector2f.{$ENDIF}CreateSinCos(AAngle) do
  begin
    Result.m11 :=  Y;
    Result.m12 :=  X;
    Result.m21 := -X;
    Result.m22 :=  Y;
  end;
end;

class function TMatrix.CreatePerspective;
var
  XScale, YScale: Float;
begin
  YScale := 1 / Tangent((AFOV * PI / 180) / 2);
  XScale := YScale / AAspect;

  Result.LoadIdentity;

  Result.m11 := XScale;
  Result.m22 := YScale;
  Result.m33 := AZFar / (AZNear - AZFar);
  Result.m34 := -1;
  Result.m43 := AZNear * AZFar / (AZNear - AZFar);
  Result.m44 := 0;
end;

class function TMatrix.CreateOrthogonal;
begin
  Result.LoadZero;

  Result.m11 :=  2 / (ARight - ALeft);
  Result.m22 :=  2 / (ATop - ABottom);
  Result.m33 := -2 / (AZFar - AZNear);

  Result.m41 := -((ARight + ALeft) / (ARight - ALeft));
  Result.m42 := -((ATop + ABottom) / (ATop - ABottom));
  Result.m43 := -((AZFar + AZNear) / (AZFar - AZNear));

  Result.m44 := 1;
end;

class function TMatrix.CreateLookAt;
begin
  {}
end;

class operator TMatrix.Multiply(const A, B: TMatrix): TMatrix;
begin
  Result.m11 := A.m11 * B.m11 + A.m12 * B.m21 + A.m13 * B.m31 + A.m14 * B.m41;
  Result.m12 := A.m11 * B.m12 + A.m12 * B.m22 + A.m13 * B.m32 + A.m14 * B.m42;
  Result.m13 := A.m11 * B.m13 + A.m12 * B.m23 + A.m13 * B.m33 + A.m14 * B.m43;
  Result.m14 := A.m11 * B.m14 + A.m12 * B.m24 + A.m13 * B.m34 + A.m14 * B.m44;
  Result.m21 := A.m21 * B.m11 + A.m22 * B.m21 + A.m23 * B.m31 + A.m24 * B.m41;
  Result.m22 := A.m21 * B.m12 + A.m22 * B.m22 + A.m23 * B.m32 + A.m24 * B.m42;
  Result.m23 := A.m21 * B.m13 + A.m22 * B.m23 + A.m23 * B.m33 + A.m24 * B.m43;
  Result.m24 := A.m21 * B.m14 + A.m22 * B.m24 + A.m23 * B.m34 + A.m24 * B.m44;
  Result.m31 := A.m31 * B.m11 + A.m32 * B.m21 + A.m33 * B.m31 + A.m34 * B.m41;
  Result.m32 := A.m31 * B.m12 + A.m32 * B.m22 + A.m33 * B.m32 + A.m34 * B.m42;
  Result.m33 := A.m31 * B.m13 + A.m32 * B.m23 + A.m33 * B.m33 + A.m34 * B.m43;
  Result.m34 := A.m31 * B.m14 + A.m32 * B.m24 + A.m33 * B.m34 + A.m34 * B.m44;
  Result.m41 := A.m41 * B.m11 + A.m42 * B.m21 + A.m43 * B.m31 + A.m44 * B.m41;
  Result.m42 := A.m41 * B.m12 + A.m42 * B.m22 + A.m43 * B.m32 + A.m44 * B.m42;
  Result.m43 := A.m41 * B.m13 + A.m42 * B.m23 + A.m43 * B.m33 + A.m44 * B.m43;
  Result.m44 := A.m41 * B.m14 + A.m42 * B.m24 + A.m43 * B.m34 + A.m44 * B.m44;
end;{}

class operator TMatrix.Multiply(const A: TVector3f; const B: TMatrix): TVector3f;
begin
  Result.X := (A.X * B.m11) + (A.Y * B.m21) + (A.Z * B.m31) + B.m41;
  Result.Y := (A.X * B.m12) + (A.Y * B.m22) + (A.Z * B.m32) + B.m42;
  Result.Z := (A.X * B.m13) + (A.Y * B.m23) + (A.Z * B.m33) + B.m43;
end;

class operator TMatrix.Multiply(const A: TVector4f; const B: TMatrix): TVector4f;
begin
  Result.X := (A.X * B.m11) + (A.Y * B.m21) + (A.Z * B.m31) + (A.W * B.m41);
  Result.Y := (A.X * B.m12) + (A.Y * B.m22) + (A.Z * B.m32) + (A.W * B.m42);
  Result.Z := (A.X * B.m13) + (A.Y * B.m23) + (A.Z * B.m33) + (A.W * B.m43);
  Result.W := (A.X * B.m14) + (A.Y * B.m24) + (A.Z * B.m34) + (A.W * B.m44);
end;

class operator TMatrix.Multiply(const A: TMatrix; const B: Float): TMatrix;
begin
  // TODO: Unroll loop
  for var i := 0 to 15 do
    Result.Data[i] := A.Data[i] * B;
end;

procedure TMatrix.LoadIdentity;
begin
  Self := Identity;
end;

procedure TMatrix.LoadZero;
begin
  Self := Zero;
end;

procedure TMatrix.Translate;
begin
  Self := Self * CreateTranslate(AOffset);
end;

procedure TMatrix.Scale;
begin
  Self := Self * CreateScale(AScale);
end;

procedure TMatrix.Rotate;
begin
  Self := Self * CreateRotate(AAngle, AAxis);
end;

procedure TMatrix.RotateX;
begin
  Self := Self * CreateRotateX(AAngle);
end;

procedure TMatrix.RotateY;
begin
  Self := Self * CreateRotateY(AAngle);
end;

procedure TMatrix.RotateZ;
begin
  Self := Self * CreateRotateZ(AAngle);
end;

function TMatrix.Transpose;
begin
  Result := Create(
    m11, m21, m31, m41,
    m12, m22, m32, m42,
    m13, m23, m33, m43,
    m14, m24, m34, m44
  );
end;

function TMatrix.Adjoint;
begin
  Result := Create(
     (m22 * (m33 * m44 - m43 * m34) - m23 * (m32 * m44 - m42 * m34) + m24 * (m32 * m43 - m42 * m33)),
    -(m12 * (m33 * m44 - m43 * m34) - m13 * (m32 * m44 - m42 * m34) + m14 * (m32 * m43 - m42 * m33)),
     (m12 * (m23 * m44 - m43 * m24) - m13 * (m22 * m44 - m42 * m24) + m14 * (m22 * m43 - m42 * m23)),
    -(m12 * (m23 * m34 - m33 * m24) - m13 * (m22 * m34 - m32 * m24) + m14 * (m22 * m33 - m32 * m23)),
    -(m21 * (m33 * m44 - m43 * m34) - m23 * (m31 * m44 - m41 * m34) + m24 * (m31 * m43 - m41 * m33)),
     (m11 * (m33 * m44 - m43 * m34) - m13 * (m31 * m44 - m41 * m34) + m14 * (m31 * m43 - m41 * m33)),
    -(m11 * (m23 * m44 - m43 * m24) - m13 * (m21 * m44 - m41 * m24) + m14 * (m21 * m43 - m41 * m23)),
     (m11 * (m23 * m34 - m33 * m24) - m13 * (m21 * m34 - m31 * m24) + m14 * (m21 * m33 - m31 * m23)),
     (m21 * (m32 * m44 - m42 * m34) - m22 * (m31 * m44 - m41 * m34) + m24 * (m31 * m42 - m41 * m32)),
    -(m11 * (m32 * m44 - m42 * m34) - m12 * (m31 * m44 - m41 * m34) + m14 * (m31 * m42 - m41 * m32)),
     (m11 * (m22 * m44 - m42 * m24) - m12 * (m21 * m44 - m41 * m24) + m14 * (m21 * m42 - m41 * m22)),
    -(m11 * (m22 * m34 - m32 * m24) - m12 * (m21 * m34 - m31 * m24) + m14 * (m21 * m32 - m31 * m22)),
    -(m21 * (m32 * m43 - m42 * m33) - m22 * (m31 * m43 - m41 * m33) + m23 * (m31 * m42 - m41 * m32)),
     (m11 * (m32 * m43 - m42 * m33) - m12 * (m31 * m43 - m41 * m33) + m13 * (m31 * m42 - m41 * m32)),
    -(m11 * (m22 * m43 - m42 * m23) - m12 * (m21 * m43 - m41 * m23) + m13 * (m21 * m42 - m41 * m22)),
     (m11 * (m22 * m33 - m32 * m23) - m12 * (m21 * m33 - m31 * m23) + m13 * (m21 * m32 - m31 * m22))
  );
end;

function TMatrix.Inverse;
var
  Det: Float;
begin
  Det := Determinant;

  if System.Abs(Det) = 0 then
    Result := Identity
  else
    Result := Adjoint * (1 / Det);
end;

function TMatrix.Determinant;
begin
  Result :=
    m11 * (m22 * (m33 * m44 - m43 * m34) - m23 * (m32 * m44 - m42 * m34) + m24 * (m32 * m43 - m42 * m33)) -
    m12 * (m21 * (m33 * m44 - m43 * m34) - m23 * (m31 * m44 - m41 * m34) + m24 * (m31 * m43 - m41 * m33)) +
    m13 * (m21 * (m32 * m44 - m42 * m34) - m22 * (m31 * m44 - m41 * m34) + m24 * (m31 * m42 - m41 * m32)) -
    m14 * (m21 * (m32 * m43 - m42 * m33) - m22 * (m31 * m43 - m41 * m33) + m23 * (m31 * m42 - m41 * m32));
end;

function TMatrix.WorldPos;
begin
  Result.X := m41;
  Result.Y := m42;
  Result.Z := m43;
end;

function TMatrix.EyePos;
begin
  Result.X := -m11 * m41 - m12 * m42 - m13 * m43;
  Result.Y := -m21 * m41 - m22 * m42 - m23 * m43;
  Result.Z := -m31 * m41 - m32 * m42 - m33 * m43;
end;

function TMatrix.Lerp;
begin
  Result.m1 := m1.Lerp(ADest.m1, AAlpha);
  Result.m2 := m2.Lerp(ADest.m2, AAlpha);
  Result.m3 := m3.Lerp(ADest.m3, AAlpha);
  Result.m4 := m4.Lerp(ADest.m4, AAlpha);
end;

function TMatrix.LerpCos;
begin
  Result := Lerp(ADest, (1 - System.Cos(AAlpha * PI)) * 0.5);
end;

procedure TMatrix.Load;
begin
  glGetFloatv(AMatrix, @Self);
end;

procedure TMatrix.Save;
begin
  glLoadMatrixf(@Self);
end;

function TMatrix.ToString;
begin
  Result :=
    m1.ToString + #13#10 +
    m2.ToString + #13#10 +
    m3.ToString + #13#10 +
    m4.ToString;
end;
