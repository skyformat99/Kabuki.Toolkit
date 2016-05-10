/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G2D/Enity.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    interface Entity //: java.awt.Panel : d2.Rectangle, grfx2D.Drawable
    {
        /** Returns the bounds of the entity. */
        _2D.Rectangle_i Bounds ();

        /**  */
        void Draw (_G2D.Cell canvas);
    }
}
