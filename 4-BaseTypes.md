# Base Types

As we won't be using the Delphi RTL, it'll be nice to include some utility for the commonly used basic types.
These types will be:
* Integers
* Floats
* Strings
* Booleans
* Pointers

The `Float` type will be defined in the main source as we may want to change it for increased precision or performance at a later date.
For now we will use the standard IEE 32-bit `Single` as this is commonly used in OpenGL.
```Delpi
type
  Float = Single;
```

All utility will be provided via record helpers and at very least these will provide a way to convert the type from/to a string as this is very useful for debugging.
E.g.
```Delphi
type
  TIntegerHelper = record helper for Integer;
    class function FromString(const AStr: String; const ADefault: Integer = 0): Integer; static;
    function ToString: String;
  end;
```

This will the give us the ability to easily dump values
E.g.
```Delphi
var
  i: Integer;
begin
  i := 1234;
  Log('i is ' + i.ToString);
  
  i := Integer.FromString('5678');
end;
```

## Vectors

We will probably end using vectors a lot. Specifically vectors of size 2, 3 and 4. Let's make a record to make it easy to define them.
```Delphi
type
  TVector2<T> = record
  type
    TData = array[0..1] of T;
  case Byte of
    1: (Data: TData);
    2: (X, Y: T);
  end;
```

Now we can simply define our 2D vectors for different types as:
```Delphi
type
  TVector2i = TVector2<Integer>;
  TVector2f = TVector2<Float>;
```

#### Vector constuctors

Let's add a little trick using default class properties to make constructing these in a short, easy way.
```Delphi
  public
    class function  Create(const X, Y: T): TVector2<T>; static;
    class property _Create[const X, Y: T]: TVector2<T> read Create; default;

...

class function TVector2<T>.Create;
begin
  Result.X := X;
  Result.Y := Y;
end;
```

At first this may look a little odd. But using a class property like this marked as `default` allows us to do this:
```Delphi
var
  v: TVector2i;
begin
  v := TVector2i[10, 20];
  
  Writeln(v.X); // Outputs 10
  Writeln(v.Y); // Outputs 20
end;
```

## Operators

It would be nice if our vector class supported operator overloading but as the type of T is unknown and could be a type that doesn't support the operator, the compiler will be unable to figure out how to do this.
We can fix that by making a "magic" generics class that will contain all the basic operations of each base type.

```Delphi
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
```

And now for the fun part (I will only include the a few `Add` operations here for readability. See the source code for full implementation)...
```Delphi
class constructor TOperator<T>.Create;
begin
  TOperator<Byte>.AddProc     := function(const ALeft, ARight: Byte):     Byte     begin Result := ALeft + ARight end;
  TOperator<Word>.AddProc     := function(const ALeft, ARight: Word):     Word     begin Result := ALeft + ARight end;
  TOperator<Cardinal>.AddProc := function(const ALeft, ARight: Cardinal): Cardinal begin Result := ALeft + ARight end;
  TOperator<UInt64>.AddProc   := function(const ALeft, ARight: UInt64):   Uint64   begin Result := ALeft + ARight end;
  // ...etc, extend for all base types ...
  
  // Do the same for subtracting, multiplying and dividing...
end;

class function TOperator<T>.Add(const ALeft, ARight: T): T;
begin
  if Assigned(AddProc) then
    Result := AddProc(ALeft, ARight)
  else
    Result := ALeft;
end;
```

At first this seems like overkill. What's the point? Well, this will allow us to write code that will allow us to easily perform operations as long as we know the type at run time.
So now our vector type can have operators!
```Delphi
    class operator Add     (const ALeft, ARight: TVector3<T>): TVector3<T>; inline;
    class operator Subtract(const ALeft, ARight: TVector3<T>): TVector3<T>; inline;
    class operator Multiply(const ALeft, ARight: TVector3<T>): TVector3<T>; inline;
    class operator Divide  (const ALeft, ARight: TVector3<T>): TVector3<T>; inline;

    class operator Add     (const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
    class operator Subtract(const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
    class operator Multiply(const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;
    class operator Divide  (const ALeft: TVector3<T>; const ARight: T): TVector3<T>; inline;

...

class operator TVector2<T>.Add(const ALeft, ARight: TVector2<T>): TVector2<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight.X);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight.Y);
end;

...

class operator TVector2<T>.Add(const ALeft: TVector2<T>; const ARight: T): TVector2<T>;
begin
  Result.X := TOperator<T>.Add(ALeft.X, ARight);
  Result.Y := TOperator<T>.Add(ALeft.Y, ARight);
end;
```

Was all the fuss worth it? I think so, we can now do things like this:
```Delphi
var
  v: TVector2i;
begin
  v := TVector2f[10, 20];
  
  v := v div 2;
  
  v := v + TVector2i[2, 1];
  
  Writeln(v.X); // 7  (10/2+2)
  Writeln(v.Y); // 11 (20/2+1)
end;
```

## Comparing

We can create a similar "magic" class for comparing two values of the same type.
```Delphi
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
  
...

class function TCompare<T>.Compare;
begin
  if Assigned(CompareProc) then
    Result := CompareProc(ALeft, ARight)
  else
    Result := TypeCompare(ALeft, ARight);
end;

class function TCompare<T>.TypeCompare;
var
  PT: Pointer;
begin
  PT := TypeInfo(T);

       if PT = TypeInfo(Byte)     then Result := PByte(@ALeft)^     - PByte(@ARight)^
  else if PT = TypeInfo(Word)     then Result := PWord(@ALeft)^     - PWord(@ARight)^
  else if PT = TypeInfo(Cardinal) then Result := PCardinal(@ALeft)^ - PCardinal(@ARight)^
  else if PT = TypeInfo(UInt64)   then Result := PUInt64(@ALeft)^   - PUInt64(@ARight)^
  // etc.. add for more types
  
  else Result := BinaryCompare(@ALeft, @ARight);
end;

class function TCompare<T>.BinaryCompare;
begin
  for var i := 0 to SizeOf(T) - 1 do
  begin
    Result := PByte(ALeft)[i] - PByte(ARight)[i];

    if Result <> 0 then
      Exit;
  end;

  Result := 0;
end;
```

And what is the point of this? Well, now we can not only easily compare known types inside a generics class, we can also add custom compare functions for our custom types.
E.g.
```Delphi
type
  TPlayer = record
    Level: Integer;
    Dead:  Boolean;
  end;
  
TCompare<TPlayer>.CompareProc := function(const ALeft, ARight: TPlayer): Integer;
begin
  if ALeft.Dead and ARight.Dead then
    Result := 0
  else if ALeft.Dead then
    Result := 1
  else if ARight.Dead then
    Result := -1
  else
    Result := ALeft.Level - ARight.Level;
end;
```
