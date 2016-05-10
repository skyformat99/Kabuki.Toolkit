/** Underscore
    @file       /.../Kabuki.Toolkit/_App/Window.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _App
{
    /** Class represents a Window of an Application. */
    class Window
    {
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /// Public:
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


        int Show ()
        {
            return 0;
        }

        int Hide ()
        {
            return 0;
        }

        int Close ()
        {
            return 0;
        }

        void Update ()
        {

        }

        void Draw (_G2D.Cell g)
        {

        }

        char TransparencyLevel
        {
            get { return transparencyLevel; }
            set { transparencyLevel = Value; }
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        byte transparencyLevel;
    }
}
