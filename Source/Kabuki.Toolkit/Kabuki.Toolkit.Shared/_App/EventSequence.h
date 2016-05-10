/** Underscore
    @file       /.../Kabuki.Toolkit/_App/EventSequence.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Collections.Generic;

namespace _App
{
    /**  */
    class EventSequence : IEvent
    {
        /** Default constructor. **/
        EventSequence ()
        {

        }

        void Trigger (object source = null)
        {
            foreach (IEvent e in events)
                e.Trigger (source);
        }

        string Description { get; set; }

        string ToString ()
        {
            return Description;
        }

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------

        List<IEvent> events;
    }
}
