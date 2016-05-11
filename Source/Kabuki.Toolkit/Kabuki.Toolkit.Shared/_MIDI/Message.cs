/*! Symmetry Station \version 0.2.0
 *
 * \file      ~/Win/MIDI/Message.cpp
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */


#include "Message.h"

#include <WinDef.h>


using namespace Win::MIDI::Message;







///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////                                              ////////////////////////////////
/////////////////////       Win::MIDI::Message::InputHeader        ////////////////////////////////
/////////////////////            Class Implementation              ////////////////////////////////
/////////////////////                                              ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



InputHeader::InputHeader(HMIDIIN devHandle, LPSTR buffer, DWORD length, bool &errorFlag)
//////////////////
// Constructor. //
//////////////////
   :deviceHandle(devHandle)
{
    // Initialize header
    midiHeader.lpData         = buffer;
    midiHeader.dwBufferLength = length;
    midiHeader.dwFlags        = 0;

    errorFlag = (::midiInPrepareHeader(devHandle, &midiHeader, sizeof midiHeader) != MMSYSERR_NOERROR);
}



InputHeader::~InputHeader()
/////////////////
// Destructor. //
/////////////////
{
    ::midiInUnprepareHeader(deviceHandle, &midiHeader, sizeof midiHeader);
}



bool InputHeader::addSysExBuffer()
////////////////////////////////////////////////
// Add a buffer for receiving SysEx messages. //
////////////////////////////////////////////////
{
    MMRESULT result = ::midiInAddBuffer(deviceHandle, &midiHeader, sizeof midiHeader);

    if(result != MMSYSERR_NOERROR) // an error occurred
        return false;

    return true;
}





///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////                                              ////////////////////////////////
/////////////////////  Win::MIDI::Message::InputHeader::Queue  ////////////////////////////////
/////////////////////            Class Implementation              ////////////////////////////////
/////////////////////                                              ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



InputHeader::Queue::Queue()
//////////////////////////
// Default constructor. //
//////////////////////////
{
    ::InitializeCriticalSection(&criticalSection);
}


InputHeader::Queue::~Queue()
/////////////////
// Destructor. //
/////////////////
{
    removeAll();

    ::DeleteCriticalSection(&criticalSection);
}



void InputHeader::Queue::addHeader(InputHeader *header)
//////////////////////////////////////
// Adds a InputHeader to the Queue. //
//////////////////////////////////////
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




















///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////                                               ///////////////////////////////
/////////////////////     Win::MIDI::Message::OutputHeader      ///////////////////////////////
/////////////////////            Class Implementation               ///////////////////////////////
/////////////////////                                               ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


OutputHeader::OutputHeader(HMIDIOUT devHandle, LPSTR message, DWORD length, bool &errorFlag)
//////////////////
// Constructor. //
//////////////////
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



OutputHeader::~OutputHeader()
/////////////////
// Destructor. //
/////////////////
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




OutputHeader::Queue::Queue()
//////////////////////////
// Default Constructor. //
//////////////////////////
{
    ::InitializeCriticalSection(&criticalSection);
}


OutputHeader::Queue::~Queue()
/////////////////
// Destructor. //
/////////////////
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
