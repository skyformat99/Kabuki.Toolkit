/** Kabuki.Toolkit
    @file       /.../Kabuki.Toolkit/_GUI2D/Menu.cpp
    @author     Cale McCollough
    @copyright  Copyright 2016 Cale McCollough ©
    @license    http://www.apache.org/licenses/LICENSE-2.0
    @brief      This file contains the _ class.
*/

namespace _GUI2D
{
    /**  */
    class Menu : _G2D.Entity, IInteractive
    {  
        /** Default constructor.
        */
        Menu ();
    
        /** 
        */
        void Reset ();
        /*
        void ProcessData (InputDriver data, DataFlow dataFlow)
        {
        }
        */
    
        /** 
        */
        InputDriver Inputdriver ();
    
        /**  */
        void SetInputDriver (InputDriver newDriver);
        
        /**  */
        ActiveEvent ActiveComponent ();
    
        /**  */
        void Add (IEvent newEvent);
    
        /**  */
        void Add (MenuEvent newEvent);
    
        /**  */
        bool Save (File thisFile);
    
        /**  */
        void Draw (_G2D.Cell canvas);
    
        /**  */
        int Select ();
    
        /**  */
        int Deselect ();
    }
}
