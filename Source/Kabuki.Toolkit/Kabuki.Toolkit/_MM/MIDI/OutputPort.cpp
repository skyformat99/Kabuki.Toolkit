/*! Symmetry Station \version 0.2.0
 *
 * \file      ~/Win/MIDI/OutputPort.cpp
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */


#include "OutputPort.h"

#include "../../global.h"

#include <windows.h>


using namespace Win::MIDI;




OutputPort::OutputPort()
///////////////////////////////////////////////////////////
// Default constructor initializes port in CLOSED state. //
///////////////////////////////////////////////////////////
   :currentState(CLOSED)
{

    if(!CreateEvent()) // then unable to create signalling event...
    {
        // and do this
    }
}




OutputPort::OutputPort(UINT deviceID)
/////////////////////////////////////////////////////
// Constructor initializes object in CLOSED state. //
/////////////////////////////////////////////////////
   :currentState(CLOSED)
{
    open(deviceId);

    if(!CreateEvent()) // then unable to create signalling event...
    {
        close(); //so close the port and do something...
    }
}




OutputPort::~OutputPort()
{
    //! Destructor.

    close(); // this device.

    ::closeHandle(eventHandle); // and close the handle to the signalling event
}

















void OutputPort::open(UINT deviceID)
{
    //! opens the MIDI output device

    // Makes sure the previous device, if any, is CLOSED before opening another one
    close();

    // open MIDI output device
    MMRESULT Result = ::midiOutopen(&deviceHandle, deviceID,
                                 reinterpret_cast<DWORD>(MidiOutProc),
                                 reinterpret_cast<DWORD>(this),
                                 CALLBACK_FUNCTION);

    // If we are able to open the device, change state
    if(Result == MMSYSERR_NOERROR)
    {
        currentState = OPENED;
        workerThread = AfxBeginThread(reinterpret_cast<AFX_THREADPROC>(HeaderProc), this);
    }
    // Else opening failed, throw exception
    else
    {
        ::SetEvent(eventHandle);
        ::WaitForSingleObject(workerThread->m_hThread, INFINITE);

        throw CMIDIOutException(Result);
    }
}


// closes the MIDI output device
void OutputPort::close()
{
    // Only close an already OPENED device
    if(currentState == OPENED)
    {
        // Change state
        currentState = CLOSED;

        // Notify our worker thread and wait for it to finish
        ::SetEvent(eventHandle);
        ::WaitForSingleObject(workerThread->m_hThread, INFINITE);

        // Empty header queue - we're finished with the headers
        headerQueue.RemoveAll();

        // close the MIDI output device
        ::midiOutclose(deviceHandle);
    }
}



bool OutputPort::sendMessage(DWORD message)
//////////////////////////
// Sends short message. //
//////////////////////////
{
    if(currentState == OPENED)
    {
        MMRESULT result = ::midiOutShortMsg(deviceHandle, message);

        return (result != MMSYSERR_NOERROR); // Return true/false if there was an error.
    }
    return false;
}



bool OutputPort::sendMessage(LPSTR message, DWORD length)
{
    // Sends long message

    if(currentState == OPENED)
    {  
        Message::OutputHeader *newMessageHeader = new Message::OutputHeader(deviceHandle, message, length);;

        // Send SysEx data
        newMessageHeader->sendMessage();

        // Add header to queue
        headerQueue.enqueue(newMessageHeader);

        return true;
    }
    return false;
}



bool OutputPort::isopen() const
{
    return (currentState == OPENED);
}



UINT OutputPort::getDeviceID(MMRESULT &result)
{
    UINT deviceID;

    result = ::midiOutGetID(deviceHandle, &deviceID);

    return deviceID;
}


WORD getIDFromName(LPSTR lpszDesc)
{
    WORD id;
    char thisDesc[MAXPNAMELEN];
    WORD MaxDevs = midiOutGetNumDevs();

    for(id = 0; id < MaxDevs; id++)
    {
        GetMidiOutDescription(id, thisDesc);
        if(strcmp(thisDesc, lpszDesc) == 0)
            return id;

        id++;
    }

    return ERR_NOMATCH;
}


static UINT OutputPort::getNumDevices()
/////////////////////////////////////////////////////////////////////////////
// Returns the number of MIDI::OutputPort(s) are connected to this system. //
/////////////////////////////////////////////////////////////////////////////
{
    return midiOutGetNumDevs();
}





bool OutputPort::getCapabilities(UINT deviceID, MIDIOUTCAPS &portCapabilties)
///////////////////////////////////////////////////////////////
// Gets the capabilities of a particular MIDI output device. //
///////////////////////////////////////////////////////////////
{
    MMRESULT Result = ::midiOutGetDevCaps(deviceId, &portCapabilties, sizeof portCapabilties);

    return (Result != MMSYSERR_NOERROR); // Return true/false if there was an error
}


bool OutputPort::CreateEvent()
//////////////////////////////////////////////////////
// Creates an event for signalling a header thread. //
//////////////////////////////////////////////////////
{
    bool result = true;

    eventHandle = ::CreateEvent(NULL, FALSE, FALSE, NULL);


    if(eventHandle == NULL) // then the event creation failed
    {// so
        return false;
    }

    return true;
}



void CALLBACK OutputPort::MidiOutProc(HMIDIOUT MidiOutHandle, UINT message, DWORD_PTR instance, DWORD_PTR param1, DWORD_PTR param2)
///////////////////////////////////////////////////////////////
// Function is called by Win when a MIDI input event occurs. //
///////////////////////////////////////////////////////////////
{
    OutputPort *thisDevice;
    
    thisDevice = reinterpret_cast<OutputPort *>(instance);

    if(message == MOM_DONE)
    {
        ::SetEvent(Device->m_Event);
    }
}



DWORD OutputPort::HeaderProc(LPVOID Parameter)
{
    // Header worker thread

    OutputPort *device;
    
    device = reinterpret_cast<OutputPort *>(Parameter);

    // Continue while the MIDI output device is open
    while(device->currentState == OPENED)
    {
        ::WaitForSingleObject(device->eventHandle, INFINITE);

        // Make sure the device is still open
        if(device->currentState == OPENED)
        {
            // Remove the finished header
            device->headerQueue.RemoveHeader();
        }
    }

    return 0;
}



