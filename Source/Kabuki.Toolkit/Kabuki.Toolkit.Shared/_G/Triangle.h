/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G2D/Triangle.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#import +

namespace _G2D
{
    /**  */
    class Triangle: public _2D.Triangle, Cell
    {
    /**  */
    Triangle (): base ()
    {
    }

    Triangle (_2D.Point_i initOne, _2D.Point_i initTwo, _2D.Point_i initThree):
        base (initOne, initTwo, initThree)
    {

    }

    Triangle (int x1, int y1, int x2, int y2, int x3, int y3):
        base (x1, y1, x2, y2, x3, y3);

    void Draw (_G2D.Cell canvas);

    void Draw (_G2D.Cell canvas, _G.Colour colour);

    /** Draws a triangle on the screen */
    static inline void Draw (_G2D.Cell canvas, _G.Colour colour, Triangle drawShape);

    /** Draws a triangle on the screen */
    static inline void Draw (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3);

    static inline void Fill (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3);
    static inline void DrawBottom (_G2D.Cell canvas, _G.Colour colour, int x1, int y1, int x2, int y2, int x3, int y3);

    private:

    _G.Colour_i colour;
};
}
