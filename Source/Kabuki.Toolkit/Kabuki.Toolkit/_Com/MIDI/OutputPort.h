/*! Symmetry Station \version 0.2.0
 *
 * \file      OutputPort.h
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */


#ifndef MIDI_OUT_DEVICE_H
#define MIDI_OUT_DEVICE_H

#include <windows.h>

#include "../../global.h"
#include "Message.h"

#include "Port.h"

//#include "stdafx.h" // Necessary for Win data types
//#include <mmsystem.h>



namespace Win
{
    namespace MIDI
    {

    /*! \class OutputPort
        \brief A MIDI output port on a Win
 *************************************
 *  Class Dependencies
 ************************************/
//! **** End class dependencies ****




class OutputPort: public Port
{
  public:

    OutputPort();                                                  //!< Constructor opens port in closed state
    OutputPort(UINT deviceId);                                     //!< Constructor opens port in closed state

    ~OutputPort();                                                 //!< Destructor

    void open(UINT deviceId);                                      //!< Opens the MIDI output device
    void close();                                                  //!< Closes the MIDI output device
    bool sendMessage(DWORD message);                               //!< Sends short message
    bool sendMessage(LPSTR message, DWORD length);                 //!< Sends long message
    bool isOpen() const;                                           //!< Returns true if the device is open
    UINT getDeviceID(MMRESULT &result);                            //!< Gets the Id for this device
    static UINT getNumDevices();                                   //!< Gets the number of MIDI output devices on this system

    static void getCapabilities(UINT deviceId, MIDIOUTCAPS &caps); //!< Gets the capabilities of a particular MIDI output device.
                                                                   /*!<  Stores the results are stored in the caps struct. */
  private:

    OutputPort(const OutputPort &);                                //!< Copy and assignment are not allowed
    OutputPort &operator = (const OutputPort &);                   //!< Copy and assignment are not allowed

    bool createEvent();                                            //!< Creates an event for signalling the header thread

    static void CALLBACK MidiOutProc(HMIDIOUT midiOut, UINT msg, DWORD_PTR instance,
                                     DWORD_PTR param1,
                                     DWORD_PTR param2);            //!< Called by Win when a MIDI output event occurs
                                                                    /*!< \param midiOut The blah blah blah.
                                                                        \param msg      The message.
                                                                        \param instance A pointer to the actual message.
                                                                        \param param1   The status byte.
                                                                        \param param2   The data byte. */

    static DWORD WINAPI HeaderProc(LPVOID parameter);              //!< Thread function for managing headers
                                                                   /*!< \param parameter Just what is an LPVOID struct anyways? */

    HMIDIOUT       deviceHandle;                                   //!< The windows device handle to the OutputPort.
    HANDLE         eventHandle;                                    //!< A handle to the event being???
    CWinThread    *workerThread;                                   //!< The thread this port uses.
    Message::OutputHeader::Queue   headerQueue;                                    //!< The static queue.

    enum State { CLOSED, OPENED } currentState;                    //!< The two possible states of this port and this Port's currentState.
};
    }
}


#endif
