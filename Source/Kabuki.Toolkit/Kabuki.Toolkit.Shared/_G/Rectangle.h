/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G2D/Rectangle.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    class Rectangle<T> : _2D.Rectangle<T> Entity
    {
        /**  */
        Rectangle (Point relativePosition, Point dimensions)
        {
            //base (relativePosition, dimensions)
        }

        /**  */
        static void Draw (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
            // All we need to do is draw the outline of the rectangle
            //The lines drawing routines will clip the lines for us
            Line.DrawHorizontal (context, colour, leftEdge, topEdge, width);
            Line.DrawHorizontal (context, colour, leftEdge, topEdge + height, width);
            Line.DrawVertical (context, colour, leftEdge, topEdge + 1, height - 2);
            Line.DrawVertical (context, colour, leftEdge + width, topEdge + 1, height - 2);
        }

        /**  */
        static void Fill (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
            // The first thing that we need to do is check to see if the width or height
            // are negative and if they are, translate the north-west corner by that and
            // reverse the polarity of the dimension

            if (width < 0)
            {
                leftEdge += width;
                width = -width;
            }
            if (height < 0)
            {
                topEdge += height;
                height = -height;
            }
            if (leftEdge > context.Width || topEdge > context.Height) return;//< It's is off the screen

            // The second step is to clip the rectangle to the context
            if (leftEdge < 0)
            {
                if (leftEdge < -width)
                    return;
                leftEdge = 0;
            }
            if (topEdge < 0)
            {
                if (topEdge < -height)
                    return;
                topEdge = 0;
            }
            if (width > context.Width)
            {
            }
        }

        /**  */
        static void FillClipped (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
            int startOffset;
        }

        /**  */
        static void DrawRounded (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
        }

        /**  */
        static void FillRounded (_G2D.Cell canvas, _G.Colour_i colour, int leftEdge, int topEdge, int width, int height)
        {
        }

        /**  */
        void Draw (_G2D.Cell canvas)
        {
            Rectangle.Draw (context, thisColour, Left, Rectangle.Top, Rectangle.Width, Rectangle.Height);
        }

        /**  */
        void Fill (_G2D.Cell canvas)
        {
            Rectangle.Fill (context, thisColour, Rectangle.Left, Rectangle.Top, Rectangle.Width,
                Rectangle.Height);
        }

        Colour thisColour;
    }
}
