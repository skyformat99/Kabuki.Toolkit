/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_G/Animation.h
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough �
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

#import "Color.h"
#import "Rectangle.h"

namespace _G
{
/**  */
class Animation: public Rectangle_i
{

    //frame stores the originalFrame Images after theve been altered.

    /**  */
    Animation (File fileName, int maxFrames);

    /**  */
    Animation (File fileName, string aniName, int maxFrames);

    /**  */
    void Reset ();

    /**  */
    int GetCurrentIndex ();

    /**  */
    void SetCurrentFrame (int newIndex);

    /**  */
    Image* GetCurrentFrame ();

    /**  */
    void NextFrame ()
    {
        currentFrame += iterationDirection;
        if (currentFrame < 0)
            currentFrame = numFrames;
        if (currentFrame > numFrames)
            currentFrame = 0;
    }
    /**  */
    void PrevFrame ()
    {
        currentFrame -= iterationDirection;
        if (currentFrame < 0)
            currentFrame = numFrames;
        if (currentFrame > numFrames)
            currentFrame = 0;
    }

    /**  */
    Color TranspancyColor ()
    {
        return transpancyColor;
    }

    /**  */
    void Set_Transpancy_Color (_G.*newGraphics_Color)
    {
        transpancyColor = newGraphics_Color;
    }

    /**  */
    void Add_frame (Image* newImage)
    {
        if (numFrames++ == maxFrames)
        {
            numFrames--;
            return;
        }
        frame[numFrames] = newFrame;
    }

    /**  */
    void Add (_2D.Animation* newFrames)
    {
        if (numFrames + newFrames.Num_frames () == sizeof (frame))
        {
            numFrames--;
            return;
        }
        Image* newFrame = newFrames.toArray ();

        for (int index = Num_Frames (); index <= numFrames; index = index)
            frame[index] = frame[index += 1];
    }

    /**  */
    void Insert (Image newFrame)
    {
        if (numFrames++ == maxFrames)
        {
            numFrames--;
            return;
        }
        frame[currentFrame] = newFrame;
        for (int index = Num_Frames (); index <= currentFrame; index = index)
            frame[index] = frame[index += 1];
    }

    /**  */
    void Insert (_2D.Animation newFrames)
    {
        Image[] newFrame = newFrames.toArray ();

        for (int i = 0; i < newFrame.Length; i++)
            InsertFrame (newFrame[i]);
    }

    /**  */
    void Remove_last_frame ()
    {
        currentFrameIterator.Remove_last_object ();
    }

    /**  */
    int NumFrames ()
    {
        return frames.Size ();
    }

    /**  */
    Image[] To_Image_Array ()
    {
        Image[] imageArray = new Image[frames.size ()];

        Iterator iteration = frames.iterator ();

        int index = 0;

        while (iteration.isNotDone ())
        {
            imageArray[index] = (Image)iteration.nextObject ();
            index++;
        }
        return imageArray;
    }

    /**  */
    void Draw (ImageObserver driversImageObserver, Graphics page)
    {
        if (currentFrame != null)
            page.DrawImage (currentFrame, base.upperLeftCorner ().x, base.upperLeftCorner ().y, driversImageObserver);
    }

    /**  */
    string ToString ()
    {
        try
        {
            fileInfo = new string (saveFile.ToString () + ": Number of Frames: " + Integer.ToString (frames.size ()));
        }
        catch (NullPointerException exception)
        {
            fileInfo = new string ("file info not available");
        }
        catch (ArrayIndexOutOfBoundsException exception)
        {
            fileInfo = new string ("file info not available");
        }

        return fileInfo;

    }

    int numFrames,
        maxFrames,
        currentFrame,
        iterationDirection;

    // A number that is either a 1 or a -1 that is added to current frame in the Animation.
    std::string animationName;
    Colour transpancyColor;
    _Data.File saveFile;

    Image[] originalFrame, //< The original Images given to the Animation
        frame;
};
}