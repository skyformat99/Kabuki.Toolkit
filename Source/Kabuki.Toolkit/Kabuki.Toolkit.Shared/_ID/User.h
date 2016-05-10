/** Underscore
    @file       /.../Kabuki.Toolkit/_Game/User.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _Game
{
    /** A user account on a computer.
        A user does not necessarily have an account. Some accounts are and any user can use. i.e. the guest account.
    */
    class User
    {
        /**  */
        User (string aUsername, string aPassword)
        {
            if (IsValid (aPassword))
                return;

            username = aUsername;
            password = aPassword;

            //activeAccounts = new Underscore.Game.Account.List ();
        }

        /**  */
        string Name      { get { return username; } }

        /**  */
        string Password ()
        {
            return password;
        }

        /**  */
        string EncryptPassword ()
        {
            return "";
        }

        /**  */
        bool IsValid ()
        {
            if (username == null || username == "")
                return false;
            return true;
        }

        /**  */
        bool Verify (string aUsername, string aPassword)
        {
            return username == aUsername;
        }

        /**  */
        bool Login (Account thisAccount)
        {
            if (!thisAccount.Users ().Contains (this))
                return false;
            activeAccounts.Add (thisAccount);
            return true;
        }

        /**  */
        bool Equals (User aUser)
        {
            if (username != aUser.Name || password != aUser.password) //< The aUser is not this user
                return false;
            return true;
        }

        /**  */
        string ToString ()
        {
            return "User Name: " + username + " Password: " + password;
        }


        string username,
            password;

        // Currently the user is able log into more the one account at a time. This could cause a security threat.
        //Account.List activeAccounts;
    }
}
