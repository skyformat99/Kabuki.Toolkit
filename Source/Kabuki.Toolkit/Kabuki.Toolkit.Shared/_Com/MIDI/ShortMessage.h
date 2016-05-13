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


#ifndef __MIDI__ShortMessage__dot_h__
#define __MIDI__ShortMessage__dot_h__

#include "../../../C-HAL/global.h"


namespace MIDI
{
/*! \class   ShortMessage
 *  \brief   Represents a short MIDI message.
 *  \details Write me!
 *************************************
 *  Class Dependencies
 ************************************/
}
#include "Message.h"

namespace MIDI
{
    class Port;
//<----- End class dependencies ----->

class ShortMessage: public Message
{
  public:

    explicit ShortMessage(word32_t TimeStamp = 0);
    ShortMessage(word32_t Msg, word32_t TimeStamp = 0);
    ShortMessage(byte_t Status, byte_t Data1, byte_t Data2, word32_t TimeStamp);
    ShortMessage(byte_t Command, byte_t Channel, byte_t Data1, byte_t Data2, word32_t TimeStamp);

//    void send(Port &thisDevice); //!< Sends this Message out thisDevice.
//    void SendMsgNoStatus(midi::CMIDIOutDevice &OutDevice); //!< Sends message without status byte_t

    word32_t length() const;

    const byte_t *message() const;
    byte_t status() const;
    byte_t channel() const;
    byte_t command() const;
    byte_t dataByte1() const;
    byte_t dataByte2() const;

    void setMessage(byte_t statusbyte_t, byte_t databyte_t1, byte_t databyte_t2);
    void setMessage(byte_t commandbyte_t, byte_t channelbyte_t, byte_t databyte_t1, byte_t databyte_t2);

    static word32_t pack(byte_t databyte_t1, byte_t databyte_t2);                                     //!< Packs a short messages without status byte_t.
    static word32_t pack(byte_t statusbyte_t, byte_t databyte_t1, byte_t databyte_t2);                    //!< Packs a short messages with status byte_t.
    static word32_t pack(byte_t commandbyte_t, byte_t channelbyte_t, byte_t databyte_t1, byte_t databyte_t2); //!< Packs a short messages on a given channel.

    static void unpack(word32_t thisMessage, byte_t &statusbyte_t, byte_t &databyte_t1, byte_t &databyte_t2);                    //!< Unpacks thisMessage
    static void unpack(word32_t thisMessage, byte_t &commandbyte_t, byte_t &channebyte_t, byte_t &databyte_t1, byte_t &databyte_t2); //!< Unpacks thisMessage

    static const word32_t LENGTH = 3;

  private:

    word32_t theMessage;
    word32_t messageNoStatus;
};

}


#endif // __MIDI__ShortMessage__dot_h__
