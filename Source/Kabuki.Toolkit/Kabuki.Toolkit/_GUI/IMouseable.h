/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_GUI2D/IMouseable.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _GUI2D.IMouseable interface.
*/

namespace _GUI2D
{
    /** An object that accepts mouse input. */
    class IMouseable
    {
        void Click (Point mousePos);       //< Processes a single click.
        void DoubleClick (Point mousePos);  //< Processes a double click.
        void Drag (Point mousePos);       //< Processes a drag.
        void Drop (Point mousePos);       //< Processes a drop.
        void Hovor (Point mousePos);       //< Processes a hovor.
        void Throw (Point mousePos);       //< Processes a throw.
    };
}
