/** Underscore
    @file       /.../Underscore.Library/_Data/BinaryTree.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /**  */
    public class BinaryTree
    {
        Branch rootNode, currentBranch;
        File treeFile;
        int size = 0, index = 0;

        Branch currentNode;

        BinaryTree ()
        {
            treeFile = new File (randomText (8));
            resetList ();
        }
        BinaryTree (File fileSeed)
        {
            treeFile = fileSeed;
            resetList ();
        }
        BinaryTree (string fileSeed)
        {
            treeFile = new File (fileSeed);
            resetList ();
        }
        public void resetList ()
        {
            rootNode = new Branch (0);
            size = 0;
        }
        string randomText (int numChars)
        { string string = "";
            for (int i = 0; i < numChars; i++)
                string = string.concat (Integer.ToString ((int)(Math.random () * 9)));
            return string;
        }
        Branch findDepthFirst (Branch startBranch, object thisObj)
        {
            currentBranch = startBranch;
            while (!currentBranch.contains (thisObj))
            {
                while (true)
                {
                    if (currentBranch.thisBranch () != null && currentBranch.haveBeenThisWay == false)
                    {
                        currentBranch = currentBranch.thisBranch ();// can go this way
                        currentBranch.haveBeenThisWay = true;// flag the node so it knows were its been
                    }
                    else if (currentBranch.thatBranch () != null && currentBranch.haveBeenThatWay == false)
                    { currentBranch = currentBranch.thatBranch ();// can go that way
                        currentBranch.haveBeenThatWay = true;// flag the node so it knows were its been
                    }
                    else if (currentBranch.rootNode () != null)
                    {
                        currentBranch = currentBranch.rootNode ();
                        currentBranch.haveBeenThatWay = currentBranch.haveBeenThatWay = false;
                        // now were done with this sub-tree so we reset the flags so that
                        // we don't have to reset the whole tree to search it again
                    }
                    else
                    {
                        currentBranch.haveBeenThatWay = currentBranch.haveBeenThatWay = false;
                        return null;
                    }
                }
            }
            return currentBranch;
        }
        Branch findDepthFirst (object thisObj)
        { return findDepthFirst (rootNode, thisObj);
        }
        bool findBreathFirst (object thisObj)
        { return false;
        }
        bool contains (object thisObj)
        { if (findDepthFirst (thisObj) == null)
                return false;
            return true;
        }

        /*
        Iterator iterator ()
        {  return new Iteration ();
        }   
        Iterator linearIterator ()
        {  return new Iteration ();
        }      
        public classIteration : Iterator, Iterator
        {  Branch currentBranch;
          int index=0, prevIndex;

          Iteration ()
          {  currentBranch = rootNode;
          }
          object currentObject ()
          {  return currentBranch.data ();
          }      
          object nextObject ()
          {  object nextObj = currentBranch.data ();
             if (leftBranch!=null)
                currentBranch;
          }  
          object prevObject ()
          {  prevIndex = index;
             index--;
             if (index < 1)
             {  index = size ();
                currentBranch = headOfList;
             }
             currentBranch=currentBranch.prevLink;
             return currentBranch.data;
          }  

          Link currentBranch ()
          {  return currentBranch;  }

          Link nextLink ()
          {  prevIndex = index;
             index++;
             if (index>size ())
             {  index=1;
                currentBranch = headOfList;
             }    
             currentBranch=currentBranch.nextLink;
             return currentBranch;
          }  
          Link prevLink ()
          {  prevIndex = index;
             index--;
             if (index < 1)
             {  index = size ();
                currentBranch = headOfList;
             }
             currentBranch=currentBranch.prevLink;
             return currentBranch;
          }  
          bool isNotDone ()
          {  if (index>prevIndex)// iterating forwards
             {  if (currentBranch.nextLink==headOfList)
                   return false;
             }
             else                // iterating backwards
             {  if (currentBranch.prevLink==headOfList)
                   return false;
             }
             return true;
          }   
          bool isNotDone (int forwardsOrBackwards)// Value to be < or > 0
          {  if (forwardsOrBackwards>0)// iterating forwards
             {  if (currentBranch.nextLink==headOfList)
                   return false;
             }
             else                // iterating backwards
             {  if (currentBranch.prevLink==headOfList)
                   return false;
             }
             return true;
          } 
          public void removeLastObject ()
          {  if (index>prevIndex)// iterating forwards
             {  remove (currentBranch.prevLink);
                Iteration iteration = new Iteration ();
                iteration.setIndex (index-1);
             }
             else
             {  remove (currentBranch.nextLink);
                Iteration iteration = new Iteration ();
                iteration.setIndex (index);
             }
          }  
          public void replaceLastObject (object withThis)
          {  currentBranch.prevLink.data = withThis;}

          public void insertObject (object thisGuy)
          {  add (thisGuy, currentBranch);          }

          int direction ()// returns Point if last iteration went forwards
          {  if (index>prevIndex)// and -1 if the last iteration was backwards
                return 1;

             return -1;
          }
          public void setDirection (int positiveNegative)
          {  if (positiveNegative<0)
                prevIndex=prevIndex+1;
             else
                prevIndex=prevIndex-1;
          }

          bool setIndex (int toHere)
          {  if (toHere < 1 || toHere > size)
                return false;
             if (toHere > index)
             {  if (toHere < index-toHere)
                {  for (int i=index; i<toHere; i++)
                      currentBranch = currentBranch.nextLink;
                }
                else
                {  currentBranch = linkAtIndex (toHere);
                }
             }
             else
             {  if (toHere < toHere-index)
                {  for (int i=index; i>toHere; i--)
                      currentBranch = currentBranch.prevLink;
                }
                else
                {  currentBranch = linkAtIndex (toHere);
                }
             }
             return true;
          }

          int index ()
          {  return index;  }

          int size ()
          {  return size;  }
    */
    }
}