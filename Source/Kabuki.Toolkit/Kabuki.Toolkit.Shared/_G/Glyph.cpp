/** Underscore
    @file       /.../Kabuki.Toolkit/_G/Glyph.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G
{
    /**  */
    class Gylph
    {
    
        // Returns the unique id of this symbol.
        long UID ()
        {
            get { return uID; }
        }
    
        /** Returns the key label of this object.
        A key label is a unique search key string with no whitespace that can be used to identify this object in a search.
        */
        string getKey ()
        {
            return key;
        }
    
        //
        string getDescription ()
        {
            return description;
        }
    
        //< Prints this object to the console.
        void Print ()
        {
        
        }
    
        // Returns a text representation of this object.
        string ToString ()
        {
            return "";
        }

        long uID;       //< The UID of this object.
        string key,     //< The label for the Key of this symbol.
            description;        //< The description of this symbol.
    }
}
