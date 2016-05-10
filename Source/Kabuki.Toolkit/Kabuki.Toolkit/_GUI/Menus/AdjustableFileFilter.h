/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_GUI2D/Menues/AdjustableFileFilter.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#include <string.h>

namespace _GUI2D.Menues
{
/**  */
class AdjustableFileFilter : _GUI2D.Menu
{
    static string File_Type_Unknown = "File Type Unknown";
    static string HiddenFile = "Hidden File";

    Hashtable filters;
    string description;
    string fullDescription;
    bool useExtensionsInDescription;

    AdjustableFileFilter ();

    AdjustableFileFilter (string extension);

    AdjustableFileFilter (string extension, string description);

    AdjustableFileFilter (string[] filters);

    AdjustableFileFilter (string[] filters, string description);

    bool Accepts (File thisFile);
    
    void addExtension (string extension);

    // Returns a text description of this object.
    string ToString ();

    void SortBy (string textFilter);

    void setDescription (string aDescription);

    void UseExtensionListDescriptions (bool b);

    /** This function does something that I didn't document because I was an amateur.
     */
    bool IsUsingExtensionListDescriptions ();
}
}
