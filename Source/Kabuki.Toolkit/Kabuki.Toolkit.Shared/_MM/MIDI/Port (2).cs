/*! Symmetry Station \version 0.2.0
 *
 * \file      ~/Win/MIDI/Port.cpp
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */


#include "Port.h"



Port::Port(int initQueueSize)
///////////////////////////////////////////////////////////
// Constructor initializes queue with the initQueueSize. //
///////////////////////////////////////////////////////////
   :portNum(0),
    msgQueueSize(defaultQueueSize),
    readIndex(0),
    queueIndex(0)
{
    // Perform error checking on initQueueSize
    if(initQueueSize < minQueueSize)
        msgQueueSize = minQueueSize;
    else
        msgQueueSize = defaultQueueSize;

    queue = new MIDI::Message *[msgQueueSize];

    for(int i=0; i < msgQueueSize; ++i)
        queue[i] = NULL;
}



Port::~Port()
/////////////////
// Destructor. //
/////////////////
{
    deleteQueue();
}








void Port::open()
////////////////////////////
// Opens this MIDI::Port. //
////////////////////////////
{

}

void Port::close()
/////////////////////////////
// Closes this MIDI::Port. //
/////////////////////////////
{

}

void Port::pause()
/////////////////////////////
// Pauses this MIDI::Port. //
/////////////////////////////
{

}






int Port::queueSize()
////////////////////////////////////
// Returns the size of the Queue. //
////////////////////////////////////
{
    return msgQueueSize;
}

void Port::resizeQueue(int newSize)
{
    if(   newSize < minQueueSize
       || newSize == msgQueueSize)
        return;
    // Not sure if I want this funciton to return false if newSize is ou of bounds.

    deleteQueue();

    queue = new MIDI::Message *[msgQueueSize];

    for(int i=0; i < msgQueueSize; ++i)
        queue[i] = NULL;
}




int Port::numMessages()
{
    return numMsgs;
}



void Port::increaseQueueSize()
{
    resizeQueue(msgQueueSize+queueSizeIncrease);
}



void Port::enqueue(MIDI::Message *newMessage)
{
    if(queueIndex == msgQueueSize)
        queueIndex = 0;

    if(queueIndex == readIndex-1) // Oops! We over ran the buffer!
    {
        resizeQueue(readIndex+queueSizeIncrease);
    }

    queue[queueIndex] = newMessage;
    ++queueIndex;

    if(queueIndex > msgQueueSize)
        queueIndex = 0;

}
MIDI::Message *Port::readMessage()
{
    if(numMsgs == 0) // Then queue is empty.
        return NULL;

    MIDI::Message * temp;
    temp = queue[readIndex];
    queue[readIndex] = NULL;

    --numMsgs;
    ++readIndex;

    if(readIndex == msgQueueSize) // Wrap around to the begining of the queue.
        readIndex = 0;

    return temp;
}




int Port::portIndex()
{
    return portNum;
}

void Port::setPortIndex(int newIndex)
{
    if(newIndex < 0)
        return;
    portNum = newIndex;
}




void Port::reset()
{
 // We only need to delete the messages in between the head and tail indecies.
    for(int i=0; i <= msgQueueSize; ++i)
    {
        if(queue[i])
        {
            delete queue[i];
            queue[i] = NULL;
        }
    }
}

void Port::deleteQueue()
{
 // This function is pretty much the same as reset() only it does not
 // set indecies to NULL and it deletes the queue pointer.

    for(int i=0; i <= msgQueueSize; ++i)
    {
        if(queue[i])
        {
            delete queue[i];
            queue[i] = NULL;
        }
    }
    delete queue;
}

