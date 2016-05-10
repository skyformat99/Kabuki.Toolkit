/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/Cell.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _G2D.Cell class.
*/

namespace _G2D
{
    /** A graphics cell. */
    class Cell
    {
        /**  */
        Cell (int leftEdge, int topEdge, int width, int height) :
            base ()
        { 
        }

        //._2D
        //void Draw (d2.Polygon p);
        void Draw (string thisstring, int x, int y)
        {

        }
        
        /**  */
        void Draw (string thisstring, int x, int y, float thisAngle)
        {

        }
        
        /** Gets and sets the colour. */
        static Colour_i Colour   { get; set; }
        
        /** Sets the grfx_G.Colour. */
        static void SetColour (Colour newColor)
        {

        }
       
        /**  */
        static _G.Font Font { get; set; }
        
        /**  */
        static void DrawImage (Image thisImage, int leftEdge, int topEdge)
        {

        }
        
        /**  */
        static void DrawImage (Image thisImage, int leftEdge, int topEdge, int newWidth, int newHeight)
        {

        }
        
        /**  */
        static void DrawLine (_G2D.Cell canvas, double startX, double startY, double endX, double endY)
        {

        }
        
        /**  */
        static void DrawLine (_G2D.Cell canvas, _G.Colour thisColour, int startX, int startY, int endX, int endY)
        {

        }
        
        /**  */
        static void DrawRectangle (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {

        }
        
        /**  */
        static void DrawRectangle (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height, int thickness)
        {

        }
        
        /**  */
        static void DrawOval (int x, int y,int width, int height)
        {

        }
        
        /**  */
        static void DrawRoundedRectangle (int x, int y, int width, int height, int arcWidth, int arcHeight)
        {

        }
        
        /**  */
        static void ClearArea (int x, int y, int width, int height)
        {

        }
        
        /**  */
        static void ClipArea (int x, int y, int width, int height)
        {

        }
        
        /**  */
        static void CopyArea (int x, int y, int width, int height, int dx, int dy)
        {

        }
        
        /**  */
        static void DrawArc (int x, int y, int width, int height, int startAngle, int arcAngle)
        {

        }
        
        /**  */
        static void DrawText (string thisText, int offset, int length, int x, int y)
        {

        }
        
        /**  */
        static void DrawPolygon (int[] xPoints, int[] yPoints, int nPoints)
        {

        }
        
        /**  */
        static void DrawPolyline (int[] xPoints, int[] yPoints, int nPoints)
        {

        }
        
        /**  */
        static void DrawRect (int x, int y, int width, int height)
        {

        }
        
        /**  */
        static void Fill (_2D.Polygon<int> p)
        {

        }
       
        /**  */
        static void Draw (_2D.Polygon<int> p)
        {

        }
       
        /**  */
        static void Fill3DRect (int x, int y, int width, int height, bool raised)
        {

        }
       
        /**  */
        static void FillArc (int x, int y, int width, int height, int startAngle, int arcAngle)
        {

        }
       
        /**  */
        static void FillOval (int x, int y, int width, int height)
        {

        }
       
        /**  */
        static void FillPolygon (int []xPoints, int []yPoints, int nPoints)
        {

        }
       
        /**  */
        static void FillRectangle (int x, int y, int width, int height)
        {

        }
       
        /**  */
        static void FillRound3dRectangle (int x, int y, int width, int height, int arcWidth, int arcHeight)
        {

        }
       
        /**  */
        static void SetClip (int x, int y, int width, int height)
        {

        }
       
        /**  */
        static void SetClip (_2D.Entity thisShape)
        {

        }
       
        /**  */
        static void SetXORMode (Colour newColor)
        {

        }
       
        /**  */
        static void Translate (int x, int y)
        {

        }
       
        /*
        static DrawLine (_G2D.Cell canvas, float startX, float startY, float endX, float endY)
        {
            // This routing clips the line to the drawSpace boundary returns false if the line is not drawn
        
            bool startPointInScreenBounds = false,
                    endPointInScreenBounds = false, 
                    leftEdgeClip = false,
                    rightEdgeClip = false,
                    topEdgeClip = false,
                    bottomEdgeClip = false;
        
            float deltaX,       //< The intersecting 
                  deltaY,
                  intersectX,
                  intersectY;
        
            if (startX < 0 || startX > getScreenWidth () || startY < 0 || startY > getScreenHeight ())
                startPointInScreenBounds=false;
            
            if (endX < 0 || endX > getScreenWidth () || endY < 0 || endY > getScreenHeight ())
                endPointInScreenBounds=false;
        
            if (startPointInScreenBounds && endPointInScreenBounds)
            { 
                context.setColor (colour);
                context.DrawLine ((int)startX, (int)startY, (int)endX, (int)endY);
                return;
            }
        
            if (! (startPointInScreenBounds || endPointInScreenBounds))
            {
                /// This guy test to see if the line is in the clipping plane.
                if (   ((startX < 0             ) && (endX < 0             ))// left
                     || ((startX > ScreenWidth  ()) && (endX > ScreenWidth  ()))// right
                     || ((startY < 0             ) && (endY < 0             ))// top
                     || ((startY > ScreenHeight ()) && (endY > ScreenHeight ()))// bottom
                   )
                {
                    return;
                }
            }

            if (startPointInScreenBounds || ! (startPointInScreenBounds || endPointInScreenBounds))
            {
                Clip point two;
                deltaX = endX-startX;
                deltaY = endY-startY;
                if (endX<0)
                {
                    leftEdgeClip = true;
                    if (deltaX!=0)
                        intersectY = (deltaY / deltaX)  (0-startX) + startY;
                    else
                        intersectY=-1;
                }
                else
                if (endX>ScreenWidth ())
                {  rightEdgeClip = true;
                    if (deltaX!=0)
                        intersectY = (deltaY / deltaX)  ((float)ScreenWidth ()-startX) + startY;
                    else
                        intersectY=-1;
                }
            
                if (endY<0)
                {  topEdgeClip = true;
                    if (deltaY!=0)
                        intersectX = (deltaX/deltaY)  (0 - startY) + startX;
                    else
                        intersectX=-1;
                }
                else
                if (endY>ScreenHeight ())
                {  bottomEdgeClip = true;
                    if (deltaY!=0)
                        intersectX = (deltaX / deltaY)  ((float)ScreenHeight () - startY) + startX;
                    else
                        intersectX=-1;
                }
            
                if (rightEdgeClip && (intersectY >= 0 && intersectY <= (float)ScreenWidth ()))
                {  endX = (float)ScreenWidth ();
                    endY = intersectY;
                }
                else
                if (leftEdgeClip && (intersectY >= 0&& intersectY <= (float)ScreenWidth ()))
                {  endX = 0;
                    endY = intersectY;
                }
            
                if (bottomEdgeClip && (intersectX >= 0 &&intersectX <= (float)ScreenWidth ()))
                {  endX = intersectX;
                    endY = (float)ScreenHeight ();
                }
                else
                if (topEdgeClip && (intersectX >= 0 && intersectX <= (float)ScreenWidth ()))
                {  endX = intersectX;
                    endY = 0;
                }
            }
        
            //Reset clip flags
            rightEdgeClip = leftEdgeClip = topEdgeClip = bottomEdgeClip = false;
        
            if (endPointInScreenBounds || (!startPointInScreenBounds && !endPointInScreenBounds))
            { 
                // Clip point one
                deltaX = startX-endX;
                deltaY = startY-endY;
            
                if (startX>ScreenWidth ())
                {
                    rightEdgeClip = true;
                    if (deltaX!=0)
                        intersectY = (deltaY/deltaX)  ((float)ScreenWidth ()-endX) + endY;
                    else
                        intersectY=-1;
                }
                else if (startX<0)
                {
                    leftEdgeClip = true;
                    if (deltaX!=0)
                        intersectY = (deltaY/deltaX)  (0-endX) + endY;
                    else
                        intersectY=-1;
                }
            
                if (startY>ScreenHeight ())
                {
                    bottomEdgeClip = true;
                    if (deltaY!=0)
                        intersectX = (deltaX/deltaY)  ((float)ScreenHeight () - endY) + endX;
                    else
                        intersectX=-1;
                }
                else if (startY<0)
                {
                    topEdgeClip = true;
                    if (deltaY!=0)
                        intersectX = (deltaX/deltaY)  (0 - endY) + endX;
                    else
                        intersectX=-1;
                }
            
                if (rightEdgeClip && (intersectY >= 0&&intersectY <= (float)ScreenWidth ()))
                {
                    startX = (float)ScreenWidth ();
                    startY = intersectY;
                }
                else if (leftEdgeClip && (intersectY >= 0 && intersectY <= (float)ScreenWidth ()))
                {
                    startX = 0;
                    startY = intersectY;
                }
            
                if (bottomEdgeClip && (intersectX >= 0 && intersectX <= (float)ScreenWidth ()))
                {
                    startX = intersectX;
                    startY = (float)ScreenHeight ();
                }
                else if (topEdgeClip && (intersectX >= 0 && intersectX <= (float)ScreenWidth ()))
                {
                    startX = intersectX;
                    startY = 0;
                }
            }
            DrawLinePreClipped (drawSpace, colour, (int)startX, (int)startY, (int)endX, (int)endY);
        }
    
        static void DrawLine (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
            drawLine (drawSpace, colour, (float)leftEdge, (float)topEdge, (float)width, (float)height);
        }
    
        static void DrawRectangle (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
            for (int y = 0; y < height; y++)
                drawLine (drawSpace, colour, leftEdge, topEdge, width, height);
        }
    
        static void DrawRainbowLine (_G2D.Cell canvas, int startX, int startY, int endX, int endY)
        {
            int lineLength = Math.sqrt ((startX + endX) / (startY + endY));
        
            for (int i = 0; i < lineLength; i++)
            {
                context.setColour (Colour.Red);
                context.DrawLine (i, 0, i, 320);
            }
        }
        
        void DrawPixel (_G.* color, int pixelX, int pixelY)
        {
            Image.Draw_pixel (_2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + pixelX,
                _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + pixelY, color);
        }

        void DrawImage (Image* image, int leftEdge, int topEdge)
        {  
            Image.Draw (this, image,
                             _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + leftEdge,
                            _2D.Rectangle<_2D.Point_i_t>.Top_edge_int () + topEdge);
        }

        void DrawLine (_G.* color, int startX, int startY, int   endX, int   endY)
        {
            Line.Draw (this, color, _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + startX,
                _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + startY,
                _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + endX ,
                _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + endY);
        }

        void DrawVector (_G.* color, int startX, int startY, int vectorX, int vectorY)
        {
            int screenX, screenY;
                screenX = _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + startX;
                screenY = _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + startY;
      
            Line.Draw (this, color, screenX, screenY, screenX + vectorX, screenY + vectorY);
        }

        void DrawRectangle (_G.* color, int leftEdge, int topEdge, uint width, uint height)
        {
            Rectangle.Draw (this, color, _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + leftEdge,
            _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + topEdge, width, height);
        }

        void FillRectangle (_G.* color, int leftEdge, int topEdge, uint width, uint height)
        {
            Rectangle.Fill (this , color, _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + leftEdge,
                _2D.Rectangle<_2D.Point_i_t>.Top_edge_int () + topEdge, width, height);
        }

        void DrawRoundedRectangle (_G.* color, int leftEdge, int topEdge, uint width, uint height)
        {
            Rectangle.Draw_rounded (this, color, _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + leftEdge,
                _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + topEdge, width, height);
        }

        void FillRoundedRectangle (_G.* color, int leftEdge, int topEdge, uint width, uint height)
        {
            Rectangle.Fill_rounded (this, color, _2D.Rectangle<_2D.Point_i_t>.Left_edge_int () + leftEdge,
                _2D.Rectangle<_2D.Point_i_t>.Top_edge_int ()  + topEdge, width, height);
       }
       */

        _G.Colour_i colour;
    }
}
