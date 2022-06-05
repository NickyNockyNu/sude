program Test;

{$APPTYPE CONSOLE}
{$R *.res}

uses
  sude in '..\src\sude.pas';

type
  TTest = class(TApplication)
    procedure OnStart; override;
    procedure OnStop;  override;

    procedure OnRender; override;
  end;

procedure TTest.OnStart;
begin

end;

procedure TTest.OnStop;
begin

end;

procedure TTest.OnRender;
begin
  Surface.Clear(Colour.Cobalt);
  Surface.SetBlendMode(TBlendMode.Alpha);

  Surface.Line(10, 10, 246, 182, Colour.Red);
end;

begin
  TTest.Run(256, 192, 4);
end.

