/** Underscore
    @file       /.../Underscore.Library/_Data/Iterable.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /**  */
    interface Iterable<T>
    {
        Iterator<T> GetIterator ();
    }
}
