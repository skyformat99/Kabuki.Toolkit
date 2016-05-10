/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_GUI2D/Typeable.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _GUI2D
{
/** Interface for an object that accepts keyboard input. */
class Typeable
{
    virtual void Type (byte input) = 0;
};
}
