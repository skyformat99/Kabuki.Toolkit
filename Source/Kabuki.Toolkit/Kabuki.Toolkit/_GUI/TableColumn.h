/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G2D/TableColumn.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Collections.Generic;

namespace _G2D
{
    /**  */
    class Column : BorderedElement
    {
        LinkedList components;
        
        Column (_2D.Point upperLeftHandCorner, int width, int height, _G.Colour_i backgroundColour);
        {
            base (upperLeftHandCorner, width, height, backgroundColour);
            components = new LinkedList ();
        }
        
        bool add (BorderedElement newEvent)
        {  
            Iterator iteration = components.iterator ();
            
            int height=0;
            g2d.Rectangle currentBounds;
            
            while (iteration.IsNotDone ())
            {
                currentBounds = (g2d.Rectangle) iteration.nextObject ();
                height += currentBounds.Height;
            }
            if (height+newEvent.Height > maxHeight ())
            {
                newEvent.setMaxWidth (Width);
                newEvent.Point ().x = Point ().x;
                newEvent.Point ().y = height;
                components.add (newEvent);
            }  
        }  
        
        bool resize (int newWidth)
        {
            if (width > 0)
            {
                float scaleFactor = Width/newWidth;            
                ResizableLinear currentResizableEvent;
                
                Iterator iteration = visibleEvents.iterator ();
                while (iteration.isNotDone ())
                {
                    currentResizableEvent = (ResizableLinear) iteration.nextObject ();
                    currentResizableEvent.Resize (currentResizableEvent.WidthscaleFactor, Height);
                }
                
                return true;
            }
            return false;
        }
        
        bool resize (int newWidth, int newHeight)
        {
            if (width > 0 && height > 0)
            {
                float scaleFactorX = Width / newWidth;
                
                Resizeable2D currentResizableEvent;
                
                Iterator iteration = visibleEvents.iterator ();
                while (iteration.isNotDone ())
                {
                    currentResizableEvent = (Resizeable2D) iteration.nextObject ();
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
            
            while (iteration.isNotDone ())
            {
                currentBounds = (g2d.Rectangle) iteration.nextObject ();
                currentBounds.SetLeftEdge (width);
                currentBounds.SetTopEdge (TopEdge ());
                currentBounds.setMaxHeight (Height);
                width += currentBounds.Width;
            }  
        }
        
        void Draw (Image screenBuffer)
        {
            Menu.Draw (screenBuffer);
                    
            Iterator iteration = components.iterator ();
            
            IEvent currentVisibleEvent;
            
            while (iteration.isNotDone ())
            {
                currentVisibleEvent = (IEvent) iteration.nextObject ();
                currentVisibleEvent.Draw (screenBuffer);
            }
        }  
    }
}  