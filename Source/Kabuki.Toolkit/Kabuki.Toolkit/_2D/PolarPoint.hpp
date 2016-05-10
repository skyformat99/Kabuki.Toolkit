/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/PolarPoint.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

#include <math.h>

namespace _2D
{
/** A point in a polar coordinate system. */
template<typename T>
struct PolarPoint
{
    T Angle,            //< The angle in radians.
        Radius;         //< The radius in abstract units.

    /** Constructor initializes with given values
        @param  thisAngle   The angle of the coordinate.
        @param  thisNumber  The magnitude of the coordinate.
    */
    PolarPoint (double angle, double radius)
    {
        Angle = angle;
        Radius = radius;
    }

    double Magnitude ()
    {
        return sqrt ((dAngle * Angle + Radius * Radius);
    }
};

typedef PolarPoint<float> PolarPoint_f;
typedef PolarPoint<double> PolarPoint_d;
}
