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

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  Winapi.MMSystem,
  Winapi.OpenGL,
  Winapi.OpenGLext;

type
  // This exists to make record-case look less stupid
  RecordUnion = Byte;

  // Floating point type
  Float = Single;

// Type utility
{$I .\intf\Compare.inc}
{$I .\intf\Operators.inc}
{$I .\intf\Vectors.inc}

// Base types
{$I .\intf\Integers.inc}
{$I .\intf\Floats.inc}
{$I .\intf\Strings.inc}
{$I .\intf\Pointers.inc}
{$I .\intf\Booleans.inc}

// Core classes
{$I .\intf\Exceptions.inc}
{$I .\intf\Timing.inc}
{$I .\intf\Random.inc}

// Maths
{$I .\intf\Geometry.inc}
{$I .\intf\Matrix.inc}

// Multimedia
{$I .\intf\Colours.inc}
{$I .\intf\Audio.inc}

// OpenGL
{$I .\intf\Texture.inc}
{$I .\intf\Uniform.inc}
{$I .\intf\Shader.inc}
{$I .\intf\FrameBuffer.inc}
{$I .\intf\Sprites.inc}

// Interface
{$I .\intf\Application.inc}
{$I .\intf\Input.inc}
{$I .\intf\Window.inc}
{$I .\intf\Surface.inc}

implementation

// Type utility
{$I .\impl\Compare.inc}
{$I .\impl\Operators.inc}
{$I .\impl\Vectors.inc}

// Base types
{$I .\impl\Integers.inc}
{$I .\impl\Floats.inc}
{$I .\impl\Strings.inc}
{$I .\impl\Pointers.inc}
{$I .\impl\Booleans.inc}

// Core classes
{$I .\impl\Exceptions.inc}
{$I .\impl\Timing.inc}
{$I .\impl\Random.inc}

// Maths
{$I .\impl\Geometry.inc}
{$I .\impl\Matrix.inc}

// Multimedia
{$I .\impl\Colours.inc}
{$I .\impl\Audio.inc}

// OpenGL
{$I .\impl\Texture.inc}
{$I .\impl\Uniform.inc}
{$I .\impl\Shader.inc}
{$I .\impl\FrameBuffer.inc}
{$I .\impl\Sprites.inc}

// Interface
{$I .\impl\Application.inc}
{$I .\impl\Input.inc}
{$I .\impl\Window.inc}
{$I .\impl\Surface.inc}

end.
