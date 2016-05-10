/*! Symmetry Station \version 0.2.0
 *
 * \file      InputPort.h
 * \author    Chal J. McCollough
 * \copyright This code is the intellectual property of Blue Storm Engineering. © 2012 ®
 */


#ifndef __Win__MIDI__InputDevice__h__
#define __Win__MIDI__InputDevice__h__

namespace Win
{
    namespace MIDI
    {
/*!
 *  \class   InputDevice
 *  \brief   This class represents MIDI input devices.
 *  \details Write me!
 *************************************
 *  Class Dependencies
 ************************************/
#include <windows.h>
#include <WinDef.h>
//#include "afxwin.h" // For CWinThread but doesn't work with this compiler!!!

    class ReceivesMidiInput;

    namespace Message
    {
        class InputHeader
        {
          public:
            class Queue;
        };
    }

//! **** End class dependencies ****

class InputPort
{
  public:

    InputPort();                                                  //!< Constructor initializes in an closed state.
    InputPort(InputDevice &theInputDevice);                       //!< Constructor initializes port in closed state and initializes the InputDevice.
    InputPort(UINT deviceID, InputDevice &theInputDevice);        //!< Constructor initializes port in opened state.

    ~InputPort();                                                 //!< Destructor!

    void open(UINT deviceId);                                     //!< Opens the MIDI input device.
    void close();                                                 //!< Closes the MIDI input device.

    void addSysExBuffer(LPSTR buffer, DWORD bufferLength);        //!< Adds a buffer to receive SysEx messages.

    void startRecording();                                        //!< Starts the recording process.
    void stopRecording();                                         //!< Stops the recording process.

    InputDevice *setReceiver(InputDevice &theInputDevice);        //!< Sets the current MIDI receiver. Returns the previous receiver.
    bool isOpen() const;                                          //!< Returns true if the device is open.
    bool isRecording() const;                                     //!< Returns true if the device is recording.

    UINT getDeviceID() const;                                     //!< Gets Id for this device.
    static UINT getNumDevices();                                  //!< Gets the number of MIDI input devices on this system.
    static void getCapabilities(UINT deviceId, MIDIINCAPS &caps); //!< Gets the capabilities of a particular MIDI input device The results are stored in the MIDIINCAPS parameter.

  private:

    InputPort(const InputPort &);                                 //!< Copy and assignment operators are not allowed.
    InputPort &operator = (const InputPort &);                    //!< Copy and assignment operators are not allowed.

    bool createEvent();                                           //!< Creates an event for signalling the header thread.

    static void CALLBACK MidiInProc(HMIDIIN MidiIn, UINT msg, DWORD_PTR Instance, DWORD_PTR param1, DWORD_PTR param2);
                                                                  //!< Called by Win when a MIDI input event occurs.

    static DWORD WINAPI HeaderProc(LPVOID parameter);             //!< Thread function for managing headers

    HMIDIIN       deviceHandle;                                   //!< The MIDIIN deviceHandle.
    HANDLE        messageEvent;                                   //!< The handle for the messageEvent.
    CWinThread   *messageThread;                                  //!< The windows thread for this port.
    InputDevice *InputDevice;                                     //!< The InputDevice for this this port.

    Message::InputHeader::Queue messageQueue;                     //!< The MIDI message queue.

    enum State { OPENED, CLOSED, RECORDING }  currentState;       //!< The two possible states of this port and this Port's currentState.

};
    }
}

#endif // __Win__MIDI_InputDevice__h__
