/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/Pipeline.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D  //< 2D Gemetry.
{
    /**  */
    class Pipeline : Layer
    {
        Pipeline ()
        {
            head = null;
            head.prev = null;
            head.next = null;
        
            Reset ();
        }
    
        Pipeline (string pipeDesc)
        {
            head = new EmptyLayer ();
        
            Reset ();
        }
        void Delete ()
        {
            head.prev = this;
            //head.next = this);//Dont need to do this
        
            Layer.prev = head;
            Layer.next = head;
        }
    
        void Draw (_G2D.Cell canvas)
        {
            if (head == null)
                return;
        
            head.Draw (context);
            head.next.Draw (conext);
        }
    
        void deconstructPipeline (Layer currentPipe)
        {
            if (currentPipe == null)
                return
        
            deconstructPipeline (currentPip.next);
        }

        Layer head;
    }
}
