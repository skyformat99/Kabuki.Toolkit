#include "Text.h"

#include "Numbers.h"

using namespace Text;


char *Number::toString(char thisNum)
{
	char *returnString = new char[5];
	_itoa_s(thisNum, returnString, 5, 10);
    return returnString;
}

char *Number::toString(int thisNum)
{
	char *returnString = new char[7];
	_itoa_s(thisNum, returnString, 7, 10);
    return returnString;
}

char *Number::toString(unsigned char thisNum)
{
	char *returnString = new char[7];
	_itoa_s(thisNum, returnString, 7, 10);
    return returnString;
}

char *Number::toString(unsigned int thisNum)
{
	char *returnString = new char[7];
	_itoa_s(thisNum, returnString, 7, 10);
    return returnString;
}


char *Text::emptyString()
{
	char *emptyString = new char[1];
	emptyString[0] = '0';
    return emptyString;
}

int Text::length(char *thisString)
{
    return strlen(thisString);
}

void Text::concat(char *string1, char thisNum)
{
    char buffer[5];
	_itoa_s(thisNum, buffer, 5, 10);
    strcat_s(string1,strlen(string1)+5, buffer);
}

void Text::concat(char *string1, int thisNum)
{
    char buffer[7];
	_itoa_s(thisNum, buffer, 5, 10);
    strcat_s(string1, 7, buffer);
}

void Text::concat(char *string1, unsigned char thisNum)
{
    char buffer[5];
	_itoa_s(thisNum, buffer, 5, 10);
    strcat_s(string1, 5, buffer);
}

void Text::concat(char *string1, unsigned int thisNum)
{
    char buffer[11];
	_itoa_s(thisNum, buffer, 5, 10);
    strcat_s(string1, 11, buffer);
}

void Text::concat(char *&string1, const char *string2)
{
    int thisLength,
        thatLength;

    if(string1 == NULL)
        thisLength = 0;
    else
        thisLength = strlen(string1);

    thatLength = strlen(string2);

    int newStringLength = thisLength + thatLength + 1;

    char *temp = string1;
    string1 = new char[newStringLength];

    int i;
    for(i=0; i < thisLength; ++i)
        string1[i] = temp[i];

    delete temp;

    for(i=0; i < newStringLength; ++i)
        string1[i+thisLength] = string2[i];


    string1[i] = '\0';
}



void Text::concat(char *&string1, const char *string2, const char *string3)
{
 // This is broken!!! Fix me!!!!

    int thisLength,
        thatLength,
        string3Length;

    if(string1 == NULL)
        thisLength = 0;
    else
        thisLength = strlen(string1);

    thatLength = strlen(string2);
    string3Length = strlen(string3);

    int newStringLength = thisLength + thatLength + string3Length + 1;

    char *temp = string1;

    string1 = new char[newStringLength];

    int i;
    for(i = 0; i < thisLength; ++i)
        string1[i] = temp[i];

    delete temp;

    int thisAndThatStringLength = thisLength + thatLength;

    for(i=0; i < thisAndThatStringLength; ++i)
        string1[i+thisLength] = string2[i];

    for(i=0; i < newStringLength; ++i)
        string1[i+thisAndThatStringLength] = string3[i];

    string1[i] = '\0';
}



bool Text::toLowerCase(char *string1)
{
    bool isNotAlphaFlag = true;
    for(unsigned int i=0; i < strlen(string1); ++i)
    {
        if(!isalpha(string1[i]))
            isNotAlphaFlag = false;
        else
            string1[i] = tolower(string1[i]);
    }
    return isNotAlphaFlag;
}


char *Text::copy(char *string1)
{
	int stringLength = strlen(string1)+1;
	char *returnString = new char[stringLength];
	strcpy_s(returnString,stringLength, string1);
    return returnString;
}


char *Text::copy(const char *string1)
{
	int stringLength = strlen(string1)+1;
	char *returnString = new char[stringLength];
	strcpy_s(returnString,stringLength, string1);
    return returnString;
}


char *Text::copy(const char *string1, int thisNumber)
{
 // To do: Optimize me!!!

	int stringLength = strlen(string1)+8;

		char *returnString = new char[stringLength];

    char buffer[7];
    _itoa_s(thisNumber, buffer, 10);

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, buffer);

    return returnString;
}

char *Text::copy(const char *string1, int thisNumber, const char *string2)
{
 // To do: Optimize me!!!
	int stringLength = strlen(string1) + 7 + strlen(string2) +1;
    char *returnString = new char[stringLength];

    char buffer[7];
    _itoa_s(thisNumber, buffer, 7, 10);

    strcpy_s(returnString,stringLength, string1);
    strcat_s(returnString,stringLength, buffer);
    strcat_s(returnString,stringLength, string2);

    return returnString;
}

char *Text::copy(const char *string1, const char *string2)
{
    int thisLength,
        thatLength,
        thisAndThatLength;

    if(string1 == NULL)
        thisLength = 0;
    else
        thisLength  = strlen(string1);

    if(string2 == NULL)
        thatLength = 0;
    else
        thatLength  = strlen(string2);

    thisAndThatLength = thisLength + thatLength;



    char * returnString = new char[thisAndThatLength + 1];

    int i;

    for(i=0; i < thisLength; ++i)
        returnString[i] = string1[i];

    for(i=0; i < thatLength; ++i)
        returnString[i+thisLength] = string2[i];

    returnString[thisAndThatLength] = '\0';

    return returnString;
}



char *Text::copy(const char *string1, const char *string2, const char *string3)
{
    int thisLength,
        thatLength,
        anotherLength,
        thisAndThatLength,
        allStringLength;

    if(string1 == NULL)
        thisLength = 0;
    else
        thisLength  = strlen(string1);

    if(string2 == NULL)
        thatLength = 0;
    else
        thatLength  = strlen(string2);

    if(string3 == NULL)
        anotherLength = 0;
    else
        anotherLength  = strlen(string3);

    thisAndThatLength = thisLength + thatLength;
    allStringLength   = thisAndThatLength + anotherLength;



    char * returnString = new char[allStringLength + 1];

    int i;

    for(i=0; i < thisLength; ++i)
        returnString[i] = string1[i];

    for(i=0; i < thatLength; ++i)
        returnString[i+thisLength] = string2[i];

    for(i=0; i < anotherLength; ++i)
        returnString[i+thisAndThatLength] = string3[i];

    returnString[allStringLength] = '\0';

    return returnString;
}


char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4)
{
    // To do: Optimize me!!!

	int stringLength = strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);

    return returnString;
}
char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5)
{
    // To do: Optimize me!!!

	int stringLength = strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) + strlen(string5) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);
    strcat_s(returnString, stringLength, string5);

    return returnString;
}
char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5, const char *string6)
{
    // To do: Optimize me!!!

	int stringLength = strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) + strlen(string5) + strlen(string6) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);
    strcat_s(returnString, stringLength, string5);
    strcat_s(returnString, stringLength, string6);

    return returnString;
}
char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5, const char *string6,
                 const char *string7)
{
    // To do: Optimize me!!!

	int stringLength =   strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) + strlen(string5) + strlen(string6)
                       + strlen(string7) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);
    strcat_s(returnString, stringLength, string5);
    strcat_s(returnString, stringLength, string6);
    strcat_s(returnString, stringLength, string7);

    return returnString;
}
char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5, const char *string6,
                 const char *string7, const char *string8)
{
    // To do: Optimize me!!!

	int stringLength =   strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) + strlen(string5) + strlen(string6)
                       + strlen(string7) + strlen(string8) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);
    strcat_s(returnString, stringLength, string5);
    strcat_s(returnString, stringLength, string6);
    strcat_s(returnString, stringLength, string7);
    strcat_s(returnString, stringLength, string8);

    return returnString;
}
char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5, const char *string6,
                 const char *string7, const char *string8, const char *string9)
{
    // To do: Optimize me!!!

	int stringLength =   strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) + strlen(string5) + strlen(string6)
                       + strlen(string7) + strlen(string8) + strlen(string9) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);
    strcat_s(returnString, stringLength, string5);
    strcat_s(returnString, stringLength, string6);
    strcat_s(returnString, stringLength, string7);
    strcat_s(returnString, stringLength, string8);
    strcat_s(returnString, stringLength, string9);

    return returnString;
}
char *Text::copy(const char *string1, const char *string2, const char *string3, const char *string4, const char *string5, const char *string6,
                 const char *string7, const char *string8, const char *string9, const char *string10)
{
    // To do: Optimize me!!!

	int stringLength =   strlen(string1) + strlen(string2) + strlen(string3) + strlen(string4) + strlen(string5) + strlen(string6)
                       + strlen(string7) + strlen(string8) + strlen(string9) + strlen(string10) +1;

    char *returnString = new char[stringLength];

    strcpy_s(returnString, stringLength, string1);
    strcat_s(returnString, stringLength, string2);
    strcat_s(returnString, stringLength, string3);
    strcat_s(returnString, stringLength, string4);
    strcat_s(returnString, stringLength, string5);
    strcat_s(returnString, stringLength, string6);
    strcat_s(returnString, stringLength, string7);
    strcat_s(returnString, stringLength, string8);
    strcat_s(returnString, stringLength, string9);
    strcat_s(returnString, stringLength, string10);

    return returnString;
}













char *Text::truncate(const char *thisString, int newLength)
{
	int stringLength = strlen(thisString);
	if(newLength >= stringLength)
		return copy(thisString);
    char *returnString = new char[newLength+1];
    strncpy_s(returnString,newLength, thisString, newLength);
    return returnString;
}





char *Text::incrementCounter(const char *string1)
{
    // Has bug on case 5!!! 3/14/2012



    // There are 6 cases that we have to deal with:
    // 1.) Cases where there is no number at the end.
    // 2.) Cases where a number like 1 turns into 2.
    // 3.) Cases where a number like  99 turns into 100 or   9 turns into  10.
    // 4.) Cases where a number like 199 turns into 200 or 909 turns into 919.
    // 5.) Cases of an emtpy string.

    int endIndex = strlen(string1)-1;

    // Cases 1.) - 5.)
    if(endIndex > 0)
    {
        // Case 1.) Cases where there is no number at the end.
        if(!isdigit(string1[endIndex]))
        {
			int stringLength = endIndex+4;
            char *newString = new char[stringLength]; // grow array by 2 chars and put a '1' at the end
            strcpy_s(newString,stringLength, string1);
            newString[endIndex+1] = ' ';
            newString[endIndex+2]   = '1';
            newString[endIndex+3] = '\0';

            return newString;
        }
        // Now we know that there is a number at the end

        // Case 2.) Cases where a number like 1 turns into 2.
        if(string1[endIndex] != '9')
        {
            char *newString = copy(string1);
            ++newString[endIndex];// then just increment the counter and return;
            return newString;
        }

        // Now we know that the last digit is a 9

        // In one of these cases, we have to grow the array by 1 char. The easy way to do this is
        // to grow the array in all cases

		int stringLength = endIndex+3;
        char *newString = new char[stringLength]; // grow array by 1 char
        strcpy_s(newString, stringLength, string1);


        int index = endIndex;
        while(newString[index] == '9')
        {
            newString[index] = '0';
            --index;
        }
        // Case 3.) Cases where a number like  99 turns into 100 or 9 turns into 10.
        if(!isdigit(newString[index]))
        {
            // Shift all of the 0's over one
            for(int i=index+1; i <= endIndex+1; ++i)
                newString[i] = '0';

            newString[index+1] = '1';
            newString[endIndex+2] = '\0';
            return newString;
        }
        // Case 4.) Cases where a number like 199 turns into 200 or 909 turns into 919.
        ++newString[index];
        return newString;

    }
    // Case 5.)

	return emptyString();
}



char *Text::removeWhiteSpaceAround(const char *string1)
{
    int endIndex = strlen(string1)-1;

    if(endIndex <= 0)
        return emptyString();

    int startIndex = 0;

 // Remove whitespace at beginning
    while(string1[startIndex] == ' ' && startIndex < endIndex)
        ++startIndex;

 // Remove whitespace at end
    while(string1[endIndex] == ' ' && endIndex > startIndex)
        --endIndex;

    int stringLength = endIndex-startIndex+2;
    char *returnString = new char[stringLength];

    for(int i = 0; i < stringLength; ++i)
        returnString[i] = string1[i + startIndex];

    returnString[stringLength] = '\0';

    return returnString;
}


int Text::parseLastNumber(const char *string1)
{
    if(string1 == NULL)
        return 0xFFFFFFFF;

    int endIndex = strlen(string1)-1;

    if(endIndex < 0)
        return 0;

    //remove white space at end
    while(string1[endIndex] == ' ')
        --endIndex;

    int startIndex = endIndex;

    // scan left to start of number
    while(isdigit(string1[startIndex]))
        --startIndex;

    int sum,
        index,
        multiplier = 10;


    if( !isdigit(string1[endIndex]) )
        return 0xFFFFFFFF;

    sum = (string1[endIndex] - '0');

    for(int i=1; i < endIndex - startIndex; ++i)
    {
        index = endIndex - i;

        if( !isdigit(string1[index]) )
            return 0xFFFFFFFF;

        sum += (string1[index]-'0') * multiplier;
        multiplier *= 10;
    }
    return sum;
}


char *Text::parseBeforeLastNumber(const char *string1)
{
    if(string1 == NULL)
        return emptyString();

    int endIndex = strlen(string1)-1;

    if(endIndex < 0)
        return emptyString();

    //remove end whitespace
    while(string1[endIndex] == ' ')
        --endIndex;

    //remove end digits
    while(isdigit(string1[endIndex]))
        --endIndex;

    //remove end whitespace
    while(string1[endIndex] == ' ')
        --endIndex;

	int returnStringEndIndex = endIndex+2;


    char *returnString = new char[returnStringEndIndex];
	strncpy_s(returnString, returnStringEndIndex, string1, endIndex+1);
    returnString[endIndex+1] = '\0';

    return returnString;
}




int Text::toInt(const char thisDecimalDigit)
{
    if(!isdigit(thisDecimalDigit))
        return 0;// thisDecimalDigit is not a number

    return (int)(thisDecimalDigit - '0');// number value
}



int Text::toInt(const char *string1)
{
    int endIndex = strlen(string1)-1;

    if(endIndex < 0)
        return 0xFFFFFFFF;

    int sum,
        index = 0,
        multiplier = 10;

    if(string1[0] != '-') // then the number is positive
    {
        // There is no point in multiplying the first int by pow(10, 0).
        // This is faster.
        if( !isdigit(string1[endIndex]) )
            return 0xFFFFFFFF;

        sum = (string1[endIndex]-'0');

        for(int i=1; i <= endIndex; ++i)
        {
            index = endIndex - i;

            if(!isdigit(string1[index]))
                return 0xFFFFFFFF;

            sum += (string1[index]-'0') * multiplier;
            multiplier *= 10;
        }
        return sum;
    }
    else // then the number is negative
    {
        if( !isdigit(string1[endIndex]) )
            return 0xFFFFFFFF;

        sum = 0 - (string1[index]-'0');

        for(int i=1; i <= endIndex-1; ++i)
        {
            index = endIndex - i;

            if( !isdigit(string1[index]) )
                return 0xFFFFFFFF;

            sum -= (string1[index]-'0') * multiplier;
            multiplier *= 10;
        }
        return sum;
    }
    return 0;
}



int Text::aplhaIndex(char thisLetter)
{
    if(isupper(thisLetter))
        return (int)(thisLetter-'A');// upper case letter
    else
    if(islower(thisLetter))
        return (int)(thisLetter-'a');// lower case letter

    return 0; // is not a letter
}


bool Text::isPrintable(char thisChar)
{
	if(isprint(thisChar))
		return true;
    return false;
}

bool Text::isAlphaNumberic(char thisChar)
{
	if(isalnum(thisChar))
		return true;
    return false;
}

bool Text::isPrintableAlphaNumberic(char thisChar)
{
    if(   isprint(thisChar)
       && isalnum(thisChar)
      ) return true;
    return false;
}









char *Text::parseNextWord(const char *thisLine, int &index)
{
    if(thisLine == NULL || thisLine <= 0) // no work to do
        return NULL;

    int stopIndex = strlen(thisLine);

    if(index >= stopIndex) // no work to do
        return NULL;

    char *newSymbol; // this is the string we are going to return

    // Scan over to the next letter (i.e. remove white space and punctuation)
    while(!isalpha(thisLine[index]))
    {
        ++index;
        if(index >= stopIndex) // no work to do
            return NULL;
    }

    int startIndex = index; // used to calc string length and as local variable for looping

    while(isalpha(thisLine[index]) && index <= stopIndex) // we have to check if index <= stopIndex
        ++index;                                          // just in case there isn't a null term char

    int strLength = index - startIndex + 1, // then length of the return string
        i; // looping variable

    newSymbol = new char[strLength];

    for(i=0; i < strLength; ++i)
        newSymbol[i] = thisLine[startIndex + i];

    newSymbol[strLength-1] = '\0';

    if(thisLine[index] ==  '\'') // if there is an apostrophe, then the s is not part of the word
        index += 2;

    return newSymbol;
}




int Text::numWords(const char *thisLine)
{
 // I think there is a bug in this... it displayed 1 less word then I inputed.

    if(thisLine == NULL || thisLine <= 0) // no work to do
        return 0;

    int stopIndex  = strlen(thisLine),
        numWords = 0,
        index      = 0;

    while(index <= stopIndex)
    {
        while(!isalpha(thisLine[index]) && index <= stopIndex)
            ++index;

        ++ numWords;

        while(thisLine[index] != ' ' && index <= stopIndex)
            ++index;
    }

    return numWords;
}







int Text::hashIndex(const char *thisString, int primeMultiplier, int hashTableSize)
{// For our hash function, were going to add up the values of ever other letter.

    if(thisString == NULL)
        return 0;

    unsigned int stringLength = strlen(thisString);

    if(stringLength == 0)
        return 0;

    int foldValue = 0;

    for(unsigned int i=0; i < stringLength; ++i)
        foldValue += thisString[i];

    return primeMultiplier*foldValue % hashTableSize;
}






//! Linear Linked List stuff

void Text::insert(char *thisString, LNode *&thisNode)
{//! Does a shallow copy of thisString after thisNode.

	if(thisNode == NULL)
	{
        thisNode = new LNode;
		thisNode->string = thisString;
		return;
	}
    LNode *newNode = new LNode;
    newNode->next = NULL;
    newNode->string = thisString;

    thisNode->next = newNode;
}

void Text::insertDeep(const char *thisString, int stringLegnth, LNode *&thisNode)
{//! Does a deep copy of thisString after thisNode.

    if(thisNode == NULL)
    {
        thisNode = new LNode;
        thisNode->next = NULL;
        thisNode->string = new char;
        strcpy_s(thisNode->string, stringLegnth, thisString);
        return;
    }
    LNode *newNode = new LNode;
    newNode->next = NULL;
    strcpy_s(newNode->string, stringLegnth, thisString);

    thisNode->next = newNode;
}







//! Binary Tree stuff


void Text::insert(TNode *thisSubString, TNode *&subTree)
{
    if(subTree == NULL)
    {
        subTree = thisSubString;
        return;
    }
    if(strcmp(subTree->string, thisSubString->string))
        insert(subTree->left, thisSubString);
    else
        insert(subTree->right, thisSubString);
}



void Text::insert(const char *string1, TNode *&subTree)
{
    if(subTree == NULL)
    {
        subTree = new TNode;
        subTree->string = Text::copy(string1);
        subTree->left = subTree->right = NULL;
        return;
    }
    if(strcmp(subTree->string, string1))
        insert(string1, subTree->left);
    else
        insert(string1, subTree->right);
}


void Text::remove(TNode *&subTree, const char *string1)
{
    if (subTree == NULL)
        return;

    int compareValue = strcmp(string1, subTree->string);

    if(compareValue < 0)
        return remove(subTree->left, string1);
    if(compareValue > 0)
        return remove(subTree->right, string1);

 // Then this is the node to delete.

 // Note: A string list can have multiple strings with the same name. The next step is
 //       to compaire the string info. This feature has not been implemented yet.

    if(subTree->left)
    {
        if(subTree->right) // Then there are 2 children
        {
            insert(subTree->left, subTree->right);

            TNode *tempNode = subTree;
            subTree = subTree->left;
            delete tempNode;

            return;
        }
        else //< Then only remove the right node
        {
            TNode *tempNode = subTree;
            subTree = subTree->left;
            delete tempNode;

            return;
        }
    }
    // Then only remove the right child


    TNode *tempNode = subTree;
    subTree = subTree->right;
    delete tempNode;

    return;
}




void Text::destroy(TNode *&subTree)
{
    if(!subTree)
        return;

    destroy(subTree->left);
    destroy(subTree->right);

    delete subTree->string;
    delete subTree;
    subTree = NULL;
}



bool Text::find(TNode *subTree, const char *string1)
{
    if(subTree == NULL)
        return NULL;

    if(!strcmp(subTree->string, string1))
        return true;//subTree->string;

    bool foundString = find(subTree->left, string1);

    if(foundString)
        return true;

    return find(subTree->right, string1);
}



TNode *Text::removeGIOS(TNode *&subTree)
{
    if(subTree->right)
        return removeGIOS(subTree->right);

    TNode *temp = subTree;

    subTree = subTree->left;

    return temp;
}















void Text::countCharsAndNodes(TNode *subTree, int *numChars_numNodes)
{
    if(subTree == NULL)
        return;

    numChars_numNodes[0] += strlen(subTree->string);
    ++numChars_numNodes[1];

    countCharsAndNodes(subTree->left, numChars_numNodes);
    countCharsAndNodes(subTree->right, numChars_numNodes);
}



void Text::countChars(TNode *subTree, int &numChars)
{
    if(subTree == NULL)
        return;

    numChars += strlen(subTree->string);

    countChars(subTree->left, numChars);
    countChars(subTree->right, numChars);
}




void Text::toString(TNode *subTree, char *returnString, int stringLength, const char *nodeFormatter)
{
 // To Do: Optimize me!!!

    if(subTree == NULL)
        return;

    toString(subTree->left, returnString, stringLength, nodeFormatter);

    strcat_s(returnString, stringLength, subTree->string);
    strcat_s(returnString, stringLength, nodeFormatter);

    toString(subTree->right, returnString, stringLength, nodeFormatter);
}



char *Text::toString(TNode *subTree)
{
    return toString(subTree, "\n");
}

char *Text::toString(TNode *subTree, const char *nodeFormatter)
{
    char *returnString;

    const char header[] = "",
               instancesFormatter[] = ": ";

    int instancesFormatterStringLength = strlen(instancesFormatter)
                              + 5                 // int is signed and can have a maximum of 5 places
                              + strlen(nodeFormatter);

    int *sizeOfThisTree = new int[2];
    sizeOfThisTree[0] = 0;
    sizeOfThisTree[1] = 0;

    countCharsAndNodes(subTree, sizeOfThisTree);

    int numChars = strlen(header)+1   // +1 for endl char
                 + sizeOfThisTree[0]  // total num chars
                 + sizeOfThisTree[1]* instancesFormatterStringLength // Total max length of the formating strings
                 + 1; // null term char

    returnString = new char[numChars];

    strcpy_s(returnString, numChars, header);

    toString(subTree, returnString, numChars, nodeFormatter);

    return returnString;
}
