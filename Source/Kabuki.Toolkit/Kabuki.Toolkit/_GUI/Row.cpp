/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/TableRow.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Collections.Generic;

namespace _G2D
{
    /**  */
    class Row : Entity
    {
        LinkedList components;
        
        Row (_2D.Point_i upperLeftHandCorner, int width, int height, _G.Colour_i backgroundColour);
        {
            base (upperLeftHandCorner, width, height, backgroundColour);
            components = new LinkedList ();
        }
        
        bool add (Entity newElement)
        {
            Iterator iteration = components.iterator ();
            
            int width=0;
            Rectangle currentBounds;        
            while (iteration.isNotDone ())
            {
                currentBounds = (g2d.Rectangle) iteration.nextObject ();
                width += currentBounds.Width;
            }
            if (width+newEvent.Width > maxWidth ())
            {
                newEvent.setMaxHeight (Height);
                newEvent.Point ().x = width;
                newEvent.Point ().y = Point ().y;
                components.add (newEvent);
            }
        }        
        
        bool resize (int newWidth)
        {
            if (width>0)
            {
                float scaleFactor = Width/newWidth;            
                Resizeable2D currentResizableEvent;
                
                Iterator iteration = visibleEvents.iterator ();
                while (iteration.isNotDone ())
                {  currentResizableEvent = (Resizable) iteration.nextObject ();
                    currentResizableEvent.resize (currentResizableEvent.WidthscaleFactor, Height);
                }
                
                return true;
            }  
            return false;
        }  
        
        bool resize (int newWidth, int newHeight)
        {
            if (width>0 && height>0)
            {  float scaleFactorX = Width / newWidth;
                
                Resizeable2D currentResizableEvent;
                
                Iterator iteration = visibleEvents.iterator ();
                while (iteration.isNotDone ())
                {  currentResizableEvent = (Resizable) iteration.nextObject ();
                    currentResizableEvent.resize (currentResizableEvent.Width scaleFactorX, newHeight);
                }  
                
                return true;
            }  
            return false;
        }      
        
        void Update ()
        {
            int width=0;
            g2d.Rectangle currentBounds;
            
            Iterator iteration = rows.iterator ();
            
            while (iteration.IsNotDone ())
            {
                currentBounds = (g2d.Rectangle) iteration.nextObject ();
                currentBounds.SetLeftEdge  (width);
                currentBounds.SetTopEdge    (TopEdge ());
                currentBounds.setMaxHeight (Height);
                width += currentBounds.Width;
            }  
        }
        
        void Draw (ImageObserver driversIO, Graphics page)
        {
            base.Draw (driversIO, page);
                    
            Iterator iteration = rows.iterator ();
            
            GraphicsEvent currentVisibleEvent;
            
            while (iteration.isNotDone ())
            {
                currentVisibleEvent = (GraphicsEvent) iteration.nextObject ();
                currentVisibleEvent.Draw (driversIO, page);
            }
        }  
    }
}