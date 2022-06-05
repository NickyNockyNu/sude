class destructor Audio.MIDI.Destory;
begin
  Close;
end;

class procedure Audio.MIDI.SetInstrument;
begin
  midiOutShortMsg(FHandle, ($C0 or FChannel) or (AInstrument shl 8));
end;

class function Audio.MIDI.Open;
begin
  Close;

  Result := midiOutOpen(@FHandle, UINT(-1), Window.FHandle, 0, CALLBACK_WINDOW) = MMSYSERR_NOERROR;

  if not Result then
    FHandle := 0;
end;

class procedure Audio.MIDI.Close;
begin
  if FHandle = 0 then
    Exit;

  midiOutClose(FHandle);
end;

class procedure Audio.MIDI.Reset;
begin
  if FHandle = 0 then
    Exit;

  midiOutReset(FHandle);
end;

class procedure Audio.MIDI.PressNote;
begin
  midiOutShortMsg(FHandle, ($90 or FChannel) or (ANote shl 8) or (AVelocity shl 16));
end;

class procedure Audio.MIDI.ReleaseNote;
begin
  midiOutShortMsg(FHandle, ($80 or FChannel) or (ANote shl 8) or (AVelocity shl 16));
end;

class procedure Audio.MIDI.AsyncNote;
begin
  PressNote(ANote, AVelocity);
  Sleep(ADuration);
  ReleaseNote(ANote, AVelocity);
end;

class procedure Audio.MIDI.Play;
begin
  Stop;

  mciSendString(PChar('open sequencer! ' + AFileName + ' alias ' + MIDIID), nil, 0, Window.FHandle);
  mciSendString(PChar('play '                                    + MIDIID), nil, 0, Window.FHandle);
end;

class procedure Audio.MIDI.Stop;
begin
  mciSendString('stop '  + MIDIID, nil, 0, Window.FHandle);
  mciSendString('close ' + MIDIID, nil, 0, Window.FHandle);
end;

class procedure Audio.Reset;
begin
  MIDI.Stop;
  MIDI.Reset;
end;
