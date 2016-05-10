/** Underscore
    @file       /.../Kabuki.Toolkit/_App/RealTimeApp.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _App
{
    abstract class RealTimeApp : App
    {
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /// Public:
        ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        int delay;
        //Thread runner;

        RealTimeApp (int width, int height, int timerDelay) : 
            base (width, height)
        {
            delay = timerDelay;
        }

        /** Gets and sets the timer delay. */
        int TimerDelay
        {
            get { return delay; }
            set
            {
                if (value < 0) return;
                delay = value;
            }
        }

        void Run ()
        {
            while (true)
            {
                try
                {
                    //runner.sleep (delay);
                }
                catch
                {
                }

                Update ();
            }
        }

        void Start ()
        {
            /*
            if (runner == null)
            {
                //runner = new Thread (this);
                runner.start ();
            }
            */
        }

        void Stop ()
        {
            /*
            if (runner != null)
            {
                runner.stop ();
                runner = null;
            }
            */
        }

        void Update ()
        {
            /*
            Dimension d = size ();
            if ((offScreenImage == null) || (d.Width != offScreenSize.Width) || (d.Height != offScreenSize.Height))
            {
                offScreenImage = createImage (d.Width, d.Height);
                offScreenSize = d;
                offScreenGraphics = offScreenImage.getGraphics ();
            }
            offScreenGraphics.clearRect (0, 0, d.Width, d.Height);
            paint (offScreenGraphics);
            page.DrawImage (offScreenImage, 0, 0, this);
            */
        }

        abstract void Draw (_G2D.Cell a);

        ///------------------------------------------------------------------------------------------------------------
        /// Private:
        ///------------------------------------------------------------------------------------------------------------
        
    }
}
 