/** Underscore
    @file       ~/Math/Fraction.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _. class.
*/

namespace _.Math
{
    /**  A fractional number. */
    public class Fraction
    {

        public Fraction (double thisNumberator, double thisDenominator)
        {
            numberator = thisNumberator;
            denominator = thisDenominator;
        }

        /** Gets and sets the numberator. */
        public double Numberator
        {
            get { return numberator; }
            set { numberator = value; }
        }

        /** Gets and sets the denominator. */
        public double Denominator
        {
            get { return denominator; }
            set { denominator = value; }
        }

        public override string ToString ()
        {
            return "";
        }

        private double numberator,
            denominator;
    }
}
