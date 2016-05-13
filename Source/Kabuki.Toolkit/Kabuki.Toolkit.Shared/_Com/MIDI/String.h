/* C-HAL - C/C++ Handy Application Libraries \version 0.4.0
 *
 * This is free software distributed under the LGPL v3 license.
 * Lincense information can be found at http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * \file   C_HAL_Numbers.h
 * \date   5/1/2011
 * \author Chal J. McCollough
 * \author This code is the intillectual property of The People of the Planet Earth © 2011
 */

#pragma once

namespace BlueStorm
{
namespace MIDI
{

/* \class   String
    \brief   This class represents a String that can be displayed on a standard MIDI complaitble device.
    \details This class contains a few usingant static functions for verifiying if a String is valid.
 *************************************
 *  Class Dependencies
 ************************************/
#ifndef NULL
#define NULL 0
#endif//NULL
// **** End class dependencies ****


class String
{
  public:

    String(const char * initString=NULL);         //< Default constructor.

    ~String();                                    //< Destructor.

    void copy(String *thisString);                //< Deep copies the state of thisString.

    char *text();                                 //< The text of this String.
    int setText(const char newName[]);            //< Renames this control to the newName.
                                                  /*< \pre   String::isValid(newString) must be true.
                                                      \param newName The new nameText string.         */

    void forceText(char *newName);                //< Renames this control to newName without error checking.
                                                  /*< \param   newName The new name for this String.
                                                      \warning Does not perform error checking! */

    bool compairedTo(String *thatString);         //< Compaires this String to thatString and returns true if they are identical(before the NULL term char).
    bool compairedTo(char *thatString) const;     //< Compaires this String to thatString and returns true if they are identical(before the NULL term char).

    static char *format(const char *thisString);  //< Formats thisString to remove any invalid charictors.
                                                  /*< \param newName The text string to be formatted.
                                                      \return Returns a new instance of the formatted string */

    static bool isValid(const char thisChar);     //< Checks to see if thisChar is a valid String char.
                                                  /*< \param  thisChar The char to check the validity of. */

    static bool isValid(const char *thisString);   //< Checks to see if thisString is a valid String
                                                  /*< \pre    thisString must be initialized
                                                      \return Returns true thisString if every char in thisString isValid.
                                                      \param  thisName The String to check the validity of. */

    static const int defaultLength = 16;            //< The maximum length of a String.

    char *toString();                             //< Returns a string representation of this object.

  private:

    char *stringText;                              //< The text of this String.
};
}
}
