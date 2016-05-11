/** Underscore
    @file       /.../Kabuki.Toolkit/_App/Password.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Text.RegularExpressions;

namespace _App
{
    /**  */
    class Password
    {
        const int MinLength = 4,
            MaxLength = 12;

        const string DefaultFormat = "^[a-zA-Z0-9]*$",
            DefaultPassword = "password";

        /** . */
        Password (string aPassword = DefaultPassword, string aFormat = DefaultFormat)
        {
            password = aPassword;
        }
        
        /**  */
        void Change (string newPassword)
        {
            if (!IsValid (newPassword)) return;
            password = newPassword;
        }
        
        /** Returns true if the given password is valid. */
        static bool IsValid (string aPassword)
        {
            if (aPassword.Length < MinLength || aPassword.Length > MaxLength)
                return false;

            Regex r = new Regex ();
            if (r.IsMatch(aPassword)) return true;

            return false;
        }
        
        /**  */
        string Encript ()
        {
            return password;
        }
        
        /**  */
        string ToString ()
        {
            return password;
        }

        string rules,
            password;
    }
}
