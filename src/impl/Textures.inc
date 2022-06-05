type
  TBitmapData = packed record
    Width:        Cardinal;
    Height:       Cardinal;
    Stride:       Integer;
    PixelFormat:  Integer;
    Scan0:        Pointer;
    Reserved:     Pointer;
    Size:         Cardinal;
  end;

  TGDIPlusStartupInput = packed record
    Version: Cardinal;

    DebugCallback:            Pointer;
    SuppressBackgroundThread: LongBool;
    SuppressExternalCodecs:   LongBool;
  end;

  TGDIPlusObject = Pointer;

const
  GDIPlus = 'GDIPlus.dll';

function GdiplusStartup(out Token: LongWord; const Input: TGDIPlusStartupInput; Output: Pointer): Integer; stdcall; external GDIPlus;
function GdipLoadImageFromFile(const FileName: PWideChar; var Image: TGDIPlusObject): Integer; stdcall; external GDIPlus;
function GdipDisposeImage(Image: TGDIPlusObject): Integer; stdcall; external GDIPlus;
function GdipGetImageWidth (Image: TGDIPlusObject; var Width:  Integer): Integer; stdcall; external GDIPlus;
function GdipGetImageHeight(Image: TGDIPlusObject; var Height: Integer): Integer; stdcall; external GDIPlus;
function GdipBitmapLockBits  (Bitmap: TGDIPlusObject; const Box: TRect; Flags: Cardinal; Format: Integer; var BitmapData: TBitmapData): Integer; stdcall; external GDIPlus;
function GdipBitmapUnlockBits(Bitmap: TGDIPlusObject; var BitmapData: TBitmapData): Integer; stdcall; external GDIPlus;

var
  GDIPlusToken: LongWord = 0;

function InitializeGDIPlus: Boolean;
const
  StartupInput: TGDIPlusStartupInput = (Version:                  1;
                                        DebugCallback:            nil;
                                        SuppressBackgroundThread: False;
                                        SuppressExternalCodecs:   False);
begin
  if GDIPlusToken <> 0 then
    Exit(True);

  Result := GDIPlusStartup(GDIPlusToken, StartupInput, nil) = 0;
end;

constructor TTexture.Create(const AWidth, AHeight: Integer; const AData: Pointer = nil);
begin
  inherited Create;

  FHandle := 0;

  Resize(AWidth, AHeight, AData);
end;

constructor TTexture.Create(const AFileName: String);
var
  Image:      TGDIPlusObject;
  BitmapData: TBitmapData;
begin
  inherited Create;

  if not InitializeGDIPlus then
    Exit;

  Image := nil;

  if GdipLoadImageFromFile(@AFileName[1], Image) <> 0 then
    raise ETexture.Create('Failed to load image "' + AFileName + '"');

  try
    GdipGetImageWidth (Image, FWidth);
    GdipGetImageHeight(Image, FHeight);

    GdipBitmapLockBits(Image, TRect.Create(0, 0, FWidth, FHeight), 1, 2498570, BitmapData);

    glGenTextures(1, @FHandle);
    Activate;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FWidth, FHeight, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, BitmapData.Scan0);
  finally
    GdipDisposeImage(Image);
  end;

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
end;

destructor TTexture.Destroy;
begin
  Resize(0, 0);

  inherited;
end;

procedure TTexture.Resize;
begin
  if FHandle <> 0 then
  begin
    glDeleteTextures(1, @FHandle);
    FHandle := 0;
  end;

  if (AWidth = 0) or (AHeight = 0) then
  begin
    FWidth  := 0;
    FHeight := 0;

    Exit;
  end;

  FWidth  := AWidth;
  FHeight := AHeight;

  glGenTextures(1, @FHandle);

  Activate;

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, FWidth, FHeight, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, AData);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  Deactivate;
end;

procedure TTexture.Activate;
begin
  if FHandle = 0 then
    Exit;

  glEnable(GL_TEXTURE_2D);
  glActiveTexture(GL_TEXTURE0 + AIndex);
  glBindTexture(GL_TEXTURE_2D, FHandle);
end;

class procedure TTexture.Deactivate;
begin
  glActiveTexture(GL_TEXTURE0 + AIndex);
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
end;

procedure TTexture.Draw;
begin
  Activate;

  Surface.SetColour(AHint);

  glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(AX,          AY);
    glTexCoord2f(1, 0); glVertex2i(AX + FWidth, AY);
    glTexCoord2f(1, 1); glVertex2i(AX + FWidth, AY + FHeight);
    glTexCoord2f(0, 1); glVertex2i(AX,          AY + FHeight);
  glEnd;

  Deactivate;
end;

