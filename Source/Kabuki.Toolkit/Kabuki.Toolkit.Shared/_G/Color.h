/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Colour_i.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G
{
    /**  */
    struct Colour_i
    {
        const int DefaultTranparency = 0;

        // Copy constructor initializes with copy of colour.
        Colour_i (Colour_i colour)
        {
            bytes = colour.bytes;
        }


        // Constructor initializes with colour.
        Colour_i (uint colour)
        {
            bytes = colour;
        }

        // Constructor initializes with given bytess.
        Colour_i (int red, int green, int blue)
        {
            SetRGB (red, green, blue);
        }

        // Constructor initializes with given bytess.
        Colour_i (int red, int green, int blue, int alpha)
        {
            SetRGBA (red, green, blue, alpha);
        }

        // Constructor initializes with given bytess.
        Colour_i (float red, float green, float blue)
        {
            SetRGB (red, green, blue);
        }

        // Constructor initializes with given bytess.
        Colour_i (float red, float green, float blue, float alpha)
        {
            SetRGB (red, green, blue, alpha);
        }

        uint Bytes
        {
            get { return bytes; }
            set { bytes = value; }
        }

        // Sets the bytes to the given bytess.
        void SetRGB (int red, int green, int blue)
        {
            uint redMask  = ((uint)red)   << 16,
                greenMask = ((uint)green) << 8,
                blueMask  = ((uint)blue)  << 0;

            bytes = (redMask | greenMask | blueMask);
        }

        // Sets the bytes to the given bytess.
        void SetRGBA (int red, int green, int blue, int alpha)
        {
            uint redMask  = (((uint)red)   & 0xff) << 0,
                greenMask = (((uint)green) & 0xff) << 8,
                blueMask  = (((uint)blue)  & 0xff) << 16,
                alphaMask = ((uint)alpha) << 24;

            bytes = redMask | greenMask | blueMask | alphaMask;
        }

        // Sets the bytes to the given bytess.
        void SetRGB (float red, float green, float blue)
        {
            uint red_i  = (uint)(red   * 256.0f),
                green_i = (uint)(green * 256.0f),
                blue_i  = (uint)(blue  * 256.0f);
            
            if (red_i   > 255) red_i   = 255;
            if (green_i > 255) green_i = 255;
            if (blue_i  > 255) blue_i  = 255;

            bytes = red_i | (green_i << 8) | (blue_i << 16);
        }

        // Sets the bytes to the given bytess.
        void SetRGB (float red, float green, float blue, float alpha)
        {
            uint red_i  = (uint)(red   * 256.0f),
                green_i = (uint)(green * 256.0f),
                blue_i  = (uint)(blue  * 256.0f),
                alpha_i = (uint)(alpha * 256.0f);
            
            if (red_i   > 255) red_i   = 255;
            if (green_i > 255) green_i = 255;
            if (blue_i  > 255) blue_i  = 255;
            if (alpha_i > 255) alpha_i = 255;

            bytes = red_i | (green_i << 8) | (blue_i << 16) | (alpha_i << 24);
        }

        // 
        void Swap (Colour_i a)
        {
            uint temp = a.Bytes;
            a.Bytes = bytes;
            bytes = temp;
        }

        void Swap (Colour_f colour)
        {
            SetRGB (colour.Red, colour.Green, colour.Blue, colour.Alpha);
        }

        /** Gets and sets the red component. */
        byte Red
        { 
            get { return (byte)(bytes & 0xff); }
            set { bytes = (bytes ^ 0xff) & ((uint)value); }
        }

        /** Gets and sets the green component. */
        byte Green
        { 
            get { return (byte)((bytes & 0xff00) >> 8); }
            set { bytes = (bytes ^ 0xff00) & (((uint)value) << 8); }
        }

        /** Gets and sets the blue component. */
        byte Blue
        { 
            get { return (byte)((bytes & 0xff0000) >> 16); }
            set { bytes = (bytes ^ 0xff0000) & (((uint)value) << 16); }
        }

        /** Gets and sets the alpha component. */
        byte Alpha
        { 
            get { return (byte)((bytes & 0xff000000) >> 24); }
            set { bytes = (bytes ^ 0xff000000) & (((uint)value) << 24); }
        }

        //
        byte Hue
        {
            get { return 0; }
            set { ; }
        }

        //
        byte Saturation
        {
            get { return 0; }
            set { ; }
        }

        //
        byte Balance
        {
            get { return 0; }
            set { ; }
        }

        //
        void SetHSB (uint colour)
        {


        }

        //
        void SetHSB (int hue, int saturation, int balance)
        {


        }

        // 
        void setHSB (int hue, int saturation, int balance, int alpha)
        {


        }

        //
        void SetHSB (float hue, float saturation, float balance)
        {


        }

        // 
        void setHSB (float hue, float saturation, float balance, float alpha)
        {


        }

        //
        void Set (Colour_i colour)
        {
            bytes = colour.bytes;
        }

        //
        void printConsole ()
        {
        }

        //
        string ToString ()
        {
            return null;
        }

        uint bytes;
    }
}
