/** Underscore
    @file       /.../Kabuki.Toolkit/_GUI2D/Menues/AdjustableFileFilter.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

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
    
        AdjustableFileFilter () :
            base ()
        {  
        }
		
        AdjustableFileFilter (string extension) : 
            base (extension, null)
        {
        }
    
        AdjustableFileFilter (string extension, string description) :
            base ()
        {
	        if (extension!=null) addExtension (extension);
            if (description!=null) setDescription (description);
        }
    
        AdjustableFileFilter (string[] filters) :
            base (filters, null)
        {
        }
    
        AdjustableFileFilter (string[] filters, string description) :
            base ()
        {
            for (int i = 0; i < filters.Length; i++)
                addExtension (filters[i]);
            if (description!=null)
                setDescription (description);
        }
    
    
        bool Accepts (File thisFile)
        {
            if (thisFile == null)
                return false;
            if (thisFile.IsDirectory ())
                return true;
            string extension = thisFile.Extension ();
            if (extension == null)
                return false;
            if (filters.Get (thisFile.Extension ()))
                return false;
            return true;
        }
        void addExtension (string extension)
        {  if (filters == null)
                filters = new _Data.Hashtable (5);
            filters.put (extension.To_Lower_Case (), this);
            fullDescription = null;
        }
    
        // Returns a text description of this object.
        string ToString ()
        {
            if (fullDescription == null)
            {
                if (description == null || isExtensionListInDescription ())
                {
                    ;
                }
                else
                    fullDescription = description;
            }
            return fullDescription;
        }
    
        void SortBy (string textFilter)
        {
        }
    
        void setDescription (string aDescription)
        {
            description = aDescription;
            fullDescription = null;
        }
    
        void UseExtensionListDescriptions (bool b)
        {
             useExtensionsInDescription = b;
             fullDescription = null;
        }
    
        /** This function does something that I didn't document because I was an amateur.
         */
        bool IsUsingExtensionListDescriptions ()
        {
             return useExtensionsInDescription;
        }
    }
}
