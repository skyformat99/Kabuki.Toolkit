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


#include "LongMessage.h"

using namespace MIDI;


LongMessage::LongMessage(const char *message, word32_t length):
    messageData(0),
    messageLength(0)
{
    setMessage(message, length);
}



LongMessage::LongMessage(const LongMessage &message)
{
    messageData = 0;
    messageLength = 0;

    *this = message;
}



LongMessage::~LongMessage()
{
    if(messageData != NULL) // Release resources for this object if they exist
        delete [] messageData;
}



LongMessage &LongMessage::operator = (const LongMessage &copyObject)
{
    if(this != &copyObject)  // Test for self assignment
        setMessage(copyObject.messageData, copyObject.messageLength);

    return *this;

}

word32_t LongMessage::length() const
{
    return messageLength;
}



char *LongMessage::message()
{
    return messageData;
}



void LongMessage::setMessage(const char *message, word32_t length)
{

    if(messageData != NULL) // Release old LongMessage if it exists
        delete [] messageData;

 // Allocate and initialize new LongMessage

    messageData = new char[length];
    messageLength = length;

    for(uint i = 0; i < messageLength; ++i)
        messageData[i] = message[i];
}



char &LongMessage::operator [] (int index)
{
    // Warning!!! No bounds checking is being performed!
    return messageData[index];
}
