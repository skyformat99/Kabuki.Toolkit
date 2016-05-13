/*! Symmetry Station \version 0.2.0
 *
 * \file      Port.h
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */

#ifndef __Win__MIDI__Port__dot_h__
#define __Win__MIDI__Port__dot_h__

#include "../../global.h"
#include "../../MIDI/Port.h"
#include "../../MIDI/Message.h"


/*! \class   Port
 *  \brief   Each port has a circular queue of MIDI_Message.
 *  \details  There are two types of MIDI::Ports, an input and an output port. The only real difference is
 *  that the InputPort Queue stores a MIDI::IncommingMessage and the OutputPort stores MIDI::OutgoingMessage(s).
 *
 *  Im not sure if it would be better to implement the queue as a template. Templates are C++ specific so
 *  I am very hessitant to use them.
 *
 *  One very usingant the that needs to happen is that this class needs to be thread safe.
 *
 *  SysEx message have not been implemented.
 *************************************
 *  Class Dependencies
 ************************************/
//! **** End class dependencies ****




class Port: public MIDI::Port
{
  public:

    Port(int initQueueSize=defaultQueueSize);               //!< Constructor.
    ~Port();                                                //!< Destructor.

    virtual void open()=0;                                  //!< Opens this MIDI port.
    virtual void close()=0;                                 //!< Closes this MIDI port.
    virtual void pause()=0;                                 //!< Pauses this MIDI port.

    int portIndex();                                        //!< Returns the index of this Port.
    void setPortIndex(int newIndex);                        //!< Sets the index of this Port to the newIndex.

    int queueSize();                                        //!< returns the queue size.
    void resizeQueue(int newSize);                          //!< resizes the queue to the newSize.
    void increaseQueueSize();                               //!< Increases size of the message queue by the queueSizeIncrease.
    int numMessages();                                      //!< returns the number of messages in the queue.


    void enqueue(MIDI::Message *newMessage);                 //!< Adds a newMessage to the tail of the queue.
    MIDI::Message *dequeue();                                //!< Dequeues the next message from the queue.

    MIDI::Message *readMessage();                            //!< Dequeues the next message from the queue.
    void reset();                                            //!< Dumps the queue and resets to init state.
    void deleteQueue();                                      //!< Dumps the queue.

  private:

    static const int defaultQueueSize = 1024,                //!< The default initial size of the queue.
                     queueSizeIncrease = 64,                 //!< The number to increase the queue size by in case of an overflow.
                     minQueueSize = 512;                     //!< The minumum queue size.

    int portNum,                                             //!< This port index.
        msgQueueSize,                                        //!< The size of the Message queue.
        numMsgs,                                             //!< The number of messages in the queue.
        readIndex,                                           //!< The head of the queue.
        queueIndex;                                          //!< The tail of the queue.

    MIDI::Message **queue;                                   //!< The MIDI message queue.

    typedef enum states { CLOSED=0, OPEN, RECORDING } state; //!< The three possible port states .
    state currentState;                                      //!< The currentState of this port.
};

#endif // __Win__MIDI__Port__dot_h__
