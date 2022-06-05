# 1 - Layout

As a single unit engine, managing and navigating this code could get tricky. Normally, with large units I'd section off code using `{$REGION}`. A better option for somthing this ambitious is to break code into `.inc` files.
I'll further break in the `.inc` files into separate `interface` and `implementation` files.

As we wont be using the Delphi RTL, lets start with exception handling as we will need to be able to raise and catch exceptions from the early stages of this project.

Here is the basic layout of how the project will be built:
```Delphi
unit sude;

{$SCOPEDENUMS ON}
{$DEFINE DEBUG}

interface

uses
  // These are the ONLY units this engine sould use.
  Winapi.Windows,
  Winapi.Messages,
  Winapi.MMSystem,
  Winapi.OpenGL,
  Winapi.OpenGLext;

{$I .\intf\Exceptions.inc}

implementation

{$I .\impl\Exceptions.inc}

end.
```
