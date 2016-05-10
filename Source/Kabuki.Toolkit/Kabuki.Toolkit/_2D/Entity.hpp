/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/Entity.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

#include "string.h";

namespace _2D
{
/** Interface for a standard 2D graphics entinty.
*/
template<typename T>
class Entity : Rectangle<T>
{
    ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    public:
    ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /** Default constructor. */
    Entity (std::string , T x = (T) 0, T y = (T) 0)
    {

    }

    /** Returns the name of the string. */
    std::string& GetName () { return &name; }

    /** Sets the name of the string. */
    std::string& SetName (const char& a)
    { 
        name = a; 
    }

    /** Sets the name of the string. */
    std::string& SetName (std::string& a)
    { 
        name = a; 
    }

    /** Returns a string representation of this object. */
    std::string ToString ()
    {
        std::string s = "Entity: " + name + "\n" + ;
    }

    ///----------------------------------------------------------------------------------------------------------------
    private:
    ///----------------------------------------------------------------------------------------------------------------

    std::string name;       //< Name string.
};
}