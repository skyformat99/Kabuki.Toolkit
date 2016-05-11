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

#ifndef __MIDI__Device__header__
#define __MIDI__Device__header__


namespace MIDI
{
/*! \class   Device
 *  \brief   Class that represents a MIDI device connected to the computer.
 *  \details This class extends a MIDI device class that is platform specific. Each OS has different
 *  low-level MIDI IO protocals but they all function the same way in the high-level abstraction.
 *
 *  Some MIDI devices are not connected internally(meaning connected via USB, Firewire, or PCI) and are
 *  extermal MIDI only devices. This class supports them too. A MIDI device might be spread out over
 *  several different internal MIDI connections. Each Internal MIDI device have one global instance
 *  of a class associated with it. This class will store pointers to the static instances of the ports
 *  so that multiple sources can write to the same MIDI buffer.
 *
 *  Not all devices are obviously grouped together. A lot of USB MIDI devices have names listed as
 *  USB MIDI Port 1 and it is not evident that they are part of the same device buss. Because of this,
 *  all of the universal static port objects are instantiated in the SymmetryLive object and the user
 *  is able to group the devices together. This solves most of the conflicts of this system. A function
 *  still needs to be written that scans the port names for like names and group them automatically.
 *************************************
 *  Class Dependencies
 ************************************/
    class Message;
    class Port;
//! **** End class dependencies ****


class Device
{
  public:

    Device();                                    //!< Constructor.

    ~Device();                                   //!< Destructor.

    char *name();                                //!< Returns the name of this Device.

    int numInputPorts();                         //!< Returns the number of input ports this device has.
    int numOutputPorts();                        //!< Returns the number of output ports this device has.


  private:

    char *deviceName;                            //!< The name of this MIDI device.

    int numInPorts,                              //!< The number of input ports.
        numOutPorts;                             //!< The number of output ports.

    Port  *inputPorts,                           //!< The array of MIDI input ports.
          *outputPorts;                          //!< The array of MIDI output ports.
};

}

#endif // __MIDI__Device__header__
