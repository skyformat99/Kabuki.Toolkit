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
//
#ifndef C_HAL_TEXT_TEXT_CLASS
#define C_HAL_TEXT_TEXT_CLASS
//
namespace Text
{//
    class Text
    {//This Text class is a data structure to store the language type
     //and the Text format(i.e. ASCII, Unicode, Compressed, ect).
	
      public:
    //  
      Text()
      {//If there are no declaired variables the they are set to a blank space.
         text_language = ' ';
         text_format = ' ';
      }
      Text(char language, char format)
      {//If there are declared variables then this is were the are set.
         text_language = language;
         text_format = format;
      }//
    //This following method returns the text_language code
      char Language()
      {  return text_language;
      }
    //This following method returns the text_format code
      char Format()
      {  return text_format;
      }//
     private:
       char text_language;
       char text_format;
   };
};
#endif