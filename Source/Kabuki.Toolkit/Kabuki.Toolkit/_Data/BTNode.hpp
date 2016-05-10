/** Underscore
    @file       /.../Underscore.Library/_Data/BTNode.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /** A node in a binary tree. */
    public class BTNode : Node
    {
        private object data;
        private BTNode thisBranch, thatBranch, rooBTNode;
        private string name;
        private int index;
        bool haveBeenThisWay = false,
                       haveBeenThatWay = false;

        BTNode (int initIndex)
        {
            index = initIndex;
        }

        BTNode (string initName)
        {
            name = initName;
        }
        BTNode (string initName, int initIndex)
        {
            name = initName;
            index = initIndex;
        }
        BTNode (BTNode rooBTNodeBranch)
        {
            rooBTNode = rooBTNodeBranch;
        }
        BTNode (BTNode rooBTNodeBranch, int initIndex)
        {
            rooBTNode = rooBTNodeBranch;
            index = initIndex;
        }
        BTNode (BTNode rooBTNodeBranch, string initName)
        {
            rooBTNode = rooBTNodeBranch;
            name = initName;
        }
        BTNode (BTNode rooBTNodeBranch, string initName, int initIndex)
        {
            rooBTNode = rooBTNodeBranch;
            name = initName;
            index = initIndex;
        }
        BTNode thisBranch ()
        {
            return thisBranch;
        }
        BTNode thatBranch ()
        {
            return thatBranch;
        }
        BTNode rooBTNode ()
        {
            return rooBTNode;
        }
        public void setLeftBranch (BTNode newBranch)
        {
            thisBranch = newBranch;
        }
        public void setRightBranch (BTNode newBranch)
        {
            thatBranch = newBranch;
        }
        public void setRooBTNode (BTNode newBranch)
        {
            rooBTNode = newBranch;
        }
        object data ()
        {
            return data;
        }
        public void setData (object newData)
        {
            data = newData;
        }
        bool contains (object thisObj)
        {
            if (data == thisObj)
                return true;
            return false;
        }
        BTNode FindDepthFirst (object thisObj)
        {
            if (contains (thisObj))
                return this;

            if (thisBranch != null && haveBeenThisWay == false)// can go this way
            {
                haveBeenThisWay = true;// stores that you've gone this way
                return thisBranch.findDepthFirst (thisObj);
            }
            if (thatBranch != null && haveBeenThatWay == false)// can go that way
            {
                haveBeenThatWay = true;// stores that you've gone that way
                return thatBranch.findDepthFirst (thisObj);
            }
            if (rooBTNode != null)// cant go this or that way so go up
            {
                haveBeenThisWay = haveBeenThatWay = false;// were done with this subtree so we can
                return rooBTNode.findDepthFirst (thisObj); // reset the flags so that we can search
            }                                                          // again without resetting the whole tree.
            return null;
        }

        public string Name
        {
            get { return name; }
            set { name = Value; }
        }
        
        public int Index
        {
            get { return index; }
            set { index = Value; }
        }
        
        public override string ToString ()
        {
            return name + "/n" + data.ToString ();
        }
    }
}