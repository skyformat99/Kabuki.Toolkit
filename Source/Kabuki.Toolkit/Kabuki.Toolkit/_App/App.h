/** Underscore
    @file       /.../Kabuki.Toolkit/_App/App.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the Underscore.App.Application class.
*/

namespace _App
{
/** An Underscore Application. */
class App : Application
{
    public:

    static const int MinWidthOrHeight = 1,
        MaxWidth = 2 * 4096,                //< Double 4K Ultra resolution.
        MaxHeight = 2 * 2160;               //< Double 4K Ultra resolution.

    /**  */
    App (int initWidth, int initHeight);

    /** Returns the process ID of this App. */
    long GetUID { return uID; }

    /** Sets the activeWindow to the newIndex. */
    int ActivateWindow (int newWindowIndex);

    /** Sets the activeWindow to the newWindow. */
    int ActivateWindow (Window newWindow);

    /** Returns the */
    WindowGroup Windows { return windows; }

    /**  */
    int Show  ();

    /**  */
    int Hide  ();

    /**  */
    int Close ();

    /** Returns a link to this application's drawing context. */
    _G2D.Cell Cell ();

    /** Draws the graphics on in the Cell canvas g. */
    void Draw (_G2D.Cell g);

    /** Redraws the screen */
    void Redraw ();

    /** Returns a text representation of this object. */
    string ToString ();

    ///------------------------------------------------------------------------------------------------------------
    /// Private:
    ///------------------------------------------------------------------------------------------------------------

    int uID;                 //< The UID of this appliction.

    WindowGroup windows;     //< This windows 

    Window activeWindow;
};
}
