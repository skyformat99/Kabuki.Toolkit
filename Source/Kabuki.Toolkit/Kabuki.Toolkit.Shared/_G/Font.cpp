/** Underscore
    @file       /.../Kabuki.Toolkit/_G/Font.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _G
{
    /**  */
    class Font
    {
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /// public:
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        const int Plain = 0,
            Bold = 1,
            Italisized = 2,
            Underlined = 4;

        Font ()
        {
            name = "Times New Roman";
            attributes = Plain;
            size = 12;
            attributes = 0;
        }

        Font (string aName, int aSize, int theAttributes)
        {
            name = aName;
            size = aSize;
            attributes = theAttributes;
        }
    
        string Name
        {
            get { return name; }
            set { name = value; }
        }

        int Atributes
        {
            get { return attributes; }
            set { attributes = value; }
        }

        int Size
        {
            get { return size; }
            set { size = value; }
        }

        string ToString ()
        {
            switch (attributes)
            {
                case 0:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: None";
                case 1:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Bold";
                case 2:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Italisized";
                case 3:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Bold - Italisized";
                case 4:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Underlined";
                case 5:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Bold - Underlined";
                case 6:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Italisized - Underlined";
                case 7:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: Bold - Italisized - Underlined";
                default:
                    return "Font: \"" + name + "\" Size: " + size + " Attributes: None";
            }
        }

        ///------------------------------------------------------------------------------------------------------------
        /// private:
        ///------------------------------------------------------------------------------------------------------------
        
        string name;

        int size, 
            attributes; 
    }
}

