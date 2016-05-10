/*! Symmetry Station \version 0.2.0
 *
 * \file      Device.h
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */

#ifndef __Win__MIDI__Device__dot_h__
#define __Win__MIDI__Device__dot_h__


namespace Win
{
    namespace MIDI
    {

/*! \class   Device
    \brief   Represents a MIDI device connected to a Win PC.
    \details This class is an extention of a MIDI::Device. It encapsulates an OS specific code.
 *************************************
 *  Class Dependencies
 ************************************/
#include <WinDef.h>
#include "../../../C-HAL/global.h"
//! **** End class dependencies ****



class Device
{
  public:
    Device();               //!< Constructor.
    ~Device();              //!< Destructor.

    char * name();          //!< Retrns the name of this Device.
    int numPorts();         //!< Returns the number of ports attached to this device.
    Device * probDevices(); //!< Probs for MIDI::Devices hooked up to the system and returns an array of them.

  private:

    word64 deviceHandle;    //!< The Handle to the MIDI device.
};
}   }  // End of Win::MIDI

#endif // __Win__MIDI__Device__dot_h__
