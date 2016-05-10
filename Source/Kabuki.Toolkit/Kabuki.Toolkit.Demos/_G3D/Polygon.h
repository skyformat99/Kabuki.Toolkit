/** Underscore
    @file       /.../Kabuki.Toolkit/_G3D/Polygon.cs
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _2D.Vector_f interface.
*/

namespace _G3D
{
    /**  */
    public class Polygon
    {
        /**  */   
        public Polygon (int[] indexOfPoints, _3D.Point[] pointValues)
        {
            vertexIndex = indexOfPoints;
            vertexPoint = pointValues; 
            numVerticies = vertexIndex.Length;
            base.data = this;
        }
        
        /**  */  
        public _3D.Point Vertex (int forThisPoint)
        {
            return vertexPoint[forThisPoint];
        }
        
        /**  */  
        public int VertexIndex (int forThisPoint)
        {
            return vertexIndex[forThisPoint];
        }
        
        /**  */  
        public _3D.Point Normal
        {
            get { return normal; }
        }
        
        /**  */  
        public void ComputeNormal ()
        {
            _3D.Point vectorU = new _3D.Point (vertexPoint[0], vertexPoint[1]);
            _3D.Point vectorV = new _3D.Point (vertexPoint[0], vertexPoint[2]);
        
            normal = vectorV.crossProduct (vectorU);
        
            normalMagnitude=normal.magnitude ();
        }
        
        /**  */  
        public double NormalMagnitude ()
        {
            return normalMagnitude;
        }
        
        /**  */  
        public void ScaleNormalMagnitude (double scaleFactor)
        {
            normalMagnitude*=scaleFactor;
        }
    
        /**  */  
        public double ZAverage
        {
            get { return zAverage; }
        }
        
        /**  */  
        public void ComputeZAverge ()
        {
            if (vertexIndex.Length==3)
                zAverage = (double).33333* (vertexPoint[0].z+vertexPoint[2].z+vertexPoint[2].z);
            else // polygon is a quad
                zAverage = (double).25* (vertexPoint[0].z+vertexPoint[2].z+vertexPoint[2].z+vertexPoint[3].z);
        }
    
        /**  */  
        public override string ToString ()
        {
            string colourText = colour.ToString ()
            override string ToString = .concat ("\n");
        
            for (int i=0; i< numVerticies; i++)
                ToString = ToString.concat (vertexPoint[i].ToString () + " localVertex[" + vertexIndex[i]+ "] " + "\n");
        
            return ToString;
        }  

        private const int flatShading = 0;
    
        private bool isTwoSided  = false,
                isClipped   = false,
                isActive    = false,
                isVisible   = true;
    
        private _G.Colour_i colour,
                shade;// Will be removed with texture mapping
           
        private int shadingType=0,
            numVerticies;
        
        private double  normalMagnitude,
                zAverage;  

        private _3D.Point normal;
    
        private _3D.Point[] vertexPoint;
    
        private int[] vertexIndex;
    }
}
