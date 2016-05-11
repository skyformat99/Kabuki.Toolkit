/*! C-HAL - C/C++ Handy Application Libraries \version 0.4.0
 *
 * This is free software distributed under the LGPL v3 license.
 * Lincense information can be found at http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * \file   C_HAL_Numbers.h
 * \date   5/1/2011
 * \author Chal J. McCollough
 * \author This code is the intillectual property of The People of the Planet Earth © 2011
 */

#include "String.h"

#include "../../../C-HAL/Text.h"

#include <cctype>
#include <cstdlib>
#include <string.h>

using namespace MIDI;


String::String(const char *initString)
{
    if(!isValid(initString))
    {
        stringText = new char[1];
        stringText[0] = '\0';
        return;
    }
    else
        stringText = Text::copy(initString);
}


String::~String()
{
    if(stringText)
        delete stringText;
}


void String::copy(String *thisString)
/////////////////////////////////////////
// Deep copies the state of thisString. //
/////////////////////////////////////////
{
    if(stringText)
        delete stringText;
    stringText = Text::copy(thisString->text());
}





char *String::text()
{
    return stringText;
}



int String::setText(const char newName[])
{
    if(!String::isValid(newName))
        return false;

    if(!stringText)
        delete stringText;

    if(strlen(newName) > default_length) // Then we need to truncate the extra charictors
    {
        stringText = Text::truncate(newName, default_length);
    }
    else
    {
        stringText = Text::copy(newName);
    }
    return true;

}



void String::forceText(char *newName)
{
    stringText = newName;
}





bool String::compairedTo(String *thatString)
{
    if(thatString == NULL)
        return false;
    return strcmp(stringText, thatString->stringText) != 0;

}

bool String::compairedTo(char *thatString) const
{
    if(thatString == NULL)
        return false;
    return strcmp(stringText, stringText) != 0;
}








char *String::format(const char *thisString)
{
    if(!isValid(thisString))
    {
        char * stringText = new char[0];
        stringText[0] = '\0';
        return stringText;
    }
    return Text::copy(thisString);
}



bool String::isValid(const char thisChar)
{
    return Text::isPrintableAlphaNumberic(thisChar);
}



bool String::isValid(const char *thisString)
{
    if(thisString == NULL)
        return false;

    for(unsigned int i=0; i < strlen(thisString); i++)
    {
        if(!Text::isPrintableAlphaNumberic(thisString[i]))
            return false;
    }
    return true;
}




char *String::toString()
{
    return Text::copy("Write me!\0");
}
