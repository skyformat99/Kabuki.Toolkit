/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/Point.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Point_i interface.
*/

namespace _2D
{
/** A 2D T point.
    
*/
template<typename T>
struct Point
{
    T X,        //< The x position.
        Y;      //< The y position.

    /** Default constructor initializes with given Point. */
    Point (T initX = 0, T initY = 0)
    {
        X = initX;
        Y = initY;
    }

    /** Sets the X and Y Values to the new Values. */
    void Set (T newX = 0, T newY = 0)
    {
        X = newX;
        Y = newY;
    }

    /** Sets the X and Y Values to the this Point's X and Y. */
    void Set (Point<T> a)
    {
        X = a.X;
        Y = a.Y;
    }

    /** Compares this object's Point to a and returns true if the two Positions are identical. */
    bool Equals (Point<T> a)
    {
        if (X != a.X || Y != a.Y)
            return false;
        return true;
    }

    /** Swaps this object's Point with a. */
    void Swap (Point<T> a)
    {
        T tempX = a.X,
            tempY = a.Y;

        a.X = X;
        a.Y = Y;

        X = tempX;
        Y = tempY;
    }
};
typedef Point<int> Point_i;
typedef Point<long> Point_l;
typedef Point<float> Point_i;
typedef Point<double> Point_i;
}
