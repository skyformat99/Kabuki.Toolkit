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


#ifndef __SL__MIDI__Port__dot_h__
#define __SL__MIDI__Port__dot_h__



namespace MIDI
{
/*!
 *  \class   Port
 *  \brief   A class that represents a standard MIDI I/O port.
 *  \details This class contains a circuilar buffer of Message objects and the index of the
 *           port on the host system. The port can either be an input or an output port.
 *************************************
 *  Class Dependencies
 ************************************/
    class Message;
    //! **** End class dependencies ****

class Port
{
  public:

    typedef enum Types { IN=0, OUT } Type;

    Port(Type inOrOut=IN, int initQueueSize=defaultQueueSize);
                                              //!< Constructor.
    ~Port();                                  //!< Destructor.

    int portIndex();                          //!< Returns the index of this MIDI port
    void setPortIndex(int newIndex);          //!< Sets the index of this MIDI Port to the newIndex

    virtual void open()=0;                    //!< Opens the MIDI port.
    virtual void close()=0;                   //!< Closes the MIDI port.
    virtual void pause()=0;                   //!< Pauses the MIDI port.

    int queueSize();                          //!< returns the queue size.
    void resizeQueue(int newSize);            //!< resizes the queue to the newSize.
    void increaseQueueSize();                 //!< Increases size of the message queue by the queueSizeIncrease
    int numMessages();                        //!< returns the number of messages in the queue.

    void enqueue(Message *newMessage);        //!< Adds a newMessage to the tail of the queue.
    Message *dequeueNextMessage();            //!< Dequeues the next message from the queue.

    //void enqueue(Message *message, int portNum); //!< Enqueues a MIDI::Message.
    //Message *dequeue(int portNum);               //!< Dequeues a MIDI::Message.

    void increaseBufferSize(int deltaSize);      //!< Increases the MIDI message buffer size by the deltaSize.

    void reset();                             //!< Dumps the queue and resets to init state.
    void deleteQueue();                       //!< Dumps the queue.

  private:

    Message **queue;                          //!< The MIDI message queue.

    int portNum,                              //!< This Port's number.
        msgQueueSize,                         //!< The size of the Message queue.
        numMsgs,                              //!< The number of messages in the queue.
        readIndex,                            //!< The head of the queue.
        queueIndex;                           //!< The tail of the queue.

    static const int defaultQueueSize = 1024, //!< The default initial size of the queue.
                     queueSizeIncrease = 64,  //!< The number to increase the queue size by in case of an overflow.
                     minQueueSize = 512;      //!< The minumum queue size.
};
}

#endif // __SL__MIDI__Port__dot_h__
