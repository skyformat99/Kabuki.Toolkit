/****************************************************************************

  GLUI User Interface Toolkit
  ---------------------------

     bitmaps.cpp

Draws the hardcoded images listed in bitmap_img_data with OpenGL.

FIXME: upload the images to a texture.  This will allow them to be:
    - Drawn with alpha blending
    - Drawn at random sizes and angles onscreen
    - Drawn much faster than with glDrawPixels

 --------------------------------------------------

  Copyright (c) 1998 Paul Rademacher

  WWW:    http://sourceforge.net/projects/glui/
  Forums: http://sourceforge.net/forum/?group_id=92496

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*****************************************************************************/

#include "../Public/_GUI/UI.h"
#include "Internal.h"
#include <cassert>

/************ Image Bitmap arrays **********/

extern unsigned char ImgCheckBox0[];
extern unsigned char ImgCheckBox1[];
extern unsigned char img_radiobutton_0[];
extern unsigned char img_radiobutton_1[];
extern unsigned char img_uparrow[];
extern unsigned char img_downarrow[];
extern unsigned char img_leftarrow[];
extern unsigned char img_rightarrow[];
extern unsigned char img_spinup_0[];
extern unsigned char img_spinup_1[];
extern unsigned char img_spindown_0[];
extern unsigned char img_spindown_1[];
extern unsigned char imgCheckBox_0_dis[];
extern unsigned char imgCheckBox_1_dis[];
extern unsigned char img_radiobutton_0_dis[];
extern unsigned char img_radiobutton_1_dis[];
extern unsigned char img_spinup_dis[];
extern unsigned char img_spindown_dis[];
extern unsigned char img_listbox_up[];
extern unsigned char img_listbox_down[];
extern unsigned char img_listbox_up_dis[];


// These must be in the same order as the STDBITMAP enums from glui.h!
unsigned char *bitmap_arrays[] = {
    ImgCheckBox0,
    ImgCheckBox1,
    img_radiobutton_0,
    img_radiobutton_1,
    img_uparrow,
    img_downarrow,
    img_leftarrow,
    img_rightarrow,
    img_spinup_0,
    img_spinup_1,
    img_spindown_0,
    img_spindown_1,
    imgCheckBox_0_dis,
    imgCheckBox_1_dis,
    img_radiobutton_0_dis,
    img_radiobutton_1_dis,
    img_spinup_dis,
    img_spindown_dis,
    img_listbox_up,
    img_listbox_down,
    img_listbox_up_dis,
};


/************************************ Bitmap::load_from_array () ********/

Bitmap::Bitmap () : 
    pixels (NULL),
    w (0),
    h (0)
{
}

Bitmap::~Bitmap ()
{
    if (pixels)
    {
        free (pixels);
        pixels = NULL;
    }
}

/* Create bitmap from greyscale byte array */
void Bitmap::InitGrey (unsigned char *array)
{
    w = array[0]; h = array[1];
    pixels = (unsigned char *)malloc (w*h * 3);
    assert (pixels);

    for (int i = 0; i < w*h; i++)
        for (int j = 0; j < 3; j++) /* copy grey to r,g,b channels */
            pixels[i * 3 + j] = (unsigned char)array[i + 2];
}


/* Create bitmap from color int array.
 (OSL) This used to be how all GLUI bitmaps were stored, which was horribly
  inefficient--three ints per pixel, or 12 bytes per pixel!
*/
void Bitmap::Init (int *array)
{
    w = array[0]; 
    h = array[1];
    pixels = (unsigned char *)malloc (w*h * 3);
    assert (pixels);

    for (int i = 0; i < w*h * 3; i++)
        pixels[i] = (unsigned char)array[i + 2];
}


/*********************************** StdBitmaps::Draw () *****************/

StdBitmaps::StdBitmaps ()
{
    for (int i = 0; i < STDBITMAP_NUM_ITEMS; i++)
        bitmaps[i].InitGrey (bitmap_arrays[i]);
}

StdBitmaps::~StdBitmaps ()
{
}

int StdBitmaps::width (int i) const
{
    assert (i >= 0 && i < STDBITMAP_NUM_ITEMS);
    return bitmaps[i].w;
}

int StdBitmaps::height (int i) const
{
    assert (i >= 0 && i < STDBITMAP_NUM_ITEMS);
    return bitmaps[i].h;
}

void StdBitmaps::Draw (int i, int x, int y) const
{
    assert (i >= 0 && i < STDBITMAP_NUM_ITEMS);

    if (bitmaps[i].pixels != NULL)
    {
        glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
        glRasterPos2f (0.5f + x, 0.5f + y + bitmaps[i].h);
        glDrawPixels ( bitmaps[i].w, bitmaps[i].h, GL_RGB, GL_UNSIGNED_BYTE, bitmaps[i].pixels);
    }
}

