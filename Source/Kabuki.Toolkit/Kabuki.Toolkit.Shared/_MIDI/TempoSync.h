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


#ifndef SYMMETRYLIVEAPI_MIDI_TEMPOSYNC_H


namespace MIDI
{

/*!
    \class   TempoSync
    \brief   Class that is used to sync the host computer to the MIDI clock.
    \details For right now,
 */

class TempoSync
{
  public:

    TempoSync();        //!< Constructor.

    ~TempoSync();       //!< Destructor.

    void tick();        //!< Processes a clock tick.
    void tock();        //!< processes a sync event?

  private:

    int TPB;       //!< Number of Ticks Per Beat.
    int tickCount;  //!< The current tick count.
};

}

#endif // SYMMETRYLIVEAPI_MIDI_TEMPOSYNC_H
