/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/EntityList.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using namespace _Id;

EntityList::EntityList ()
{
    entities = new List<Entity> ();
}

int EntityList::GetCount () { return entities.Count; }

void Add (Entity a)         { entities.Add (a); }

/** Adds a list of Entity(s) to the list. */
void Add (List<Entity> a)   { entities.AddRange (a); }

/**  */
Entity EntityList::Find (string a)
{
    if (a.Length == 0)
    {
        return null;//static website guest entities
    }
    for (int i = 0; i < entities.Count; i++)
        if (entities[i].Name.Equals (a))
            return entities[i];
    return null;//static website guest entities
}

/**  */
bool EntityList::Contains (string a)
{
    if (a.Length == 0 || a == null) return false;

    for (int i = 0; i < entities.Count; i++)
        if (entities[i].Name == a)
            return true;

    return false;//static website guest entities
}

/**  */
string EntityList::ToString ()
{
    string returnstring;
    returnstring = "Number of Accounts: " + entities.Count + (char)13;

    for (int i = 0; i < entities.Count; i++)
    {
        // Iterated throught the users array and write the
        // ToString () strings to the returnstring
        returnstring = returnstring + ("Account " + (i + 1) + ": " + entities[i].ToString () + (char)13);
    }

    return returnstring;
}