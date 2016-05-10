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


#include "Port.h"

#include "../global.h"
#include "../MIDI/Message.h"


using namespace MIDI;



Port::Port(Type inOrOut, int initQueueSize):
    portNum(0),
    msgQueueSize(defaultQueueSize),
    readIndex(0),
    queueIndex(0)
{
 // Constructor that initializes queue with the initQueueSize

    // Perform error checking on initQueueSize
    if(initQueueSize < minQueueSize)
        msgQueueSize = minQueueSize;

    msgQueueSize = defaultQueueSize;

    queue = new Message *[msgQueueSize];

    for(int i=0; i < msgQueueSize; ++i)
        queue[i] = NULL;
}

Port::~Port()
{
    deleteQueue();
}













int Port::queueSize()
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

    queue = new Message *[msgQueueSize];

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



void Port::enqueue(Message *newMessage)
{
    if(queueIndex == msgQueueSize)
        queueIndex = 0;

    if(queueIndex == readIndex-1) // Oops! We over ran the buffer!
    {
        resizeQueue(readIndex+queueSizeIncrease);
    }

}
Message *Port::dequeueNextMessage()
{
    if(numMsgs == 0) // Then queue is empty.
        return NULL;

    Message * temp;
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
 // We only need to delete the messages in between the head
 // and tail indecies.
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
