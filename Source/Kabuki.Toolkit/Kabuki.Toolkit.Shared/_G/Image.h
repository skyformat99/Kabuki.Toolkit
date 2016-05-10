/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Entity.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#

namespace _G
{
    /** Bitmap file header
        Provides general information about the file. */
    struct BitmapImageFileHeader
    {
        short   bitmapIsValid;
        long    sizeInBytes;
        short   bfReserved1;
        short   bfReserved2;
        long    colourDataStartBit;
    }
    
    /**  */
    struct BitmapcolourDataHeader
    {
        long    sizeInBytes;
        long    width;
        long    height;
        short   numPlanes;
        short   bitsPerPixel;
        long    compressionType;
        long    imageSizeInBytes;
        long    pixelsPerMeterX;
        long    pixelsPerMeterY;
        long    numColoursUsed;
        long    numImportantColourIndexs;
    }


    class Image : object
    {
        /**  */
        Image ()
        {  
            isLoaded = false;
            bpp = 0;
        }
        
        /**  */
        Image (int width, int height, int bitsPerPixel, _G.Colour bgColour)
        {  
            bpp = bitsPerPixel;
            //imageRowWidthInBytes = width  bpp;
            //byte newColourData[imageRowWidthInBytes  height];
            //byte  newColourDataPointer;
        
        }
        
        /**  */
        void markLoaded ()
        {  isLoaded = true;
        }
        
        /**  */
        int BPP ()
        {  return bpp;
        }
        
        /**  */
        void Set_BPP (int newBPP)
        {
            //  Reconstruct colourData to new BPP
        
            bpp = newBPP;
        }
        
        /**  */
        int Width_bytes ()
        {  return imageRowWidthInBytes;
        }
        
        /**  */
        _G.Colour Pixel (int pixelX, int pixelY)
        {
            if (pixelX > Plane.Width || pixelY > Plane.Height)
                return null;
        
            int pixelOffset = (imageRowWidthInBytes  pixelY) + (pixelX  bpp);
        
            return new Colour (colourData[pixelOffset   ],
                colourData[pixelOffset +1],
                colourData[pixelOffset +2]);
        }
        
        /**  */
        bool Load (char fileName)
        {  
            string fileNameText;
            fileNameText = new Text_Array (fileName);
        
            return Load (fileNameText);
        }
        
        /**  */
        bool Load (std::string fileName)
        {  
            string fileType;
            fileType = new Text_Array (fileName);
            fileType = fileType.SubText (fileType.Last_index_of ('.') + 1,
                                                      fileType.Length);
            if (   (fileType.char_at (0) == 'b' || fileType.char_at (0) == 'B')
                && (fileType.char_at (1) == 'm' || fileType.char_at (1) == 'M')
                && (fileType.char_at (2) == 'p' || fileType.char_at (2) == 'P'))
                return Load_from_bitmap (fileName.To_char_array ());
        
            return false;
        }
        
        /**  */
        bool Load_from_bitmap (char fileName)
        {
            // Load the file into memory
            FILE inFile;
            inFile = fopen (fileName, "rb");
        
            //Create the bitmap file
            BitmapImageFileHeader bitmapFile;
            fread (&bitmapFile, sizeof (BitmapImageFileHeader), 1, inFile);
        
            //Create the BitmapcolourDataHeader
            BitmapcolourDataHeader thisBitmap;
            fread (&thisBitmap, sizeof (BitmapcolourDataHeader), 1, inFile);
        
            //load the palette for 8 bits per pixel
            int numColours = thisBitmap.bitsPerPixel;
            if (numColours == 8)
            {  colourPallet = new Colour_RGBA[numColours];
                fread (colourPallet, sizeof (Colour_RGBA), thisBitmap.bitsPerPixel, inFile);
            }
        
            long colourDataSizeInBytes;
            colourDataSizeInBytes = (long) bitmapFile.sizeInBytes 
                                                 - bitmapFile.colourDataStartBit;
        
            byte tempcolourData;
            tempcolourData = new byte[colourDataSizeInBytes];
            if (sizeof (tempcolourData) == 0)
            {  fclose (inFile);
                return false;
            }
            fread (tempcolourData, sizeof (byte), colourDataSizeInBytes, inFile);
        
            //  To determine the pixelRowWidth_In32-BitColour you must find
            //  out how many bits are in each row of the image data table.
        
            long colourDataArrayWidthInBtyes;
            colourDataArrayWidthInBtyes = (long) (((float)thisBitmap.Width) * ((float) bpp / 8.0));
            long newcolourDataArrayWidth;
        
            newcolourDataArrayWidth = colourDataArrayWidthInBtyes;
        
            //This loop adds a little bit of white space in the image data array because
            //some programs wont acknowledge the image data unless its in 32-bit format
        
            while (newcolourDataArrayWidth % 4 != 0)
                newcolourDataArrayWidth++;
        
            //Set newcolourDataSizeInBytes to the actual files image data size
            long newcolourDataSizeInBytes;
            newcolourDataSizeInBytes = thisBitmap.Height  colourDataArrayWidthInBtyes;
        
            //Allocate memory for the image data
            colourData = new byte[newcolourDataSizeInBytes];
            if (colourData == null)
            {  fclose (inFile);
                return false;
            }If it fucks up.  Return false;
        
            //If the height of the Bitmap is < 0
            //Then the image data is inverted
            int memoryOffset;
        
            if (thisBitmap.Height > 0)
            {  
                int j = colourDataSizeInBytes - 3;
                memoryOffset = newcolourDataArrayWidth - colourDataArrayWidthInBtyes;
                for (int i = 0; i < newcolourDataSizeInBytes; i += 3)
                {
                    if ((i+1) % newcolourDataArrayWidth == 0)
                        i += memoryOffset;
                
                    (colourData + j + 2) = (tempcolourData + i    );
                    (colourData + j + 1) = (tempcolourData + i + 1);
                    (colourData + j   ) = (tempcolourData + i + 2);
                    j++;
                }
            }
            //the image is not reversed.  Only the padding needs to be removed.
            else
            {
                thisBitmap.Height = -1;
                memoryOffset = 0;
                do{
                    memcpy ((colourData + (memoryOffset  colourDataArrayWidthInBtyes)),
                                (tempcolourData + (memoryOffset  newcolourDataArrayWidth)),
                                (colourDataArrayWidthInBtyes)
                            );
                    memoryOffset++;
                }while (memoryOffset < thisBitmap.Height);
            }
            bitmapFile.bitmapIsValid = 19778;
            fclose (inFile); 
        
            Plane.Set_width (thisBitmap.Width);
            Plane.Set_height (thisBitmap.Height);
            bpp = bpp / 8;
            if (bpp == 0)
            {  
                if (bpp == 8)
                    bpp = 1;
                else
                if (bpp == 16)
                    bpp = 2;
                else
                if (bpp == 24)
                    bpp = 3;
                else
                if (bpp == 32)
                    bpp = 4;
                else
                    return false;
            }
            imageRowWidthInBytes = thisBitmap.Width  bpp;
        
            return true;
        }
        
        /**  */
        void setPixel (int pixelX, int pixelY,
                              Colour pixelColour)
        {  Image.setPixel (colourData,
                             (imageRowWidthInBytes pixelY) + (pixelX  bpp), pixelColour);
        }
        
        /**  */
        void setPixel (int pixelX, int pixelY, byte colourValue)
        {  Image.setPixel (colourData,
                             (imageRowWidthInBytes pixelY) + (pixelX  bpp), colourValue);
        }

        /**  */
        void setPixel (int pixelX, int pixelY,
                              byte colourValue1, byte colourValue2)
        {  Image.setPixel (colourData,
                                              (imageRowWidthInBytes pixelY) + (pixelX  bpp),
                                              colourValue1, colourValue2);
        }
        
        /**  */
        void setPixel (int pixelX, int pixelY, byte redValue, byte greenValue, byte blueValue)
        {  Image.setPixel (colourData,
                                              (imageRowWidthInBytes pixelY) + (pixelX  bpp),
                                              redValue, greenValue, blueValue);
        }

        /**  */
        void setPixel (int pixelX, int pixelY, byte redValue, byte greenValue, byte blueValue, byte alphaValue)
        {
            Image.setPixel (colourData, (imageRowWidthInBytes pixelY) + (pixelX  bpp),
                redValue, greenValue, blueValue, alphaValue);
        }
        
        
        /**  */
        //void Draw (Image canvas)
        //{  Image.Draw (canvas, this);
        //}
        
        /**  */
        //void Draw (Image canvas, int leftEdge, int topEdge)
        //{  Image.Draw (canvas, this, leftEdge, topEdge);
        //}
        
        /**  */
        static void SetPixel (uint pixel, int imageDataOffset, _G.Colour_i color)
        {
            if (color.bPP () == 1)
                Image.setPixel (imageData, imageDataOffset, color.Red ());
            else
            if (color.bPP () == 2)
                Image.setPixel (imageData, imageDataOffset, color.Red (), color.Green ());
            else
            if (color.bPP () == 3)
                Image.setPixel (imageData, imageDataOffset,
                                                         color.Red (), color.Green (), color.blue ());
            else if (color.bPP () == 4)
                Image.setPixel (imageData, imageDataOffset, color.Red (), color.Green (), color.blue (), 
                    color.alpha ());
        }
        
        /**  */
        static void setPixel (uint pixel, int imageDataOffset, byte colourValue)
        {
            if (imageDataOffset > 1)
                return;
            imageData[imageDataOffset     ] = colourValue;
        }
        
        /**  */
        static void setPixel (uint pixel, int imageDataOffset, byte colourValue1, byte colourValue2)
        {
            if (imageDataOffset > sizeof (imageData))
                return;
            imageData[imageDataOffset     ] = colourValue1;
            imageData[imageDataOffset + 2] = colourValue2;
        }
        
        /**  */
        static void setPixel (uint pixel, int imageDataOffset, byte redValue, byte greenValue, 
            byte blueValue)
        {
            if (imageDataOffset > sizeof (imageData))
                return;
            imageData[imageDataOffset     ] = redValue;
            imageData[imageDataOffset + 2] = greenValue;
            imageData[imageDataOffset + 3] = blueValue;
        }
        
        /**  */
        static void setPixel (uint pixel, int imageDataOffset, byte redValue, byte greenValue, 
            byte blueValue, byte alphaValue)
        {
            if (imageDataOffset > sizeof (imageData))
                return;
            imageData[imageDataOffset     ] = redValue;
            imageData[imageDataOffset + 2] = greenValue;
            imageData[imageDataOffset + 3] = blueValue;
            imageData[imageDataOffset + 4] = alphaValue;
        }

        /** Draws the source to the canvas on the NW corner. */
        static void Draw (Image canvas, Image source)
        {
            int sourceRowWidthInBytes, canvasRowWidthInBytes,
                             canvasOffset, canvasLineEndOffset, sourceOffset,
                             canvasLastLineOffset;
        
            sourceRowWidthInBytes = source.Width  source.bPP ();
            canvasRowWidthInBytes = canvas.Width  canvas.bPP ();
            /// This series of control statements clips the source's bounds to the canvas's
            /// bounds and stores the results in memory format of the source's colour map.
            canvasOffset = 0;
            sourceOffset = 0;
        
            if (sourceRowWidthInBytes > canvasRowWidthInBytes)
            {
                Clip the right edge
                canvasLineEndOffset = canvasRowWidthInBytes;
            }
            else
            {
                    canvasLineEndOffset = canvasRowWidthInBytes;
            }
        
            if (source.Height > canvas.Height)
            {
                /// Clip the bottom edge
                canvasLastLineOffset = (canvas.Height-1)  canvasRowWidthInBytes;
            }
            else
            {
                    canvasLastLineOffset = (source.Height-1)  canvasRowWidthInBytes;
            }
        
            Image.DrawClippedSection (canvas, source,
                                                              canvasOffset, canvasLineEndOffset,
                                                              canvasLastLineOffset, sourceOffset);
        }
        
        /** This method draws the source to the canvas. */
        static void Draw (Image canvas, Image source,
            int leftEdge, int topEdge)
        {
            /// The leftEdge and topEdge are in pixel format
            if (   leftEdge  < -canvas.Width
                 || topEdge  < -canvas.Height
                 || leftEdge >  canvas.Width
                 || topEdge  >  canvas.Height)
            {
                /// The source is not visible
                return;
            }
        
            int canvasOffset, 
                    canvasLineEndOffset, 
                    sourceOffset,
                    canvasLastLineOffset, 
                    sourceLeftEdgeOffset;

            sourceLeftEdgeOffset = leftEdge;
            source.bPP ();
        
            /// This series of control statements clips the source's bounds to the canvas's
            /// bounds and stores the results in memory format of the source's colour map.
        
            if (leftEdge < 0)
            {
                /// Clip the left edge
                canvasOffset = 0;
                sourceOffset = -sourceLeftEdgeOffset;
            }
            else
            {
                canvasOffset = sourceLeftEdgeOffset;
                sourceOffset = 0;
            }
        
            if (topEdge < 0)
            {
                /// Clip the top edge
                canvasOffset += (canvas.Width_bytes ()  (-topEdge));
                sourceOffset += (source.Width_bytes ()  (-topEdge));
            }
            //else the sourceOffet remains the same because the top edge is in bounds.
        
            if (sourceLeftEdgeOffset + source.Width_bytes () > canvas.Width_bytes ())
            {
                /// Clip the right edge
                canvasLineEndOffset = canvas.Width_bytes ();
            }
            else
            {
                    canvasLineEndOffset = sourceLeftEdgeOffset + source.Width_bytes ();
            }
        
            if (topEdge + source.Height > canvas.Height)
            {
                /// Clip the bottom edge
                canvasLastLineOffset = (canvas.Height  canvas.Width_bytes ())
                                            + canvasOffset;
            }
            else
            {
                canvasLastLineOffset = ((topEdge + source.Height)
                                              (canvas.Width_bytes ())
                                            )+ canvasOffset;
            }
            Image.DrawClippedSection (canvas, source, canvasOffset, canvasLineEndOffset, canvasLastLineOffset,  
                sourceOffset);
        }
    
        void DrawClippedSection (Image canvas, Image source, int canvasOffset, int canvasLineEndOffset, 
            int canvasLastLineOffset)
        {

        }
    
        int SourceOffset ()
        {
            /** This method draws a clipped section of the image. the Offsets are in 
                the 2D Array format where offset = (image.Width  y) + x 
            */
            imageWidthInBytes = image.Width  image.bPP
        
            byte canvasImageData,  sourceImageData;
            
            while (canvasOffset < canvasLastLineOffset)
            {
                Image.DrawClippedHorizontalLine (canvasImageData, sourceImageData,  canvasOffset,  canvasLineEndOffset, 
                    sourceOffset);
                canvasOffset += canvas.Width_bytes ();
                canvasLineEndOffset += canvas.Width_bytes ();
                sourceOffset += source.Width_bytes ();
            }
        }

        static void DrawClippedHorizontalLine (byte canvasColourData, byte sourceColourData, int canvasOffset, 
            lineEndOffset, int sourceOffset)
        {
            // This method copies a line from the source source to the canvas source. The offsets are in memory format. Byte format: x = (image.Width  y) + x
            
            while (canvasOffset < lineEndOffset)
                canvasColourData[canvasOffset++] == sourceColourData[sourceOffset++];
        }
        //    bool LoadGLTexture ()
        //    {  glGenTextures (1, &texture[0]);
        //        glBindTexture (GL_TEXTURE_2D, texture[0]);
        //        glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        //        glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        //        glTexImage2D (GL_TEXTURE_2D, 0, 3, width, height, 0,
        //                         GL_RGB, GL_UNSIGNED_BYTE, pixel);
        //  }

        Colour colourPallet;
        uint8_t colourData;
        int imageRowWidthInBytes;
    
        bool isLoaded;
        int bpp;
    }
}
