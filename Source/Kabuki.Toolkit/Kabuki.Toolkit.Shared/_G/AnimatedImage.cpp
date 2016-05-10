/** Underscore
    @file       /.../Kabuki.Toolkit/_G2D/AnimatedImage.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G2D
{
    /**  */
    class AnimatedImage
    {
        
        Image originalImage, currentImage;
        
        AnimatedImage ()
        {

        }

        void Resize (int newWidth, int newHeight)
        {
            currentWidth = newWidth;
            currentHeight = newHeight;
            currentImage = originalImage.getResizedImage (width, height);
        }

        Image CurrentImage
        {
            get
            {
                return currentImage;
            }
        }

        int originalWidth, 
            originalHeight, 
            currentWidth, 
            currentHeight;
    }
}
