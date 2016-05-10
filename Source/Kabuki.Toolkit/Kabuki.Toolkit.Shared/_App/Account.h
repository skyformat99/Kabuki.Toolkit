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
    Account (string aUsername = "New user");

    Account (string aUsername, string aPassword);
    
    bool isValid ();
    
    string GetName ();
    
    bool SetName (string newName);

    bool RequiresPassword ();
    
    void SetPassword (string new_password);t

    //
    User.List Users ();

    //
    void allowUser (User.User this_user);

    //
    bool requestNewAccount (Network.Address request_source, string User_Name, string Password,
        string First_Name, string Last_Name, string Adress1, string Adress2, string Zip_Code);

    //
    bool login (User this_user);


    //
    string ToString ();

    Username username;
    Password password;

    List<User> users;
};
}