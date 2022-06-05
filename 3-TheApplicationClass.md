# The Application Class

Not really much to it. We will create a base class that can be inherited by the users code to contain the app.
```Delphi
type
  TApplication = class abstract
  public
    // Used to start and stop your application
    class procedure Run(const AWidth, AHeight: Integer);
    procedure Stop;
  
    // Called when the app is started/stopped. Create/Free any resources here.
    procedure OnStart; virtual;
    procedure OnStop;  virtual;

    // Perform updates here. Scale by ADelta to preserve timing
    procedure OnUpdate(const ADelta: Double); virtual;

    // Draw a single frame. 
    procedure OnRender; virtual;
  end;
```

A minimal project should then look something like this:
```Delphi
program Test

uses
  sude;
  
 type
  TMyApp = class(TApplication);
  public
    procedure OnRender; override;
  end;

procedure TMyApp.OnRender;
begin
  // Render a frame here
end;

begin
  TMyApp.Run(640, 480);
end.
```


