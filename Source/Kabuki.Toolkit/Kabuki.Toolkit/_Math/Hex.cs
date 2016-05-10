/** J-HAL: Handy Application Libraries in Java
@file        ~/math/num/Hex.cs
@date        May 20, 2014
@author      Cale McCollough
@copyright   Blue Storm Engineering
@license     http://www.apache.org/licenses/LICENSE-2.0
@brief       This file contains the _.math.num.Hex public class.
*/
package _.math.num;

public class Hexidecimal
{
    /**  */
    public static char ToChar (byte hexValue)
    {
        switch (hexValue)
        {
            case 0:
               return '0';
            case 1:
               return '1';
            case 2:
               return '2';
            case 3:
               return '3';
            case 4:
               return '4';
            case 5:
               return '5';
            case 6:
               return '6';
            case 7:
               return '7';
            case 8:
               return '8';
            case 9:
               return '9';
            case 10:
               return 'a';
            case 11:
               return 'b';
            case 12:
               return 'c';
            case 13:
               return 'd';
            case 14:
               return 'e';
            case 15:
               return 'f';
        } 
        return '0';
    }

    /**  */
    public static string ToString (int integer)
    {
        return Hexidecimal.ToString ((byte)integer);
    }

    /**  */
    public static string ToString (byte thisByte)
    { 
        return "";
    }

    /**  */
    public static int ToInt (string binaryHex)
    {/*
        if (binaryHex.Length > 4)
            return 15;
        
        int amount=128,
            Value = 0;
        
        for (int i = 0; i < 4; i++)
        {
            if (binaryHex.substring (i,i+1).equals ("1"))
            Value += amount;
            amount/=2;
        }
        return amount;
        */
        return 0;
    }
    
    //
    public static int ToInt (char charictor)
    {
        switch (charictor)
        {
            case '0':
               return 0;
            case '1':
               return 1;
            case '2':
               return 2;
            case '3':
               return 3;
            case '4':
               return 4;
            case '5':
               return 5;
            case '6':
               return 6;
            case '7':
               return 7;
            case '8':
               return 8;
            case '9':
               return 9;
            case 'A':
                return 10;
            case 'B':
                return 11;
            case 'C':
                return 12;
            case 'D':
                return 13;
            case 'E':
                return 14;
            case 'F':
                return 15;
            case 'a':
               return 10;
            case 'b':
               return 11;
            case 'c':
               return 12;
            case 'd':
               return 13;
            case 'e':
               return 14;
            case 'f':
               return 15;
        }
        return 0;
    }
}
