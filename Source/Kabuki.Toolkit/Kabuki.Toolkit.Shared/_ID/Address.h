/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/Address.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#include <string.h>

namespace _Id
{
/** A physical address. */
class Address
{
    const string Home = "Home",
        Work = "Work",
        Other = "Other";

    /** Default constructor. **/
    Address ();

    /** Constructor creates an address with the given parameters. */
    Address (string street, string city, string state, string zip, string country, string type);

    string GetType ();
    void SetType (string newType);
    
    string GetStreet ();
    void SetStreet (string newValue);
    
    string GetCity ();
    void SetCity (string newValue);
    
    string GetState ();
    void SetState (string newValue);
    
    string GetZip ();
    void SetZip (string newValue);
    
    string GetCountry ();
    void SetCountry (string newValue);

    string ToString ();
};
}
