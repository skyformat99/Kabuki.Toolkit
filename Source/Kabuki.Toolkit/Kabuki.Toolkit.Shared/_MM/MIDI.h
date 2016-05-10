/*! C-HAL - C/C++ Handy Application Libraries \version 0.4.0
 *
 * This is free software distributed under the LGPL v3 license.
 * Lincense information can be found at http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * \file      MIDI.h
 * \date      5/1/2011
 * \author    Chal J. McCollough
 * \copyright This code is the intillectual property of The People of the Planet Earth © 2011
 */


#ifndef _BlueStorm__MIDI_header
#define _BlueStorm__MIDI_header

namespace MIDI
{
    const byte_t ACTIVE_SENSING         = 0xFE;   //< Status byte_t for Active Sensing message
    const byte_t CHANNEL_PRESSURE       = 0xD0;   //< Command value for Channel Pressure (Aftertouch)
    const byte_t CONTINUE               = 0xFB;   //< Status byte_t for Continue message
    const byte_t CONTROL_CHANGE         = 0xB0;   //< Command value for Control Change message
    const byte_t SYSTEM_EXCLUSIVE       = 0xF0;   //< Status byte_t for System Exclusive message
    const byte_t END_OF_EXCLUSIVE       = 0xF7;   //< Status byte_t for End of System Exclusive message
    const byte_t MIDI_TIME_CODE         = 0xF1;   //< Status byte_t for MIDI Time Code Quarter Fram message
    const byte_t NOTE_OFF               = 0x80;   //< Command value for Note Off message
    const byte_t NOTE_ON                = 0x90;   //< Command value for Note On message
    const byte_t PITCH_BEND             = 0xE0;   //< Command value for Pitch Bend message
    const byte_t POLY_PRESSURE          = 0xA0;   //< Command value for Polyphonic Key Pressure (Aftertouch)
    const byte_t PROGRAM_CHANGE         = 0xC0;   //< Command value for Program Change message
    const byte_t SONG_POSITION_POINTER  = 0xF2;   //< Status byte_t for Song Position Pointer message
    const byte_t SONG_SELECT            = 0xF3;   //< Status byte_t for MIDI Song Select message
    const byte_t START                  = 0xFA;   //< Status byte_t for Start message
    const byte_t STOP                   = 0xFC;   //< Status byte_t for Stop message
    const byte_t SYSTEM_RESET           = 0xFF;   //< Status byte_t for System Reset message
    const byte_t TIMING_CLOCK           = 0xF8;   //< Status byte_t for Timing Clock message
    const byte_t TUNE_REQUEST           = 0xF6;   //< Status byte_t for Tune Request message
    const byte_t SHORT_MSG_MASK         = 15;     //< For unpacking and packing short messages
    const byte_t SHORT_MSG_SHIFT        = 8;      //< For unpacking and packing short messages
}


#endif // _BlueStorm__MIDI_header
