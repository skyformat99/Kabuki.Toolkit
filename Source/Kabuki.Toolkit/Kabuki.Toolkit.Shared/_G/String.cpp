/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/String.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    class String : Rectangle<_2D.Point_i_i>
    {  
        const _G.Colour DefaultTextColour = _G.Colour.black;

        const string DefaultFontName =  "Times New Roman";

        const int DefaultFontSize = 12,
            DefalutFontStyle = Font.Plain;

        const Font DefaultFont = new Font (DefaultFontName, DefalutFontStyle, DefaultFontSize);
     
        /**  */
        String ()
        {
            fontSize = DefaultFontSize;
            fontStyle = DefalutFontStyle;
            fontWidth = 6;
            fontHeight = 15;
            numCharictors = 0;

            fontName = DefaultFontName;
            colour = DefaultTextColour;
            font = DefaultFont;
        }
    
        String (int leftEdge, int bottomEdge)
        {
            base (leftEdge, bottomEdge, 0, 0);
        }

        /**  */
        String (int leftEdge, int bottomEdge, string initText)
        {
            base (leftEdge, bottomEdge, 0, 0);
            text = initText;
            numCharictors = text.numChars ();
        }

        /**  */
        String (int leftEdge, int bottomEdge, string initText, int initFontSize)
        {
            base (leftEdge, bottomEdge, 0, 0);
            fontSize = initFontSize;
            text = initText;
            numCharictors = text.numChars ();
        }

        /**  */
        String (int leftEdge, int bottomEdge, string initText, _G.Colour_i initTextColour)
        {
            base (leftEdge, bottomEdge, 0, 0);
            text = initText;
            colour = initTextColour;
            numCharictors = text.numChars ();
        }

        /**  */
        String (int leftEdge, int bottomEdge, string initText, _G.Colour_i initTextColour, int initFontSize)
        {
            base (leftEdge, bottomEdge, 0, 0);
            text = initText;
            numCharictors = text.numChars ();
            colour = initTextColour;
            fontSize = initFontSize;
        }

        /**  */
        void AddText (string newString)
        {
            text.concat (newString);
            numCharictors = text.numChars ();
            SetWidth (text.numChars ()  fontWidth);
        }

        /**  */
        string AddTextOverflow (string newString)
        {
            int newTextWidth = newString.numChars ()  fontWidth;
            if (newTextWidth + Width > MaxWidth ())
            {
                int difference = newTextWidth+Width -MaxWidth (),
                overflowIndex = (newTextWidth-Width)/fontWidth;
                addText (text.SubText (0,overflowIndex));
                return newString.SubText (overflowIndex,newString.numChars ());
            }
            AddText (newString);
            numCharictors = text.numChars ();
            return new string ();
        }

        /**  */
        bool InsertText (string newString, int here)
        {
            if (newString.numChars ()fontWidth > MaxWidth ())
                return false;
            text = text.SubText (0, here).concat (text.SubText (here+1, text.numChars ()));
            numCharictors = text.numChars ();
            return true;
        }    

        /**  */
        void removeCharAtIndex (int index1)
        {
            text = text.SubText (0,index1-1).concat (text.SubText (index1,text.numChars ()));
            numCharictors = text.numChars ();
        }

        /**  */
        void removeTextAtIndex (int index1, int index2)
        {
            text = text.SubText (0,index1).concat (text.SubText (index2,text.numChars ()));
            numCharictors = text.numChars ();
        }  

        /**  */
        void setFont (string newFontName)
        {
            fontName = newFontName;
            font = new Font (fontName, fontStyle, fontSize);
        }  

        /**  */
        void setFont (Font newFont)
        {
            if (newFont==null)
            {
                fontName = newFont.Name;
                fontSize = newFont.Size ();
            }
        }  

        /**  */
        void setFontSyle (int newStyle)
        {
            fontStyle = newStyle;
            font = new Font (fontName, fontStyle, fontSize);
        }  

        /**  */
        int fontSize ()
        {
            return fontSize;
        }

        void setFontSize (int newSize)
        {
            fontSize = newSize;
            font = new Font (fontName, fontStyle, fontSize);
        }

        /**  */
        Colour defaultColour ()
        {
            return DefaultTextColour;
        }

        /**  */
        void setFontColour (Colour newColour)
        {
            colour = newColour;
        }  

        /**  */
        string string
        {
            get { return text; }
            set { text = value; }
        }

        /**  */
        void Update ()
        {  
        }

        /**  */
        void UpdateHeight ()
        {
            Char currentChar;
            Iterator iteration = charictors.iterator ();
            while (iteration.IsNotDone ())
            {
                currentChar = (Char) iteration.nextObject ();
                int newHeight = currentChar.fontSizefontHeight;
                if (newHeight > Height)
                    SetHeight (newHeight);
            }  
        }
        int Length ()
        {
            return numCharictors;
        }
        void Draw (ScreenBuffer screenBuffer)
        {
            if (text == null)
                return;
            screenBuffer.setPixel (0,0, colour);
        }
    
        int fontSize,
            fontStyle,
            fontWidth,
            fontHeight,
            numCharictor;
                    
        string fontName;
    
        Colour colour = DefaultTextColour;
        Font font = DefaultFont;
    }
}
