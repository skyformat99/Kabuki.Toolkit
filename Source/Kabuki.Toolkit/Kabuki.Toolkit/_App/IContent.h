/** Underscore
    @file       /.../Kabuki.Toolkit/_App/IContent.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _App
{
    /**  */
    interface IContent
    {
        int Catagory ();                    
        int MinAgeGroup ();                 //< Returns a number 0 - 21 for the recommended age group.
        string Descriptiong ();
        string FullDescriptiong ();
        string ContentDescription ();       //< Returns a string with the type of content.
    }
}
