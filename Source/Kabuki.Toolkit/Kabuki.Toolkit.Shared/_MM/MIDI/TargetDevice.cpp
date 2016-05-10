#ifndef TARGETDEVICE_H
#define TARGETDEVICE_H

#include "windows.h"

namespace BlueStorm
{
namespace MIDI
{

class TargetDevice
{
   public:

    virtual ~TargetDevice() {}
    virtual void receiveMessage(DWORD Msg, DWORD TimeStamp) = 0;                    // Receives short messages
    virtual void receiveMessage(LPSTR Msg, DWORD BytesRecorded, DWORD TimeStamp)=0; // Receives long messages
    virtual void onError(DWORD Msg, DWORD TimeStamp)=0;                             // Called when an invalid short message is received
    virtual void onError(LPSTR Msg, DWORD BytesRecorded, DWORD TimeStamp)=0;        // Called when an invalid long message is received
};
}
}

#endif // TARGETDEVICE_H
