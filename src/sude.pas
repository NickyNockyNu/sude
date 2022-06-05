{
  sude.pas

    Single Unit Delphi Engine
    Copyright © 2022 Nicholas Smith

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
}

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

type
  // Floating point type
  Float = Single;

// Core classes
{$I .\intf\Exceptions.inc}
{$I .\intf\Timing.inc}

// Interface
{$I .\intf\Window.inc}

implementation

// Core classes
{$I .\impl\Exceptions.inc}
{$I .\impl\Timing.inc}

// Interface
{$I .\impl\Window.inc}

end.
