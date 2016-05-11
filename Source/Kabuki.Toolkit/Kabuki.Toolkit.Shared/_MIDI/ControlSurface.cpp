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

#include "../../C-HAL/Text.h"

#include "ControlSurface.h"

#include "Control.h"

using namespace MIDI;


ControlSurface::ControlSurface():
    common_Channel(0),
    keyboard_Channel(1),
    drums_Channel(7)
{
    // Nothing to do here!
}



ControlSurface::~ControlSurface()
{
    // Nothing to do here!
}





int ControlSurface::commonChannel()
{
    return common_Channel;
}

void ControlSurface::setCommonChannel(int thisChannel)
{
    if(thisChannel < 0)
        common_Channel = 1;
    else
    if(thisChannel >= 16)
        common_Channel = 16;
    else
        common_Channel = thisChannel;
}


int ControlSurface::keyboardChannel()
{
    return keyboard_Channel;
}
void ControlSurface::setKeyboardChannel(int thisChannel)
{
    if(thisChannel < 1)
        keyboard_Channel = 1;
    else
    if(thisChannel >= 16)
        keyboard_Channel = 16;
    else
        keyboard_Channel = thisChannel;
}



int ControlSurface::drumsChannel()
{
    return drums_Channel;
}
void ControlSurface::setDrumsChannel(int thisChannel)
{
    if(thisChannel < 1)
        drums_Channel = 1;
    else
    if(thisChannel >= 16)
        drums_Channel = 16;
    else
        drums_Channel = thisChannel;
}




char *ControlSurface::toString()
{
    return Text::copy("Write me!!!\n");
}
