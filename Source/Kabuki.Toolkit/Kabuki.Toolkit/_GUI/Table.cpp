/** Underscore
    @file       /.../Kabuki.Toolkit/_GUI2D/Table.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

using System.Collections.Generic;

namespace _GUI2D
{
    /**  */
    class Table : Entity
    {
        const int MaxNumRows = 0x7FFFFFFF;   //< 

        /**  */ 
        Table (int leftEdge, int topEdge, int width, int height, _G.Colour backgroundColour, int maxNumRows) :
            base (leftEdge, topEdge, width, height, backgroundColour)
        {
            rows[maxNumRows];
        }  
    
         void AddRow ()
         {
             IEvent newTable[numColums][++numRows];
        
            if (Rectangle.Height == rows.MaxSize)
            {
                return false;
            }
            if (newRow.Width!=Width)
                newRow.Resize (Width);
            
            int height=0;
            Rectangle currentBounds;
            
            _Data.Iterator iteration = rows.GetIterator ();
            
            while (iteration.isNotDone ()) // calculate height
            {
                currentBounds = (Rectangle) iteration.nextObject ();
                height+=currentBounds.Height;
            }
            if (height + newRow.Width <= Width)
            {
                rows.add (newRow);
                return true;
            }
            return false;
        }  
    
        void NumRows     {  get { return row.size ();} }
    
        void Update ()
        {
            int height=0;
            Rectangle currentBounds;
        
            Iterator iteration = rows.iterator ();
        
            while (iteration.isNotDone ())
            {
                currentBounds = (g2d.Rectangle) iteration.nextObject ();
                currentBounds.Point ().y = height;
                currentBounds.Point ().x = Point ().x;
                currentBounds.setMaxWidth (Width);
                height += currentBounds.Height;
            }  
        }  
    
        void Draw (_G2D.Cell canvas)
        {  
            Rectangle.Draw (context);
        
            Rows.Draw (context);
        }

List<TableRow> rows;
    }
}