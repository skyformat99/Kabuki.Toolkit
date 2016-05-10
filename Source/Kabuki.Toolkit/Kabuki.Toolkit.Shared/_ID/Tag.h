/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/UID.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Id
{
    interface UID_i
    {
        int UID { get; set; }           //< Unique identifier number.
        string Name { get; set; }       //< ID name.
    }
}
