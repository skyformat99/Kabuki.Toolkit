/*! Symmetry Station \version 0.2.0
 *
 * \file      Message.h
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */


#ifndef __Win__MIDI__Message__dot_h__
#define __Win__MIDI__Message__dot_h__

#include <windows.h>

namespace Win
{   namespace MIDI
    {

    /*! \namespace Message
        \brief     Conntains four classes to handles Windows specific MIDI messages.
     */
        namespace Message
        {


/*! \class   InputHeader
 *  \brief   A class that encapsulates the MIDIHDR struct for MIDI input in Win.
 *  \details What details?
 */



class InputHeader
{
  public:

    InputHeader(HMIDIIN devHandle, LPSTR buffer, DWORD length, bool &errorFlag);
                            //!< Constructor.
                            /*!< \param devHandle A handle to the MIDI input device.
                                 \param buffer    The buffer.
                                 \param length    The length of the buffer.
                                 \param errorFlag This is a variable that the user passes into the contstructor
                                                  that is set true if there is an error createing */
    ~InputHeader();         //!< Destructor

    bool addSysExBuffer();  //!< Add a buffer for receiving SysEx messages.

  private:

    HMIDIIN deviceHandle;   //!< A handle to the MIDIIN device this message will be processed by.
    MIDIHDR midiHeader;     //!< The MIDI header for this message.



    public:

    ///////////////////////////////////////////////////////
    // Nested Class Win::MIDI::Message::InputHeader. //
    ///////////////////////////////////////////////////////

    /*! \class   Queue
     *  \brief   Thread safe queue for storing MIDI::Message::InputHeader objects
     *  \details This is a public nested class. Its just a  queue.
     */

    class Queue
    {
      public:

        Queue();
        ~Queue();

        void addHeader(InputHeader *header);    //!< Enqueues a header.
        void removeHeader();                    //!< Dequeues a haeder.
        void removeAll();                       //!< Dumps the Queue.
        bool isEmpty();                         //!< Returns true if the Queue is empty.

      private:

        InputHeader *queue;                     //!< Pointer to the Win::MIDI::Message::InputHeader::Queue

        CRITICAL_SECTION criticalSection;       //!< Thread stuff.
    };
};




class OutputHeader
{
  public:

    OutputHeader(HMIDIOUT devHandle, LPSTR message, DWORD length, bool &errorFlag);
    //!< Constructor.
    /*!< \param devHandle A handle to the MIDI input device.
         \param buffer    The buffer.
         \param length    The length of the buffer.
         \param errorFlag This is a variable that the user passes into the contstructor
                          that is set true if there is an error createing
     */
    ~OutputHeader();    //!< Destructor.

    void sendMessage();    //!< Sends this message the portHandle.

  private:

    HMIDIOUT portHandle; //!< A handle to the port to send the midiHeader's message.
    MIDIHDR  midiHeader; //!< The header of the MIDI message to send.

  public:

    //! A thread-safe queue for storing Win::MIDI::Message::OutputHeader objects
    class Queue
    {
      public:
        Queue();
        ~Queue();

        void addHeader(OutputHeader *Header);
        void removeHeader();
        void removeAll();
        bool isEmpty();

      private:

        CRITICAL_SECTION criticalSection;
    };
};
        }
    }
}

#endif // __Win__MIDI__Message__dot_h__
