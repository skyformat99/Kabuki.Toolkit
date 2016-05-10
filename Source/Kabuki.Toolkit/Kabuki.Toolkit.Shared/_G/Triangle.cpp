/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/Triangle.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    class Triangle : _2D.Triangle, Drawable
    {
        /**  */
        Triangle () : base ()
        {
        }

        Triangle (_2D.Point_i initOne, _2D.Point_i initTwo, _2D.Point_i initThree) :
            base (initOne, initTwo, initThree)
        {
    
        }
        Triangle (int x1, int y1, int x2, int y2, int x3, int y3) :
            base (x1, y1, x2, y2, x3, y3)
        {
      
        }
   
        void Draw (_G2D.Cell canvas)
        {  
        }
    
        void Draw (_G2D.Cell canvas, _G.Colour colour)
        {  
        
        }
    
        static void Draw (_G2D.Cell canvas, _G.Colour colour, Triangle drawShape)
        {
            Triangle.Draw (context, colour,
            drawShape.Point_one ().X_int (), drawShape.Point_one ().X_int (),
            drawShape.Point_two ().X_int (), drawShape.Point_two ().X_int (),
            drawShape.Point_three ().X_int (), drawShape.Point_three ().X_int ());
        
        }
    
        static void Draw (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3)
        {
            // This method draws a triangle on the screen
            Line.Draw (context, colour, x1, y1, x2, y2);
            Line.Draw (context, colour, x2, y2, x3, y3);
            Line.Draw (context, colour, x1, y1, x3, y3);
        }
    
        static void Fill (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3)
        {
            int temp;
        
            if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))//The triangle is to small to bother rendering
                return;
                
            // The firs step is to sort points in ascending y order
            if (y2 < y1)
            {
                temp = y2;  // pt.3 |\<--- x3,y3
                y2 = y1;    //      | \
                y1 = temp;  // pt.2 |__\<--x2,y2
                temp = x2;  //      |  /
                x2 = x1;    //      | /
                x1 = temp;  // pt.1 |/<--- x1,y1
            }
            if (y3 < y1)
            {
                temp = y3;
                y3 = y1;
                y1 = temp;
                temp = x3;
                x3 = x1;
                x1 = temp;
            }
            if (y3 < y2)
            {
                temp = y3;
                y3 = y2;
                y2 = temp;
                temp = x3;
                x3 = x2;
                x2 = temp;
            }
        
            if (     y3 < 0                         //< Above screen.
                 ||  y1 > context.Height            //< Below screen.
                 || (x1 < 0 && x2 < 0 && x3 < 0)    //< Left of screen.
                 || (x1 > context.Width && x2 > context.Width && x3 > context.Width) // Right of screen.
               )
                return;
        
            if (y1 == y2)// if the top point and the middle point are equal
            {             // then the triangle is a flat topped triangle
                Triangle.DrawTop (context, colour, x1, y1, x2, y2, x3, y3);
                return;
            }
        
            if (y2 == y3)// if the lowest point and the middle point are equal
            {             // then the triangle is a flat bottomed triangle
                Triangle.DrawBottom (context, colour, x1, y1, x2, y2, x3, y3);
                return;
            }
        
            // else the triangle need to be split vertically in to a flat top and a flat bottom triangle
            float newX = ((x1)     // farthest point left on the triangle, used to define newX's Point in the triangle.
                          + ( (y2 - y1)// The horizontal break of the triangle
                              (x3 - x1)// The slope of the line
                             / (y3 - y1)// = the x intercept
                          )
                        );
                     
            Triangle.DrawBottom (context, colour, x1, y1, (int) newX, y2, x2, y2);        
            Triangle.DrawTop    (context, colour, x2, y2, (int) newX, y2, x3, y3);
        
            if (y2 > 0 && y2 < context.Height)
            {
                Line.Draw (context, colour, 0, y2, context.Width, y2);
            }
        } 
    
        static void DrawTop (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3)
        {
            // This method draws a triangle with a flat top on the context image.
            int deltaXleft, deltaXright, triangleHeight, xStart, xStop,  y, temp;
        
            if (x2 < x1)    // Organize the triangle from left to right
            {
                temp = x2;  //The y doesn't need to be switched because there the same
                x2 = x1;
                x1 = temp;
            }
            triangleHeight = y3 - y1;
        
            deltaXleft  = (x3-x1)               // change in width
                         /triangleHeight;   // change in height y = m/x  + b
                     
            deltaXright = (x3-x2)               // change in width
                         /triangleHeight;   // change in height
        
            // These variable are the vectors of the y = m/x + B slope for each side of the triangle                
        
            if (y1 < 0)
            {
                // Needs y clipping
            
                xStart = x1 + deltaXleft (0 - y1);
                xStop  = x2 + deltaXright (0 - y1);
                y1=0;
            }  
            else
            {
                xStart = x1;    // Its a flat topped triangle so the
                xStop  = x2;    // first line will be the longest
            }
        
            if (y3 > context.Height) y3 = context.Height;
        
            if (    x1 < 0 || x1 > context.Width
                 || x2 < 0 || x2 > context.Width
                 || x3 < 0 || x3 > context.Width)
            {
                // Perform y clipping
            
                int y;

                for (y = y1; y <= y3; y++)
                {
                    if (xStart >= 0) // Doesn't need x clipping of the first line
                    {
                        if (xStop <= context.Width)
                        {
                            // Doesn't need any x clipping
                            Line.Draw (context, colour, xStart, y, xStop, y);
                        }
                        else
                        {
                            // Only needs x clipping on the second line
                            if (xStart <= context.Width)
                                Line.Draw (context, colour,
                                                        xStart, y, context.Width, y);
                        }
                    }
                    else
                    if (xStart <= context.Width)
                    {
                        // Needs x clipping on the first line
                        if (xStop > context.Width)
                        {
                            // Only needs x clipping on the first line
                            Line.Draw (context, colour, 0, y,
                                                                             context.Width, y);
                        }
                        //else//page.DrawLine (0, y, (int)xStop, y);
                    }
                
                    xStart += deltaXleft;
                    xStop  += deltaXright; 
                }            
            }
            else
            {
                // No x clipping is necessary
                for (y = y1; y <= y3; y++)
                {  Line.Draw (context, colour,
                                                    (int)xStart, y, (int)xStop, y);
                    xStart += deltaXleft;
                    xStop  += deltaXright;
                }
            }
        }
        static void DrawBottom (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3)
        {
            // This method draws a triangle with a flat bottom on the context image.
        
            int deltaXleft, deltaXright, triangleHeight, xStart, xStop,  y, temp;
        
            if (x3 < x2)
            { 
                temp = x2;  // the y (s) don't need to be switched because there the same
                x2 = x3;
                x3 = temp;
            }
            triangleHeight = y3-y1;
            deltaXleft = (x2-x1)/triangleHeight;    // slope equations for the lines
            deltaXright= (x3-x1)/triangleHeight;
        
            // Since its a flat bottomed triangle the the top point is the x1, y1 _2D.Point_i
            if (y1 < 0)
            {
                // Perform y clipping
                xStart = x1 + deltaXleft  (0 - y1);
                xStop  = x2 + deltaXright (0 - y1);
                y1 = 0;
            }
            else//the top point is x1, y1
                xStart =x1;
                xStop = x1;
        
            if (y3 > context.Height)
                y3 = context.Height;
        
            if (    x1 < 0 || x1 > context.Width
                 || x2 < 0 || x2 > context.Width
                 || x3 < 0 || x3 > context.Width)
            {
                //  Triangle needs x clipping
                int x, y;
                for (y = y1; y <= y3; y++)
                {
                    if (xStart >= 0)                         // Doesn't need x clipping of the first line
                    {
                        if (xStop <= context.Width)    // Doesn't need any x clipping
                            Line.Draw (context, colour,
                                                            (int)xStart, y, (int)xStop, y);
                        else    //  Only needs x clipping on the second lines x intercept;
                            Line.Draw (context, colour,
                                                            (int)xStart, y, context.Width, y);
                    }
                    else// Needs x clipping on the first line
                    if (xStart <= context.Width)
                    {
                        if (xStop <= context.Width)//Only needs x clipping on the first line
                            Line.Draw (context, colour, 0, y, (int)xStop, y);
                        else//Needs x clipping on both lines
                         ;//  page.DrawLine (0, y, context.Width, y);
                    }
                
                    xStart += deltaXleft;
                    xStop  += deltaXright; 
                }
            }
            else
            {
                for (int y = (int)y1; y<= (int)y3; y++)
                {
                    Line.Draw (context, colour,
                                                    (int)xStart,y, (int)xStop,y);
                    xStart += deltaXleft;
                    xStop  += deltaXright;
                }
            }
        }
        _G.Colour_i colour;
    }
}
