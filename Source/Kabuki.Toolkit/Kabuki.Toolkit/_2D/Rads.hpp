/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/Rads.hpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

#define _USE_MATH_DEFINES
#include <cmath>

namespace _2D
{
/** An angle between two lines. **/
template<typename T>
struct Rads_f
{
    T Angle;        //< The angle in radians.

    /** Simple default constructor. */
    Rads_f (T a = (T) 0)
    {
        Angle = a;
    }

    float ToDegrees () { return Angle * (float)(180.0 / M_PI); }   //< The angle in degrees.
};
}
