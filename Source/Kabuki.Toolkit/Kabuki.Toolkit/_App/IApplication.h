/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_App/IApplication.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _App.App class.
*/

namespace _App
{
    /** Interface for an Kabuki.Toolkit app. */
    interface IApplication
    {
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /// Public:
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /**
        const int MaxWindows = 256;
        
        long UID;
        numWindows;
        
        Window windows[];
        Window activeWindow;
        */
        
        void Initialize ();                             //< Initializer
        
        long GetUID ();                          //< Returns the process ID of this App.

        int ActivateWindow (int newIndex);       //< Sets the activeWindow to the newIndex.
        int ActivateWindow (Window newWindow);   //< Sets the activeWindow to the newWindow.

        WindowGroup Windows ();                  //< Returns the 

        int Show ();                             //<
        int Hide ();                             //<
        int Close ();                            //<

        /** Returns a link to this application's drawing context. */
        _G2D Cell ();
        void Draw (_G2D.Cell canvas);         //< Draws 
        void Redraw ();                          //<
        string ToString ();             //< Returns a text representation of this object.
    }
}
