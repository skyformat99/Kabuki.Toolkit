/** Underscore
    @file       /.../Underscore.Library/_Data/Data.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /**  An abstract public class that stores raw data and metadata about the data. */
    interface Data<T>
    {
        T GetData ();       //< Retursn the HAL.object data.
        string DataType ();  //< Function returns a string representing the data type.

        void deconstruct (); //< Agnostic deconstructor.

        void Print ();     //< Prints this object to the console.
        string ToString (); //< Returns a text representation of this object.
    }
}
