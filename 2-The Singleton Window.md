# 2 - The Singleton Window

For simplicity, our engine will only use one window. Now we could use global scope procedures to manage and control this but there is another approach that may upset a lot of Pascal coders... Using an abstract class as a singleton!

Although frowned upon by most, this method will allow us to contain our single window into a sort of pseudo-object/namespace.

Concider the following:
```Delphi
type
  Window = class abstract
  private class var
    FSomeProperty: Integer;
  public
    class procedure SomeMethod;

    class property SomeProperty: Integer read FSomeProperty write FSomeProperty;
  end;
```

We never need to create an instance of the `Window` class as all of it's properties and methods belong to the class. Therefore we have a singleton `Window` class that can be accessed as if it were a single global object.
```Delphi
Window.SomeProperty := 12345;
Window.SomeMethod();
```
