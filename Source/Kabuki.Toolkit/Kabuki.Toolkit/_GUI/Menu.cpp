/** Underscore
    @file       /.../Kabuki.Toolkit/_GUI2D/Menu.h
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
        Menu ()
        {  
            Reset ();
        }
    
        /** 
        */
        void Reset ()
        {
        }
        /*
        void ProcessData (InputDriver data, DataFlow dataFlow)
        {
        }
        */
    
        /** 
        */
        InputDriver Inputdriver ()
        {
            return inputDriver;
        }
    
        /**  */
        void SetInputDriver (InputDriver newDriver)
        {
            inputDriver = newDriver;
        }
        
        /**  */
        ActiveEvent ActiveComponent ()
        {
            return activeEvent;
        }
    
        /**  */
        void Add (IEvent newEvent)
        {
            keyboardControler.add (newEvent);
        }
    
        /**  */
        void Add (MenuEvent newEvent)
        {
            graphics.add (newEvent);
        }
    
        /**  */
        bool Save (File thisFile)
        {
            return false;  
        }
    
        /**  */
        void Draw (_G2D.Cell canvas)
        {
            _G.Draw (context);
        }
    
        /**  */
        int Select ()
        {
            return 0;
        }
    
        /**  */
        int Deselect ()
        {
            return 0;
        }
    }
}
