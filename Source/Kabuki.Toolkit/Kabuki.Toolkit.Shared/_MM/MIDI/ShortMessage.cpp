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

#include "../global.h"

#include "ShortMessage.h"

#include "MIDI.h"
#include "Port.h"


using namespace MIDI;


ShortMessage::ShortMessage(word32_t initTimeStamp):
    theMessage(0),
    messageNoStatus(0)
{
    setTimeStamp(initTimeStamp);
}


ShortMessage::ShortMessage(word32_t message, word32_t initTimeStamp):
    theMessage(message)
{
    byte_t byte1 = dataByte1();
    byte_t byte2 = dataByte2();

    messageNoStatus = pack(byte1, byte2);

    setTimeStamp(initTimeStamp);
}



ShortMessage::ShortMessage(byte_t statusByte, byte_t dataByte1, byte_t dataByte2, word32_t initTimeStamp)
{
    setMessage(statusByte, dataByte1, dataByte2);
    messageNoStatus = pack(dataByte1, dataByte2);

    setTimeStamp(initTimeStamp);
}



ShortMessage::ShortMessage(byte_t commandByte, byte_t channelByte, byte_t dataByte1, byte_t dataByte2, word32_t TimeStamp)
{
    setMessage(commandByte, channelByte, dataByte1, dataByte2);
    messageNoStatus = pack(dataByte1, dataByte2);

    setTimeStamp(TimeStamp);
}





word32_t ShortMessage::length() const
{
    return LENGTH;
}












const byte_t *ShortMessage::message() const
{
    return reinterpret_cast<const byte_t *>(&theMessage);
}



byte_t ShortMessage::status() const
{
    byte_t statusByte;
    byte_t dummyVar;

    unpack(theMessage, statusByte, dummyVar, dummyVar);

    return statusByte;
}



byte_t ShortMessage::channel() const
{
    byte_t channelByte;
    byte_t dummyVar;

    unpack(theMessage, dummyVar, channelByte, dummyVar, dummyVar);

    return channelByte;
}



byte_t ShortMessage::command() const
{
    byte_t commandByte;
    byte_t dummyVar;

    unpack(theMessage, commandByte, dummyVar, dummyVar, dummyVar);

    return commandByte;
}



byte_t ShortMessage::dataByte1() const
{
    byte_t dataByte1;
    byte_t dummyVar;

    unpack(theMessage, dummyVar, dummyVar, dataByte1, dummyVar);

    return dataByte1;
}



byte_t ShortMessage::dataByte2() const
{
    byte_t dataByte2;
    byte_t dummyVar;

    unpack(theMessage, dummyVar, dummyVar, dummyVar, dataByte2);

    return dataByte2;
}



void ShortMessage::setMessage(byte_t Status, byte_t dataByte1, byte_t dataByte2)
{
    theMessage = pack(Status, dataByte1, dataByte2);
    messageNoStatus = pack(dataByte1, dataByte2);
}



void ShortMessage::setMessage(byte_t commandByte, byte_t channelByte, byte_t dataByte1, byte_t dataByte2)
{
    theMessage = pack(commandByte, channelByte, dataByte1, dataByte2);
    messageNoStatus = pack(dataByte1, dataByte2);
}



word32_t ShortMessage::pack(byte_t dataByte1, byte_t dataByte2)
{
    word32_t thisMessage = dataByte1;
    thisMessage |= dataByte2 << MIDI::SHORT_MSG_SHIFT;

    return thisMessage;
}



word32_t ShortMessage::pack(byte_t Status, byte_t dataByte1, byte_t dataByte2)
{
    word32_t thisMessage = Status;
    thisMessage |= dataByte1 << MIDI::SHORT_MSG_SHIFT;
    thisMessage |= dataByte2 << MIDI::SHORT_MSG_SHIFT * 2;

    return thisMessage;
}



word32_t ShortMessage::pack(byte_t commandByte, byte_t channelByte, byte_t dataByte1, byte_t dataByte2)
{
    word32_t thisMessage = commandByte | channelByte;
    thisMessage |= dataByte1 << MIDI::SHORT_MSG_SHIFT;
    thisMessage |= dataByte2 << MIDI::SHORT_MSG_SHIFT * 2;

    return thisMessage;
}



void ShortMessage::unpack(word32_t thisMessage, byte_t &statusByte, byte_t &dataByte1, byte_t &dataByte2)
{
    statusByte = static_cast <byte_t> (thisMessage);
    dataByte1  = static_cast <byte_t> (thisMessage >> MIDI::SHORT_MSG_SHIFT);
    dataByte2  = static_cast <byte_t> (thisMessage >> MIDI::SHORT_MSG_SHIFT * 2);
}



void ShortMessage::unpack(word32_t thisMessage, byte_t &commandByte, byte_t &channelByte, byte_t &dataByte1, byte_t &dataByte2)
{
    commandByte = static_cast <byte_t> (thisMessage & ~MIDI::SHORT_MSG_MASK);
    channelByte = static_cast <byte_t> (thisMessage &  MIDI::SHORT_MSG_MASK);
    dataByte1   = static_cast <byte_t> (thisMessage >> MIDI::SHORT_MSG_SHIFT);
    dataByte2   = static_cast <byte_t> (thisMessage >> MIDI::SHORT_MSG_SHIFT * 2);
}
