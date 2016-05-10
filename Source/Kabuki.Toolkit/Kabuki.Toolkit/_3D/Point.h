/** Underscore
    @file       /.../Kabuki.Toolkit/_3D/Point_i.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _3D.Point_i interface.
*/

namespace _3D
{
    /** A 2D int point. */
    public struct Point_i
    {
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /// Public:
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        /** Default constructor initializes with given Point. */
        public Point_i (int initX = 0, int initY = 0)
        {
            x = initX;
            y = initY;
            z = initZ;
        }

        /** Gets and sets the x component. */
        public int X
        {
            get { return x; }
            set { x = value; }
        }

        /** Gets and sets the y component. */
        public int Y
        {
            get { return y; }
            set { x = value; }
        }

        /** Gets and sets the z component. */
        public int Z
        {
            get { return z; }
            set { z = value; }
        }

        /** Sets the x and y values to the new values. */
        public void Set (int newX = 0, int newY = 0, int newZ = 0)
        {
            x = newX;
            y = newY;
            z = newZ;
        }

        /** Sets the x and y values to the this Point's x and y. */
        public void Set (Point_i thisPoint)
        {
            x = thisPoint.x;
            y = thisPoint.y;
            z = thisPoint.z;
        }

        /** Compares this object's Point to thisPoint and returns true if the two Positions are identical. */
        public bool Equals (Point_i thisPoint)
        {
            if (x != thisPoint.x || y != thisPoint.y || z != thisPoint.z)
                return false;
            return true;
        }

        /** Swaps this object's Point with thisPoint. */
        public void Swap (Point_i thisPoint)
        {
            int tempX = thisPoint.x,
                tempY = thisPoint.y,
                tempZ = thisPoint.z;

            thisPoint.x = x;
            thisPoint.y = y;
            thisPoint.z = z;

            x = tempX;
            y = tempY;
            z = tempZ;
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        private int x,          //< The x value.
            y,                  //< The y value.
            z;                  //< The z value.
    }
}
