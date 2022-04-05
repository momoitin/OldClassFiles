/* Name: (Evan Dunlap)
Date: (4/5/2021)
Section: (Your section)
Assignment: (Assignment#6)
Due Date: (4/8/2021)
About this project: (counts stats about a string that was input)
Assumptions: (all values must be the correct data types.)

All work below was performed by (Evan Dunlap) */

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int spaceCount(string);
int digitCount(string);
int lowercaseCount(string);
bool findSubString(string);

int main()
{
    cout << "Enter the string: ";
    string userInput;

    bool doneCheck = 0;
    int doneFound = 0;

    while (doneCheck != 1)
    {
        getline(cin, userInput, '#'); //reads up to # in the string
        //flags the location of Done in the string
        doneFound = userInput.find("Done");
        if (doneFound == 1) //if the first word in the string is Done, then exits
        {
            return 0;
        }

        int stringSpaces = spaceCount(userInput);
        cout << "Number of whitespace: " << stringSpaces << endl;

        int stringDigits = digitCount(userInput);
        cout << "Number of hexadecimal digits: " << stringDigits << endl;

        int stringLowers = lowercaseCount(userInput);
        cout << "Number of lowercase characters: " << stringLowers << endl;

        bool stringFind = findSubString(userInput);
        if (stringFind == 1)
        {
            cout << "'people' is a part of this string " << endl;
        }
        else
        {
            cout << "'people' is not a part of this string" << endl;
        }
    }

    return 0;
}

int spaceCount(string userInput)
{
    int stringSpaces = 0;

    //goes through the string (length) times
    for (int i = 0; i < userInput.length(); i++)
    {
        //find locates the position of the object found
        //cuts the string off by 1 each itteration starting from point 0;
        string spaceCheck(userInput, i);
        //if there is a space in the first position (0), add to the coutner
        if (spaceCheck.find(" ") == 0)
        {
            stringSpaces++;
        }
    }

    return stringSpaces;
}

int digitCount(string userInput)
{
    int stringDigits = 0;
    //goes through the string (length) times
    for (int i = 0; i < userInput.length(); i++)
    {
        if (isxdigit(userInput[i]))
        {
            stringDigits++;
        }
    }
    return stringDigits;
}

int lowercaseCount(string userInput)
{
    int stringLowers = 0;
    //goes through the string (length) times
    for (int i = 0; i < userInput.length(); i++)
    {
        if (islower(userInput[i]))
        {
            stringLowers++;
        }
    }
    return stringLowers;
}

bool findSubString(string userInput)
{
    bool stringFound = 0;
    //if the starting location of the word "people", is greater than 0,
    //triggers the flag.
    int found = 0;
    found = userInput.find("people");
    if (found >= 0)
    {
        stringFound = 1;
    }

    return stringFound;
}