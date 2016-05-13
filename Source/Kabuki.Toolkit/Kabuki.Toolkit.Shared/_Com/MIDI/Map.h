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


#ifndef __MIDI__Map__dot_h__
#define __MIDI__Map__dot_h__

#include "../global.h"


namespace MIDI
{
/*! \class   Map
 *  \brief   Class that remaps MIDI Parameters to other specified values.
 *  \details Write more about me!!!
 *************************************
 *  Class Dependencies
 ************************************/
//! **** End class dependencies ****


class Map
{
  public:

    Map();

    byte mapParam(uint channelNum, byte thisParameter); //!< Re-maps thisParameter to its remappedParam.

  private:

    byte remappedParam[16][128]; //!< Aa 16x128 grid of 7-bit MIDI values to remap parameters to.
    //char **paramString[16][128]; //!< The string names of the remapped parameters.
};
}

#endif // __MIDI__Map__dot_h__
