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

#ifndef __MIDI__Message__dot_h__
#define __MIDI__Message__dot_h__

#include "../../../C-HAL/global.h"

#include "Port.h"


namespace MIDI
{
/*! \class   Message
 *  \brief   This class represents the base class for all MIDI messages.
 *  \details MIDI messages are represented by different operating systems in different ways. This class
 *  allows any OS specific code to be wrapped to corrent data member(s).
 *
 *  It is currently unknown if this will cause any significant performance hit from the virtual function
 *  calls... for right now, optimization is not a priority so its going to stay a virtual base class but
 *  in the future might be fine tuned after the application is fully functional.
 *************************************
 *  Class Dependencies
 ************************************/
    class Device;
//<------ Class dependencies ------->

class Message
{
  public:

    Message();                                 //!< Constructor.
    virtual ~Message();                        //!< Destructor.

    virtual const byte_t *message() const = 0; //!< Returns this Message's data.
    virtual word32_t length() const = 0;       //!< Returns the length of this Message.

    word64_t timeStamp() const;                //!< Returns the time stamp of this message
    void setTimeStamp(word64_t newTimeStamp);  //!< Sets the time_stamp of this message.

  private:

    word64_t time_stamp;                       //!< The time stamp of this message.
};

}


#endif // __MIDI__Message__dot_h__
