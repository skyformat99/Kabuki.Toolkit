/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/Entity.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

#include "string.h";
#include "Point.hpp"

namespace _2D
{
/* Class that represents a fourth order BezierCurve.
*/
template<typename T>
class BezierCurve
{
    ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    public:
    ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    const int DefaultNumPoints = 4;

    /** Constructor.
        @warning the length of xPoints and yPoints must equal nPoints or curve will not be created correctly.
    */
    BezierCurve (T xPoints[], T yPoints[], int nPoints)
    {
        assert (yPoints != null): "Error creating BezierCurve. xPoings is null.";
        assert (yPoints != null): "Error creating BezierCurve. yPoints is null.";

        int tempX = xPoints.length;

        assert (tempX != nPoints): "Error creating BezierCurve. nPoints doesn't match the length of the point arrays.";

        if (yPoints == null || xPoints == null || tempX != yPoints.length || tempX != nPoints)
        {
            numPoints = 4;

            xPoints = new T[4];
            yPoints = new T[4];

            xPoints[0] = 0;
            yPoints[0] = 0;
            xPoints[1] = 0;
            yPoints[1] = 1;
            xPoints[2] = 1;
            yPoints[2] = -1;
            xPoints[3] = 1;
            yPoints[3] = 0;
        }
        else
        {
            numPoints = nPoints;
            xPoints = new T[nPoints];
            yPoints = new T[nPoints];

            for (int i = 0; i < nPoints; i++)
            {
                xPoints[i] = xPoints[i];
                yPoints[i] = yPoints[i];
            }
        }
    }

    /** Constructor initializes curve with the given points.
        
    */
    BezierCurve (T x0, T y0, T x1, T y1, T x2, T y2, T x3, T y3)
    {
        numPoints = 4;
        xPoints = new T[4];
        yPoints = new T[4];

        xPoints[0] = x0;
        yPoints[0] = y0;
        xPoints[1] = x1;
        yPoints[1] = y1;
        xPoints[2] = x2;
        yPoints[2] = y2;
        xPoints[3] = x3;
        yPoints[3] = y3;
    }

    /** Copy constructor initializes curve with the given points.
    */
    BezierCurve (const BezierCurve& initState)
    {
        assert (initState != null): "Error creating BezierCurve using copy constructor. Input was null.";

        if (initState != null)
        {
            numPoints = 4;

            xPoints = new T[4];
            yPoints = new T[4];

            xPoints[0] = 0;
            yPoints[0] = 0;
            xPoints[1] = 0;
            yPoints[1] = 1;
            xPoints[2] = 1;
            yPoints[2] = -1;
            xPoints[3] = 1;
            yPoints[3] = 0;
        }
        else
        {
            numPoints = initState.numPoints;

            xPoints = new T[numPoints];
            yPoints = new T[numPoints];

            for (int i = 0; i < numPoints; i++)
            {
                xPoints[i] = initState.xPoints[i];
                yPoints[i] = initState.yPoints[i];
            }
        }
    }

    /** Returns a Point<T> along the path of the of curve at time t. */
    Point<T> GetPoint (T t)
    {
        T x = 0,                           //< The x position to return.
            y = 0,                           //< The y position to return.
            factn = factoral (numPoints);    //< Local copy of n!.

        int n = numPoints;                      //< Local copy of numPoints as a T.

        for (int i = 0; i <= n; i++)
        {
            T b = factn / (factoral (i) * factoral (n - i)), //< Calculate binomial coefficient
                k = Math.pow (1 - t, n - i) * Math.pow (t, i);   //< Calculate powers

         // Add weighted points to totals
            x += b*k*xPoints[i];
            y += b*k*yPoints[i];
        }

        return new Point<T>.Double (x, y);
    }

    /** Returns the factorial of the given value. */
    static int Factoral (int value)
    {
        // return special case
        if (value == 0)
            return 1;

        if (value < 0)
            value *= -1;

        // Calculate factoral of value.

        int total = value;
        while (--value > 1)
            total *= value;

        return total;
    }

    /** Gets the number of points. */
    int NumPoints ()
    {
        return numPoints;
    }

    std::String ToString ()
    {
        std::String returnString = new std::String ("numPoints = " + numPoints + "\n");

        for (int i = 0; i < numPoints; i++)
        {
            returnString += ("x[" + i + "] = " + xPoints[i] + ", y[" + i + "] = " + yPoints[i] + "\n");
        }
        returnString += ("\n");

        return returnString;
    }

    private:

    int numPoints;  // The number of 

    T[] xPoints,    //< Array of x points.
        yPoints;    //< Array of y points.
};
}
