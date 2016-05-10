/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/AnimatedImage.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G
{
/** An animated image such as a gif. */
class AnimatedImage
{
    public:

    /** Constructor. */
    AnimatedImage ();

    void Resize (int newWidth, int newHeight);

    Image CurrentImage ();

    private:

    int originalWidth,
        originalHeight,
        currentWidth,
        currentHeight;

    Image originalImage, currentImage;
};
}
