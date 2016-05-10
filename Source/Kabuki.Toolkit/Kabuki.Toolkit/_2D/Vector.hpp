/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/Vector<T>.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector<T> interface.
*/

namespace _2D
{
/** A 2D component. */
template<typename T>
struct Vector
{
    T X,        //< The x position.
        Y;      //< The y position.

    /** Default constructor initializes with given component. */
    Vector (T initX = (T) 0, T initY = (T) 0)
    {
        X = initX;
        Y = initY;
    }

    /** Sets the X and Y Values to the new Values. */
    void Set (T newX = 0.0f, T newY = 0.0f)
    {
        X = newX;
        Y = newY;
    }

    /** Sets the X and Y Values to the this Vector's X and Y. */
    void Set (Vector<T> a)
    {
        X = a.X;
        Y = a.Y;
    }

    /** Compares this object's Vector to a and returns true if the two Positions are identical. */
    bool Equals (Vector<T> a)
    {
        if (X != a.X || Y != a.Y)
            return false;
        return true;
    }

    /** Swaps this object's Vector with thiscomponent. */
    void Swap (Vector<T> a)
    {
        T tempX = a.X,
            tempY = a.Y;

        a.X = X;
        a.Y = Y;

        X = tempX;
        Y = tempY;
    }
};
typedef Vector<int> Vector_i;
typedef Vector<long> Vector_l;
typedef Vector<float> Vector_f;
typedef Vector<double> Vector_d;
}
