/** Underscore
    @file       ~/Math/Binary.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _. class.
*/

namespace _.Math
{
    /**  */
    public class Byte
    {
        static string ToString (int integer)
        {
            if (integer > 255) integer = 255;

            return Byte.ToString ((byte)integer);
        }

        static string ToString (byte thisByte)
        {
            string binary = "";

            if (thisByte - 128 >= 0)
            {
                thisByte -= 128;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 64 >= 0)
            {
                thisByte -= 64;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 32 >= 0)
            {
                thisByte -= 32;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 16 >= 0)
            {
                thisByte -= 16;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 8 >= 0)
            {
                thisByte -= 8;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 4 >= 0)
            {
                thisByte -= 4;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 2 >= 0)
            {
                thisByte -= 2;
                binary += "1";
            }
            else
                binary += "0";
            if (thisByte - 1 >= 0)
            {
                thisByte -= 1;
                binary += "1";
            }
            else
                binary += "0";
            return binary.ToString ();
        }
    }
}
