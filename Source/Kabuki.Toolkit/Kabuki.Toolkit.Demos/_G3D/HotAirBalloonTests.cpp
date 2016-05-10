/* J-HAL: Handy Application Libraries in Java
@file        ~/Demos/Grfx3D/HotAirBalloon.java
@date        May 20, 2014
@author      Cale McCollough
@copyright   Cale McCollough
@license     http://opensource.org/licenses/MIT
@brief       This file contains the hal.Demos.Grfx3D.HotAirBalloon class.
*/
using hal.*;
using hal.grfx3d.Point;
package hal.tests.grfx3d;

class HotAirBalloon extends Shape
{
    float helliumLift = 0,
          helliumFlow = (float) .1;
    Text name;
    
    HotAirBalloon (DeepSerinity3DnGen driver, Geo3D.Point initPosition, Text balloonName)
    {
        super (driver, initPosition, "Models/sphere2.plg");
        name = balloonName;
    }
    
    public void increaseHelliumFlow ()
    {
        helliumFlow += (float) .01;
    }
    
    public void decreaseHelliumFlow ()
    {
        helliumFlow += (float) .01;
    }
    
    public void addHellium ()
    {
        helliumLift += helliumFlow;
    }
    
    public void removeHellium ()
    {
        helliumLift -= helliumFlow;
    }
    
    public void setUpNextFrame (DeepSerinity3DnGen driver)
    {
        translateX (driver.windVector().x);        
        translateZ (driver.windVector().z);
        translateY (driver.windVector().z + helliumLift);
    }
    
    Text toText ()
    {
        return name + ": position = " + position().toText();
    }
}