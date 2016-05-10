/** Underscore
    @file       /.../Kabuki.Toolkit/_App/RealTimeKeyboard.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

using System.Diagnostics;

namespace _IO
{
    delegate void Event ();

    /** A computer keyboard. 
        Keyboard events are stored as delegates.
    */
    class RealTimeKeyboard
    {
        const int DefaultBufferSize = 256,       //< The default buffer size.
            MinBufferSize = 64,                         //< Min buffer size.
            MaxBufferSize = 1024 * 10;                  //< Max buffer size.

        /** Default constructor. **/
        RealTimeKeyboard (int a = DefaultBufferSize)
        {
            if (a < MinBufferSize)      bufferSize = MinBufferSize;
            else if (a > MaxBufferSize) bufferSize = MaxBufferSize;
            else                        bufferSize = a;

            start = stop = begin;
        }
        
        /** Resets the event buffer. */
        void Clear ()
        {
            start = stop = begin;
        }

        /** Inserts an event into the buffer. */
        void Insert (Event a)
        {
            if (stop + 1 > end)
            {
                Debug.Assert (start != begin, "Insert (byte): Buffer overflow.");
                stop = begin;
                buffer[stop] = a;
            }
            Debug.Assert (stop + 1 == start, "Insert (byte): Buffer overflow.");
            
            buffer[++stop] = a;
        }
        
        /**  */
        void Update ()
        {
            if (start > stop)
            {
                for (int i = start; i <= end; ++i) buffer[i] ();
                for (int i = begin; i <= stop; ++i) buffer[i] ();
                start = stop = begin;
                return;
            }

            for (int i = start; i <= end; ++i) buffer[i] ();
            start = stop = begin;
        }

        // Returns a string representation of this object.
        string ToString ()
        {
            return "begin: " + begin + " end: " + end + " start: " + start + " stop: " + stop + "\n";
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        int begin,
            end,
            start,
            stop,
            bufferSize;

        Event[] buffer;
    }
}
