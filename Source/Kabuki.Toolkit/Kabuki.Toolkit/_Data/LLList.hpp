/** Underscore
    @file       /.../Underscore.Library/_Data/LLList.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /**  */
    public class LLList<T> : Collection
    {
        public const int IsNotSpecified = -1,
            size = 0, 
            index = 0, 
            maxSize = IsNotSpecified;

        /** Default constructor initializes with empty list. */
        public LinkedList ()
        {
            headOfList = new LLNode<T> (randomText (8));
            ResetList ();
        }

        public LinkedList (int maxNumOfElements)
        {
            headOfList = new Link (randomText (8));
            resetList ();

            if (maxNumOfElements > 0)
            {
                maxSize = maxNumOfElements;
            }
        }


        public LinkedList (File listHead)
        {
            headOfList = new Link (listHead);
            resetList ();
        }

        public void resetList ()
        { headOfList.setThisLink (headOfList);
            headOfList.setThatLink (headOfList);
            size = 0;
        }

        public bool add (object newLink)
        { return insert (newLink, headOfList);
        }

        public bool insert (object newLink)
        { return add (newLink, headOfList); }

        public bool insert (object newLink, int indexNum)
        { return insert (newLink, linkAtIndex (indexNum)); }

        public bool add (object newLink, Link afterHere)
        { if (newLink == headOfList || size == maxSize)
                return false;

            size++;
            Link newLinkedObj = new Link (newLink, size);
            newLinkedObj.setThisLink (afterHere);
            newLinkedObj.setThatLink (afterHere.thatLink ());

            afterHere.thatLink ().setThisLink (newLinkedObj);
            afterHere.setThatLink (newLinkedObj);

            return true;
        }

        public bool insert (object newLink, Link beforeHere)
        { if (newLink == headOfList || size == maxSize)
                return false;

            size++;
            Link newLinkedObj = new Link (newLink, size);
            newLinkedObj.setThatLink (beforeHere);
            newLinkedObj.setThisLink (beforeHere.thisLink ());

            beforeHere.thisLink ().setThatLink (newLinkedObj);
            beforeHere.setThisLink (newLinkedObj);

            return true;
        }

        public Link Find (object objectToFind)
        {
            Iterator iteration = new Iteration ();
            object thisobject;
            while (iteration.isNotDone ())
            {
                thisobject = iteration.nextobject ();
                if (thisobject == objectToFind)// iterator object
                    return iteration.currentLink ();
            }
            return null;
        }

        public bool Remove (object thisGuy) { return Remove (find (thisGuy)); }

        public bool Remove (int atIndex)
        {
            if (atIndex > 0 && atIndex <= size)
            {
                Iterator iteration = new Iteration ();
                object thisobject;

                for (int i = 0; i < atIndex; i++)
                    iteration.Next ();

                iteration.currentLink ().delete ();
                return true;
            }
            return false;
        }

        public bool Remove (int index1, int index2)
        {
            // Index1 can not be less than zero or greater than index1
            if (index1 < 0 || index2 > size + 1 || index2 < index1)
            {
                Iterator iteration = new Iteration ();

                for (int i = 0; i < index1; i++)
                    iteration.nextobject ();

                for (int i = index1; i < index2; i++)
                {
                    iteration.currentLink ().delete ();
                    size--;
                }
                return true;
            }
            return false;
        }

        bool remove (Link thisLink)
        {
            if (thisLink.equals (headOfList))
                return false;

            thisLink.delete ();
            size--;

            return true;
        }

        bool replace (int atIndex, object withThis)
        {
            if (atIndex > 0 && atIndex <= size)
            {
                linkAtIndex (atIndex).setData (withThis);
                return true;
            }
            return false;
        }

        bool keepOnlyThese (int[] indexList)
        {
            if (indexList.length <= size)
            {
                for (int i = 0; i < indexList.length; i++)
                    if (indexList[i] < 0 || indexList[i] > size)
                        return false;

                Iterator iteration = new Iteration ();

                for (int i = 1; i < indexList.length; i++)
                {
                    for (int a = indexList[i - 1]; a < indexList[i]; a++)
                        iteration.currentLink ().delete ();
                }
            }
            return true;
        }

        bool contains (object o)
        {
            object currentobject;

            Iterator iteration = linearIterator ();

            while (iteration.isNotDone ())
            {
                currentobject = iteration.nextobject ();

                if (currentobject == o)
                    return true;
            }
            return false;
        }

        object element (int atIndex)
        {
            if (atIndex > 0 && atIndex < size)
            {
                Iterator iteration = new Iteration ();
                for (int i = 0; i < atIndex; i++)
                    iteration.nextobject ();
                return iteration.currentobject ();
            }
            return null;
        }
        Link linkAtIndex (int atIndex)
        {
            if (atIndex > 0 && atIndex < size)
            {
                Iterator iteration = new Iteration ();

                for (int i = 0; i < atIndex; i++)
                    iteration.nextobject ();
                return iteration.currentLink ();
            }
            return null;
        }

        bool isEmpty ()
        {
            if (size == 0)
                return true;
            return false;
        }

        int size ()
        {
            return size;
        }

        int maxSize ()
        {
            return maxSize;
        }

        string randomText (int numChars)
        {
            string string = "";
            for (int i = 0; i < numChars; i++)
                string = string.concat (Int32.ToString ((int)(Math.random ()9)));
            return string;
        }

        public void increaseMaxSize (int increase)
        {
            maxSize += Math.abs (increase);// Sorry, no negative numbers
        }

        object[] toArray ()
        {
            object[] objectArray = new object[size];

            int i = 0;
            Iterator iteration = linearIterator ();
            while (iteration.isNotDone ())
            {
                objectArray[i] = iteration.nextobject ();
                i++;
            }
            return objectArray;
        }

        Iterator GetIterator ()
        {
            return new Iteration ();
        }

        Iterator linearIterator ()
        {
            return new Iteration ();
        }



        private LLNode headOfList;

        private public class Iteration : Iterator
        {
            Link currentLink;
            int index = 0,
                inde;

            Iteration ()
            {
                currentLink = headOfList;
            }
            object currentobject ()
            {
                return currentLink.data ();
            }

            object nextobject ()
            {
                inde = index;
                index++;
                if (index > size ())
                {
                    index = 1;
                    currentLink = headOfList;
                }
                currentLink = currentLink.thatLink ();
                return currentLink.data ();
            }
            object prevobject ()
            {
                inde = index;
                index--;

                if (index < 1)
                {
                    index = size ();
                    currentLink = headOfList;
                }

                currentLink = currentLink.thisLink ();

                return currentLink.data ();
            }

            Link currentLink ()
            {
                return currentLink;
            }

            Link nextLink ()
            {
                inde = index;
                index++;
                if (index > size ())
                {
                    index = 1;
                    currentLink = headOfList;
                }
                currentLink = currentLink.thatLink ();
                return currentLink;
            }
            Link prevLink ()
            {
                inde = index;
                index--;
                if (index < 1)
                {
                    index = size ();
                    currentLink = headOfList;
                }
                currentLink = currentLink.thisLink ();
                return currentLink;
            }
            bool isNotDone ()
            {
                if (index > inde)// iterating forwards
                {
                    if (currentLink.thatLink () == headOfList)
                        return false;
                }
                else                     // iterating backwards
                {
                    if (currentLink.thisLink () == headOfList)
                        return false;
                }
                return true;
            }
            bool isNotDone (int forwardsOrBackwards)// Value to be < or > 0
            {
                if (forwardsOrBackwards > 0)// iterating forwards
                { if (currentLink.thatLink () == headOfList)
                        return false;
                }
                else                     // iterating backwards
                {
                    if (currentLink.thisLink () == headOfList)
                        return false;
                }
                return true;
            }
            public void removeLastobject ()
            {
                if (index > inde)// iterating forwards
                {
                    remove (currentLink.thisLink ());
                    Iteration iteration = new Iteration ();
                    iteration.setIndex (index - 1);
                }
                else
                {
                    remove (currentLink.thatLink ());
                    Iteration iteration = new Iteration ();
                    iteration.setIndex (index);
                }
            }
            public void replaceLastobject (object withThis)
            {
                currentLink.thisLink ().setData (withThis);
            }
            public void insertobject (object thisGuy)
            {
                add (thisGuy, currentLink);
            }
            int direction ()// returns position if last iteration went forwards
            {
                if (index > inde)// and -1 if the last iteration was backwards
                    return 1;

                return -1;
            }
            public void setDirection (int positiveNegative)
            {
                if (positiveNegative < 0)
                    inde = inde + 1;
                else
                    inde = inde - 1;
            }

            bool setIndex (int toHere)
            {
                if (toHere < 1 || toHere > size)
                    return false;
                if (toHere > index)
                {
                    if (toHere < index - toHere)
                    {
                        for (int i = index; i < toHere; i++)
                            currentLink = currentLink.thatLink ();
                    }
                    else
                    {
                        currentLink = linkAtIndex (toHere);
                    }
                }
                else
                {
                    if (toHere < toHere - index)
                    {
                        for (int i = index; i > toHere; i--)
                            currentLink = currentLink.thisLink ();
                    }
                    else
                    {
                        currentLink = linkAtIndex (toHere);
                    }
                }
                return true;
            }

            int index ()
            {
                return index;
            }

            int size ()
            {
                return size;
            }
        }
    }
}
