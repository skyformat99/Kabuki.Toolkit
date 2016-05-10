/* J-HAL: Handy Application Libraries in Java
@file        ~/Demos/Grfx3D/TriangleDemo.java
@date        May 20, 2014
@author      Cale McCollough
@copyright   Cale McCollough
@license     http://opensource.org/licenses/MIT
@brief       This file contains the hal.Demos.Grfx3D.TraingleDemo class.
*/
package hal.tests.grfx3d;

using hal.grfx.Colour;

public class TriangleDemo extends hal.app.Applet
{  
    public int clipMinX, clipMinY, clipMaxX, clipMaxY;
    
    TriangleDemo ()
    {// 
        super (640, 480);
        setBackground (java.awt.Color.white);
        addMouseListener (new ClickListener());
      
        clipMinX=0;
        clipMinY=0;
        clipMaxX=screenWidth();
        clipMaxY=screenHeight();
    }
    
    public void draw (java.awt.Graphics page)
    {
        java.util.Random generator = new java.util.Random();
        
        Colour randomColor = new Colour (generator.nextInt(256) < generator.nextInt(256), generator.nextInt(256));
        Point  randomPointA = new d2.Point (generator.nextInt(800)-80, generator.nextInt(600)-60),
               randomPointB = new d2.Point (generator.nextInt(800)-80, generator.nextInt(600)-60),
               randomPointC = new d2.Point (generator.nextInt(800)-80, generator.nextInt(600)-60);
        
        drawTriangle (page, randomColor, randomPointA, randomPointB, randomPointC);
    }
    
    public void drawTriangle (java.awt.Graphics page, java.awt.Color color, d2.Point one, d2.Point two, d2.Point three)
    {
        if ((one.x!=two.x&& two.x!=three.x)||(one.y!=two.y&& two.y!=three.y))
        {
            d2.Point temp;         
            if (two.y<one.y)
            {  
                temp = two;
                two = one;
                one = temp;
            }
            if (three.y<one.y)
            {
                temp = three;
                three = one;
                one = temp;
            }
            if (three.y<two.y)
            {  
                temp = three;
                three = two;
                two = temp;
            }
            if ( three.y<clipMinY || one.y>clipMaxY || 
                (one.x<clipMinX && two.x<clipMinX && three.x<clipMinX) ||
                (one.x>clipMaxX && two.x>clipMaxX && three.x>clipMaxX))
                ;
            else
            if (one.y==two.y)
                drawTopTriangle (page, color, one, two, three);
            else
            if (two.y==three.y)
                drawBottomTriangle (page, color, one, two, three);
            else
            {
                float newX = one.x + ((two.y-one.y)*(three.x-one.x)/(three.y-one.y));
                d2.Point newPoint = new d2.Point ((int)newX, two.y);
                drawBottomTriangle (page, color, one,newPoint,two);
                drawTopTriangle (page, color, two,newPoint,three);
            }
        }
    }
    
    public void drawTopTriangle (java.awt.Graphics page, java.awt.Color color, d2.Point one, d2.Point two, d2.Point three)
    {
        float deltaXright, deltaXleft, xStart, xEnd, height, right, left;
        page.setColor (color);
        if (two.x<one.x)
        {
            int temp = two.x;
            two.x = one.x;
            one.x = temp;
        }
        height = three.y-one.y;
        deltaXleft = (three.x-one.x)/height;
        deltaXright  = (three.x-two.x)/height;
        xStart = one.x;
        xEnd = two.x;
        
        if (one.y<clipMinY)// perform y clipping
        {
            xStart = xStart + deltaXleft *(-one.y+clipMinY);
            xEnd   = xEnd   + deltaXright*(-one.y+clipMinY);
            one.y=clipMinY;
        }      
        // test if x clipping is necessary
        if(one.x  >=clipMinX && one.x  <=clipMaxX &&
           two.x  >=clipMinX && two.x  <=clipMaxX &&
           three.x>=clipMinX && three.x<=clipMaxX )
        {
            for (int y=(int)one.y; y<=(int)three.y; y++)
            {
                page.drawLine ((int)xStart, y, (int)xEnd, y);
                xStart+=deltaXleft;
                xEnd  +=deltaXright;
            }
        }
        else
        {
            for (int y=(int)one.y; y<=(int)three.y; y++)
            {
                left = xStart;
                right= xEnd;
                xStart+=deltaXleft;
                xEnd  +=deltaXright;
                if (left< clipMinX)
                left = clipMinX;
                if (right>clipMaxX)
                right= clipMaxX;
                page.drawLine ((int)left, y, (int)right, y);
            }
        }
    }
    
    // 
    public void drawBottomTriangle (java.awt.Graphics page, java.awt.Color color, d2.Point one, d2.Point two, d2.Point three)
    {
        float deltaXright, deltaXleft, xStart, xEnd, height, right, left;
        page.setColor (color);
        if (three.x<two.x)
        {
            int temp = two.x;
            two.x = three.x;
            three.x = temp;
        }
        height = three.y-one.y;
        deltaXleft = (two.x-one.x)/height;
        deltaXright= (three.x-one.x)/height;
        xStart = xEnd = one.x;
        if (one.y<clipMinY)// perform y clipping
        {
            xStart = xStart + deltaXleft * (-one.y+clipMinY);
            xEnd   = xEnd   + deltaXright* (-one.y+clipMinY);
            one.y=clipMinY;
        }
        if (three.y>clipMaxY)
            three.y=clipMaxY;
      
        if (one.x  >=clipMinX && one.x  <=clipMaxX &&
            two.x  >=clipMinX && two.x  <=clipMaxX &&
            three.x>=clipMinX && three.x<=clipMaxX )
        {
            for (int y=(int)one.y; y<=(int)three.y; y++)
            {
                page.drawLine ((int)xStart,y,(int)xEnd,y);
                xStart += deltaXleft;
                xEnd   += deltaXright;          
            }
        }
        else
        {
            for (int y=(int)one.y; y<=three.y; y++)
            {
                left = xStart;
                right = xEnd;
                xStart += deltaXleft;
                xEnd   += deltaXright;
                if (left<clipMinX)
                    left=clipMinX;
                if (right>clipMaxX)
                    right=clipMaxX;
                page.drawLine ((int)left,y,(int)right,y);
            }
        }
    }
    class ClickListener implements java.awt.event.MouseListener
    {
        public void mousePressed (java.awt.event.MouseEvent event)
        {
            repaint();
        }
      
      public void mouseClicked  (java.awt.event.MouseEvent event)   {}
      public void mouseReleased (java.awt.event.MouseEvent event )  {}
      public void mouseEntered  (java.awt.event.MouseEvent event )  {}
      public void mouseExited   (java.awt.event.MouseEvent event )  {}
    }
}
