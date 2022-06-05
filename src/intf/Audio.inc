const
  MIDIID = 'dsueMIDI';

type
  TMIDIChannel = 0..127;

  Audio = class abstract
  public type
    MIDI = class abstract
    private class var
      FHandle:  HMIDIOUT;

      FChannel:    TMIDIChannel;
      FInstrument: Byte;
    private
      class destructor Destory;

      class procedure SetInstrument(const AInstrument: Byte); static;
    public
      class function  Open:  Boolean;
      class procedure Close;

      class procedure Reset;

      class procedure PressNote  (const ANote: Byte; const AVelocity: Byte = 127);
      class procedure ReleaseNote(const ANote: Byte; const AVelocity: Byte = 127);

      class procedure AsyncNote(const ANote: Byte; const ADuration: Cardinal; const AVelocity: Byte = 127);

      class procedure Play(const AFileName: String);
      class procedure Stop;

      class property Channel:    TMIDIChannel read FChannel    write FChannel;
      class property Instrument: Byte         read FInstrument write SetInstrument;
    end;
  public
    class procedure Reset;
  end;
