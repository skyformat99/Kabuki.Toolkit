/*! Symmetry Station \version 0.2.0
 *
 * \file      InputDevice.h
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */

#ifndef __Win__MIDI__InputDevice__dot_h__
#define __Win__MIDI__InputDevice__dot_h__


namespace Win {
    namespace MIDI {

/*! \class   InputDevice
 *  \brief   An abstract virtual class representing objects that receive messages from MIDI::Device objects.
 *  \details An object that recieves MIDI::Messages registers itself with a InputDevice object. It will then
 *           receive all messages that are recorded.
 *************************************
 *  Class Dependencies
 ************************************/
#include <windows.h>
//<----- End class dependencies ----->

class ReceivesMidiInput
{
    public:

    virtual ~ReceivesMidiInput();                                                       //!< Virtual destructor.

    virtual void receiveMessage(DWORD message, DWORD timeStamp) = 0;                    //!< Receives short messages.
    virtual void receiveMessage(LPSTR message, DWORD bytesRecorded, DWORD timeStamp)=0; //!< Receives long messages.
    virtual void onError(DWORD message, DWORD timeStamp) = 0;                           //!< Called when an invalid short message is received.
    virtual void onError(LPSTR message, DWORD BytesRecorded, DWORD timeStamp) = 0;      //!< Called when an invalid long message is received.
};

}   
}

#endif // __Win__MIDI__InputDevice__dot_h__
