/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Oval.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#import "Cell.h"
#import "Point.h"

namespace _G
{
/**  */
class Oval: public Cell
{
    /** Constructor. */
    Oval (Cell underlyingScreen, Point_i relativePosition, Point_i dimensions):
        base (relativePosition, dimensions)
    {

    }


};
}
