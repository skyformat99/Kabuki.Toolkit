/*! C-HAL - C/C++ Handy Application Libraries \version 0.4.1
 *
 * This is free software distributed under the LGPL v3 license.
 * Lincense information can be found at http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * \file      global.h
 * \author    Chal J. McCollough
 * \copyright This code is the intillectual property of Blue Storm Engineering © 2011
 */



#ifndef __C_HAL__Text__String__dot_h__
#define __C_HAL__Text__String__dot_h__
//
#include "Text.cpp"

namespace Text
{
class String: public Text
{
    String(char *initText); //!< Default constructor
    ~String();              //!< Destructor.

 public:

   bool comparedTo(const char *thatString); /*!< Compares this String to thatString and returns true if they are identical.
                                                 \param thatString The string to compare this String to */
   bool comparedTo(String* thatString);     /*!< Compares this String to thatString and returns true if they are identical.
                                                 \param thatString The string to compare this String to */

   void reset();                            //!< Resets this String to a blank string.
   void reset(char* newText);               //!< Resets this String to a the newText.
   void reset(String* newText);             //!< Resets this String to a the newText.

   int length();                                //!< Returns the length of this String.
   int numChars(char thisChar);

   char charAt(int thisIndex);                  //!< Returns the char at thisIndex.
   void setChar(int thisIndex, char newChar);  //!< Sets the char at thisIndex to the newChar.

   char* to_char_array();

   String* concat(char* concatText);
   String* concat(String* concatText);

   String* remove(int thisChar);
   String* remove(int startChar, int endChar);
   String* stripBefore(char thisChar);

   String* substring(int startChar, int endChar);

   int lastIndexOf(char thisChar);
   //String_Buffer* Buffer_text();
   //String_Buffer* Buffer_text(unsigned int bufferSize);
};
};
#endif
