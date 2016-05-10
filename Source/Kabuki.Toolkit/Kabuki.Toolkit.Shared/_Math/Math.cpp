/** Underscore
    @file       ~/Math/Calc.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _. class.
*/

#include "Geometry/GeometryAll.h"
#include "Math/MathAll.h"
#include "Algorithm/Random/LCG.h"
#include "Time/Clock.h"


namespace _.Math
{
    /**  */
    public class Calc
    {
        public Calc ()
        {
        }

        // Returns the absolute Value of the value.
        public static double AbsValue (double a)
        {
            return System.Math.Abs (a);
        }

        // Returns the absolute Value of a float Value.
        public static float AbsValue (float a)
        {
            return System.Math.Abs (a);
        }
    
        // Returns the absolute Value of an int Value.
        public static int AbsValue (int a)
        {
            return System.Math.Abs (a);
        }
    
        // Returns the absolute Value of a long Value.
        public static long AbsValue (long a)
        {
            return System.Math.Abs (a);
        }
    
        // Returns the arc cosine of a Value; the returned angle is in the range 0.0 through pi.
        public static double ACos (double a)
        {
            return System.Math.Acos (a);
        }
    
        // Returns the arc sine of a Value; the returned angle is in the range -pi/2 through pi/2.
        public static double ASin (double a)
        {
            return System.Math.Asin (a);
        }
    
        // Returns the arc tangent of a Value; the returned angle is in the range -pi/2 through pi/2.
        public static double ATan (double a)
        {
            return System.Math.Atan (a);
        }
    
        // Returns the angle theta from the conversion of rectangular coordinates (x, y) to polar coordinates (r, theta).
        public static double ATan2 (double y, double x)
        {
            return System.Math.Atan2 (y, x);
        }
    
        // Returns the cube root of the value.
        public static double CubeRoot (double a)
        {
            return System.Math.cbrt (a);
        }
    
        // Returns the smallest (closest to negative infinity) double Value that is greater than or equal to the argument and is equal to a mathematical integer.
        public static double Ceiling (double a)
        {
            return System.Math.ceil (a);
        }
    
        // Returns the first floating-point argument with the sign of the second floating-point argument.
        public static double copySign (double magnitude, double sign)
        {
            return System.Math.copySign (magnitude, sign);
        }
    
        // Returns the first floating-point argument with the sign of the second floating-point argument.
        public static float copySign (float magnitude, float sign)
        {
            return System.Math.copySign (magnitude, sign);
        }
    
        // Returns the trigonometric cosine of an angle.
        public static double Cos (double a)
        {
            return System.Math.cos (a);
        }
    
        // Returns the hyperbolic cosine of the value.
        public static double HCos (double x)
        {
            return System.Math.cosh (x);
        }
    
        // Returns Euler's number e raised to the power of the value.
        public static double EToTheX (double a)
        {
            return System.Math.exp (a);
        }
    
        // Returns ex -1.
        public static double OneMinusEToTheX (double x)
        {
            return System.Math.expm1 (x);
        }
    
        // Returns the largest (closest to positive infinity) double Value that is less than or equal to the argument and is equal to a mathematical integer.
        public static double Floor (double a)
        {
            return System.Math.Floor (a);
        }
    
        // Returns the unbiased exponent used in the representation of a double.
        public static int Exponent (double d)
        {
            return System.Math.getExponent (d);
        }
    
        // Returns the unbiased exponent used in the representation of a float.
        public static int Exponent (float f)
        {
            return System.Math.getExponent (f);
        }
    
        // Returns sqrt (x2 +y2) without intermediate overflow or underflow.
        public static double hypot (double x, double y)
        {
            return System.Math.hypot (x, y);
        }
    
        // Computes the remainder operation on two arguments as prescribed by the IEEE 754 standard.
        public static double IEEEremainder (double f1, double f2)
        {
            return System.Math.IEEEremainder (f1, f2);
        }
    
        // Returns the natural logarithm (base e) of the value.
        public static double Ln (double a)
        {
            return System.Math.log (a);
        }
    
        // Returns the base 10 logarithm of the value.
        public static double Log (double a)
        {
            return System.Math.log10 (a);
        }
    
        // Returns the natural logarithm of the sum of the argument and 1.
        public static double LogXPlus1 (double x)
        {
            return System.Math.log1p (x);
        }
    
        // Returns the greater of two double Values.
        public static double Max (double a, double b)
        {
            return (a > b) ? a : b;
        }
    
        // Returns the greater of two float Values.
        public static float Max (float a, float b)
        {
            return (a > b) ? a : b;
        }
    
        // Returns the greater of two int Values.
        public static int Max (int a, int b)
        {
            return (a > b) ? a : b;
        }
    
        // Returns the greater of two long Values.
        public static long Max (long a, long b)
        {
            return (a > b) ? a : b;
        }
    
        // Returns the smaller of two double Values.
        public static double Min (double a, double b)
        {
            return System.Math.Min (a, b);
        }
    
        // Returns the smaller of two float Values.
        public static float Min (float a, float b)
        {
            return System.Math.Min (a, b);
        }
    
        // Returns the smaller of two int Values.
        public static int Min (int a, int b)
        {
            return System.Math.Min (a, b);
        }
    
        // Returns the smaller of two long Values.
        public static long Min (long a, long b)
        {
            return System.Math.Min (a, b);
        }
    
        // Returns the floating-point number adjacent to the first argument in the direction of the second argument.
        public static double NextAfter (double start, double direction)
        {
            return System.Math.NextAfter (start, direction);
        }
    
        // Returns the floating-point number adjacent to the first argument in the direction of the second argument.
        public static float NextAfter (float start, double direction)
        {
            return System.Math.NextAfter (start, direction);
        }
    
        // Returns the floating-point Value adjacent to d in the direction of positive infinity.
        public static double NextUp (double d)
        {
            return System.Math.NextUp (d);
        }
    
        //  Returns the floating-point Value adjacent to f in the direction of positive infinity.
        public static float NextUp (float f)
        {
            return System.Math.NextUp (f);
        }
    
        // Returns the Value of the first argument raised to the power of the second argument.
        public static double Power (double a, double b)
        {
            return System.Math.Pow (a, b);
        }
    
        // Returns the value with a positive sign, greater than or equal to 0.0 and less than 1.0.
        public static double Random ()
        {
            return System.Math.Random ();
        }
    
        // Returns the double Value that is closest in Value to the argument and is equal to a mathematical integer.
        public static double rint (double a)
        {
            return System.Math.Rint (a);
        }
    
        // Returns the closest long to the argument, with ties Rounding up.
        public static long Round (double a)
        {
            return System.Math.Round (a);
        }
    
        // Returns the closest int to the argument, with ties Rounding up.
        public static int Round (float a)
        {
            return System.Math.Round (a);
        }
    
        // Return d × 2scaleFactor Rounded as if performed by a single correctly Rounded floating-point multiply to a member of the double Value set.
        public static double scalb (double d, int scaleFactor)
        {
            return System.Math.Scalb (d, scaleFactor);
        }

        /** Return f × 2scaleFactor.
            Rounded as if performed by a single correctly Rounded floating-point multiply to a member of the float Value set. */
        public static float FScaleFactor (float f, int scaleFactor)
        {
            return System.Math.Scalb (f, scaleFactor);
        }
    
        // Returns the signum function of the argument; zero if the argument is zero, 1.0 if the argument is greater than zero, -1.0 if the argument is less than zero.
        public static double Signum (double d)
        {
            return System.Math.Signum (d);
        }

        /** Returns the signum function of the argument
            @return 0.0 if the argument is 0.0, 1.0 if the argument is greater than 0, -1.0 if the argument is less than zero. */
        public static float Signum (float f)
        {
            return System.Math.Signum (f);
        }
    
        // Returns the trigonometric sine of an angle.
        public static double Sin (double a)
        {
            return System.Math.Sin (a);
        }
    
        // Returns the hyperbolic sine of the value.
        public static double HSin (double x)
        {
            return System.Math.Sinh (x);
        }
    
        // Returns the correctly Rounded positive square root of the value.
        public static double SquareRoot (double a)
        {
            return System.Math.Sqrt (a);
        }
    
        // Returns the trigonometric tangent of an angle.
        public static double Tan (double a)
        {
            return System.Math.tan (a);
        }
    
        // Returns the hyperbolic tangent of the value.
        public static double HTan (double x)
        {
            return System.Math.tanh (x);
        }
    
        // Converts an angle measured in radians to an approximately equivalent angle measured in degrees.
        public static double ToDegrees (double angrad)
        {
            return System.Math.toDegrees (angrad);
        }
    
        // Converts an angle measured in degrees to an approximately equivalent angle measured in radians.
        public static double ToRadians (double angdeg)
        {
            return (angle * 180) / Pi_d;
        }
    
        // Returns the size of an ulp of the argument.
        public static double ulp (double d)
        {
            return System.Math.ulp (d);
        }
    
        // Returns the size of an ulp of the argument.
        public static float ulp (float f)
        {
            return System.Math.ulp (f);
        }

        // Method calculates the factorial of thisNumber
        public static int Factoral (int thisNumber)
        {
            int total;  //< The running total.

            if (thisNumber < 0)
            {
                total = thisNumber;

                thisNumber *= -1;

                while (thisNumber-- > 1)
                    total *= thisNumber;

                return total * -1;
            }
            total = thisNumber;

            while (thisNumber-- > 1)
                total *= thisNumber;

            return total;
        }
    }
}
