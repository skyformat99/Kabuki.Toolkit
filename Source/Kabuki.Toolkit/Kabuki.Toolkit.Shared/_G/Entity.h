/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Enity.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G
{
/**  */
class Entity : public Cell
{
    public:

    /** Returns the bounds of the entity. */
    _2D.Rectangle_i Bounds () = 0;

    /**  */
    void Draw (_G.Cell canvas) = 0;
};
}
