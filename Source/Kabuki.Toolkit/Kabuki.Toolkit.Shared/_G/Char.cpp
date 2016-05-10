/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/Char.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    struct Char
    {  
        /**  */
        Char ()
        {  
            fontName = new string ("Times New Roman");

            charictor;
    
            fontSize = 12,
            fontStyle = _G.Font.Plain,
            xIncrease = fontSize/2;
    
            font = new Font (fontName, fontStyle, fontSize);
    
        Colour colour = Colour.Black;
        }      
    
        void Draw (ScreenBuffer screenBuffer)
        {
            font.Draw (screenBuffer, charictor, -font.Height (charictor), -font.Width (charictor));
        }
    
        string ToString ()
        {
            return new string (charictor);
        }

        string fontName = new string ("Times New Roman");

        char charictor;
    
        int fontSize = 12,
            fontStyle = Font.PlainText,
            xIncrease = fontSize/2;
    
        Font font = new Font (fontName, fontStyle, fontSize);
    
        Colour colour = Colour.Black;
    }
}
