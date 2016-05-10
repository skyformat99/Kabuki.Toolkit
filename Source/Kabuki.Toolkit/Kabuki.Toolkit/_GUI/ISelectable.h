/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_GUI2D/ISelectable.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _GUI2D
{
/**  */
class ISelectable
{
    virtual int Select () = 0;
    virtual int Deselect () = 0;
};
}
