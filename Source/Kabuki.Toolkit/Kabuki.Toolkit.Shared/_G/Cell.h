/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Cell.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _G.Cell class.
*/

#import "Color.h"
#import "Font.h"
#import "Rectangle.h"

#import <string>

namespace _G
{
/** A graphics cell. */
struct Cell : public Rectangle_i
{
    Color& BackgroundColor;

    Font&

    /**  */
    Cell (int leftEdge, int topEdge, int width, int height)
    {
    }

    //._2D
    //void Draw (d2.Polygon p);
    void Draw (std::string a, int x, int y)
    {

    }

    /**  */
    void Draw (std::string a, int x, int y, float thisAngle)
    {

    }

    /** Sets the grfx_G.Color_i. */
    static inline void SetColour (Color_i newColor)
    {

    }

    /**  */
    static inline void DrawImage (Image thisImage, int leftEdge, int topEdge)
    {

    }

    /**  */
    static inline void DrawImage (Image thisImage, int leftEdge, int topEdge, int newWidth, int newHeight)
    {

    }

    /**  */
    static inline void DrawLine (Cell canvas, double startX, double startY, double endX, double endY)
    {

    }

    /**  */
    static inline void DrawLine (Cell canvas, Color_i thisColour, int startX, int startY, int endX, int endY)
    {

    }

    /**  */
    static inline void DrawRectangle (Cell canvas, Color_i colour, int leftEdge, int topEdge, int width, int height)
    {

    }

    /**  */
    static inline void DrawRectangle (Cell canvas, Color_i colour, int leftEdge, int topEdge, int width, int height,
        int thickness)
    {

    }

    /**  */
    static inline void DrawOval (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void DrawRoundedRectangle (int x, int y, int width, int height, int arcWidth, int arcHeight)
    {

    }

    /**  */
    static inline void ClearArea (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void ClipArea (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void CopyArea (int x, int y, int width, int height, int dx, int dy)
    {

    }

    /**  */
    static inline void DrawArc (int x, int y, int width, int height, int startAngle, int arcAngle)
    {

    }

    /**  */
    static inline void DrawText (std::string thisText, int offset, int length, int x, int y)
    {

    }

    /**  */
    static inline void DrawPolygon (int[] xPoints, int[] yPoints, int nPoints)
    {

    }

    /**  */
    static inline void DrawPolyline (int[] xPoints, int[] yPoints, int nPoints)
    {

    }

    /**  */
    static inline void DrawRect (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void Fill (_2D.Polygon<int> p)
    {

    }

    /**  */
    static inline void Draw (_2D.Polygon<int> p)
    {

    }

    /**  */
    static inline void Fill3DRect (int x, int y, int width, int height, bool raised)
    {

    }

    /**  */
    static inline void FillArc (int x, int y, int width, int height, int startAngle, int arcAngle)
    {

    }

    /**  */
    static inline void FillOval (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void FillPolygon (int[]xPoints, int[]yPoints, int nPoints)
    {

    }

    /**  */
    static inline void FillRectangle (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void FillRound3dRectangle (int x, int y, int width, int height, int arcWidth, int arcHeight)
    {

    }

    /**  */
    static inline void SetClip (int x, int y, int width, int height)
    {

    }

    /**  */
    static inline void SetClip (_2D.Entity thisShape)
    {

    }

    /**  */
    static inline void SetXORMode (Color_i newColor)
    {

    }

    /**  */
    static inline void Translate (int x, int y)
    {

    }

    Color_i colour;
};
}
