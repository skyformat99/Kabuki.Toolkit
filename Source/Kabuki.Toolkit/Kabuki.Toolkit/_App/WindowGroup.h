/** Underscore
    @file       /.../Kabuki.Toolkit/_App/WindowGroup.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

using System.Collections.Generic;

namespace _App
{
    /** Class that stores a group of _App.Window objects. */
    class WindowGroup
    {
        const int DefaultMaxWindows = 1024;
    
        /** Default constructor. **/
        WindowGroup ()
        {
            maxWindows = DefaultMaxWindows;
            numWindows = 0;
            windows = new List<Window> ();
        }

        /** Constructor initializes with a single window. */
        WindowGroup (Window thisWindow)
        {
            maxWindows = DefaultMaxWindows;
            numWindows = 1;
            windows = new List<Window> ();
            windows[0] = thisWindow;
        }

        /** Constructor initializes with an array of windows. */
        WindowGroup (List<Window> initWindows)
        {
            windows = initWindows;
        }

        /** Returns the UID of this Group. */
        long UID     { get { return uID; } }

        /** Gets and sets the maximum number of windows in this group */
        int MaxWindows
        {
            get { return maxWindows; }
            set
            {
                if (value < 0) return;
                maxWindows = value;
            }
        }

        /**  */
        int Select (int windowNumber)
        {
            if (windowNumber < 0) return -1;
            if (windowNumber >= numWindows) return 0;
            return windowNumber;
        }

        /** Returns the number of windows in this group. */
        int NumWindows { get { return numWindows; } }

        /** Adds a newWindow to the group. */
        void AddWindow (Window newWindow)
        {
        }

        /** Returns a string representation of this object. */
        string ToString ()
        {
            return "";
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        long uID;               //< The UID of this Group.

        int numWindows,         //< The number of windows in this group.
                   maxWindows;          //< The maximum number of windows allowed in a group.

        List<Window> windows;   //< The Window (s) in this group. 
    }
}