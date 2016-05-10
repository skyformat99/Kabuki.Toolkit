/** Underscore
    @file       /.../Underscore.Library/_Data/Collection.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /**  */
    interface Collection<T>
    {
        bool Add (object thatObject);                      //< Adds thatObject to this Collection.
        bool Add (Collection<T> thatCollection);      //< Adds thatCollection to this Collection.

        void Delete ();                                      //< Deletes the Collection.
        void Clear ();                                       //< Resets the Collection without deleting the contents.

        bool Contains (object thatObect);                    //< Returns true if this Collection contains thatObect.
        bool Contains (Collection<T> c);              //< Returns true if this Collection contains thatCollection.

        bool Eequals (object thatObject);                      //< Returns true if this Collection contains only thatObject.

        long GetHashCode ();                                  //< Generates a hash code for this Collection.
        bool IsEmpty ();                                      //< Return

        bool Remove (object thatObject);
        bool Remove (Collection<T> thatCollection);

        bool Retain (Collection<T> thatCollection);

        Iterator<T> Iterator ();

        long Size ();

        object[] ToArray ();
    }
}
