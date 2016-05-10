/** Underscore
    @file       /.../Kabuki.Toolkit/_Id/EntityList.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Id
{
/** A List of Entity(s) and EntityGroup(s). */
class EntityList
{   
    public:
    
    /** A list of Entity(s). */
    EntityList ()
    {
    }

    /** Returns the number of Accounts in the List. */
    int GetCount ();
    
    /** Adds an Entity to the list. */
    void Add (Entity a);
    
    /** Adds a list of Entity(s) to the list. */
    void Add (List<Entity> a);
    
    /**  */
    Entity Find (string a);
    
    /**  */
    bool Contains (string a);

    /**  */
    string ToString ();
    
    private:
    
    Array<Entity> entities;      //< The list of entities.
};
}
