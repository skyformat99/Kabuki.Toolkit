/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/Entity.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Collections.Generic;

namespace _Id
{
    /**  */
    class Entity
    {
        /**  */
        Entity (string anEmailAdress = "", string aFirstName = "", string aLastName = "", string aPrimaryPhoneNum = "", 
            string aStreetAdress1 = "", string aZipCode1 = "", string aStreetAdress2 = "", string aZipCode2 = "")
        {
            firstName = aFirstName;
            lastName = aLastName;
            phoneNumber = aPrimaryPhoneNum;
            emailAdress = anEmailAdress;
            streetAdress1 = aStreetAdress1;
            zipCode1 = aZipCode1;
        }

        string Name { get; set; }

        bool Contains (string queery)
        {
            foreach (string a in tags)
                if (a == queery) return true;
            foreach (Address a in addresses)
                if (a == queery) return true;
            foreach (EmailAddress a in emailAddresses)
                if (a == queery) return true;
            foreach (Profile a in profiles)
                if (a == queery) return true;
            foreach (string a in tags)
                if (a == queery) return true;
            
            return false;
        }

        string firstName,
               lastName,
               emailAdress,
               streetAdress1,
               zipCode1,
               streetAddress2,
               zipCode2,
               phoneNumber;
        
        List<string> tags;
        List<Address> addresses;
        List<EmailAddress> emailAddresses;
        List<Profile> profiles;
        List<Note> notes;

    }
}
