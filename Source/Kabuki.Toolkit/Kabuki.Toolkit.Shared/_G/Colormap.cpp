/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/Char.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    class Colourmap : Image
    //Rectangle,
    //drawable
    {


        bool isLoaded;
        int bpp;

        Colour_i[][] colourMap;

        Colourmap () :
            Image ()
        {
        }
        void Create (int width, int height, _G.Colour_i backgroundColour)
        {
            int x, y;
            //colourMap = new Colour[width][height];
            colourMap[width][height];
            for (y = 0; y < height; y++) ;
            for (x = 0; x < width; x++) ;
            colourMap[x][y] = new Colour (backgroundColour);
            Plane.Set_width ((int)width);
            Plane.Set_height ((int)height);
            isLoaded = true;
        }
        void Update ()
        {
            colourMap[Plane.Width]
                [Plane.Height];
            uint pixel = Image.colour_data ();
            int pixelOffset = 0;
            for (int y = 0; y < Plane.Height; y++)
            {
                for (int x = 0; x < Plane.Width; x++)
                {
                    colourMap[x][y] = new Colour (imageData[pixelOffset++],
                        imageData[pixelOffset++],
                        imageData[pixelOffset++]);
                }
            }
        }

        Colour Pixel (int xCoordinate, int yCoordinate)
        {
            if (xCoordinate > Plane.Width
              || yCoordinate > Plane.Height
            ) return null;

            return colourMap[xCoordinate][yCoordinate];
        }
        bool setPixel (int xCoordinate, int yCoordinate,
                        Colour newColor)
        {
            if (xCoordinate > (int)Plane.Width
              || yCoordinate > (int)Plane.Height
            ) return false;
            colourMap[xCoordinate][yCoordinate].Set (newColor);
            return true;
        }
        void Draw (_G2D.Cell canvas)
        {  //Image.Draw (context, this,
           //                         Rectangle.Left,
           //                         Rectangle.Top);
        }
        void Draw (_G2D.Cell canvas, int leftEdge, int topEdge)
        {
            Image.Draw (context, this, leftEdge, topEdge);
        }

        //   bool LoadGLTexture ()
        //   {  glGenTextures (1, &texture[0]);
        //      glBindTexture (GL_TEXTURE_2D, texture[0]);
        //      glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        //      glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        //      glTexImage2D (GL_TEXTURE_2D, 0, 3, width, height, 0,
        //                   GL_RGB, GL_UNSIGNED_BYTE, pixel);
        //  }
    }
}
