/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G2D/Line.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _G.Line interface.
*/

import "Cell.h"

namespace _G2D
{
/**  */
class Line : public Entity
{
    Line (Point startingPoint, Point endingPoint):
        Line (startingPoint, endingPoint)
    {
    }

    static void DrawRainbowLine (Cell canvas, int startX, int startY, int endX, int endY)
    {
        int lineLength = Math.sqrt ((startX + endX) / (startY + endY))
            Point clipedLine = Line.clip_to_rectangle (context.Left, context.Top,
                context.Right_edge_int (), context.bottom_edge_int ());

        for (int i = 0; i < lineLength; i++)
            ;
    }

    void SetColour (Color_i newColour) { colour = newColour; }

    void Draw (Cell canvas)
    {
        Draw (context, colour, Line.Point_one ().X_int (), Line.Point_one ().Y_int (),
            Line.Point_two ().X_int (), Line.Point_two ().Y_int ());
    }
    static void Draw (Cell canvas, _G.Colour_i colour, int startX, int startY, int endX, int endY)
    {
        /// The first step is to see if the lines are horizontal or vertical because there is a faster algorythms 
        /// to draw them.

        Line clipedLine;
        clipedLine = Line.ClipToRectangle (0, 0, context.Width, context.Height, startX, startY, endX, endY);

        if (clipedLine == null)
            return;

        if (startY == endY)
        {
            if (startX < 0 || endX > context.Width) return; ///< Then the line is out of bounds

            if (startX == endX) //< Single pixel
            {
                if (startY < 0 || startY > context.Height) return; //< The pixel is out of bounds
                context.setPixel (startX, startY, colour);
                return;
            }
            Line.DrawHorizontal (context, colour, startX, startY,
                endX - startY);
            return;
        }
        if (startX == endX) //< Vertical line
        {
            if (startY < 0 || endY > context.Height) return; //< Then the line is off the screen

            if (startY == endY)
            {
                if (startX < 0 || startX > context.Width) return;   //< The pixel is out of bounds

                context.setPixel (startX, startY, colour);
                return;
            }
            Line.DrawVertical (context, colour, startX, startY, endX - startY);
            return;
        }
        if (context.bPP () == 4)//32-bit needs the most time to copy, goes first.
        {
            Line.DrawClipped (context, colour.Red (), colour.Green (), colour.blue (), colour.alpha (),
                (clipedLine.Point_one ().Y_int ()  context.Width_bytes ()) + (clipedLine.Point_one ().X_int ()  4),
                0,
                (clipedLine.Point_two ().Y_int ()  context.Width_bytes ()) + (clipedLine.Point_two ().X_int ()  4));
        }
        else if (context.bPP () == 3)    //< 24-bit images are the most common.
        {
            Line.DrawClipped (context, colour.Red (), colour.Green (), colour.blue (),
                (clipedLine.Point_one ().Y_int ()  context.Width_bytes ()) + (clipedLine.Point_one ().X_int ()  3),
                0,
                (clipedLine.Point_two ().Y_int ()  context.Width_bytes ()) + (clipedLine.Point_two ().X_int ()  3));
        }
        else if (context.bPP () == 2)//
        {
            Line.DrawClipped (context, colour.Red (), colour.Green (),
                (clipedLine.Point_one ().Y_int ()  context.Width_bytes ())
                + (clipedLine.Point_one ().X_int ()  2),
                0,
                (clipedLine.Point_two ().Y_int ()  context.Width_bytes ())
                + (clipedLine.Point_two ().X_int ()  2));
        }
        else
            if (context.bPP () == 1)
            {
                Line.DrawClipped (context, colour.Red (),
                    (clipedLine.Point_one ().Y_int ()  context.Width_bytes ())
                    + clipedLine.Point_one ().X_int (),
                    0,
                    (clipedLine.Point_two ().Y_int ()  context.Width_bytes ())
                    + clipedLine.Point_two ().X_int ());
            }
    }
    static void DrawClipped (Cell canvas, int colourValue,
        / This method draws a line / int contextOffset, int lineDelta,
        / In 16 - bit colour using 2D / int endingOffset)
    {
        Array Memory coordinates.We know that the line is going to be at least
            //1 pixel long, so we can use a do{}while (); control structure
            int contextData = context.colour_data ();
        int overflowIndex = 0;
        do
        {
            contextData[contextOffset] = colourValue;
        } while ((contextOffset += lineDelta) != endingOffset);
    }
    static void DrawClipped (Cell canvas, int colourValue1,
        / This method draws a line / int colourValue2, int contextOffset,
        / In 16 - bit colour using 2D / int lineDelta, int endingOffset)
    {
        Array Memory coordinates.We know that the line is going to be at least
            //1 pixel long, so we can use a do{}while (); control structure
            int contextData = context.colour_data ();
        int overflowIndex = 0;
        do
        {
            contextData[contextOffset] = colourValue1;
            contextData[contextOffset + 1] = colourValue2;
        } while ((contextOffset += (int)lineDelta) != endingOffset);
    }
    static void DrawClipped (Cell canvas, int red, int green,
        / This method draws a line / int blue, int contextOffset,
        / In 24 - bit colour using 2D / int lineDelta, int endingOffset)
    {
        Array Memory coordinates.We know that the line is going to be at
            //least 1 pixel long, so we can use a do{}while (); control structure
            int contextData = context.colour_data ();
        int overflowIndex = 0;
        do
        {
            contextData[contextOffset] = red;
            contextData[contextOffset + 1] = green;
            contextData[contextOffset + 2] = blue;
        } while ((contextOffset += lineDelta) != endingOffset);
    }

    /** Draws a line in 32-bit colour. */
    static void DrawClipped (Cell canvas, int red, int green, int blue, int alpha, int contextOffset, int lineDelta, int endingOffset)
    {
        /// We know that the line is going to be at least 1 pixel long,
        /// so we can use a do{}while (); control structure
        int contextData = context.colour_data ();
        int overflowIndex = 0;
        do
        {
            contextData[contextOffset] = red;
            contextData[contextOffset + 1] = green;
            contextData[contextOffset + 2] = blue;
            contextData[contextOffset + 3] = alpha;
        } while ((contextOffset += lineDelta) != endingOffset);
    }
    static void DrawVertical (Cell canvas,
        Color_i colour,
        int startX, int startY, int length)
    {
        if (length == 0 || startX < 0 || startX > context.Width)
            // The line is compleatly off screen
            return;
        if (length < 0)
        {
            The line startY needs to be traslated
                //so that the length is a positive.
                startY += length;// legnth is negative so this is subtraction.
            length = -1;
        }
        if (startY < -length || startY > context.Height)
        {
            Line is not visible
                return;
        }
        //The line is now definatly visible so all we need to do is
        //clip the left part to 0 and right to the cavas's height

        int contextOffset, endingOffset;
        if (context.bPP () == 1)
        {
            if (startY < 0)
                contextOffset = ((-startY  context.Width_bytes ())
                    + startX);
            else
                contextOffset = (startY  context.Width_bytes ()) + startX;

            if (length > context.Height)
                endingOffset = (context.Height  context.Width_bytes ())
                + startX;
            else
                endingOffset = (startY  context.Width_bytes ()) + startX;

            Line.Draw_clipped_vertical (context, colour.Red (),
                contextOffset, endingOffset);
        }
        else
            if (context.bPP () == 2)
            {
                if (startY < 0)
                    contextOffset = (-startY  context.Width_bytes ()) + (startX  2);
                else
                    contextOffset = (startY  context.Width_bytes ()) + (startX  2);
                if (length > context.Height)
                    endingOffset = (context.Height  context.Width_bytes ())
                    + (startX  2);
                else
                    endingOffset = (startY  context.Width_bytes ())
                    + (startX  2);
                Line.Draw_clipped_vertical (context, colour.Red (),
                    colour.Green (), startX,
                    contextOffset, endingOffset);
            }
            else
                if (context.bPP () == 3)
                {
                    if (startY < 0)
                        contextOffset = (-startY  context.Width_bytes ()) + (startX  3);
                    else
                        contextOffset = (startY  context.Width_bytes ()) + (startX  3);
                    if (length > context.Height)
                        endingOffset = (context.Height  context.Width_bytes ())
                        + (startX  3);
                    else
                        endingOffset = (startY  context.Width_bytes ()) + (startX  3);
                    Line.Draw_clipped_vertical (context, colour.Red (),
                        colour.Green (), colour.blue (),
                        contextOffset, endingOffset);
                }
                else
                    if (context.bPP () == 4)
                    {
                        if (startY < 0)
                            contextOffset = (-startY  context.Width_bytes ()) + (startX  4);
                        else
                            contextOffset = (startY  context.Width_bytes ()) + (startX  4);
                        if (length > context.Height)
                            endingOffset = (context.Height  context.Width_bytes ())
                            + (startX  4);
                        else
                            endingOffset = (startY  context.Width_bytes ()) + (startX  4);
                        Line.Draw_clipped_vertical (context,
                            colour.Red (), colour.Green (),
                            colour.blue (), colour.alpha (),
                            contextOffset, endingOffset);
                    }
    }

    /** Draws a preclipped in 8-bit color. */
    static void Draw_clipped_vertical (Cell canvas, int colourValue, int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        /// We can do a do{}while; loop here because we know that
        /// there is more then one pixel
        do
        {
            contextData[contextOffset] == colourValue;
        } while (contextOffset += context.Width_bytes () < endingOffset);
    }

    /** Draws a preclipped in 16-bit color. */
    static void Draw_clipped_vertical (Cell canvas, int colourValue1, int colourValue2,
        int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        /// We can do a do{}while; loop here because we know that
        /// there is more then one pixel
        do
        {
            contextData[contextOffset] == colourValue1;
            contextData[contextOffset + 1] == colourValue2;
        } while (contextOffset += context.Width_bytes () < endingOffset);
    }

    /** Draws a preclipped in 24-bit color. */
    static void Draw_clipped_vertical (Cell canvas, int red, int green, int blue,
        int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        /// We can do a do{}while; loop here because we know that
        /// there is more then one pixel
        do
        {
            contextData[contextOffset] == red;
            contextData[contextOffset + 1] == green;
            contextData[contextOffset + 2] == blue;
        } while (contextOffset += context.Width_bytes () < endingOffset);
    }

    /** Draws a preclipped in 32-bit color. */
    static void Draw_clipped_vertical (Cell canvas, int red, int green, int blue, int alpha,
        int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        //We can do a do{}while; loop here because we know that
        //there is more then one pixel
        do
        {
            contextData[contextOffset] == red;
            contextData[contextOffset + 1] == green;
            contextData[contextOffset + 2] == blue;
            contextData[contextOffset + 3] == alpha;
        } while (contextOffset += context.Width_bytes () < endingOffset);
    }
    static void Draw_horizontal (Cell canvas, _G.Colour_i colour, int startX, int startY, int length)
    {
        if (length == 0 || startY < 0 || startY > context.Height)
        {
            Line is not visible
                return;
        }
        if (length < 0)
        {
            The line startX needs to be traslated
                //so that the length is a positive.
                startX += length;// legnth is negative so this is subtraction.
            length = -1;
        }
        if (startX < -length || startX > context.Width)
        {
            Line is not visible
                return;
        }
        //The line is now definatly visible so all we need to do is
        //clip the left part to 0 and right to the cavas's height

        int contextOffset, endingOffset;


        if (context.bPP () == 1)
        {
            if (startX < 0)
                contextOffset = startX;
            else
                contextOffset = (startY  context.Width_bytes ()) + startX;

            if (length > context.Height)
                endingOffset = ((context.Height - 1)  context.Width_bytes ())
                + startX;
            else
                endingOffset = (startY  context.Width_bytes ()) + startX;

            Line.DrawClippedHorizontal (context, colour.Red (),
                contextOffset, endingOffset);
        }
        else
            if (context.bPP () == 2)
            {
                if (startX < 0)
                    contextOffset = startX  2;
                else
                    contextOffset = (startY  context.Width_bytes ()) + (startX  2);

                if (length > context.Height)
                    endingOffset = ((context.Height - 1)  context.Width_bytes ())
                    + (startX  2);
                else
                    endingOffset = (startY  context.Width_bytes ()) + (startX  2);

                Line.DrawClippedHorizontal (context, colour.Red (),
                    colour.Green (), startX,
                    contextOffset, endingOffset);
            }
            else
                if (context.bPP () == 3)
                {
                    if (startX < 0)
                        contextOffset = startX  3;
                    else
                        contextOffset = (startY  context.Width_bytes ()) + (startX  3);

                    if (length > context.Height)
                        endingOffset = ((context.Height - 1)  context.Width_bytes ())
                        + (startX  3);
                    else
                        endingOffset = (startY  context.Width_bytes ()) + (startX  3);

                    Line.DrawClippedHorizontal (context, colour.Red (),
                        colour.Green (), colour.blue (),
                        contextOffset, endingOffset);
                }
                else
                    if (context.bPP () == 4)
                    {
                        if (startX < 0)
                            contextOffset = startX  4;
                        else
                            contextOffset = (startY  context.Width_bytes ()) + (startX  4);

                        if (length > context.Height)
                            endingOffset = ((context.Height - 1)  context.Width_bytes ())
                            + (startX  4);
                        else
                            endingOffset = (startY  context.Width_bytes ()) + (startX  4);

                        Line.DrawClippedHorizontal (context,
                            colour.Red (), colour.Green (),
                            colour.blue (), colour.alpha (),
                            contextOffset, endingOffset);
                    }
    }

    /** Draws a preclipped horizontal line in 24-bit colour. */
    static void DrawClippedHorizontal (Cell canvas, int colourValue, int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        //Error:  This loop assumes that the context is in 24-bit colour
        while (contextOffset < endingOffset)
            contextData[contextOffset++] = colourValue;
    }

    /** Draws a preclipped horizontal line in 16-bit colour. */
    static void DrawClippedHorizontal (Cell canvas, int colourValue1, int colourValue2,
        int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        /// Error:  This loop assumes that the context is in 24-bit colour
        while (contextOffset < endingOffset)
        {
            contextData[contextOffset++] = colourValue1;
            contextData[contextOffset++] = colourValue2;
        }
    }

    /** Draws a preclipped horizontal line in 24-bit colour. */
    static void DrawClippedHorizontal (Cell canvas, int red, int green, int blue,
        int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        /// Error:  This loop assumes that the context is in 24-bit colour
        while (contextOffset < endingOffset)
        {
            contextData[contextOffset++] = red;
            contextData[contextOffset++] = green;
            contextData[contextOffset++] = blue;
        }
    }

    /** Draws a preclipped horizontal line in 32-bit colour. */
    static void DrawClippedHorizontal (Cell canvas, int red, int green, int blue, int alpha,
        int contextOffset, int endingOffset)
    {
        int contextData = context.colour_data ();
        /// Error:  This loop assumes that the context is in 24-bit colour
        while (contextOffset < endingOffset)
        {
            contextData[contextOffset++] = red;
            contextData[contextOffset++] = green;
            contextData[contextOffset++] = blue;
            contextData[contextOffset++] = alpha;
        }
    }

    Color_i colour;
}
}
