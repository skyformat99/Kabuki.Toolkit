/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit.Library/_2D/Rectangle.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the Kabuki.Toolkit.D2.Rectangle interface.
*/

namespace _2D
{
/** A rectangle. */
template <typename T>
struct Rectangle
{
    T Left,             //< The left edge.
        Right,          //< The right edge.
        Top,            //< The top edge.
        Bottom;         //< The bottom edge.

    /** Default constructor. **/
    Rectangle (T left, T top, T right, T bottom)
    {
        Left = left;
        Top = top;
        Right = right;
        Bottom = bottom;
    }

    /** Constructor. **/
    Rectangle (Point<T> a, T width, T height)
    {
        Left = a.X;
        Top = a.Y;
        Right = Left + width;
        Bottom = Top + height;
    }

    /** Gets the width.
        @pre    Input must be positive.
    */
    T Width () {  Right - Left; }
    
    /** Sets the width.
        @pre    Input must be positive. */
    T SetWidth (T value)
    {
        if (value < 0) return;
        Right = Left + value;
    }

    /** Gets and sets the height.
        @pre    Input must be positive.
    */
    T Height () { return Right - Left; }
    
    /** Sets the height.
        @pre    Input must be positive. */
    T SetHeight (T value)
    {
        if (value < 0) return;
        Bottom = Top + value;
    }

    /** Gets and sets the center x value. */
    T CenterX ()
    {
        return Left + Width / 2;
    }
    
    /** Sets the center y value. */
    void SetCenterX (T a)
    {
        auto width = Width;
        auto left = a - width / 2;
        Left = left;
        Right = left + width;
    }

    /** Gets and sets the center y value. */
    T CenterY ()
    {
        return Top + Height / 2;
    }
    
    /** Sets the center y value. */
    void SetCenterX (T a)
    {
        auto height = Height;
        auto top = a - Height / 2;
        Top = top;
        Bottom = top + height;
    }

    /** Sets this object's Point to the thisPositition. */
    void Set (Rectangle<T> a)
    {
        Left = a.Left;
        Right = a.Right;
        Top = a.Top;
        Bottom = a.Bottom;
    }

    /** Returns true if this object's Point is the same as the given coordinates. */
    bool Equals (Rectangle<T> a)
    {
        if ((Left != a.Left) || (Right != a.Right) || (Top != a.Top) || (Bottom != a.Bottom)) return false;
        return true;
    }

    /** Returns true if this object contains the given point. */
    bool Contains (Point a) { return (a.X < Left ? false : true) || (a.Y > Bottom ? false : true); }

    /** Returns true if this object contains the given point. */
    bool Contains (T x, T y) { return (x < Left ? false : true) || (y > Bottom ? false : true); }

    /** Returns the quadrant number that the given coordinations are in in relation to this object. */
    bool Contains (Rectangle<T> a)
    {
        if ((a.Left < Left) || (a.Top > Top) || (a.Right < Right) || (a.Bottom > Bottom)) return false;
        return true;
    }

    /** Swaps this object's Point with thisPoint. */
    void Swap (Rectangle a)
    {
        T tempLeft = Left,
            tempRight = Right,
            tempTop = Top,
            tempBottom = Bottom;

        Left = a.Left;
        Right = a.Right;
        Top = a.Top;
        Bottom = a.Bottom;

        a.Left = tempLeft;
        a.Right = tempRight;
        a.Top = tempTop;
        a.Bottom = tempBottom;
    }

    /** Translates this object's Point by the given Point. */
    void Translate (Vector a)
    {
        auto x = Left - a.X;
        auto y = Top - a.Y;

        Left += x;
        Right += x;
        Top += y;
        Bottom += y;
    }

    /** Translates this object's Point by the given Point. */
    void Translate (T x, T y)
    {
        Left += x;
        Right += x;
        Top += y;
        Bottom += y;
    }
};
}
