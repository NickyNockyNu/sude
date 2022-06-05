type
  {$REGION 'TVector2'}
  TVector2<T: record> = record
  type
    TData = array[0..1] of T;
  public
    class function  Create(const X, Y: T): TVector2<T>; static; inline;
    class property _Create[const X, Y: T]: TVector2<T> read Create; default;

    class operator Add     (const ALeft, ARight: TVector2<T>): TVector2<T>; inline;
    class operator Subtract(const ALeft, ARight: TVector2<T>): TVector2<T>; inline;
    class operator Multiply(const ALeft, ARight: TVector2<T>): TVector2<T>; inline;
    class operator Divide  (const ALeft, ARight: TVector2<T>): TVector2<T>; inline;

    class operator Add     (const ALeft: TVector2<T>; const ARight: T): TVector2<T>; inline;
    class operator Subtract(const ALeft: TVector2<T>; const ARight: T): TVector2<T>; inline;
    class operator Multiply(const ALeft: TVector2<T>; const ARight: T): TVector2<T>; inline;
    class operator Divide  (const ALeft: TVector2<T>; const ARight: T): TVector2<T>; inline;
  case RecordUnion of
    0: (Data: TData);
    1: (X, Y: T);
  end;
  {$ENDREGION}

  {$REGION 'TVector3'}
  TVector3<T: record> = record
  type
    TData = array[0..2] of T;
  public
    class function  Create(const X, Y, Z: T): TVector3<T>; static; inline;
    class property _Create[const X, Y, Z: T]: TVector3<T> read Create; default;

    class operator Add     (const ALeft, ARight: TVector3<T>): TVector3<T>; inline;
    class operator Subtract(const ALeft, ARight: TVector3<T>): TVector3<T>; inline;
    class operator Multiply(const ALeft, ARight: TVector3<T>): TVector3<T>; inline;
    class operator Divide  (const ALeft, ARight: TVector3<T>): TVector3<T>; inline;

    class operator Add     (const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
    class operator Subtract(const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
    class operator Multiply(const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
    class operator Divide  (const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
  case RecordUnion of
    0: (Data: TData);

    1: (X, Y, Z: T);
    2: (XY:      TVector2<T>);

    3: (R, G, B: T);
  end;
  {$ENDREGION}

  {$REGION 'TVector4'}
  TVector4<T: record> = record
  type
    TData = array[0..3] of T;
  public
    class function  Create(const X, Y, Z, W: T): TVector4<T>; static; inline;
    class property _Create[const X, Y, Z, W: T]: TVector4<T> read Create; default;

    class operator Add     (const ALeft, ARight: TVector4<T>): TVector4<T>; inline;
    class operator Subtract(const ALeft, ARight: TVector4<T>): TVector4<T>; inline;
    class operator Multiply(const ALeft, ARight: TVector4<T>): TVector4<T>; inline;
    class operator Divide  (const ALeft, ARight: TVector4<T>): TVector4<T>; inline;

    class operator Add     (const ALeft: TVector4<T>; const ARight: T): TVector4<T>; inline;
    class operator Subtract(const ALeft: TVector4<T>; const ARight: T): TVector4<T>; inline;
    class operator Multiply(const ALeft: TVector4<T>; const ARight: T): TVector4<T>; inline;
    class operator Divide  (const ALeft: TVector4<T>; const ARight: T): TVector4<T>; inline;
  case RecordUnion of
    0: (Data: TData);

    1: (X, Y, Z, W: T);
    2: (XY, ZW:     TVector2<T>);
    3: (XYZ:        TVector3<T>);

    4: (R, G, B, A: T);
    5: (RGB:        TVector3<T>);
  end;
  {$ENDREGION}
