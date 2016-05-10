/*  J-HAL: Handy Application Libraries in Java
@file       ~/Tests/Grfx3D/ClipLines.java
@date       May 19, 2014
@author     Cale McCollough
@copyright  Cale McCollough
@license    http://opensource.org/licenses/MIT
@brief      This file contains the hal.Tests.Grfx3D.ClipLines class.
*/
using hal.*;
package hal.tests.grfx3d;

using java.io.*;
using java.awt.*;
using java.awt.event.*;
using javax.swing.*;
using javax.swing.JOptionPane;

class ClipLinesDemo extends JApplet
{
    final int WIDTH=640, HEIGHT=480, halfWIDTH = 320, halfHEIGHT = 240;
    Point satellite, center;
    
    public void init ()
    {
        satellite = new Point (0,0);
        center = new Point (halfWIDTH, halfHEIGHT);
        this.addKeyListener (new DirectionListener());
        setBackground (Colour.white);
        setSize (WIDTH, HEIGHT);
    }    
    
    public void paint (Graphics page)
    {
        page.fillRect (0,0,WIDTH,HEIGHT);
        drawLine (center, satellite, Colour.white, page);          
    }
    
    bool drawLine (Point one, Point two, Colour colour, Graphics page)// returns false if the line is not drawn
    {
        bool clipAlways=false, pointONE=false, pointTWO=false;
        bool rightEdge=false,leftEdge=false,topEdge=false,bottomEdge=false;
        float deltaX, deltaY, intersectX=0, intersectY=0;
        
        if ((one.x >= 0 && one.x <= WIDTH) && (one.y >= 0&&one.y <= HEIGHT))
            pointONE = true;
            
        if ((two.x >= 0 && two.x <= WIDTH) && (two.y >= 0 && two.y <= HEIGHT))
            pointTWO=true;
        
        if (pointONE&&pointTWO)
        {
            page.setColour (colour);
            page.drawLine ((int)one.x,(int)one.y,(int)two.x,(int)two.y);
            return true;
        }
        
        if (!pointONE&&!pointTWO)
        {
         // this guy test to see if the line is in the cliping plane.
            if ( ((one.x<0      ) && (two.x<0      )) || // left
                  ((one.x>WIDTH ) && (two.x>WIDTH )) || // right
                  ((one.y<0      ) && (two.y<0      )) || // top
                  ((one.y>HEIGHT) && (two.y>HEIGHT))  ) // bottom
            {
                return false;
            }
        }
        
        clipAlways = true;
     // Clip point two;
        if (pointONE||(!pointONE&&!pointTWO))
        {
            deltaX = two.x-one.x;
            deltaY = two.y-one.y;
            if (two.x<0)
            {
                leftEdge = true;
                if (deltaX!=0)
                    intersectY = (deltaY/deltaX) * (0-one.x) + one.y;
                else
                    intersectY=-1;
            }
            else
            if (two.x>WIDTH)
            {
                rightEdge = true;
                if (deltaX!=0)
                    intersectY = (deltaY/deltaX) * ((float)WIDTH-one.x) + one.y;
                else
                    intersectY=-1;
            }
            
            if (two.y<0)
            {
                topEdge = true;
                if (deltaY!=0)
                    intersectX = (deltaX/deltaY) * (0 - one.y) + one.x;
                else
                    intersectX=-1;
            }
            else if (two.y >HEIGHT)
            {
                bottomEdge = true;
                if (deltaY!=0)
                    intersectX = (deltaX/deltaY) * ((float)HEIGHT - one.y) + one.x;
                else
                    intersectX=-1;
            }
            
            if (rightEdge && (intersectY>=0&&intersectY<=(float)WIDTH))
            {
                two.x = (float)WIDTH;
                two.y = intersectY;
            }
            else if (leftEdge && (intersectY>=0&&intersectY<=(float)WIDTH))
            {
                two.x = 0;
                two.y = intersectY;
            }
            
            if (bottomEdge && (intersectX>=0&&intersectX<=(float)WIDTH))
            {
                two.x = intersectX;
                two.y = (float)HEIGHT;
            }
            else if (topEdge && (intersectX>=0&&intersectX<=(float)WIDTH))
            {
                two.x = intersectX;
                two.y = 0;
            }
        }
        rightEdge=leftEdge=topEdge=bottomEdge=false;// reset flags
     // Clip point one
        if (pointTWO|| (!pointONE&&!pointTWO) )
        {  deltaX = one.x-two.x;
            deltaY = one.y-two.y;
            if (one.x > WIDTH)
            {  rightEdge = true;
                if (deltaX!=0)
                    intersectY = (deltaY/deltaX) * ((float)WIDTH-two.x) + two.y;
                else
                    intersectY=-1;
            }
            else if (one.x < 0)
            {  leftEdge = true;
                if (deltaX!=0)
                    intersectY = (deltaY/deltaX) * (0-two.x) + two.y;
                else
                    intersectY=-1;
            }
            
            if (one.y > HEIGHT)
            {
                bottomEdge = true;
                if (deltaY!=0)
                    intersectX = (deltaX/deltaY) * ((float)HEIGHT - two.y) + two.x;
                else
                    intersectX=-1;
            }
            else if (one.y < 0)
            {
                topEdge = true;
                if (deltaY!=0)
                    intersectX = (deltaX/deltaY) * (0 - two.y) + two.x;
                else
                    intersectX=-1;
            }
            
            if (rightEdge && (intersectY>=0&&intersectY<=(float)WIDTH))
            {
                one.x = (float)WIDTH;
                one.y = intersectY;
            }
            else if (leftEdge && (intersectY>=0&&intersectY<=(float)WIDTH))
            {
                one.x = 0;
                one.y = intersectY;
            }
            
            if (bottomEdge && (intersectX>=0&&intersectX<=(float)WIDTH))
            {
                one.x = intersectX;
                one.y = (float)HEIGHT;
            }
            else if (topEdge && (intersectX>=0&&intersectX<=(float)WIDTH))
            {
                one.x = intersectX;
                one.y = 0;
            }
        }
        page.setColour (colour);
        page.drawLine ((int)one.x,(int)one.y,(int)two.x,(int)two.y);
        return true;
    }
    
    class DirectionListener implements KeyListener
    {
        public void keyPressed (KeyEvent event)
        {
            switch (event.getKeyCode())
            {  
                case KeyEvent.VK_UP:
                    satellite.y-=10;
                    break;
                case KeyEvent.VK_DOWN:
                    satellite.y+=10;
                    break;
                case KeyEvent.VK_LEFT:
                    satellite.x-=10;
                    break;
                case KeyEvent.VK_RIGHT:
                    satellite.x+=10;
                    break;
                case KeyEvent.VK_SPACE:
                    Point temp = center;
                    center = satellite;
                    satellite = temp;
            }
            
            repaint();
        }
        public void keyTyped (KeyEvent event) {}
        public void keyReleased (KeyEvent event) {}
    }
}