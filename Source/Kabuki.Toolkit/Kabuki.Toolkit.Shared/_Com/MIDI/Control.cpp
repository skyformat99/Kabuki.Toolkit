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

#include "Control.h"

#include "../../../C-HAL/Text.h"
#include "../../../C-HAL/Numbers.h"

#include <string.h>

#include <stdlib.h>

using namespace MIDI;



Control::Control(int initCC, int initValue, int initMinValue, int initMaxValue, int initLSB, int initMSB, int initCh):
    controlLabel(T(initLabel))
//////////////////////////
// Default constructor. //
//////////////////////////
{
    setCC(initCC);
    setValue(initValue);
    setInitValue(initValue);
    setMinValue(initMinValue);
    setMaxValue(initMaxValue);
    setLsbValue(initLSB);
    setMsbValue(initMSB);
    setChannel(initCh);
}



Control::Control(const Control &thisControl)
///////////////////////
// Copy constructor. //
///////////////////////
// Initialization List:
   :midiCC()
{
    setCC(thisControl.midiCC);
    setValue(thisControl.midiValue);
    setInitValue(thisControl.init_Value);
    setMinValue(thisControl.min_Value);
    setMaxValue(thisControl.max_Value);
    setLsbValue(thisControl.lsb_Value);
    setMsbValue(thisControl.msb_Value);
    setChannel(thisControl.outputCh);
}



Control::~Control()
{
    // Nothing to do here.
}













Control *Control::duplicate()
{
    return new Control(*this);
}



int Control::cc()
{
    return midiCC;
}
int Control::value()
{
    return midiValue;
}
int Control::initValue()
{
    return init_Value;
}
int Control::minValue()
{
    return min_Value;
}
int Control::maxValue()
{
    return max_Value;
}
int Control::lsbValue()
{
    return lsb_Value;
}
int Control::msbValue()
{
    return msb_Value;
}
int Control::channel()
{
    return outputCh;
}




void Control::setCC(const int newCC)
{
    if(newCC < 0)
        midiCC = 0;
    else
    if (newCC > 127)
        midiCC = 127;
    else
        midiCC = newCC;
}
void Control::setValue(const int newValue)
{
    if(newValue < min_Value)
        midiValue = min_Value;
    else
    if (newValue > max_Value)
        midiValue = max_Value;
    else
        midiValue = newValue;
}
void Control::setInitValue(const int newValue)
{

    if(newValue < 0)
        init_Value = 0;
    else
    if (newValue > 127)
        init_Value = 127;
    else
        init_Value = newValue;
}
void Control::setMinValue(const int newValue)
{
    if(newValue < 0)
        min_Value = 0;
    else
    if (newValue > 127)
        min_Value = 127;
    else
        min_Value = newValue;

    if(midiValue < min_Value)
        midiValue = min_Value;
}
void Control::setMaxValue(const int newValue)
{
    if(newValue < 0)
        max_Value = 0;
    else
    if (newValue > 127)
        max_Value = 127;
    else
        max_Value = newValue;

    if(midiValue > max_Value)
        midiValue = max_Value;
}
void Control::setLsbValue(const int newValue)
{

    if(newValue < 0)
        lsb_Value = 0;
    else
    if (newValue > 127)
        lsb_Value = 127;
    else
        lsb_Value = newValue;
}
void Control::setMsbValue(const int newValue)
{

    if(newValue < 0)
        msb_Value = 0;
    else
    if (newValue > 127)
        msb_Value = 127;
    else
        msb_Value = newValue;
}
void Control::setChannel(const int newValue)
{

    if(newValue < 0)
        outputCh = 0;
    else
    if (newValue > 16)
        outputCh = 16;
    else
        outputCh = newValue;
}





void Control::toggle()
{
    if(midiValue == max_Value)
        midiValue = min_Value;
    else
        midiValue = max_Value;
}










bool Control::comparedTo(Control *thisControl)
{
    if(   thisControl == NULL
       || midiCC    != thisControl->midiCC
       || midiValue != thisControl->midiValue
       || min_Value != thisControl->min_Value
       || max_Value != thisControl->max_Value
       || outputCh  != thisControl->outputCh
      ) return false;
 // else
    return true;
}



void Control::copy(const Control *thisControl)
{
    midiCC     = thisControl->midiCC;
    midiValue  = thisControl->midiValue;
    init_Value = thisControl->init_Value;
    min_Value  = thisControl->min_Value;
    max_Value  = thisControl->max_Value;
    outputCh   = thisControl->outputCh;
}














char *Control::toString()
{
    char *returnString;

    char midiCcHeader[]  = "CC:    ",
         channelHeader[] = "Ch:    ",
         valueHeader[]   = "Value: ",
         minHeader[]     = "Min:   ",
         maxHeader[]     = "Max:   ",
         initHeader[]    = "Init:  ";

    int numChars = strlen(midiCcHeader)  +3 +1 // our MIDI values will never be greater then 127  (hind sight: mind be 14-bit MIDI values)
                 + strlen(channelHeader) +3 +1 // so we only need 3 chars for the value
                 + strlen(valueHeader)   +3 +1 // and +1 for the endl chars
                 + strlen(minHeader)     +3 +1
                 + strlen(maxHeader)     +3 +1
                 + strlen(initHeader)    +3 +1
                 +2; // for endl char and null term char

    char *buffer = new char[5];

    returnString = new char[numChars];

    strcat_s(returnString, numChars, midiCcHeader);
	_itoa_s(midiCC, buffer, numChars, 10);
    strcat_s(returnString, numChars, buffer);
    strcat_s(returnString, numChars, "\n");

    strcat_s(returnString, numChars, channelHeader);
	_itoa_s(outputCh, buffer, numChars, 10);
    strcat_s(returnString, numChars, buffer);
    strcat_s(returnString, numChars, "\n");

    strcat_s(returnString, numChars, valueHeader);
	_itoa_s(midiValue, buffer, numChars, 10);
    strcat_s(returnString, numChars, buffer);
    strcat_s(returnString, numChars, "\n");

    strcat_s(returnString, numChars, minHeader);
	_itoa_s(min_Value, buffer, numChars, 10);
    strcat_s(returnString, numChars, buffer);
    strcat_s(returnString, numChars, "\n");

    strcat_s(returnString, numChars, maxHeader);
	_itoa_s(max_Value, buffer, numChars, 10);
    strcat_s(returnString, numChars, buffer);
    strcat_s(returnString, numChars, "\n");

    strcat_s(returnString, numChars, initHeader);
	_itoa_s(init_Value, buffer, numChars, 10);
    strcat_s(returnString, numChars, buffer);
    strcat_s(returnString, numChars, "\n");

    delete buffer;

    return returnString;
}
