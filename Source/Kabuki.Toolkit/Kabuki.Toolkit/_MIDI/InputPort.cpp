/*! Symmetry Station \version 0.2.0
 *
 * \file      ~/Win/MIDI/InputPort.cpp
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */

#include "InputPort.h"
#include "InputDevice.h"

#include "Message.h"

using namespace Win::MIDI;




//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////                              ///////////////////
/////////////////   Win::MIDI::InputPort   ///////////////////
/////////////////     Class Implementation     ///////////////////
/////////////////                              ///////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////




InputPort::InputPort():
    InputDevice(0),
    currentState(CLOSED)
/////////////////////////////////////////////////////////////////
// This constructor initializes this object in an closed state //
/////////////////////////////////////////////////////////////////
{
    if(!createEvent()) // then the system was unable to create signalling event
    {
        // so do something...
    }
}



InputPort::InputPort(InputDevice &theInputDevice)
//////////////////////////////////////////////////////////////////////////////////////////
// Constructor initializes port in a closed state and initializes the MIDI InputDevice. //
//////////////////////////////////////////////////////////////////////////////////////////
   :InputDevice(&theInputDevice),
    currentState(CLOSED)
{
    if(!CreateEvent()) // then the system was to create signalling event
    {
        // so do something...
    }
}



InputPort::InputPort(uint deviceID, InputDevice &theInputDevice) :
    InputDevice(&theInputDevice),
    currentState(CLOSED)
///////////////////////////////////////////////////////////
//  Constructor initializes this port in an opened state  //
///////////////////////////////////////////////////////////

{
    open(deviceID);


    if(!createEvent()) // unable to create signalling event
    {
        close();//the port

        // and do something else...
    }
}



InputPort::~InputPort()
/////////////////
// Destructor. //
/////////////////
{
    close();//all of the MIDI ports and...
    ::CloseHandle(messageEvent); // close the handle to the signalling event.
}



















void InputPort::open(uint deviceID)
/////////////////////
// Opens the port. //
/////////////////////
{
    close(); // Makes sure the previous device, if any, is closed before opening another one.

    // Open MIDI input device
    MMRESULT result = ::midiInOpen(&deviceHandle, deviceID,
                                   reinterpret_cast<DWORD>(MidiInProc),
                                   reinterpret_cast<DWORD>(this),
                                   CALLBACK_FUNCTION);

    if(result == MMSYSERR_NOERROR) // then we are able to open the device, change state so...
         currentState = OPENED;    // set the portState to open.
    else
    {   // There was an error opening the port...
        // so do something about it damn it!
    }
}



void InputPort::close()
//////////////////////
// Closes the port. //
//////////////////////
{

    if( currentState == RECORDING) // If the device is recording then...
        stopRecording();           // stop recording before closing the device


    if( currentState == OPENED) // then the device is opened so...
    {
        MMRESULT result = ::midiInClose(deviceHandle); // attempt to close the device and...

        if(result != MMSYSERR_NOERROR) // then a failure occured...
        {
            // freak the fuck out and pray to god for our souls!!!
        }

        currentState = CLOSED; // If you don't know what this line of code does, you have no business reading this ;-)
    }
}



void InputPort::addSysExBuffer(LPSTR buffer, DWORD bufferLength)
/////////////////////////////////////////////////
// Adds a buffer for receiving SysEx messages. //
/////////////////////////////////////////////////
{

    // To do: put in some error checking here.

    Message::InputHeader *header = new InputHeader(deviceHandle, buffer, bufferLength);;

    try
    {
        header->addSysExBuffer(); // Add header to the InputHeader
        messageQueue.addHeader(header);
    }
    catch(const InputPort &)
    {
        delete header; // unable to add the buffer to the queue
        throw;
    }
}



void InputPort::startRecording()
///////////////////////////////////
// Starts the recording process. //
///////////////////////////////////
{

    // Only begin recording if the MIDI input device has been opened
    if( currentState == OPENED)
    { 
        // Change state
         currentState = RECORDING;

        messageThread = ::AfxBeginThread((AFX_THREADPROC)HeaderProc, this);

        // Start recording
        MMRESULT Result = ::midiInStart(deviceHandle);


        if(Result != MMSYSERR_NOERROR) // then recording attempt failed...
        {
             currentState = OPENED;   // Revert back to opened state

            ::SetEvent(messageEvent); // Signal the worker thread to finish

            ::WaitForSingleObject(messageThread->m_hThread, INFINITE);

            // And do something else.
        }
    }
}



void InputPort::stopRecording()
//////////////////////////////////
//  Stops the recording process //
//////////////////////////////////
{
    // If the device is in fact recording...
    if( currentState == RECORDING)
    {
        // Change state
         currentState = OPENED;

        // Signal the worker thread to finish
        ::SetEvent(messageEvent);

        ::WaitForSingleObject(messageThread->m_hThread, INFINITE);

        // Reset the MIDI input device
        ::midiInReset(deviceHandle);

        // Empty header queue
        messageQueue.RemoveAll();
    }
}



ReceivesMidiInput *InputPort::setReceiver(InputDevice &InputDevice)
/////////////////////////////////////////////////////////////////////
// Registers the MIDI::Receiver and returns the previous receiver. //
/////////////////////////////////////////////////////////////////////
{
    InputDevice *PrevReceiver = InputDevice;

    InputDevice = &InputDevice;

    return PrevReceiver;
}



bool InputPort::isOpen() const
////////////////////////////////////////////////////
// Determines if the MIDI input device is opened. //
////////////////////////////////////////////////////
{

    return (( currentState == OPENED) || ( currentState == RECORDING));
}



bool InputPort::isRecording() const
///////////////////////////////////////////////////////
// Determines if the MIDI input device is recording. //
///////////////////////////////////////////////////////
{

    return ( currentState == RECORDING);
}



uint InputPort::getDeviceID() const
//////////////////////////////////
// Gets the ID for this device. //
//////////////////////////////////
{

    uint deviceID;
    MMRESULT result = ::midiInGetID(deviceHandle, &deviceID);

    if(result != MMSYSERR_NOERROR)
    {
        // so do something!
    }

    return deviceID;
}



static uint InputPort::getNumDevices()
////////////////////////////////////////////////////////////////////
// Gets the number of MIDI input devices attached to this system. //
////////////////////////////////////////////////////////////////////
{
    return midiInGetNumDevs();
}





void InputPort::getCapabilities(uint deviceID, MIDIINCAPS &caps)
//////////////////////////////////////////////////////////////
// Gets the capabilities of a particular MIDI input device. //
//////////////////////////////////////////////////////////////
{
    MMRESULT result = ::midiInGetDevCaps(deviceID, &caps, sizeof caps);

    if(result != MMSYSERR_NOERROR) // Then the system was unable to retrieve device capabilities
    {
        // so do something about it damn it!
    }
}




bool InputPort::createEvent()
//////////////////////////////////////////////////////////////////////
// This function creates an event for signalling the header thread. //
//////////////////////////////////////////////////////////////////////
{
    messageEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);

    if(messageEvent == NULL) // then event creation failed so...
        return false;

    return true;
}




void CALLBACK InputPort::MidiInProc(HMIDIIN midiIn, uint msg, DWORD_PTR instance, DWORD_PTR param1, DWORD_PTR param2)
////////////////////////////////////////////////////////////////////////////
// This is the function called by Win when a MIDI input event occurs. //
////////////////////////////////////////////////////////////////////////////
{
    InputPort *device = reinterpret_cast<InputPort *>(instance);

    if(device->ReceivesMidiInput != NULL)
    {
        switch(msg)
        {
            case MIM_DATA: // Short message received
            {
                device->ReceivesMidiInput->receiveMessage(param1, param2);
            }
            case MIM_ERROR: // Invalid short message received
            {
                device->ReceivesMidiInput->onError(param1, param2);
            }
            case MIM_LONGDATA: // SysEx message received
            {
                if(device-> currentState == RECORDING) // then retrieve data, send it to receiver,
                {
                    // and notify header thread that we are done with the SysEx message

                    MIDIHDR *midiHeader = reinterpret_cast<MIDIHDR *>(param1);
                    device->ReceivesMidiInput->receiveMessage(midiHeader->lpData, midiHeader->dwBytesRecorded, param2);
                    ::SetEvent(device->messageEvent);
                }
            }
            case MIM_LONGERROR: // Invalid SysEx message received
            {
                if(device-> currentState == RECORDING)
                {
                    // Retrieve data, send it to receiver, and notify header thread that we are done with the SysEx message
                    MIDIHDR *midiHeader = reinterpret_cast<MIDIHDR *>(param1);
                    device->ReceivesMidiInput->onError(midiHeader->lpData, midiHeader->dwBytesRecorded, param2);
                    ::SetEvent(device->messageEvent);
                }
            }
        }
    }
}




DWORD InputPort::HeaderProc(LPVOID parameter)
///////////////////////////
// Header worker thread. //
///////////////////////////
{
    InputPort *device = reinterpret_cast<InputPort *>(parameter);

    while(device-> currentState == RECORDING) // Continue while the MIDI input device is recording
    {
        ::WaitForSingleObject(device->messageEvent, INFINITE);

        // Make sure we are still recording
        if(device-> currentState == RECORDING)
        {
            // Remove the finished header
            device->messageQueue.removeHeader();
        }
    }

    return 0;
}
