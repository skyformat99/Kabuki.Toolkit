/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/EntityGroup.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Id
{
    /** A group of entities.
        */
    class EntityGroup
    {
        EntityGroup (string groups_name)
        {
            name = new Name (groups_name);
            accounts = new _Id.Account.Account[0];
        }

        bool isValid ()
        {
        return name.IsValid ();
        }

        string Name
        {
            return name.ToString ();
        }

        void rename (string newName)
        {
            name.rename (newName);
        }

        void applyPrivilages (Privilages new_privilages)
        {
            if (new_privilages == null)
                return;
            for (int i = 0; i < base.Num_Accounts (); i++)
                accounts[i].Role ().Apply_Privilages (new_privilages);
        }

        string ToString ()
        {
            return "Group: " + name.ToString () + " " + base.ToString ();
        }
    }
}