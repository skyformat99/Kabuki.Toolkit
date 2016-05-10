/*  CHAL: Chal's Handy Application Libraries
    @file       ~/AI/Meaning.cs
    @date       May 29, 2015
    @author     Chal McCollough
    @copyright  Copyright (c) 2015 Blue Storm Engineering
    @license    http://opensource.org/licenses/MIT
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
    documentation files (the "Software"), to deal in the Software without restriction, including without limitation the 
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit 
    persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the 
    Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
    OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

    @brief      This file contains the AI.Meaning interface.
    @desc       This namespace is not mature, but will be used for creating a video game engine in the future.
*/
namespace CHAL
{

/* Interface that represents a string of Text in either ASCII, UTF-8, UTF-16, or UTF-32.
A Text object can be either ASCII or Unicode string.
*/
public interface Text
{
    /*.hal.text
    void Char[] text;
    */
    /*.hal.text.buffer
    String[] textArray;                                     //< An array of strings used to store                                     
    */
    
    public int length ();                                   //< Returns the length of the Text.
    
    public void reset ();                                   //< Resets the Text to a blank string. 
    public void reset (char newText[]);                     //< Resets the Text to the newText. 
    public void reset (Char newText[]);                     //< Resets the Text to the newText.
    public void reset (String newText);                     //< Resets the Text to the newText.
    public void reset (Text newText);                       //< Resets the Text to the newText.
    
    public Char charAt  (int thisIndex);                    //< Returns the char at thisIndex.
    public void setChar (int thisIndex, char newChar);      //< Sets the char at thisIndex to the newChar.
    public void setChar (int thisIndex, Char newChar);      //< Sets the char at thisIndex to the newChar.
    
    public int numChars (char thisChar);                    //< Returns the number of instances of thisChar.
    public int numChars (Char thisChar);                    //< Returns the number of instances of thisChar.
    
    public void setText (byte   newText[]);                 //< Sets the text to the newText.
    public void setText (char   newText[]);                 //< Sets the text to the newText.
    public void setText (Char   newText[]);                 //< Sets the text to the newText.
    public void setText (Text   newText);                   //< Sets the text to the newText.
    public void setText (String newText);                   //< Sets the text to the newText.
    
    public void append (char thisText[]);                   //< Appends thisText to the text; 
    public void append (Char thisText[]);                   //< 
    public void append (String thisText);                   //< 
    public void append (Text thisText);                     //< 

    public Text concat (String thisText);                   //< 
    public Text concat (char thisText[]);                   //< 
    public Text concat (Char thisText[]);                   //< 
    public Text concat (Text thisText);                     //< 
    
    public Text remove (int thisChar);                      //< 
    public Text remove (int startIndex, int endIndex);      //<
    
    public Text stripBefore (char thisIndex);               //< 
    
    public Text substring (int startIndex, int endIndex);   //< 
    
    public int lastIndexOf (char thisChar);                 //< 
    public int lastIndexOf (Char thisChar);                 //< 
    
    public bool equals (Text compairText);               //< 
    
    /* Compares this Text to thatText.
    @param  thatText The Text to compare this Text to.
    @return Returns 0 if the two strings are identical, 1 if this Text is higher order than thatText, and -1 if thatText is higher order than this Text.
    */
    public int compare (String thatText);                   //< 
    public int compare (char thisText[]);                   //< 
    public int compare (Char thisText[]);                   //< 

    public Text repeatString (int numTimes);                //<
    public Text repeatText   (int numTimes);                //< 

    public char language ();                                //< Returns the languages this text is in code
    
    public byte[] toASCIIArray ();                          //< 
    public byte[] toUTF8Array  ();                          //< 
    public char[] toUTF16Array ();                          //< 
    public int[]  toUTF32Array ();                          //< 
    
    void moveCurrsorLeft ();                                //< Moves the cursor to the left one increment.
    void moveCurrsorRight ();                               //< Moves the cursor to the right one increment.
    int  currsor ();                                        //< Returns the current cursor location.
    
    public Text toText       ();                            //< Returns a text representation of this object.
    public String toString   ();                            //< Returns a String representation of this object.
}
