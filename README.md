# sude
## Single Unit Delphi Engine

The aim of this project is to create a simple, single unit engine with no 3rd party dependencies.

The project goals are (subject to change):

* No 3rd party dependencies.
* No Delphi RTL dependencies. Only units from "Winapi".
* Simple to use.

The initial goal is to get something working that only requires the use to create something similar to

```delphi
program Test;

uses
  sude;

type
  TMyApp = class(TApplication)
    procedure OnRender; override;
  end;

procedure TMyApp.OnRender;
begin
  // Render code will go here
end;

begin
  TMyApp.Run;
end;
```

### Step by step

I wont be going into too much detail about how the code actually works, you can read the source code for that. But here is a step by step of how the engine is being built.

1. [Layout](1-Layout.md)
2. [The Singleton Window](2-TheSingletonWindow.md)
3. [The Application Class](3-TheApplicationClass.md)

