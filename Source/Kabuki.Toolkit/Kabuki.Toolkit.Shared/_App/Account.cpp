/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/Account.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Id
{
    /** An account with a username and password. */
    class Account
    {
        /** Default constructor. **/
        Account (string aUsername)
        {
            // If one calls this method then it is assuming that there is no password for the account.
            username = new Name (aUsername);
            password = null;

            users = new User.List ();
        }

        Account (string aUsername, string account_password)
        {
            username = new Name (aUsername);
            password = new Password (account_password);

            role = new Role ();

            users = new User.List ();
        }
        Role Role ()
        {
            return role;
        }
        bool isValid ()
        {
            if (password == null)
            {
                // The the account does not require a password
                if (!username.IsValid ())
                    return false;

                return true;
            }
            else // we have to test the password
            if (!username.IsValid () || !password.IsValid ())
                return false;

            return true;
        }
        string Name
        {
            get { return username; }
            set { username = value; }
        }

        bool RequiresPassword ()
        {
            if (password == null)
                return false;
            return true;
        }
        void SetPassword (string new_password)
        {
            password.Change (new_password);
        }

        //
        User.List Users ()
        {
            return users;
        }

        //
        void allowUser (User.User this_user)
        {
            users.add (this_user);
        }

        //
        bool requestNewAccount (Network.Address request_source, string User_Name, string Password,
            string First_Name, string Last_Name, string Adress1, string Adress2, string Zip_Code)
        {
            if (informationIsValid (user_Name, Password, Confirm_Password,
                First_Name, Last_Name, Adress1, Adress2, Zip_Code))
                return true;
            return false;
        }


        //
        bool informationIsValid (string User_Name, string Password, string First_Name, string Last_Name,
                                    string Adress1, string Adress2, string Zip_Code)
        {
            if ()
                return false;
            return true;
        }

        //
        bool login (User this_user)
        {
            User aUser;
            aUser = users.find (this_user.Name);
            if (!this_user.Equals (aUser))
                return false;
            return true;
        }


        //
        string ToString ()
        {
            return "Account Name: " + username.ToString () + " Password: " + password.ToString ();
        }

        Username username;
        Password password;

        List<User> users;
    }
}