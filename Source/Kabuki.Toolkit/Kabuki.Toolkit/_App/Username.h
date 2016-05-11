/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/Username.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Id
{
    /**  */
    class Username
    {
        static int MinMinLength = 1;        //< The minimum min length of a Username
        static int MaxMaxLength = 256;      //< The maximum max length of a Username
        
        /** Constructor creates a standard username. */
        Username (string aName, int aMinLength = 8, int aMaxLength = 32)
        {
            if (aMinLength > aMaxLength)
            {
                int temp = aMinLength;
                aMinLength = aMaxLength;
                aMaxLength = temp;
            }
            name = aName;
            if (aMinLength < MinMinLength) aMinLength = MinMinLength;
            else if (aMinLength > MaxMaxLength) aMinLength = MinMinLength;
        }

        /** Returns true if this password is value. */
        bool Set (string a)
        {
            if (a.Length < minLength || a.Length > maxLength)
                return false;

            return IsValid (name);
        }

        /**  */
        bool IsValid (string a)
        {
            if (a.Length < minLength || a.Length > maxLength)
                return false;


            return true;
        }

        /**  */
        string ToString ()
        {
            return name;
        }

        int minLength,
            maxLength;

        string name;
    }
}
