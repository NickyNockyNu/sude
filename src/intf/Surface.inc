type
  TBlendMode = (Disable, Alpha, Lighten, Darken);

  Surface = class abstract
  private class var
    FWidth:  Integer;
    FHeight: Integer;

    FBuffer: TFrameBuffer;
  private
    class constructor Create;
    class destructor  Destroy;
  public
    class procedure Prepare; inline;
    class procedure Present; inline;

    class procedure Resize(const AWidth, AHeight: Integer);

    class procedure Clear(const AColour: TVector4f);

    class procedure SetBlendMode(const ABlendMode: TBlendMode);
    class procedure SetColour(const AColour: TVector4f);

    class procedure Line(const X1, Y1, X2, Y2: Integer; const AColour: TVector4f);

    class property Width:  Integer read FWidth;
    class property Height: Integer read FHeight;
  end;
