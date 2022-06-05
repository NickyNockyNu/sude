# sude
### Single Unit Delphi Engine

The aim of this project is to create a simple, single unit engine with no 3rd party dependencies.

The project goals are (subject to change):

* No 3rd party dependencies.
* No Delphi RTL dependencies. Only units from "Winapi".
* Simple to use.

The initial goal is to get something working that only requires the use to create something similar to

'''Delphi
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
