/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Layer.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _G.Layer class.
*/

namespace _G
{
/**  */
class Layer
{
    /**  */
    void Remove ()
    {
        prev.next = next.next);
        next.prev = prev;
    }

    /**  */
    void Draw (_G.Cell canvas)
    {
        Draw (canvas);
        next.Draw (canvas);
    }

    Entity element;     //< The element of this Layer.

    Layer prev,      //< The previous Layer in the Pipeline.
        next;              //< The next Pip in the Pipeline.
}
}
