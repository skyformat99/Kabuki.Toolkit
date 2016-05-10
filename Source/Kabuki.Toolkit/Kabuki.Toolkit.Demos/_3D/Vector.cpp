/** Underscore
    @file       /.../Kabuki.Toolkit/_3D/Vector_d.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _3D.Vector_f interface.
*/

namespace _3D
{
    /** A 2D double component. */
    public struct Vector_d
    {
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /// Public:
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        
        /** Default constructor initializes with given component. */
        public Vector_d (double initX = 0.0, double initY = 0.0, double initZ = 0)
        {
            x = initX;
            y = initY;
            z = initZ;
        }

        /** Gets and sets the x component. */
        public double X
        {
            get { return x; }
            set { x = value; }
        }

        /** Gets and sets the y component. */
        public double Y
        {
            get { return y; }
            set { y = value; }
        }

        /** Gets and sets the z component. */
        public double Z
        {
            get { return z; }
            set { z = value; }
        }

        /** Sets the x and y values to the new values. */
        public void Set (double newX, double newY, double newZ)
        {
            x = newX;
            y = newY;
            z = newZ;
        }

        /** Sets the x and y values to the this Vector's x and y. */
        public void Set (Vector_d a)
        {
            x = a.x;
            y = a.y;
            z = a.z;
        }

        /** Compares this object's Vector to a and returns true if the two Positions are identical. */
        public bool Equals (Vector_d a)
        {
            if (x != a.x || y != a.y || z != a.z)
                return false;
            return true;
        }

        /** Swaps this object's Vector with thiscomponent. */
        public void Swap (Vector_d a)
        {
            double tempX = a.x,
                   tempY = a.y,
                   tempZ = a.z;

            a.x = x;
            a.y = y;
            a.z = z;

            x = tempX;
            y = tempY;
            z = tempZ;
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        private double x,       //< The x value.
            y,                  //< The y value.
            z;                  //< The z value.
    }
}
