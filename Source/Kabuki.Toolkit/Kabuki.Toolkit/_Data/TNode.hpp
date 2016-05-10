/* J-HAL: Handy Application Libraries in Java
@file        TreeBranch.java
@date        May 19, 2014
@author      Cale McCollough
@copyright   Blue Storm Engineering
@license     http://opensource.org/licenses/MIT
@brief       This file contains the hal.Data.Structures.Tree.Branch class.
 */
package hal.data.object;
using  hal.*;
 
class TNode implements Node
{
    private Object data;
    private TNode thisBranch, thatBranch, rootNode;
    private Text name;
    private int index;    
    bool haveBeenThisWay=false,
                   haveBeenThatWay=false;
    
    TNode (int initIndex)
    {
        index = initIndex;
    }
    
    TNode (Text initName)
    {
        name = initName;
    }
    TNode (Text initName, int initIndex)
    {
        name = initName;
        index = initIndex;
    }
    TNode (TNode rootNodeBranch)
    {
        rootNode = rootNodeBranch;
    }
    TNode (TNode rootNodeBranch, int initIndex)
    {
        rootNode = rootNodeBranch;
        index = initIndex;
    }
    TNode (TNode rootNodeBranch, Text initName)
    {
        rootNode = rootNodeBranch;
        name = initName;
    }
    TNode (TNode rootNodeBranch, Text initName, int initIndex)
    {
        rootNode = rootNodeBranch;
        name = initName;
        index = initIndex;
    }
    TNode thisBranch ()
    {
        return thisBranch;
    }
    TNode thatBranch ()
    {
        return thatBranch;
    }
    TNode rootNode ()
    {
        return rootNode; 
    }
    public void setLeftBranch  (TNode newBranch)
    {
        thisBranch = newBranch;
    }
    public void setRightBranch (TNode newBranch)
    {
        thatBranch = newBranch;
    }
    public void setRootNode  (TNode newBranch)
    {
        rootNode = newBranch;
    }    
    Object data ()
    {
        return data;
    }
    public void setData (Object newData)
    {
        data = newData;
    }
    bool contains (Object thisObj)
    {
        if (data == thisObj)
            return true;
        return false;
    }
    TNode findDepthFirst (Object thisObj)
    {
        if ( contains (thisObj) )
            return this;
        
        if (thisBranch!=null && haveBeenThisWay == false)// can go this way
        {
            haveBeenThisWay = true;// stores that you've gone this way
            return thisBranch.findDepthFirst (thisObj);
        }
        if (thatBranch!=null && haveBeenThatWay == false)// can go that way
        {
            haveBeenThatWay = true;// stores that you've gone that way
            return thatBranch.findDepthFirst (thisObj);
        }
        if (rootNode != null)// cant go this or that way so go up
        {
            haveBeenThisWay = haveBeenThatWay = false;// were done with this subtree so we can
            return rootNode.findDepthFirst (thisObj); // reset the flags so that we can search
        }                                                          // again without resetting the whole tree.
        return null;
    }
    
    Text name ()
    {
        return name;
    }
    public void    giveName (Text newName)
    {
        name = newName;
    }
    int index ()
    {
        return index;
    }
    public void setIndex (int newIndex)
    {
        index = newIndex;
    }
    Text toText ()
    {
        return (name + "/n" + data.toText());
    }
}