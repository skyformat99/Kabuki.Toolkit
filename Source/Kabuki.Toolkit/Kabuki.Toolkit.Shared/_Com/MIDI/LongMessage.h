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


#ifndef __MIDI__LongMessage__dot_h__
#define __MIDI__LongMessage__dot_h__

#include "../global.h"
#include "../../../C-HAL/global.h"

#include "Message.h"


namespace MIDI
{

/*! \class   SysExMessage
    \brief   Class that represents a MIDI SysEx SysExMessage.
    \details A SysExMessage extends a standard MIDI Message.
 *************************************
 *  Class Dependencies
 ************************************/
//! **** End class dependencies ****



class LongMessage: public Message
{
  public:

    LongMessage(const char *Msg=NULL, word32_t Length=NULL);    //!< Constructor.
    LongMessage(const LongMessage &Msg);                     //!< Copy Constructor.

    ~LongMessage();                                           //!< Destructor.

    LongMessage &operator = (const LongMessage &copyObject); //!< Operator(=) overloader.

    word32_t length() const;                                     //!< Returns the length of this message.
    char *message();                                           //!< Returns theMessage.
    void setMessage(const char *newMessage, word32_t Length);    //!< Sets thisMessage to the newMessage

  protected:

    char &operator [] (int i);                                  //!< Operator([]) Overloader.
                                                                /*!< This is for derived classes to use in order to access the
                                                                     individual bytes within a SysExMessage object.
                                                                     \warning No bounds checking is being performed! */
  private:

    char *messageData;
    word32_t messageLength;
};
}

#endif // __MIDI__LongMessage__dot_h__
