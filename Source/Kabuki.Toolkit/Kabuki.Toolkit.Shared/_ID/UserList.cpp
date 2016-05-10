/** Underscore
    @file       /.../Kabuki.Toolkit/_Game/UserList.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

using System.Collections.Generic;

namespace _Game
{
    /**  */
    class UserList
    {
        /**  */
        UserList ()
        {
            users = new List<User>();
        }

        /**  */
        int NumUsers { get { return users.Count; } }

        /**  */
        bool Add (User newUser)
        {
            if (!newUser.IsValid ()) return false;
            users.Add (newUser);
            return true;
        }

        /**  */
        bool Contains (string username)
        {
            for (int index = 0; index < users.Count; index++)
            {
                if (users[index].Name == username)
                    return true;
            }
            return false;
        }

        /**  */
        bool Contains (User this_user)
        {
            for (int index = 0; index < users.Count; index++)
            {
                if (users[index].Equals (this_user))
                    return true;
            }
            return false;
        }

        /**  */
        User Find (string username)
        {
            if (username.Length == 0)
            {
                return null;//static website guest account
            }
            for (int index = 0; index < users.Count; index++)
                if (users[index].Name.Equals (username))
                    return users[index];
            return null;//static website guest account
        }

        /**  */
        string ToString ()
        {
            /// This method creates a string of the users.ToString () 
            /// strings separated by spaces

            string returnString;
            returnString = "Number of Users: " + users.Count + "\n";

            for (int index = 0; index < users.Count; index++)
            {
                /// Iterated through the indexs array and write the
                /// ToString () strings to the returnString
                returnString += "User " + (index + 1) + ": " + users[index].ToString () + "\n";
            }

            return returnString;
        }

        List<User> users;
    }
}
