/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G2D/TextArea.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Collections.Generic;

namespace _G2D
{
    /**  */
    class TextArea : Panel, Scrollable
    {
        /**  */
        TextArea (int leftEdge, int topEdge, int width, int height) :
            base (leftEdge, topEdge, width, height)
        {
            /// Nothing to do here! :-)
        }
   
        /**  */
        TextArea (int leftEdge, int topEdge, int width, int height, _G.Colour_i bgColor) :
            base (leftEdge, topEdge, width, height, bgColor)
        {
        }
   
        /**  */
        TextArea (int leftEdge, int topEdge, int width, int height, _G.Colour_i bgColor, Font initFont) :
            base (leftEdge, topEdge, width, height, bgColor)
        {      
            if (initFont != null)
                defaultTextFont = initFont;
            if (bgColor != null)
                defaultTextColor  = bgColor;
        }
   
        /**  */
        bool Add (Charictor newCharictor)
        {
            String selectedLine = text.Element (currsorY);
            if (selectedLine.Insert (newSymbol, cursorX))
            {  selectedLine.Insert (newSymbol, cursorX);
                return true;
            }
            return false;
        }
   
        /**  */
        bool Add (char newCharictor)
        {
            String selectedLine = text.Element (currsorY);

            if (selectedLine.Insert (newSymbol, cursorX))
            {
                selectedLine.Insert (newSymbol, cursorX);
                return true;
            }
            return false;
        }
   
        /**  */
        void Add (string newLine)
        {
            if (newLine == null) return;

            text.Add (new string ());
        }
   
        /**  */
        void Draw (_G2D.Cell g)
        {
            base.Draw (page);
      
            Iterator iteration = text.Iterator ();
            string currentLineOfText;
            while (iteration.isNotDone ())
            {  currentLineOfText = (string) iteration.nextObject ();
                currentLineOfText.Draw (screenBuffer);
            }  
        }
   
        /**  */
        string ToString ()
        {
            string textArray;
            int i = 0;
            string currentLineOfText;
            Iterator iteration = text.Iterator ();

            while (Iterator.Is_not_done ())
            {
                currentLineOfText = (string) iteration.nextobject ();
                textArray[i] = currentLineOfText;
                i++;
            }
        }

        int currsorX = 0, currsorY = 0, topLineIndex = 0;
        bool isAllOneText_Font;
        
        string text;
        _G.Colour_i defaultTextColor = _G.Colour_i.Black;
        Font defaultTextFont;
    }
}
