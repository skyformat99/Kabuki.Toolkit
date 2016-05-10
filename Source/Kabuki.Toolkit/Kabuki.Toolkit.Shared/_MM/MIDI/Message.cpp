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


#include "Message.h"

using namespace MIDI;

Message::Message()
{
    // Nothing to do here
}

Message::~Message()
{
    // Nothing to do here.
}

word64_t Message::timeStamp() const
{
    return time_stamp;
}


void Message::setTimeStamp(word64_t newTimeStamp)
{
    time_stamp = newTimeStamp;
}



// Constructor.
InputHeader::InputHeader(HMIDIIN devHandle, LPSTR buffer, DWORD length, bool &errorFlag)

   :deviceHandle(devHandle)
{
    // Initialize header
    midiHeader.lpData         = buffer;
    midiHeader.dwBufferLength = length;
    midiHeader.dwFlags        = 0;

    errorFlag = (::midiInPrepareHeader(devHandle, &midiHeader, sizeof midiHeader) != MMSYSERR_NOERROR);
}



// Destructor. 
InputHeader::~InputHeader()
{
    ::midiInUnprepareHeader(deviceHandle, &midiHeader, sizeof midiHeader);
}



// Add a buffer for receiving SysEx messages.
bool InputHeader::addSysExBuffer()
{
    MMRESULT result = ::midiInAddBuffer(deviceHandle, &midiHeader, sizeof midiHeader);

    if(result != MMSYSERR_NOERROR) // an error occurred
        return false;

    return true;
}


// Default constructor.
InputHeader::Queue::Queue()
{
    ::InitializeCriticalSection(&criticalSection);
}


// Destructor.
InputHeader::Queue::~Queue()
{
    removeAll();

    ::DeleteCriticalSection(&criticalSection);
}



// Adds a InputHeader to the Queue.
void InputHeader::Queue::addHeader(InputHeader *header)
{


    ::EnterCriticalSection(&criticalSection);

    //headerQueue.push(Header);

    ::LeaveCriticalSection(&criticalSection);
}



void InputHeader::Queue::removeHeader()
{
    // This function removes an OutputHeader to Queue

    ::EnterCriticalSection(&criticalSection);

    //if(!headerQueue.empty())
    //{
    //    delete headerQueue.front();
    //    headerQueue.pop();
    //}

    ::LeaveCriticalSection(&criticalSection);
}



void InputHeader::Queue::removeAll()
{
    // This function removes all of headers from the Queue

    ::EnterCriticalSection(&criticalSection);

    //while(!headerQueue.empty())
    //{
   //     delete headerQueue.front();
   //     headerQueue.pop();
   // }

    ::LeaveCriticalSection(&criticalSection);
}


bool InputHeader::Queue::isEmpty()
{
    // This functino determines if the Queue is empty

    //bool result;

    ::EnterCriticalSection(&criticalSection);

    //result = headerQueue.empty();

    ::LeaveCriticalSection(&criticalSection);

    //return result;
    return false;

}









// Constructor.
OutputHeader::OutputHeader(HMIDIOUT devHandle, LPSTR message, DWORD length, bool &errorFlag)
   :portHandle(devHandle)
{
    // Initialize header
    midiHeader.lpData         = message;
    midiHeader.dwBufferLength = length;
    midiHeader.dwFlags        = 0;

    // Prepare header
    errorFlag = (::midiOutPrepareHeader(devHandle, &midiHeader, sizeof midiHeader) != MMSYSERR_NOERROR);
    //if errorFlag is true then an error occured.
}



// Destructor.
OutputHeader::~OutputHeader()
{
    ::midiOutUnprepareHeader(portHandle, &midiHeader, sizeof midiHeader);
}



void OutputHeader::sendMessage()
//////////////////////////
// Sends a LongMessage. //
//////////////////////////
{
    MMRESULT result = ::midiOutLongMsg(portHandle, &midiHeader, sizeof midiHeader);

    if(result != MMSYSERR_NOERROR)
    {
        // Do this:
    }
}











///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////                                              ////////////////////////////////
/////////////////////  Win::MIDI::Message::InputHeader::Queue  ////////////////////////////////
/////////////////////            Class Implementation              ////////////////////////////////
/////////////////////                                              ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////




// Default Constructor.
OutputHeader::Queue::Queue()
{
    ::InitializeCriticalSection(&criticalSection);
}


// Destructor.
OutputHeader::Queue::~Queue()
{
    removeAll();

    ::DeleteCriticalSection(&criticalSection);
}



void OutputHeader::Queue::addHeader(OutputHeader *Header)
////////////////////////////////////////
// Adds an OutputHeader to the Queue. //
////////////////////////////////////////
{
    ::EnterCriticalSection(&criticalSection);

    //headerQueue.push(Header);

    ::LeaveCriticalSection(&criticalSection);
}



void OutputHeader::Queue::removeHeader()
{
    // Removes an OutputHeader to Queue


    ::EnterCriticalSection(&criticalSection);

    //if(!headerQueue.empty())
    //{
    //    delete headerQueue.front();
    //    headerQueue.pop();
    //}

    ::LeaveCriticalSection(&criticalSection);
}



void OutputHeader::Queue::removeAll()
{
    // This function removes all of headers from the Queue

    ::EnterCriticalSection(&criticalSection);

    //while(!headerQueue.empty())
    //{
    //    delete headerQueue.front();
    //    headerQueue.pop();
    //}

    ::LeaveCriticalSection(&criticalSection);
}




bool OutputHeader::Queue::isEmpty()
{
    // This functino determines if the Queue is empty

    //bool result;

    ::EnterCriticalSection(&criticalSection);

    //result = headerQueue.empty();

    ::LeaveCriticalSection(&criticalSection);

    //return result;
    return false;
}
