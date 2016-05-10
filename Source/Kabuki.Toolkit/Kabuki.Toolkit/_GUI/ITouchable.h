/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_GUI2D/ITouchable.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _GUI2D
{
/** Interface represents an object that can be click on on the screen. */
class ITouchable
{
    virtual void Touch (_2D.Point[] touchPoints) = 0;
};
}
