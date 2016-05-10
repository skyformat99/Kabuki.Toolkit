/* J-HAL: Handy Application Libraries in Java
@file        ~/.java
@date        May 20, 2014
@author      Cale McCollough
@copyright   Cale McCollough
@license     http://opensource.org/licenses/MIT
@brief       This file contains the hal. class.
*/
using hal.*;
using hal.grfx3d.Point;
package hal.tests.grfx3d;

class HotAirBalloonDemo extends hal.Grfx3D.SoftwareEngine
{
    int MoveForwards     = java.awt.event.KeyEvent.VK_E,
        MoveBackwards    = java.awt.event.KeyEvent.VK_D,
        MoveLeft         = java.awt.event.KeyEvent.VK_S,
        MoveRight        = java.awt.event.KeyEvent.VK_F,
        LookLeft         = java.awt.event.KeyEvent.VK_W,
        LookRight        = java.awt.event.KeyEvent.VK_R,
        Jump             = java.awt.event.KeyEvent.VK_SPACE,
        Crouch           = java.awt.event.KeyEvent.VK_Z;
 //                /\--  Player Controls  --/\Image background;
    
    grfx2d.Image background;
    
    HotAirBalloon[] balloon;
    
    HotAirBalloonDemo ()
    {
        super (640, 480, java.awt.Colour.white);
        addKeyboardDriver (new KeyboardDriver ());
        
        javax.swing.ImageIcon temp = new javax.swing.ImageIcon ("Bliss.jpeg");
        background = temp.getImage ();
        
        balloon = new HotAirBalloon[1];
        balloon[0] = new HotAirBalloon (this, new Geo3D.Point (0, 0, 300), "Chals Balloon");
        balloon[0].scale ((float).1);
    }
    
    public void setUpNextFrame ()
    {
        for (int i=0; i<balloon.length; i++)
            balloon[i].setUpNextFrame (this);
    }
    
    public void draw (java.awt.image.ImageObserver driversIO, java.awt.Graphics page)
    {
        page.drawImage (background, 0, 0, driversIO);
        
        for (int i=0; i<balloon.length; i++)
            balloon[i].draw (driversIO, page);
        
        page.setColour (java.awt.Colour.red);
        page.drawText (windVector().toText (), 0, 15);
    }
    
    class KeyboardDriver extends JavaKeyboardDriver
    {
        KeyboardDriver ()
        {
            setKeyEvent (MoveForwards   , new MoveForwardsKey  ());
            setKeyEvent (MoveBackwards  , new MoveBackwardsKey ());
            setKeyEvent (MoveLeft       , new MoveLeftKey      ());
            setKeyEvent (MoveRight      , new MoveRightKey     ());
            setKeyEvent (Jump           , new JumpKey          ());
            setKeyEvent (Crouch         , new CrouchKey        ());     
        }
        class MoveForwardsKey implements EventTrigger
        {
            public void triggerEvent ()
            {
                windVector().translateZ (1);
            }
        }
        class MoveBackwardsKey implements EventTrigger
        {
            public void triggerEvent ()
            {
                windVector().translateZ (-1);
            }
        }
        class MoveLeftKey implements EventTrigger
        {
            public void triggerEvent ()
            {
                windVector().translateX (-1);
            }
        }
        class MoveRightKey implements EventTrigger
        {
            public void triggerEvent ()
            {
                windVector().translateX (1);
            }
        }
        class JumpKey implements EventTrigger
        {
            public void triggerEvent ()
            {
                balloon[0].addHellium ();
            }
        }
        class CrouchKey implements EventTrigger
        {  public void triggerEvent ()
            {    balloon[0].removeHellium ();
            }
        }        
    }
}