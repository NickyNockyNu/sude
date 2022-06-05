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

  Instruments = class abstract
  public const
    // Piano
    AcousticGrandPiano:  Byte = 0;
    BrightAcousticPiano: Byte = 1;
    ElectricGrandPiano:  Byte = 2;
    HonkytonkPiano:      Byte = 3;
    ElectricPianoRhodes: Byte = 4;
    ElectricPianoFM:     Byte = 5;
    Harpsichord:         Byte = 6;
    Clavinet:            Byte = 7;

    // Chromatic Percussion
    Celesta:      Byte = 8;
    Glockenspiel: Byte = 9;
    MusicBox:     Byte = 10;
    Vibraphone:   Byte = 11;
    Marimba:      Byte = 12;
    Xylophone:    Byte = 13;
    TubularBells: Byte = 14;
    Dulcimer:     Byte = 15;

    // Organ
    DrawbarOrgan:    Byte = 16;
    PercussiveOrgan: Byte = 17;
    RockOrgan:       Byte = 18;
    ChurchOrgan:     Byte = 19;
    ReedOrgan:       Byte = 20;
    Accordion:       Byte = 21;
    Harmonica:       Byte = 22;
    TangoAccordion:  Byte = 23;

    // Guitar
    AcousticGuitarnylon:      Byte = 24;
    AcousticGuitarsteel:      Byte = 25;
    ElectricGuitarjazz:       Byte = 26;
    ElectricGuitarclean:      Byte = 27;
    ElectricGuitarmuted:      Byte = 28;
    ElectricGuitaroverdriven: Byte = 29;
    ElectricGuitardistortion: Byte = 30;
    ElectricGuitarharmonics:  Byte = 31;

    // Bass
    AcousticBass:       Byte = 32;
    ElectricBassfinger: Byte = 33;
    ElectricBasspicked: Byte = 34;
    FretlessBass:       Byte = 35;
    SlapBass1:          Byte = 36;
    SlapBass2:          Byte = 37;
    SynthBass1:         Byte = 38;
    SynthBass2:         Byte = 39;

    // Strings
    Violin:           Byte = 40;
    Viola:            Byte = 41;
    Cello:            Byte = 42;
    Contrabass:       Byte = 43;
    TremoloStrings:   Byte = 44;
    PizzicatoStrings: Byte = 45;
    OrchestralHarp:   Byte = 46;
    Timpani:          Byte = 47;

    // Ensemble
    StringEnsemble1:     Byte = 48;
    StringEnsemble2:     Byte = 49;
    SynthStrings1:       Byte = 50;
    SynthStrings2:       Byte = 51;
    ChoirAahs:           Byte = 52;
    VoiceOohsorDoos:     Byte = 53;
    SynthVoiceorSoloVox: Byte = 54;
    OrchestraHit:        Byte = 55;

    // Brass
    Trumpet:      Byte = 56;
    Trombone:     Byte = 57;
    Tuba:         Byte = 58;
    MutedTrumpet: Byte = 59;
    FrenchHorn:   Byte = 60;
    BrassSection: Byte = 61;
    SynthBrass1:  Byte = 62;
    SynthBrass2:  Byte = 63;

    // Reed
    SopranoSax:  Byte = 64;
    AltoSax:     Byte = 65;
    TenorSax:    Byte = 66;
    BaritoneSax: Byte = 67;
    Oboe:        Byte = 68;
    EnglishHorn: Byte = 69;
    Bassoon:     Byte = 70;
    Clarinet:    Byte = 71;

    // Pipe
    Piccolo:     Byte = 72;
    Flute:       Byte = 73;
    Recorder:    Byte = 74;
    PanFlute:    Byte = 75;
    Blownbottle: Byte = 76;
    Shakuhachi:  Byte = 77;
    Whistle:     Byte = 78;
    Ocarina:     Byte = 79;

    // Synth Lead
    Lead1square:      Byte = 80;
    Lead2sawtooth:    Byte = 81;
    Lead3calliope:    Byte = 82;
    Lead4chiff:       Byte = 83;
    Lead5charang:     Byte = 84;
    Lead6spacevoice:  Byte = 85;
    Lead7fifths:      Byte = 86;
    Lead8bassandlead: Byte = 87;

    // Synth Pad
    Pad1newageorfantasia:  Byte = 88;
    Pad2warm:              Byte = 89;
    Pad3polysynthorpoly:   Byte = 90;
    Pad4choir:             Byte = 91;
    Pad5bowedglassorbowed: Byte = 92;
    Pad6metallic:          Byte = 93;
    Pad7halo:              Byte = 94;
    Pad8sweep:             Byte = 95;

    // Synth Effects
    FX1rain:              Byte = 96;
    FX2soundtrack:        Byte = 97;
    FX3crystal:           Byte = 98;
    FX4atmosphere:        Byte = 99;
    FX5brightness:        Byte = 100;
    FX6goblins:           Byte = 101;
    FX7echoesorechodrops: Byte = 102;
    FX8scifiorstartheme:  Byte = 103;

    // Ethnic
    Sitar:    Byte = 104;
    Banjo:    Byte = 105;
    Shamisen: Byte = 106;
    Koto:     Byte = 107;
    Kalimba:  Byte = 108;
    Bagpipe:  Byte = 109;
    Fiddle:   Byte = 110;
    Shanai:   Byte = 111;

    // Percussive
    TinkleBell:          Byte = 112;
    Agogô:               Byte = 113;
    SteelDrums:          Byte = 114;
    Woodblock:           Byte = 115;
    TaikoDrum:           Byte = 116;
    MelodicTomor808Toms: Byte = 117;
    SynthDrum:           Byte = 118;
    ReverseCymbal:       Byte = 119;

    // Sound Effects
    GuitarFretNoise: Byte = 120;
    BreathNoise:     Byte = 121;
    Seashore:        Byte = 122;
    BirdTweet:       Byte = 123;
    TelephoneRing:   Byte = 124;
    Helicopter:      Byte = 125;
    Applause:        Byte = 126;
    Gunshot:         Byte = 127;
  end;


