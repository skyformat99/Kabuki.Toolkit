/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/Address.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Id;
Address::Address ()
{
    /// Nothing to do here! :-)
}

/** Constructor creates an address with the given parameters. */
Address::Address (string street, string city, string state, string zip, string country, string type)
{
    Street  = street;
    City    = city;
    State   = state;
    Zip     = zip;
    Country = country;
    Type    = type;
}

string Address::GetType () { return type; }
void Address::SetType (string newValue)
{ 
    type = newValue;
}

string Address::GetStreet () { return street; }
void Address::SetStreet (string newValue)
{ 
    street = newValue;
}

string Address::GetCity () { return city; }
void Address::SetCity (string newValue)
{ 
    city = newValue;
}

string Address::GetState () { return state; }
void Address::SetState (string newValue)
{ 
    state = newValue;
}

string Address::GetZip () { return zip; }
void Address::SetZip (string newValue)
{ 
    zip = newValue;
}

string Address::ToString ()
{
    return "Street: " + Street + "\n" + " Cit: " + City + "\n" + " State/Province: " + State + "\n" +
        "Zip/Postal Code: " + Zip + "\n" + "Country: " + Country + "\n";
}