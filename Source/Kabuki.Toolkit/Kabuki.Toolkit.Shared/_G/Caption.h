/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Caption.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#include <string>

#include "Cell.h"

namespace _G
{
/**  */
class Caption
{
    /**  */
    Caption ():
        base (0, 0, 0, 0)
    {
        lrMargin = 5;
        tbMargin = 5;

        captionText = new TextArea (0, 0, 0, 0);
        SetBorderMode (Cell.FillRoundCorners);
    }

    Caption (int captOriginX, int captOriginY):
        base (captOriginX, captOriginY, 0, 0)
    {
        origin.x = captOriginX;
        origin.y = captOriginY;
        captionText = new TextArea (origin.x, origin.y, 0, 0);
        SetBorderMode (Cell.FillRoundCorners);
    }

    void SetText (std::string newString)
    {
    }

    void SetVerticalMargin (uint newTBMargen)
    {
        tbMargin = newTBMargen;
    }

    void SetHorizontalMargin (uint newLRMargin)
    {
        lrMargin = newLRMargin;
    }

    void Update ()
    {
        captionText.Set_left_edge (Left_edge_int () + lrMargin;
        captionText.Set_top_edge (Top_edge_int () + tbMargin;
        SetWidth (captionText.Left_edge_int () + lrMargin);
        SetHeight (captionText.Bottom_edge_int () + tbMargin);
    }

    void Draw (Image* canvas)
    {
        if (isVisible)
            return;

        Rectangle.Draw (drawSpace);
        captionText.Draw (canvas);
    }

    std::string ToString ()
    {
        return captionText.ToString ();
    }

    private:

    _2D.Point_i origin;
    TextArea captionText;
    int lrMargin = 5, tbMargin = 5;
    bool isVisible = false;
};
}
