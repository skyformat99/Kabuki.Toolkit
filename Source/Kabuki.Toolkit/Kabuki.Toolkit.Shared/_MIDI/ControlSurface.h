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

#ifndef __MIDI__ControlSurface__dot_h__
#define __MIDI__ControlSurface__dot_h__

namespace MIDI
{
/*! \class   ControlSurface
    \brief   This class represents a generic Control Surface.
    \details This class is to help facilitate the editing of templates on other control
             surfaces through the Symmetry Live!'s API. For right now its pretty bare bones.
 *************************************
 *  Class Dependencies
 ************************************/
//! **** End class dependencies ****



class ControlSurface
{
public:

    ControlSurface();                         //!< Default contrustor

    ~ControlSurface();                        //!< Default destructor

    int commonChannel();                      //!< Returns the common MIDI channel (0 for all channels).
    int keyboardChannel();                    //!< Returns the common keyboard MIDI channel.
    int drumsChannel();                       //!< Returns the common drums MIDI channel.

    void setCommonChannel(int thisChannel);   //!< Sets the common MIDI channel.
    void setKeyboardChannel(int thisChannel); //!< Sets the common keyboard MIDI channel.
    void setDrumsChannel(int thisChannel);    //!< Sets the common drums MIDI channel.

    char *toString();                         //!< Returns a string representation this object.


    static const int MAX_TEMPO = 999;         //!< The maximum tempo allowed.

private:

    int common_Channel,                       //!< The common MIDI Channel (0)
        keyboard_Channel,                     //!< The keyboard MIDI out channel
        drums_Channel;                        //!< The drums MIDI out channel

    /*!<
        To Do:

        - Write code to determine how many MIDI devices are connected to the computer and get their handles.
        - Determine what the fuck I was doing with the macro lists??? Should they have their own data struct?
     */
};

}

#endif //__MIDI__ControlSurface__dot_h__
