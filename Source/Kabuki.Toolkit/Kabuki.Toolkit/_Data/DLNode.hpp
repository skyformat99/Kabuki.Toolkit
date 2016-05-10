/** Underscore
    @file       /.../Underscore.Library/_Data/DLNode.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Blue Storm Engineering ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _Data
{
    /** A doubly-linked node. */
    public struct DLNode<T>
    {
        /**  */
        public DLNode (T)
        {
            Data = T;
        }
        
        /**  */
        public DLNode<T> (T data, DLNode<T> prev)
        {
            Data = T;
        }

        /**  */
        public DLNode<T> (T prevLinkedObject, int initIndex)
        {
            data = prevLinkedObject;
            index = initIndex;
        }

        /**  */
        public DLNode<T> (T prevLinkedObject, string nodeName)
        {
            data = prevLinkedObject;
            name = nodeName;
        }

        /**  */
        public DLNode<T> (T prevLinkedObject, string nodeName, int initIndex)
        {
            data = prevLinkedObject;
            index = initIndex;
            name = nodeName;
        }

        /** The node content. */
        public T Data { get; set; }

        /** The previous node. */
        public DLNode<T> Prev { get; set; }

        /** The next node. */
        public DLNode<T> Next { get; set; }

        bool contains (T a)
        {
            if (data == a)
                return true;

            return false;
        }

        public override string ToString ()
        {
            return string.concat (name, "/n", data.ToString ());
        }

        public void Delete ()
        {
            Prev.Next = Next;
            Next.Prev = Prev;
        }
    }
}
