/** Underscore
    @file       /.../Kabuki.Toolkit/_App/IEvent.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _App
{
    /**  */
    interface IEvent
    {
        System.DateTime EventTime ();
        
        void Trigger (object source);
    }
}
