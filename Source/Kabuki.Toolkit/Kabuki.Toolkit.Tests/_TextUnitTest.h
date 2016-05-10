/*  J-HAL: Handy Application Libraries in Java
 @file       ~/tests/text/String_UnitTest.java
 @date       May 29, 2014
 @author     Cale McCollough
 @copyright  Blue Storm Engineering
 @license    http://opensource.org/licenses/MIT
 @brief      This file contains the HAL.tests.Text class.
 */
package hal.tests;

using hal.HAL;

public class Text_UnitTest// extends hal.UnitText
{
    /*
    public void run_diagnostics()
    {
        HAL.print ("\nTesting hal.Text...\n\n");
    
        // removeWhiteSpaceAround();
        // incrementCounter();
        // concat();
        // parseFunctions();
    
        HAL.print ("\n\nDone testing hal.Text\n\n");
    }
    
    
    
    public void incrementCounter()
    {
        HAL.print (hal.Console.UnderLnBreak  +  "\n\nTesting Text.incrementCounter(const char[])\n\n");
    
        try
        {
            Text testText;
    
            HAL.print ("\nCase 1.) Cases where there is no number at the end.\n\n");
    
            testText = Text.incrementCounter("test");
            HAL.print ("'test' = '"  +  testText  +  "' strlen="  +  testText.length ());
    
            //~ delete testText;
    
            HAL.print ("\n\n\nCase 2.) Cases where a number like 1 turns into 2.\n\n");
    
            testText = Text.incrementCounter("test 1");
            HAL.print ("'test 1' = '"  +  testText  +  "' strlen="  +  testText.length ()  +  "\n");
            //~ delete testText;
    
            testText = Text.incrementCounter("test 198");
            HAL.print ("'test 198' = '"  +  testText  +  "' strlen="  +  testText.length ()  +  "\n\n\n");
            //~ delete testText;
    
    
            HAL.print ("Case 3.) Cases where a number like  99 turns into 100 or 9 turns into 10.\n\n");
    
            testText = Text.incrementCounter("test 9");
            HAL.print ("'test 9' = '"  +  testText  +  "' strlen="  +  testText.length ()  +  "\n");
            //~ delete testText;
    
            testText = Text.incrementCounter("test 99");
            HAL.print ("'test 99' = '"  +  testText  +  " strlen="  +  testText.length ()  +  "\n");
            //~ delete testText;
    
            testText = Text.incrementCounter("test 999");
            HAL.print ("'test 999' = '"  +  testText  +  "' strlen="  +  testText.length ()  +  "\n\n\n");
            //~ delete testText;
    
            HAL.print ("Case 4.) Cases where a number like 199 turns into 200 or 909 turns into 919.\n\n");
    
            testText = Text.incrementCounter("test 199");
            HAL.print ("'test 199' = '"  +  testText  +  "' strlen="  +  testText.length ()  +  "\n");
            //~ delete testText;
    
            testText = Text.incrementCounter("test 919");
            HAL.print ("'test 919' = "  +  testText  +  "' strlen="  +  testText.length ()  +  "\n\n\n");
            //~ delete testText;
    
            HAL.print ("Case 5.) Case of an empty string\n\n";
    
            HAL.print ("'' = '"  +  Text.incrementCounter("")  +  "' strlen="  +  testText.length ()  + "\n\n\n\n");
            //~ delete testText;
    
    
            HAL.print ("Testing 1000 times...\n\n");
    
            testText = new Text.ASCII ("Test");
    
            for(int i=0; i < 1000; ++i)
            {
                //[
                long temp = testText;
                //]
                testText = Text.incrementCounter (testText);
                //~ delete temp;
            }
    
            HAL.print (testText;
    
            //~ delete testText;
        }
        catch (...)
        {
            ;
        }
    }
    
    
    
    public void removeWhiteSpaceAround()
    {
        HAL.print (hal.Console.UnderLnBreak  +  endl  +  "Testing Text.removeWhitespaceAround(const char[])\n\n";
    
        try
        {
            char testText;
        
            testText = Text.removeWhiteSpaceAround("     test       ");
            HAL.print ("'    test   ' = '"  +  " strlen="  +  testText.length ()  +  "\n\n";
            //~ delete testText;
        
            HAL.print ("Done testing Text.removeWhitespaceAround(const char[])\n\n\n\n";
        }
        catch (...)
        {
            ;
        }
    }
    
    
    public void toInt()
    {
        HAL.print (hal.Console.UnderLnBreak  +  "\nTesting int Text.toInt(const char)...\n\n");
    
        HAL.print ("\'9\' = "  +  Text.toInt('9')  +  "\n\n\n\n");
    
    
        HAL.print ("Testing int Text.toInt(const char )...\n\n");
    
        HAL.print ("'1' = "  +  Text.toInt("1")  +  "\n");
        HAL.print ("'10' = "  +  Text.toInt("10")  +  "\n");
        HAL.print ("'11' = "  +  Text.toInt("11")  +  "\n");
        HAL.print ("'99' = "  +  Text.toInt("99")  +  "\n");
        HAL.print ("'555' = "  +  Text.toInt("555")  +  "\n");
        HAL.print ("'420' = "  +  Text.toInt("420")  +  "\n\n\n\n");
    }
    
    
    
    public void concat()
    {
        HAL.print (hal.Console.UnderLnBreak  +  "\nText Text.concat(char , const char )\n\n");
    
        char testText;
    
        testText = null;
        Text.concat(testText, "Test");
        Text.concat(testText, " Test 2");
    
        HAL.print (testText  +  " strlen ="  +  testText.length ()  +  "\n\n");
    
    
    
        HAL.print ("Text Text.concat(char , const char , const char )\n\n");
    
        Text.concat(testText, " ", "Test 3");
    
        HAL.print (testText  +  " strlen ="  +  testText.length ()  +  "\n\n");
    
    
        //~ delete testText;
    }
    
    public void parseFunctions()
    {
        HAL.print (hal.Console.UnderLnBreak  +  "\nTesting int Text.parseBeforeLastNumber(const char )...\n\n");
    
        char testText;
    
        testText = Text.parseBeforeLastNumber("Test 420");
        HAL.print ("'Test 420' = '"  +  testText  +  "' strlen="  +  testText.length ()  +  "\n\n\n");
        //~ delete testText;
    
        HAL.print ("Testing int Text.parseBeforeLastNumber(const char )...\n\n");
    
        HAL.print ("'Test 1' = "    +  Text.parseLastNumber("Test 1")    +  "\n");
        HAL.print ("'Test 10' = "   +  Text.parseLastNumber("Test 10")   +  "\n");
        HAL.print ("'Test 420' = "  +  Text.parseLastNumber("Test 420")  +  "\n\n\n");
    
        HAL.print ("\n\nTesting Text.incrementCounter(const char[])\n\n");
    }
    */
}