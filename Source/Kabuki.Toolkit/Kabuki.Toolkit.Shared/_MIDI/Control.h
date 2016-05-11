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

#ifndef __SL__MIDI__Control__dot_h__
#define __SL__MIDI__Control__dot_h__

namespace MIDI
{
//!
/*! \class   Control
    \brief   A class that represents a standard MIDI CC.
        1.) A montary button
        2.) A latching button
        3.) An absoulte value control (0-127)
    Both types have a the same type of text label and trigger a MIDI CC.
    In the future, we need to implement the other types of advanced controls like SysEx and Program
    changes
 *************************************
 *  Class Dependencies
 ************************************/
#ifndef NULL
#define NULL 0
#endif//NULL

    class Label;
//! **** End class dependencies ****


class Control
{

public:

    //! Default constructor.
    Control(int initCC=0, int initValue=0, int initMinValue=0, int initMaxValue=127, int initLSB=0, int initMSB=127, int initCh=0);
    Control(const Control &copyObject);       //!< Copy contructor.

    ~Control();                               //!< Destructor.

    void copy(const Control *thisControl);    //!< Copies thisControl

    Control *duplicate();                     //!< Returns a duplicate copy of this object.

    bool comparedTo(Control *thatControl);    //!< Compares this Control to thatControl.
                                              /*!< \return Returns true if this control is the same as thatControl. */

    int cc();                                 //!< Returns this control's MIDI CC.
    int value();                              //!< Returns the current MIDI value of this control.
    int initValue();                          //!< Returns the default MIDI value of this control.
    int minValue();                           //!< Returns the min value of this control.
    int maxValue();                           //!< Returns the max value of this control.
    int lsbValue();                           //!< Returns the lsb value of this control.
    int msbValue();                           //!< Returns the msb value of this control.
    int channel();                            //!< Returns the output channel of this control.

    void setCC(const int newValue);           //!< Sets this control's CC parameter to the newValue
    void setValue(const int newValue);        //!< Sets this control's value parameter to the newValue.
    void setInitValue(const int newValue);    //!< Sets the default value of this control to the newValue.
    void setMinValue(const int newValue);     //!< Sets this control's min value to the newValue.
    void setMaxValue(const int newValue);     //!< Sets this control's max value to the newValue.
    void setLsbValue(const int newValue);     //!< Sets this control's lsb value to the newValue.
    void setMsbValue(const int newValue);     //!< Sets this control's msb value to the newValue.
    void setChannel(const int newValue);      //!< Sets this control's output channel to newValue.

    void toggle();                            //!< Toggle the midiValue from the min_Value to the max_Value.

    char *toString();                         //!< Returns a text represenation of this conrol.

private:

    int midiCC,                               //!< The MIDI CC parameter.
        midiValue,                            //!< The current MIDI value.
        init_Value,                           //!< The init MIDI value.
        min_Value,                            //!< The min MIDI value.
        max_Value,                            //!< The max MIDI value.
        lsb_Value,                            //!< The lsb MIDI value.
        msb_Value,                            //!< The msb MIDI value.
        outputCh;                             //!< The output channel.
                                              /*!< 0 = all channels(common). */
};

}

#endif // __SL__MIDI__Control__dot_h__
