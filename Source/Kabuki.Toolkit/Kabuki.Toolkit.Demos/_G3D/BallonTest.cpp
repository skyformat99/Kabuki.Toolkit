/*  J-HAL: Handy Application Libraries in Java
 @file       Ballon.java
 @date       May 19, 2014
 @author     Cale McCollough
 @copyright  Cale McCollough
 @license    http://opensource.org/licenses/MIT
 @brief      This file contains the hal.Demos.Grfx3D class.
 */
using hal.*;
package hal.tests.grfx3d;

using java.awt.*;
using java.util.Random;

class Ballon
{
   int x, y, z, value, place, ballonNumber;
   Color color;

   Ballon (int xValue, int yValue, int zValue, Color shade)
   {
     x = xValue;
     y = yValue;
     z = zValue;
     color = shade;
   }

   public void setX (int newX)
   {
      x = newX;
   }


   public void setY (int newY)
   {
      y = newY;
   }

   public void setZ (int newZ)
   {
      z = newZ;
   }

   int getZ ()
   {
      return z;
   }

   public void draw (Graphics page)
   {
      page.setColor (color);

      if (z < 0)
      {
         x = ballonNumber; 
         y = 400;
         z = 30;
      }
      page.fillOval (x, y, ((z*2)/3), z);
      page.fillRect (x+(((z*2)/3)/2)-2, y+z, (z/15)*2, (z/15));
      
      page.setColor (Color.black);
      page.drawLine (x+(((z*2)/3)/2), y+z+(z/15), x+(((z*2)/3)/2), y+z+z);
   }

   public void newPos ()
   {
      Random generator = new Random();
      value = generator.nextInt(600);

      if (value < 100 || value > 450)
      {
         z--;
         y--;
      }
      if (value > 50 && value < 400)
      {
         x++;
         y--;
      }
      if (value > 400)
      {
         x--;
         y--;
      }
   }
   
} // End