/*******************************************************************************
    Copyright 2005 Blue Inspiration Technologies. All Rights Reserved.
    chal_jamison@yahoo.com
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*******************************************************************************/

#ifndef GNU_COM_Version_1_Text_String
#define GNU_COM_Version_1_Text_String
//
#include "Text.cpp"
//
//#ifndef Text_String_Buffer_Interface
//#include "Text_String_Buffer.cpp"
//#endif
//
namespace Text
{//
   class String:
      public Text
   {//
      public:
    // 
      virtual bool equals(char* compairString);
      virtual bool equals(String* compairString);
    //  
      virtual void reset();
      virtual void reset(char* newText);
      virtual void reset(String* newText);
    //  
      virtual unsigned int length();
      virtual unsigned int num_chars();
      virtual unsigned int num_chars(char thisChar);
    //  
      virtual char char_at(int thisIndex);
      virtual void set_char(int thisIndex, char newChar);
    //  
      virtual char* to_char_array();
    //
      virtual String* concat(char* concatText);
      virtual String* concat(String* concatText);
    //
      virtual String* remove(int thisChar);
      virtual String* remove(int startChar, int endChar);
      virtual String* stripBefore(char thisChar);
    //  
      virtual String* substring(int startChar, int endChar);
    //  
      virtual int lastIndexOf(char thisChar);
    //  virtual String_Buffer* Buffer_text();
    //  virtual String_Buffer* Buffer_text(unsigned int bufferSize);
   };
};
#endif
