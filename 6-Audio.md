# Audio

It may seem odd to add basic audio support before we are even drawing anything but there is a reason for this;
I've been spending hours on OpenGL code and need a break. :)

I'm not going to spend too much time on this yet. Just enough to make some basic noise. We can make this really easy if we just use general MIDI.

Take a look at the [instruments](https://en.wikipedia.org/wiki/General_MIDI#Program_change_events) provided. We can use the synth and effect instruments to make some quick and easy bleeps and bloops.

Stay with me on this. We can implement with just a handful of lines of code.
```Delphi
class function Audio.MIDI.Open: Boolean;
begin
  Result := midiOutOpen(@FHandle, UINT(-1), Window.FHandle, 0, CALLBACK_WINDOW) = MMSYSERR_NOERROR;
end;

class procedure Audio.MIDI.SetInstrument(const AInstrument: Byte);
begin
  midiOutShortMsg(FHandle, ($C0 or FChannel) or (AInstrument shl 8));
end;

class procedure Audio.MIDI.PressNote(const ANote: Byte; const AVelocity: Byte = 127);
begin
  midiOutShortMsg(FHandle, ($90 or FChannel) or (ANote shl 8) or (AVelocity shl 16));
end;
```

And just like that, we can PEW! PEW! all day long!
```Delphi
procedure TTest.OnStart;
begin
  Audio.MIDI.Open;
  Audio.MIDI.Instrument := Instruments.Gunshot;
end;

procedure TTest.OnButtonPressed(const AButton: Word);
begin
  Audio.MIDI.PressNote(56);
end;
```
