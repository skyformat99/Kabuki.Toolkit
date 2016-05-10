/*  C-HAL - C/C++ Handy Application Libraries
    @version 0.4.1
    
    This is free software distributed under the LGPL v3 license.
    Licence information can be found at http://www.gnu.org/licenses/lgpl-3.0.txt
    
    @file      C_HAL_Text.h
    @author    Chal Jamison McCollough
    @copyright This code is the intellectual property of The People of the Planet Earth © 2011
 */

#ifndef hal_text_header
#define hal_text_header

#include "global.h"

//! The Text namespace contains various utilities used for text.

namespace hal
{

class Text
{
    Text 
    char *toString(char thisNum);          //!< converts a char integer to a dynamically allocated char array
    char *toString(int  thisNum);          //!< converts an int to a dynamically allocated char array
    char *toString(unsigned char thisNum); //!< converts an unsigned char to a dynamically allocated char array
    char *toString(unsigned int  thisNum); //!< converts an unsigned int to a dynamically allocated char array
    
    
	char *emptyString();                                    //!< Returns an empty null terminated string.

    void concat(char *thisString, char thisNum);             //!< concats thisNum onto thisString without any error checking
    void concat(char *thisString, int  thisNum);             //!< concats thisNum onto thisString without any error checking
    void concat(char *thisString, unsigned char thisNum);    //!< concats thisNum onto thisString without any error checking
    void concat(char *thisString, unsigned int  thisNum);    //!< concats thisNum onto thisString without any error checking

    void concat(char *&thisString, const char *thatString);   //!< concats thatString onto thisString without any error checking
                                                              /*!< \pre thatString cannot be NULL. */

    void concat(char *&thisString, const char *thatString, const char *anotherString);
    //!< Concatenates thatString and anotherString onto thisString without any error checking
    /*!< \pre thatString cannot be NULL.
         \pre anotherString cannot be NULL. */

    char *truncate(const char *thisString, int newLength);    //!< Truncates thisString to the newLength.

    int length(char *thisString);                             //!< Returns the length of thisString.

    char *copy(char *thisString);                             //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *thisString);                       //!< Creates a dymanically allocated copy of thisString.

    char *copy(const char *thisString, int thisNumber);       //!< Copies thisString and thisNumber to a new char string.

    char *copy(const char *thisString, int thisNumber, const char *thatString);
    //!< Copies thisString, thisNumber, and thatString to a new char string.

    char *copy(const char *string1, const char *string2);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5,
               const char *string6);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5,
               const char *string6, const char *string7);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5,
               const char *string6, const char *string7, const char *string8);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5,
               const char *string6, const char *string7, const char *string8, const char *string9);
    //!< Creates a dymanically allocated copy of thisString.
    char *copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5,
               const char *string6, const char *string7, const char *string8, const char *string9, const char *string10);
    //!< Creates a dymanically allocated copy of thisString.

    bool compare(char *thisString, char *thatString);     //!< Compares thisString to thatString.
                                                                    /*!< \return Returns true if the strings are identical. */

    bool isPrintable(char thisChar);                      //!< Returns true of thisChar is a printalble ASCII charactor.
    bool isAlphaNumberic(char thisChar);                  //!< Returns true if thisChar is an alpha-numberic ASCII charactor.
    bool isPrintableAlphaNumberic(char thisChar);         //!< Returns true if thisChar is a printable alpha-numberic ASCII charactor.

    bool toLowerCase(char *thisString);                   //!< Converts thisString to lowercase letters
                                                                    /*!< \return Returns false if thisString contains any non-alphabetical chars */

    char *incrementCounter(const char *thisString);       //!< Function that adds or increments a counter to thisString.

    char *removeWhiteSpaceAround(const char *thisString); //!< Removes all of the whilespace at the end of thisString.
                                                                    /*!< \return Returns the length of the string after white space is removed */

    int parseLastNumber(const char thisString[]);         //!< returns the value of the number at teh end of thisString.
    char *parseBeforeLastNumber(const char *thisString);  //!< Returns the contents of thisString before the last number

    int toInt(const char thisDecimalDigit);               //!< Returns the int value of thisDecimalDigit.
                                                                    /*!< \return Returns a value between 0 and 9 for the value of thisDecimalDigit.
                                                                         \return Returns 0 if thisDecimalDigit is not a letter. */

    int toInt(const char *thisString);                    //!< Returns a decimal value of thisString.
                                                                    //!< \return Returns 0 if any of the chars are not decimal digits

    int aplhaIndex(const char thisLetter);                //!< Returns the aplhabetical index of thisLetter.
                                                                    /*!< \param thisLetter The letter to return the value of.
                                                                         \return Returns a value between 1 and 26 for the index of the letter.
                                                                         \return Returns 0 if thisLetter is not a letter. */

     char *parseNextWord(const char *thisLine, int &index); //!< Function that extracts the next word from thisLine.
                                                                      /*!< \pre    thisLine can not equal NULL.
                                                                           \param  thisLine: the line we are parsing word out of.
                                                                           \return Returns NULL if there are no more word to parse. */


    int numWords(const char *thisLine);                     //!< Returns the number of words in thisLine

    int hashIndex(const char *textString, int primeMultiplier, int hashTableSize);
    //!< Returns a hash index of the textString.
	
	
//-------------------------------------------------------------------------------------------------------
// The following code is for data structures of text

    /*! \struct LNode
        \brief  A LNode is a node in a linear linked list. */
    struct LNode
    {
        char *string; //!< The node content.
        LNode *next;  //!< The next node in the list.
    };


    /*! \struct DNode
        \brief  A DNode is a node in a doubly linked list. */
    struct DNode
    {
        char *string; //!< The node content.
        DNode *prev,  //!< The prev node in the list.
              *next;  //!< The next node in the list.
    };

    /*! \struct TNode
        \brief  A TNode is a node in a binary tree. */
    struct TNode
    {
        char *string; //!< The node content.
        TNode *left,  //!< The left child node.
              *right; //!< The right child node.
    };


//! The following code allows a user to create a Binary Tree in C.
	
    void insert(char *thisString, LNode *&thisNode);              //!< Inserts thisString after thisNode.
    void insertDeep(const char *thisString, int stringLength, LNode *&thisNode);
																  //!< Inserts and deep copies thisString after thisNode.
	
    void insert(const char *thisString, TNode *&subTree);         //!< Inserts thisString into this subTree.
    void insert(TNode *thisSubString, TNode *&subTree);           //!< Inserts the newSubTree into this subTree.

    void remove(TNode *&subTree, const char *thisString);         //!< Recursively deletes thisString from the subTree.

    bool find(TNode *subTree, const char *thisString);            //!< Recursively searchs for thisString and returns it if it exist.

    TNode *removeGIOS(TNode *&subTree);                           //!< Removes and returns the greatest in order successor TNode in this subTree;

    void destroy(TNode *&subTree);                                //!< Recursively deletes every Node and char string in this subTree.

    void countChars(TNode *subTree, int &numChars);               //!< Recursively counts the number of chars in the subTree.

    void countCharsAndNodes(TNode *root, int *numChars_numNodes); //!< Calculates to total number of chars and nodes in a tree/sub-tree
                                                                  /*!< \pre numChars must be a 2x1 array initialized to [0,0]. */

    char *toString(TNode *root);                                  //!< Returns a string representation of this tree/subTree
    char *toString(TNode *subTree, const char *nodeFormatter);    //!< Returns a string representation of this tree/subTree with the specified node formatter.

    void toString(TNode *subTree, char *returnString, int stringLength, const char *nodeFormatter);
    //!< Functino that returns a test representation of this tree/subTree
}
}
#endif // hal_text_header
