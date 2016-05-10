/** Underscore
    @file       ~/Text/Grammer.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _. class.
*/

namespace _.Text
{
    /** Used for settings rules to text grammer.
        Useful for rules for passwords.
    */
    public class Grammer
    {
        public const int ToShortFlag = 1,       //< 
            ToLongFlag = 2,                     //< 
            ContainsInvalidCharsFlag = 3,       //< 
            MissingMandatoryCharsFlag = 4,      //< 
            MustStartWithCharFlag = 5;          //< 

        /** Default Contructor initializes with no rules. */
        public Grammer ()
        {
            numIllegalCharRanges = 0;
            numMandatoryCharRanges = 0;

            illegalChars = null;
            mandatoryChars = null;
        }

        /** Copy Constructor. */
        public Grammer (Grammer initState)
        {
            numIllegalCharRanges = initState.numIllegalCharRanges;
            numMandatoryCharRanges = initState.numMandatoryCharRanges;

        /*
            int i;
            if (numIllegalCharRanges)
            {
                illegalChars = new char[numIllegalCharRanges][2];
                for (i = 0; i < numIllegalCharRanges; ++i)
                {
                    illegalChars[i][1] = initState.illegalChars[i][1];
                    illegalChars[i][2] = initState.illegalChars[i][2];
                }
            }
            else
                illegalChars = null;

            if (numMandatoryCharRanges)
            {
                illegaChars = new char[numIllegalCharRanges][2];
                for (i = 0; i < numIllegalCharRanges; ++i)
                {
                    illegalChars[i][1] = initState.illegalChars[i][1];
                    illegalChars[i][2] = initState.illegalChars[i][2];
                }
            }
            else
                mandatoryChars = null;
         */
        }

        /** Verifies thisstring to see if it has proper grammer. */
        public bool IsValid (string aString)
        {
            /*
               int stringLength = strlen (thisstring);

               if (stringLength  < minLength || stringLength > maxLength)
                   return false;

               int i, j; // Looping variables
               for (i = 0; i < ; ++i)
               {
                   for (j = 0; j < numIllegalCharRanges; ++j)
                       if (thisstring[i])
               }
            */
            return true;
        }

        /** Gets and sets the min length of a valid symbol. */
        public int MinLength
        {
            get { return minLength; }
            set
            {
                if (value < 0 || value >= maxLength) return;
                minLength = value;
            }
        }
    
        /**  */
        public int MaxLength
        {
            get { return maxLength; }
            set
            {
                if (value < minLength) return;
                maxLength = value;
            }
        }

        /** Checks to see if thisChar is an illegal char. */
        public bool IsIllegal (char aChar)
        {
            return true;
        }

        /** Adds char index of illegal chars.
            @pre thisChar  must be > 0.
            @param thisChar The illegal char to add.
        */
        public bool MakeIllegal (char thisChar, string descstring)
        {
            //if (!isprint (thisChar))
             //   return false;
            return true;
        }

        /** Adds char or range of indexs of illegal chars.
            @pre startIndex and stopIndex must be a printable char.
            @param startIndex The starting ASCII char index.
            @param stopIndex  The stoping ASCII char index. */
        public bool MakeIllegal (int startIndex, int stopIndex, string descstring)
        {
            return true;
        }

        /** Adds a char or set of range of char indexes that must be included in a valid symbol.
            @pre startIndex and stopIndex must be a printable char and numInstances must be > 0 and < maxLength.
            @param startIndex The starting ASCII char index.
            @param stopIndex  The stoping ASCII char index.
            @param numInstances  The number of times the symbol range must occur. */
        public bool MakeMandatory (int startIndex, int stopIndex, int numInstances, string descstring)
        {
            return true;
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        private int numIllegalCharRanges,   //< The number of illegal char ranges.
            numMandatoryCharRanges,         //< The number of mandatory char ranges.
            minLength,                      //< The min length of a valid symbol.
            maxLength;                      //< The max length of a valid symbol.

        private int illegalChars,           //< A 2 column table of ints that represents all of illegal char ranges.
             mandatoryChars,                //< A 3 column table of ints that represents all of mandatory char ranges and how many are mandatory.
             mustStartWithChars;            //< A 2 column table of ints that represents the range (s) of chars that the symbol must start with.

        private string illegalCharsDesc,    //< An array of strings that describes what illegal char (s) are.
            mandatoryCharsDesc,             //< An array of strings that describes what what the mandatory char (s) are.
            mustStartWithCharsDesc;         //< An array of strings that describes what mandatory first char (s) are.
    }
}
 