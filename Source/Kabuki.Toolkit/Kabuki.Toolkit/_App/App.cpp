/** Underscore
    @file       /.../Kabuki.Toolkit/_App/App.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the Underscore.App.Application class.
*/

#include "App.h"
using namespace _App;

/**  */
App::App (int initWidth, int initHeight)
{
    if (initWidth < MinWidthOrHeight)   initWidth = MinWidthOrHeight;
    else if (initWidth > MaxWidth)      initWidth = MaxWidth;

    if (initHeight < MinWidthOrHeight)  initHeight = MinWidthOrHeight;
    else if (initHeight > MaxWidth)     initHeight = MaxWidth;
}

/** Returns the process ID of this App. */
long App::GetUID { return uID; }

/** Sets the activeWindow to the newIndex. */
int App::ActivateWindow (int newWindowIndex)
{
    return windows.Select (newWindowIndex);
}

/** Sets the activeWindow to the newWindow. */
int App::ActivateWindow (Window newWindow)
{
    if (newWindow == nullptr)
        return -1;

    activeWindow = newWindow;

    return 0;
}

/** Returns the */
WindowGroup Windows { return windows; }

/**  */
int App::Show  ()
{
    return 0;
}

/**  */
int App::Hide  ()
{
    return 0;
}

/**  */
int App::Close ()
{
    return 0;
}

/** Returns a link to this application's drawing context. */
_G2D.Cell App::Cell ()
{
    return null;
}

/** Draws the graphics on in the Cell canvas g. */
void App::Draw (_G2D.Cell g)
{

}

/** Redraws the screen */
void App::Redraw ()
{

}

/** Returns a text representation of this object. */
string App::ToString ()
{
    return "";
}
