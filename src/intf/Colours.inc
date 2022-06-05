type
  Colours = class abstract
  public const
    // Specials
    None: TVector4f = (R:1; G:1; B:1; A:0);

    // Whites
    AntiqueWhite:        TVector4f = (R:0.980392; G:0.921569; B:0.843137; A:1);
    Azure:               TVector4f = (R:0.941176; G:1.000000; B:1.000000; A:1);
    Bisque:              TVector4f = (R:1.000000; G:0.894118; B:0.768627; A:1);
    BlanchedAlmond:      TVector4f = (R:1.000000; G:0.921569; B:0.803922; A:1);
    Cornsilk:            TVector4f = (R:1.000000; G:0.972549; B:0.862745; A:1);
    Eggshell:            TVector4f = (R:0.988235; G:0.901961; B:0.788235; A:1);
    FloralWhite:         TVector4f = (R:1.000000; G:0.980392; B:0.941176; A:1);
    Gainsboro:           TVector4f = (R:0.862745; G:0.862745; B:0.862745; A:1);
    GhostWhite:          TVector4f = (R:0.972549; G:0.972549; B:1.000000; A:1);
    Honeydew:            TVector4f = (R:0.941176; G:1.000000; B:0.941176; A:1);
    Ivory:               TVector4f = (R:1.000000; G:1.000000; B:0.941176; A:1);
    Lavender:            TVector4f = (R:0.901961; G:0.901961; B:0.980392; A:1);
    LavenderBlush:       TVector4f = (R:1.000000; G:0.941176; B:0.960784; A:1);
    LemonChiffon:        TVector4f = (R:1.000000; G:0.980392; B:0.803922; A:1);
    Linen:               TVector4f = (R:0.980392; G:0.941176; B:0.901961; A:1);
    MintCream:           TVector4f = (R:0.960784; G:1.000000; B:0.980392; A:1);
    MistyRose:           TVector4f = (R:1.000000; G:0.894118; B:0.882353; A:1);
    Moccasin:            TVector4f = (R:1.000000; G:0.894118; B:0.709804; A:1);
    NavajoWhite:         TVector4f = (R:1.000000; G:0.870588; B:0.678431; A:1);
    OldLace:             TVector4f = (R:0.992157; G:0.960784; B:0.901961; A:1);
    PapayaWhip:          TVector4f = (R:1.000000; G:0.937255; B:0.835294; A:1);
    PeachPuff:           TVector4f = (R:1.000000; G:0.854902; B:0.725490; A:1);
    Seashell:            TVector4f = (R:1.000000; G:0.960784; B:0.933333; A:1);
    Snow:                TVector4f = (R:1.000000; G:0.980392; B:0.980392; A:1);
    Thistle:             TVector4f = (R:0.847059; G:0.749020; B:0.847059; A:1);
    TitaniumWhite:       TVector4f = (R:0.988235; G:1.000000; B:0.941176; A:1);
    Wheat:               TVector4f = (R:0.960784; G:0.870588; B:0.701961; A:1);
    White:               TVector4f = (R:1.000000; G:1.000000; B:1.000000; A:1);
    WhiteSmoke:          TVector4f = (R:0.960784; G:0.960784; B:0.960784; A:1);
    ZincWhite:           TVector4f = (R:0.992157; G:0.972549; B:1.000000; A:1);

    // Greys
    ColdGrey:            TVector4f = (R:0.501961; G:0.541176; B:0.529412; A:1);
    DimGrey:             TVector4f = (R:0.411765; G:0.411765; B:0.411765; A:1);
    Grey:                TVector4f = (R:0.752941; G:0.752941; B:0.752941; A:1);
    LightGrey:           TVector4f = (R:0.827451; G:0.827451; B:0.827451; A:1);
    SlateGrey:           TVector4f = (R:0.439216; G:0.501961; B:0.564706; A:1);
    SlateGreyDark:       TVector4f = (R:0.184314; G:0.309804; B:0.309804; A:1);
    SlateGreyLight:      TVector4f = (R:0.466667; G:0.533333; B:0.600000; A:1);
    WarmGrey:            TVector4f = (R:0.501961; G:0.501961; B:0.411765; A:1);

    // Blacks
    Black:               TVector4f = (R:0.000000; G:0.000000; B:0.000000; A:1);
    IvoryBlack:          TVector4f = (R:0.160784; G:0.141176; B:0.129412; A:1);
    LampBlack:           TVector4f = (R:0.180392; G:0.278431; B:0.231373; A:1);

    // Reds
    AlizarinCrimson:     TVector4f = (R:0.890196; G:0.149020; B:0.211765; A:1);
    Brick:               TVector4f = (R:0.611765; G:0.400000; B:0.121569; A:1);
    CadmiumRedDeep:      TVector4f = (R:0.890196; G:0.090196; B:0.050980; A:1);
    Coral:               TVector4f = (R:1.000000; G:0.498039; B:0.313726; A:1);
    CoralLight:          TVector4f = (R:0.941176; G:0.501961; B:0.501961; A:1);
    DeepPink:            TVector4f = (R:1.000000; G:0.078431; B:0.576471; A:1);
    EnglishRed:          TVector4f = (R:0.831373; G:0.239216; B:0.101961; A:1);
    Firebrick:           TVector4f = (R:0.698039; G:0.133333; B:0.133333; A:1);
    GeraniumLake:        TVector4f = (R:0.890196; G:0.070588; B:0.188235; A:1);
    HotPink:             TVector4f = (R:1.000000; G:0.411765; B:0.705882; A:1);
    IndianRed:           TVector4f = (R:0.690196; G:0.090196; B:0.121569; A:1);
    LightSalmon:         TVector4f = (R:1.000000; G:0.627451; B:0.478431; A:1);
    MadderLakeDeep:      TVector4f = (R:0.890196; G:0.180392; B:0.188235; A:1);
    Maroon:              TVector4f = (R:0.690196; G:0.188235; B:0.376471; A:1);
    Pink:                TVector4f = (R:1.000000; G:0.752941; B:0.796078; A:1);
    PinkLight:           TVector4f = (R:1.000000; G:0.713726; B:0.756863; A:1);
    Raspberry:           TVector4f = (R:0.529412; G:0.149020; B:0.341176; A:1);
    Red:                 TVector4f = (R:1.000000; G:0.000000; B:0.000000; A:1);
    RoseMadder:          TVector4f = (R:0.890196; G:0.211765; B:0.219608; A:1);
    Salmon:              TVector4f = (R:0.980392; G:0.501961; B:0.447059; A:1);
    Tomato:              TVector4f = (R:1.000000; G:0.388235; B:0.278431; A:1);
    VenetianRed:         TVector4f = (R:0.831373; G:0.101961; B:0.121569; A:1);

    // Browns
    Beige:               TVector4f = (R:0.639216; G:0.580392; B:0.501961; A:1);
    Brown:               TVector4f = (R:0.501961; G:0.164706; B:0.164706; A:1);
    BrownMadder:         TVector4f = (R:0.858824; G:0.160784; B:0.160784; A:1);
    BrownOchre:          TVector4f = (R:0.529412; G:0.258824; B:0.121569; A:1);
    Burlywood:           TVector4f = (R:0.870588; G:0.721569; B:0.529412; A:1);
    BurntSienna:         TVector4f = (R:0.541176; G:0.211765; B:0.058824; A:1);
    BurntUmber:          TVector4f = (R:0.541176; G:0.200000; B:0.141176; A:1);
    Chocolate:           TVector4f = (R:0.823529; G:0.411765; B:0.117647; A:1);
    DeepOchre:           TVector4f = (R:0.450980; G:0.239216; B:0.101961; A:1);
    Flesh:               TVector4f = (R:1.000000; G:0.490196; B:0.250980; A:1);
    FleshOchre:          TVector4f = (R:1.000000; G:0.341176; B:0.129412; A:1);
    GoldOchre:           TVector4f = (R:0.780392; G:0.470588; B:0.149020; A:1);
    GreenishUmber:       TVector4f = (R:1.000000; G:0.239216; B:0.050980; A:1);
    Khaki:               TVector4f = (R:0.941176; G:0.901961; B:0.549020; A:1);
    KhakiDark:           TVector4f = (R:0.741176; G:0.717647; B:0.419608; A:1);
    LightBeige:          TVector4f = (R:0.960784; G:0.960784; B:0.862745; A:1);
    Peru:                TVector4f = (R:0.803922; G:0.521569; B:0.247059; A:1);
    RosyBrown:           TVector4f = (R:0.737255; G:0.560784; B:0.560784; A:1);
    RawSienna:           TVector4f = (R:0.780392; G:0.380392; B:0.078431; A:1);
    RawUmber:            TVector4f = (R:0.450980; G:0.290196; B:0.070588; A:1);
    Sepia:               TVector4f = (R:0.368627; G:0.149020; B:0.070588; A:1);
    Sienna:              TVector4f = (R:0.627451; G:0.321569; B:0.176471; A:1);
    SaddleBrown:         TVector4f = (R:0.545098; G:0.270588; B:0.074510; A:1);
    SandyBrown:          TVector4f = (R:0.956863; G:0.643137; B:0.376471; A:1);
    Tan:                 TVector4f = (R:0.823529; G:0.705882; B:0.549020; A:1);
    VanDykeBrown:        TVector4f = (R:0.368627; G:0.149020; B:0.019608; A:1);

    // Oranges
    CadmiumOrange:       TVector4f = (R:1.000000; G:0.380392; B:0.011765; A:1);
    CadmiumRedLight:     TVector4f = (R:1.000000; G:0.011765; B:0.050980; A:1);
    Carrot:              TVector4f = (R:0.929412; G:0.568627; B:0.129412; A:1);
    DarkOrange:          TVector4f = (R:1.000000; G:0.549020; B:0.000000; A:1);
    MarsOrange:          TVector4f = (R:0.588235; G:0.270588; B:0.078431; A:1);
    MarsYellow:          TVector4f = (R:0.890196; G:0.439216; B:0.101961; A:1);
    Orange:              TVector4f = (R:1.000000; G:0.501961; B:0.000000; A:1);
    OrangeRed:           TVector4f = (R:1.000000; G:0.270588; B:0.000000; A:1);
    YellowOchre:         TVector4f = (R:0.890196; G:0.509804; B:0.090196; A:1);

    // Yellows
    AureolineYellow:     TVector4f = (R:1.000000; G:0.658824; B:0.141176; A:1);
    Banana:              TVector4f = (R:0.890196; G:0.811765; B:0.341176; A:1);
    CadmiumLemon:        TVector4f = (R:1.000000; G:0.890196; B:0.011765; A:1);
    CadmiumYellow:       TVector4f = (R:1.000000; G:0.600000; B:0.070588; A:1);
    CadmiumYellowLight:  TVector4f = (R:1.000000; G:0.690196; B:0.058824; A:1);
    Gold:                TVector4f = (R:1.000000; G:0.843137; B:0.000000; A:1);
    Goldenrod:           TVector4f = (R:0.854902; G:0.647059; B:0.125490; A:1);
    GoldenrodDark:       TVector4f = (R:0.721569; G:0.525490; B:0.043137; A:1);
    GoldenrodLight:      TVector4f = (R:0.980392; G:0.980392; B:0.823529; A:1);
    GoldenrodPale:       TVector4f = (R:0.933333; G:0.909804; B:0.666667; A:1);
    LightGoldenrod:      TVector4f = (R:0.933333; G:0.866667; B:0.509804; A:1);
    Melon:               TVector4f = (R:0.890196; G:0.658824; B:0.411765; A:1);
    NaplesYellowDeep:    TVector4f = (R:1.000000; G:0.658824; B:0.070588; A:1);
    Yellow:              TVector4f = (R:1.000000; G:1.000000; B:0.000000; A:1);
    YellowLight:         TVector4f = (R:1.000000; G:1.000000; B:0.878431; A:1);

    // Greens
    Chartreuse:          TVector4f = (R:0.498039; G:1.000000; B:0.000000; A:1);
    ChromeOxideGreen:    TVector4f = (R:0.400000; G:0.501961; B:0.078431; A:1);
    CinnabarGreen:       TVector4f = (R:0.380392; G:0.701961; B:0.160784; A:1);
    CobaltGreen:         TVector4f = (R:0.239216; G:0.568627; B:0.250980; A:1);
    EmeraldGreen:        TVector4f = (R:0.000000; G:0.788235; B:0.341176; A:1);
    ForestGreen:         TVector4f = (R:0.133333; G:0.545098; B:0.133333; A:1);
    Green:               TVector4f = (R:0.000000; G:1.000000; B:0.000000; A:1);
    GreenDark:           TVector4f = (R:0.000000; G:0.392157; B:0.000000; A:1);
    GreenPale:           TVector4f = (R:0.596078; G:0.984314; B:0.596078; A:1);
    GreenYellow:         TVector4f = (R:0.678431; G:1.000000; B:0.184314; A:1);
    LawnGreen:           TVector4f = (R:0.486275; G:0.988235; B:0.000000; A:1);
    LimeGreen:           TVector4f = (R:0.196078; G:0.803922; B:0.196078; A:1);
    Mint:                TVector4f = (R:0.741176; G:0.988235; B:0.788235; A:1);
    Olive:               TVector4f = (R:0.231373; G:0.368627; B:0.168627; A:1);
    OliveDrab:           TVector4f = (R:0.419608; G:0.556863; B:0.137255; A:1);
    OliveGreenDark:      TVector4f = (R:0.333333; G:0.419608; B:0.184314; A:1);
    PermanentGreen:      TVector4f = (R:0.039216; G:0.788235; B:0.168627; A:1);
    SapGreen:            TVector4f = (R:0.188235; G:0.501961; B:0.078431; A:1);
    SeaGreen:            TVector4f = (R:0.180392; G:0.545098; B:0.341176; A:1);
    SeaGreenDark:        TVector4f = (R:0.560784; G:0.737255; B:0.560784; A:1);
    SeaGreenMedium:      TVector4f = (R:0.235294; G:0.701961; B:0.443137; A:1);
    SeaGreenLight:       TVector4f = (R:0.125490; G:0.698039; B:0.666667; A:1);
    SpringGreen:         TVector4f = (R:0.000000; G:1.000000; B:0.498039; A:1);
    SpringGreenMedium:   TVector4f = (R:0.000000; G:0.980392; B:0.603922; A:1);
    TerreVerte:          TVector4f = (R:0.219608; G:0.368627; B:0.058824; A:1);
    ViridianLight:       TVector4f = (R:0.431373; G:1.000000; B:0.439216; A:1);
    YellowGreen:         TVector4f = (R:0.603922; G:0.803922; B:0.196078; A:1);

    // Cyans
    Aquamarine:          TVector4f = (R:0.498039; G:1.000000; B:0.831373; A:1);
    AquamarineMedium:    TVector4f = (R:0.400000; G:0.803922; B:0.666667; A:1);
    Cyan:                TVector4f = (R:0.000000; G:1.000000; B:1.000000; A:1);
    CyanWhite:           TVector4f = (R:0.878431; G:1.000000; B:1.000000; A:1);
    Turquoise:           TVector4f = (R:0.250980; G:0.878431; B:0.815686; A:1);
    TurquoiseDark:       TVector4f = (R:0.000000; G:0.807843; B:0.819608; A:1);
    TurquoiseMedium:     TVector4f = (R:0.282353; G:0.819608; B:0.800000; A:1);
    TurquoisePale:       TVector4f = (R:0.686275; G:0.933333; B:0.933333; A:1);

    // Blues
    AliceBlue:           TVector4f = (R:0.941176; G:0.972549; B:1.000000; A:1);
    Blue:                TVector4f = (R:0.000000; G:0.000000; B:1.000000; A:1);
    BlueLight:           TVector4f = (R:0.678431; G:0.847059; B:0.901961; A:1);
    BlueMedium:          TVector4f = (R:0.000000; G:0.000000; B:0.803922; A:1);
    Cadet:               TVector4f = (R:0.372549; G:0.619608; B:0.627451; A:1);
    Cobalt:              TVector4f = (R:0.239216; G:0.349020; B:0.670588; A:1);
    Cornflower:          TVector4f = (R:0.392157; G:0.584314; B:0.929412; A:1);
    Cerulean:            TVector4f = (R:0.019608; G:0.721569; B:0.800000; A:1);
    DodgerBlue:          TVector4f = (R:0.117647; G:0.564706; B:1.000000; A:1);
    Indigo:              TVector4f = (R:0.031373; G:0.180392; B:0.329412; A:1);
    ManganeseBlue:       TVector4f = (R:0.011765; G:0.658824; B:0.619608; A:1);
    MidnightBlue:        TVector4f = (R:0.098039; G:0.098039; B:0.439216; A:1);
    Navy:                TVector4f = (R:0.000000; G:0.000000; B:0.501961; A:1);
    Peacock:             TVector4f = (R:0.200000; G:0.631373; B:0.788235; A:1);
    PowderBlue:          TVector4f = (R:0.690196; G:0.878431; B:0.901961; A:1);
    RoyalBlue:           TVector4f = (R:0.254902; G:0.411765; B:0.882353; A:1);
    SlateBlue:           TVector4f = (R:0.415686; G:0.352941; B:0.803922; A:1);
    SlateBlueDark:       TVector4f = (R:0.282353; G:0.239216; B:0.545098; A:1);
    SlateBlueLight:      TVector4f = (R:0.517647; G:0.439216; B:1.000000; A:1);
    SlateBlueMedium:     TVector4f = (R:0.482353; G:0.407843; B:0.933333; A:1);
    SkyBlue:             TVector4f = (R:0.529412; G:0.807843; B:0.921569; A:1);
    SkyBlueDeep:         TVector4f = (R:0.000000; G:0.749020; B:1.000000; A:1);
    SkyBlueLight:        TVector4f = (R:0.529412; G:0.807843; B:0.980392; A:1);
    SteelBlue:           TVector4f = (R:0.274510; G:0.509804; B:0.705882; A:1);
    SteelBlueLight:      TVector4f = (R:0.690196; G:0.768627; B:0.870588; A:1);
    TurquoiseBlue:       TVector4f = (R:0.000000; G:0.780392; B:0.549020; A:1);
    Ultramarine:         TVector4f = (R:0.070588; G:0.039216; B:0.560784; A:1);

    // Magentas
    BlueViolet:          TVector4f = (R:0.541176; G:0.168627; B:0.886275; A:1);
    CobaltVioletDeep:    TVector4f = (R:0.568627; G:0.129412; B:0.619608; A:1);
    Magenta:             TVector4f = (R:1.000000; G:0.000000; B:1.000000; A:1);
    Orchid:              TVector4f = (R:0.854902; G:0.439216; B:0.839216; A:1);
    OrchidDark:          TVector4f = (R:0.600000; G:0.196078; B:0.800000; A:1);
    OrchidMedium:        TVector4f = (R:0.729412; G:0.333333; B:0.827451; A:1);
    PermanentRedViolet:  TVector4f = (R:0.858824; G:0.149020; B:0.270588; A:1);
    Plum:                TVector4f = (R:0.866667; G:0.627451; B:0.866667; A:1);
    Purple:              TVector4f = (R:0.627451; G:0.125490; B:0.941176; A:1);
    PurpleMedium:        TVector4f = (R:0.576471; G:0.439216; B:0.858824; A:1);
    UltramarineViolet:   TVector4f = (R:0.360784; G:0.141176; B:0.431373; A:1);
    Violet:              TVector4f = (R:0.560784; G:0.368627; B:0.600000; A:1);
    VioletDark:          TVector4f = (R:0.580392; G:0.000000; B:0.827451; A:1);
    VioletRed:           TVector4f = (R:0.815686; G:0.125490; B:0.564706; A:1);
    VioletRedMedium:     TVector4f = (R:0.780392; G:0.082353; B:0.521569; A:1);
    VioletRedPale:       TVector4f = (R:0.858824; G:0.439216; B:0.576471; A:1);
  end;

