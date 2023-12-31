## TExtender

**Say Hello To TExtender**

### Your New Powerful Friend, When It Comes to Text Rendering

> #### Question 1. Tired of Managing Everything for a Single Text Render?

```cpp
CFont::SetAlphaFade(fAlpha);
CFont::SetCentreOff();
CFont::SetPropOn();

if (CGame::germanGame)
    CFont::SetScale(SCREEN_SCALE_X(0.52f * 0.85f), SCREEN_SCALE_Y(1.1f * 0.85f));
#ifdef MORE_LANGUAGES
else if (CFont::IsJapanese())
    CFont::SetScale(SCREEN_SCALE_X(0.52f) * 1.35f, SCREEN_SCALE_Y(1.1f) * 1.25f);
#endif
else
    CFont::SetScale(SCREEN_SCALE_X(0.52f), SCREEN_SCALE_Y(1.1f));

CFont::DrawFonts();
CFont::SetColor(CRGBA(175, 175, 175, 255));
CFont::SetJustifyOff();
#ifdef MORE_LANGUAGES
if (CFont::IsJapanese())
    CFont::SetWrapx(SCREEN_SCALE_X(229.0f + 34.0f - 4.0f));
else
#endif
    CFont::SetWrapx(SCREEN_SCALE_X(200.0f + 34.0f - 4.0f));
CFont::SetFontStyle(FONT_LOCALE(FONT_STANDARD));
CFont::SetBackgroundOn();
CFont::SetBackGroundOnlyTextOff();
CFont::SetDropShadowPosition(0);
CFont::SetBackgroundColor(CRGBA(0, 0, 0, fAlpha * 0.9f));
CFont::SetColor(CRGBA(175, 175, 175, 255));
CFont::PrintString(SCREEN_SCALE_X(34.0f), SCREEN_SCALE_Y(28.0f + (150.0f - PagerXOffset) * 0.6f), m_HelpMessageToPrint);
```

And Resetting EveryThing After You've Printed?

```cpp

CFont::SetAlphaFade(255.0f);
CFont::SetWrapx(SCREEN_WIDTH);
```

And Check Everything Before A New Render?

```cpp
CFont::SetCentreOff();
CFont::SetRightJustifyOff();
CFont::SetBackGroundOnlyTextOff();
CFont::SetDropShadowPosition(0);
```

#### What If We Could Have A Single Instance That Automatically Invalidates After Use

#### Something Like:

### TExtender

```cpp
{
TExtender::TextPrinter tPrinter;
tPrinter
    .Proportional(true)
    .Scale(isPersian ? CVector2D(SCREEN_SCALE_X(0.72f), SCREEN_SCALE_Y(1.4f)) : CVector2D(SCREEN_SCALE_X(0.52f), SCREEN_SCALE_Y(1.1f)))
    .FontStyle(notIsEnglish ? 7 : 0)
    .Color(CRGBA(175, 175, 175, 255))
    .Alpha(fAlpha)
    .Background(true, CRGBA(64, 0, 128, fAlpha * 0.9f));

if (notIsEnglish)
    tPrinter
        .RightJustify(true, SCREEN_SCALE_FROM_RIGHT(200.0f + 34.0f - 4.0f));
else
    tPrinter
        .JustifyWrap(true, SCREEN_SCALE_X(200.0f + 34.0f - 4.0f));

tPrinter.Print(notIsEnglish ? SCREEN_SCALE_FROM_RIGHT(34.0f) : SCREEN_SCALE_X(34.0f), SCREEN_SCALE_Y(28.0f + (150.0f - PagerXOffset) * 0.6f), m_HelpMessageToPrint, notIsEnglish); // last param is optional isRTL
}
```

##### Every Setting You Made Is Valid Until `}`

#### And If We Want To Duplicate:

```cpp
TextPrinter newPrinter;
newPrinter.CopyFrom(tPrinter); // call before tPrinter invalidates
```

## Or:

```cpp
auto newPrinter = TExtender::TextPrinter(tPrinter);
```

## Or:

### Create Re-Usable Templates:
```cpp
// Define
TextPrinter tPrinter;
tPrinter
    .AlphaFade(fAlpha)
    .Proportional(true)
    .Scale(CVector2D(SCREEN_SCALE_X(0.72f), SCREEN_SCALE_Y(1.4f)))
    .FontStyle(8)
    .Background(true, CRGBA(64, 0, 128, fAlpha * 0.9f))
    .BackGroundOnlyText(false)
    .DropShadowPosition(0)
    .TextColor(CRGBA(175, 175, 175, 255));

if (isPersian) {
    tPrinter
        .RightJustify(true)
        .Alignment(ALIGN_RIGHT)
        .RightJustifyWrap(SCREEN_SCALE_FROM_RIGHT(200.0f + 34.0f - 4.0f));
}
else
    tPrinter.WrapX(SCREEN_SCALE_X(200.0f + 34.0f - 4.0f));

tPrinter.SaveAs("MSG_BOX");

// Use SomeWhere Else
TextPrinter newPrinter;
if (TextPrinter::HasStructure("MSG_BOX")) {
    newPrinter
        .Use("MSG_BOX")
        .Color(CRGBA(255, 0, 0, 255)); // New Color Won't Be Saved On "MSG_BOX" Template

    newPrinter
        .SaveAs("MSG_BOX"); // Now It's Saved
}

```

### Well, As You Guessed We Have It!


> #### Question 2. Tired of Creating Font Textures for every Single New Font? What If You Changed your Mind or Want A New One?

### What If We Could Use Any .TTF Font In The World, Without Converting To GTA Format?!

### Well, As You Guessed We Have It!



> #### Question 3. Tired of  Searching for “Best GXT Editor” That Supports Every World Language Without Problem?

#### What If We Could Use "Any", And By “Any” I Mean “Any” Text Editor In The World to Edit Game Texts?

### Well, As You Guessed We Have It!


I Had These Problems too, So I Decided To Make

> ### A Revolution In Text Rendering

#### I Named That:

## TExtender

#### A Combined Abbreviation Of: **Text Extender** + **Text Render 😁**

For Understand What **TExtender** Do, We Should Understand What GTA Does for Showing Texts To Display

It Consists Of 3 Levels:

1.  Loading Fonts
2.  Loading Texts
3.  Rendering Texts In Each Frame

#### **TExtender** uses Power of [**Plugin-SDK**](https://github.com/DK22Pac/plugin-sdk) **To Empower** And **Enrich reVC Text Engine,** By Improving **All of These 3 Levels**

_Actually To Make That Unlimited & Enjoyable_

1.  Any TTF Font Can Load Into The Game ([DK22Pac's](https://github.com/DK22Pac/directFont))
2.  Any Text File With UTF-8 Encoding (Means WorldWide Support) Can Load Into The Game ([\_AG's](https://github.com/DK22Pac/plugin-sdk/commit/b9ab0a97702afae084f047bdeec55613865fba47))
3.  The Whole `CFont` API Redesigned, Targeting To Be Enjoyable (DoKtor K.'s)

> Amusing Fact:
> 
> Formerly I Was a Full-Stack Web Developer, And Influenced By The Lovely Syntax Of: [jQuery](https://github.com/jquery/jquery) & [Laravel](https://github.com/laravel/laravel)
> 
> So This API Is Plainly Inspired By Those API :)

So Now I Can Copy This Text From [Laravel Website](https://laravel.com/) 😎

**TExtender** values beauty. We love clean code just as much as you do. Simple, elegant syntax puts amazing functionality at your fingertips. Every feature has been thoughtfully considered to provide a wonderful developer experience.

Compare This Codes For Better Understanding

```cpp
// check and reset every time
CFont::SetJustifyOff();
CFont::SetPropOn();
CFont::SetBackgroundOff();

if (FrontEndMenuManager.m_PrefsLanguage == CMenuManager::LANGUAGE_SPANISH)
    CFont::SetScale(SCREEN_SCALE_X(1.7f * 0.8f), SCREEN_SCALE_Y(1.8f));
else
    CFont::SetScale(SCREEN_SCALE_X(1.7f), SCREEN_SCALE_Y(1.8f));

CFont::SetSlantRefPoint(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(128.0f));
CFont::SetSlant(0.15f);

CFont::SetRightJustifyOn();
CFont::SetRightJustifyWrap(0.0f);
CFont::SetBackGroundOnlyTextOff();
CFont::SetDropShadowPosition(2);
CFont::SetDropColor(CRGBA(0, 0, 0, fZoneAlpha));
CFont::SetFontStyle(FONT_BANK);
CFont::SetColor(CRGBA(ZONE_COLOR.r, ZONE_COLOR.g, ZONE_COLOR.b, fZoneAlpha));

if (!CTheScripts::bPlayerIsInTheStatium)
    CFont::PrintStringFromBottom(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(128.0f), m_ZoneToPrint);


// reset everything you changed, including alignment ...
CFont::SetSlant(0.f);
```

With **TExtender**

```cpp
TextPrinter tPrinter;
if (!CTheScripts::bPlayerIsInTheStatium)
    tPrinter
        .Proportional(true)
        .Scale((FrontEndMenuManager.m_PrefsLanguage == CMenuManager::LANGUAGE_SPANISH) ? CVector2D(SCREEN_SCALE_X(1.7f * 0.8f), SCREEN_SCALE_Y(1.8f)) : CVector2D(SCREEN_SCALE_X(1.7f), SCREEN_SCALE_Y(1.8f)))
        .SlantRefPoint(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(128.0f))
        .Slant(0.15f)
        .RightJustify(true, 0.0f)
        .DropShadowPosition(2)
        .DropColor(CRGBA(0, 0, 0, fZoneAlpha))
        .FontStyle(FONT_BANK)
        .TextColor(CRGBA(ZONE_COLOR.r, ZONE_COLOR.g, ZONE_COLOR.b, fZoneAlpha))
        .PrintFromBottom(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(128.0f), m_ZoneToPrint);
```

As You See It's Chainable, Until You Need To Know A Value

Then It Returns That Value:

```cpp
bool bIsPropOn = tPrinter.Proportional();
bool bIsRightJustify = tPrinter.RightJustify();
float fRightJustifyWrap = tPrinter.RightJustifyWrap();
...
```

Plus It Suppports `Shadow` & `Outline (Edge in SA)` Together

```cpp
tPrinter
    .ShadowWidth(0.5f)
    .OutlineWidth(1.0f)
```

Want A Special Color For Each Of Them? (besides of `DropColor`)

```cpp
tPrinter
    .ShadowColor(CRGBA(0, 255, 0, 255))
    .OutlineColor(Colors::Orange)
```

Yes It Supports [Colors From Plugin-SDK](https://github.com/DK22Pac/plugin-sdk/blob/master/shared/Color.h) 

Expect An Easier Way? Right

```cpp
tPrinter
    .Shadow(0.5f, CRGBA(0, 255, 0, 255))
    .Outline(1.0f, Colors::Orange)
```

Speaking Of Colors, Any Old Color Tag is Supported In Values, Plus Custom RGB Tags
```ini
[GameLogic::WatedText]
Hello ~R~Red ~W~White ~p~Purple ~l~Black ... But Also ~FF0000~ Yes, It's A Good Red ~FFC90E~:D

[GameLogic::BustedText]
Something Missing? Like ~0000FFFF~Alpha? What About ~0000FF0FF~Force Alpha? ~R~put a 0 Before Alpha

# Want To Keep Color And Only Change Alpha?
# There Are Two Ways: Combined & Forced
[GA_23]
Not ~a255~Enough ~A255~Money
# Note: You Have To Zero-Pad This Value To Use This Feature, So 99 Must Be 099, 9 Must Be 009

```
Want To Convert Your Colors To Hex?
Try The Fastest Way:
*   Press `F12` In Your Browser
*   Go To `Console`
*   Write This And Press Enter, Wasn't Hard No? :P
```js
(255).toString(16)
```

**Note!
Only TE Renderer Can Understand And Use New Color Tags,
So You Must Use `TPrinter` or `CFontNew::PrintString` Otherwise You Will See Color Values In Your Message**


Want To Set Text Color Globallay?
```cpp
tPrinter
    .TextColor(Colors::Crimson) // same as CFont::SetColor()
    .Alpha(255) // same as CFont::SetAlphaFade()

// Note: If You Use Color Tags, Color Of That Part will be Overwritten
// If You Use Forced Alpha eg: ~A255~ Or ~0000FF0FF~, Alpha Of That Part will be Overwritten
```

#### Orientation
In GTA If We Have Setted `SetJustifyOn()` Then We Should `SetWrapx()`

 If We Have Setted `SetRightJustifyOn()` Then We Should `SetRightJustifyWrap()`

And  If We Have Setted `SetCentreOn()` Then We Should `SetCentreSize()`

As You May Noticed There Is:  

```cpp
tPrinter.RightJustify(true, 0.0f)
```

But Also We Can:

```cpp
tPrinter.Justify(true);
// OR
tPrinter.RightJustify(true);
// OR
tPrinter.Centred(true);
// Then
tPrinter.HorizantalWrap(0.5f); // works for any of them that is active now
```

So Instead Of
```cpp
switch (alignment) {
    case AlignCenter:
        CFont::SetRightJustifyOff();
        CFont::SetJustifyOff();
        CFont::SetCentreOn();
        CFont::SetCentreSize(SCREEN_SCALE_X(lineSize));
        break;
    case AlignLeft:
        CFont::SetCentreOff();
        CFont::SetRightJustifyOff();
        CFont::SetJustifyOn();
        CFont::SetWrapx(SCREEN_SCALE_X(lineSize));
        break;
    case AlignRight:
        CFont::SetCentreOff();
        CFont::SetJustifyOff();
        CFont::SetRightJustifyOn();
        CFont::SetRightJustifyWrap(SCREEN_SCALE_X(lineSize));
        break;
}
```

You Can:

```cpp
tPrinter
    .Orientation(alignment) // same as SA CFont::SetOrientation()
    .HorizantalWrap(SCREEN_SCALE_X(lineSize));
if(alignment == AlignLeft)
    tPrinter.SetJustifyOn(); // Yes, Old Setters Are Supported
```

```cpp
// plus there is:
short tPrinter.Orientation(); // get
float tPrinter.HorizantalWrap(); // get
// and
tPrinter.ClearOrientation();
/*
instead of
SetCentreOff();
SetRightJustifyOff();
*/
```

#### You Want To Use Old Sytax And Just Use New Benefits Like NewFontLoader & NewTextLoader ??

#### Really?!! But Why ?!

However It's Possible:

It's Old Boring Code That R\* Did In 2002:

```cpp
CFont::SetJustifyOff();
CFont::SetPropOn();
CFont::SetBackgroundOff();

if (FrontEndMenuManager.m_PrefsLanguage != CMenuManager::LANGUAGE_ITALIAN && FrontEndMenuManager.m_PrefsLanguage != CMenuManager::LANGUAGE_SPANISH)
    CFont::SetScale(SCREEN_SCALE_X(1.7f), SCREEN_SCALE_Y(1.8f));
else
    CFont::SetScale(SCREEN_SCALE_X(1.7f * 0.85f), SCREEN_SCALE_Y(1.8f));

CFont::SetSlantRefPoint(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(105.0f));
CFont::SetSlant(0.15f);

CFont::SetRightJustifyOn();
CFont::SetRightJustifyWrap(0.0f);
CFont::SetBackGroundOnlyTextOff();
CFont::SetFontStyle(FONT_BANK);
CFont::SetDropShadowPosition(2);
CFont::SetColor(CRGBA(VEHICLE_COLOR.r, VEHICLE_COLOR.g, VEHICLE_COLOR.b, fVehicleAlpha));
CFont::SetDropColor(CRGBA(0, 0, 0, fVehicleAlpha));

CFont::PrintStringFromBottom(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(105.0f), m_pVehicleNameToPrint);

CFont::SetSlant(0.f);
```

And It's Also Old Code, But With TE Renderer

```cpp
CFont::SetJustifyOff();
CFont::SetPropOn();
CFont::SetBackgroundOff();

if (FrontEndMenuManager.m_PrefsLanguage != CMenuManager::LANGUAGE_ITALIAN && FrontEndMenuManager.m_PrefsLanguage != CMenuManager::LANGUAGE_SPANISH)
    CFont::SetScale(SCREEN_SCALE_X(1.7f), SCREEN_SCALE_Y(1.8f));
else
    CFont::SetScale(SCREEN_SCALE_X(1.7f * 0.85f), SCREEN_SCALE_Y(1.8f));

CFont::SetSlantRefPoint(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(105.0f));
CFont::SetSlant(0.15f);

CFont::SetRightJustifyOn();
CFont::SetRightJustifyWrap(0.0f);
CFont::SetBackGroundOnlyTextOff();
CFontNew::SetFontStyle(FONT_BANK);
CFont::SetDropShadowPosition(2);
CFont::SetColor(CRGBA(VEHICLE_COLOR.r, VEHICLE_COLOR.g, VEHICLE_COLOR.b, fVehicleAlpha));
CFont::SetDropColor(CRGBA(0, 0, 0, fVehicleAlpha));

CFontNew::PrintStringFromBottom(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(105.0f), m_pVehicleNameToPrint);

CFont::SetSlant(0.f);
```

As You See There Is Need Only For Two Lines:

```cpp
CFontNew::SetFontStyle(FONT_BANK);
CFontNew::PrintStringFromBottom(SCREEN_SCALE_FROM_RIGHT(32.0f), SCREEN_SCALE_FROM_BOTTOM(105.0f), m_pVehicleNameToPrint);
```

What?!

It Changes `CFont` Class ??

No, It Just Extends `CFont` Class

```cpp
// So Calling
CFont::SetRightJustifyOn();
// Or
CFontNew::SetRightJustifyOn();
// Basically Doesnt Have Any Difference
```

### How To Add New Fonts?

Open `directFont.ini`

Clean File And Add Your Font Details in That

Notes:

1.  I've Said Unlimited, But Actually It Can Have Up to 255 Fonts, Enough For You? 😁
2.  Font Index In C++ Starts From 0, So `[FONT1]` Needs `CFontNew::SetFontStyle(0);` and Upwards…
3.  Make Sure `FontName=` Matches The Real Font Name, Otherwise It Won't Work. To Know FontName, Simply DoubleClick to Open ttf :)

### How To Add New Texts?

Go To `text` folder

Create A New `.xfxt` file

The Example Text Will Help You How To Do That

## Cons:

*   **It Limits You To Use D3D9 Version**
*   **It Limits You To Windows Version**

### FAQ:

#### Port to re3?
##### Must Not Be Hard, Cause re3 Also Uses `wchar*`

### ASI Version?
#### I Believe This Is Possible, But I Dont Have Any Time Or Motivation For That, However You Can Do That

### SA Version?
#### Maybe A Bit Hard Cause SA Uses `char*`

But Some Years Ago I used directFont for Rendering Persian Texts On SA  
And That Was Possible  
No Any Guarantee That I Will Port That, But You Can Do That


### What About Performance?
#### It's OK, Any Instance Get Invalid When You Don't Need That
However if you find performance issues, report that [here](https://github.com/DoK-K/TExtender/issues)

## Credits:

*   #### DoKtor K. - Who Enjoys Coding And Loves Enjoyable Code

*   #### [DK22Pac](https://github.com/DK22Pac) - Who Started With A Great Belief To "Change" And Then Started The Great Project Plugin-SDK

*   #### [\_AG](https://github.com/gennariarmando) - Who Learns Me A Lot, Without learning directly :D

*   #### All Of [Plugin-SDK Contributors](https://github.com/DK22Pac/plugin-sdk/graphs/contributors)

*   ### And Last, But Not Least, THE GREAT HERO “aap” Who Changed Entire Level of Everything with re3 / reVC  
*   #### All of [re3](https://github.com/gtamodding/re3) Contributors, The Great People On The World

*   #### All of GTA Modding Community  
  
## Links:

[**Plugin-SDK**](https://github.com/DK22Pac/plugin-sdk)

[**directFont**](https://github.com/DK22Pac/directFont) (Load TTF Fonts Into D3DX Format)

[**effects-loader**](https://github.com/DK22Pac/effects-loader) (Search ForAllFiles Method)

And Finally Excuse Me for PascalCasing, I Like This Style :D