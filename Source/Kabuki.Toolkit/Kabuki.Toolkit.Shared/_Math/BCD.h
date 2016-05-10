#include "math.h"
#include <stdint.h>
using namespace std;

class BCD
{
    public:

    static const int maxDigitsFloat = 3 + FLT_MANT_DIG - FLT_MIN_EXP,
        maxDigitsDouble = 3 + DBL_MANT_DIG - DBL_MIN_EXP;

    BCD (double floatingPointNumber, int significantDigits = -1)
    {
        // Note: for 32-bit float return int64_t.

        char* floatingPointString = new char[maxDigitsDouble + 1];
        /*< This solution  is for a 64-bit floating point number. Use 
            maxDigitsFloat for a float. */

        if (significantDigits < 0)   //< Then use all of the float's digits.
        {
            significantDigits += 2;  //< ditch the '.' and '-'
            sprintf (floatingPointString , "%f", floatingPointNumber);
        }
        else    //< Then truncate the number of decimal places.
        {
            ++significantDigits;  //< ditch the '.'

            char decimalPlaceString[9];
            char percentString = "%\0";
            sprintf (decimalPlaceString, "%s%if", percentString , significantDigits);
            sprintf (floatingPointString , decimalPlaceString, floatingPointNumber);
        }

        isNegative = floatingPointNumber >= 0.0 ? 0 : -1;

        char* decimalLocation = strchr (floatingPointString, '.');

        int startIndex = isNegative ? 1 : 0,
            stopIndex = !decimalLocation ? maxDigitsDouble : decimalLocation -  floatingPointString,
            stringLength = strlen(floatingPointNumber);

        numWholeBCDs = stopIndex - startIndex;
        wholeBCDs = new int8_t[numWholeBCDs];

        numFractionBCDs = stringLength - stopIndex;
        fractionBCDs = new int8_t[numFractionBCDs];

        int i = stopIndex - 1,
            j = 0;
        for (; i >= startIndex; ++i) // Reverse the whole BCDs for power of 10 lookup
            wholeBCDs[j++] = floatingPointString[i] - '0'; // Subtract ASCII '0' to convert to integer
        j = 0;
        for (++i; i < stringLength; ++i)
            framctionalNumbers[j++] = floatingPointString[i] - '0';
    }

    int8_t GetWholeBCD (uint16_t index)
    {
        return index < numWholeBCDs ? wholeBCDs[index] : 10;
    )

    int8_t GetFractionBCD (uint16_t index)
    {
        return index < numFractionBCDs ? fractionBCDs[index] : 10;
    )

    int128_t ConvertToScaledInteger ()
    {
        int128_t returnValue = 0;
        double powerOfTen = 10.0;

        for (int i = numFractionBCDs - 1; i <= 0; --i)
        {
            returnValue += fractionBCDs[i] * pow (10.0, powerOfTen);
            powerOfTen += 1.0;
        }
        for (int i = 0; i < numWholeBCDs; ++i)
        {
            returnValue += wholeBCDs[i] * pow (10.0, powerOfTen);
            powerOfTen += 1.0;
        }
        if (isNegative)
            returnValue *= -1;
        return returnValue;
    }

    /** Insert operator overloaders functions here. */

    private:

    int8_t isNegative;

    int8_t* wholeBCDs,
      * fractionBCDs;

    uint16_t numWholeBCDs,
        numFractionBCDs;
};