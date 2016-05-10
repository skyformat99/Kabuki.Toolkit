/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/EmailAddress.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/
using System;
using System.Globalization;
using System.Text.RegularExpressions;

namespace _Id
{
    /** An email address. */
    class EmailAddress
    {
        /** Default constructor. **/
        EmailAddress (string address)
        {

        }

        /** Sets the email address to a string. */
        bool SetAddress (string a)
        {
            invalid = false;
            if (String.IsNullOrEmpty(a)) return false;

            /// Use IdnMapping class to convert Unicode domain names.
            try
            {
                a = Regex.Replace(a, @"(@)(.+)$", this.DomainMapper, RegexOptions.None, TimeSpan.FromMilliseconds(200));
            }
            catch (RegexMatchTimeoutException) { return false; }

            if (invalid) return false;

            // Return true if a is in valid e-mail format.
            try
            {
                return Regex.IsMatch(a,
                    @"^(?("")("".+?(?<!\\)""@)|(([0-9a-z]((\.(?!\.))|[-!#\$%&'\*\+/=\?\^`\{\}\|~\w])*)(?<=[0-9a-z])@))" +
                    @"(?(\[)(\[(\d{1,3}\.){3}\d{1,3}\])|(([0-9a-z][-\w]*[0-9a-z]*\.)+[a-z0-9][\-a-z0-9]{0,22}[a-z0-9]))$",
                    RegexOptions.IgnoreCase, TimeSpan.FromMilliseconds(250));
            }
            catch (RegexMatchTimeoutException) { return false; }
        }

        string Address { get; set; }         //< Stores the email address.

        bool invalid = false;

        string DomainMapper(Match match)
        {
            // IdnMapping class with default property values.
            IdnMapping idn = new IdnMapping();

            string domainName = match.Groups[2].Value;
            try
            {
                domainName = idn.GetAscii(domainName);
            }
            catch (ArgumentException) {
                invalid = true;
            }
            return match.Groups[1].Value + domainName;
        }
    }
}
