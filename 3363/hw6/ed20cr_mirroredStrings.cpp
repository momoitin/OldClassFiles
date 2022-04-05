/* Name: (Evan Dunlap)
Date: (4/8/2021)
Section: (Your section)
Assignment: (Assignment#6)
Due Date: (4/8/2021)
About this project: (mirrors a cstring)
Assumptions: (all values must be the correct data types.)

All work below was performed by (Evan Dunlap) */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
//prototype decliration
void readAndMirror();

int main()
{
    readAndMirror();

    return 0;
}

void readAndMirror()
{
    cout << "Enter the number of strings: ";
    int numOfStrings;
    cin >> numOfStrings;
    

    cout << "Enter the strings:";

    char userInput[150];
    cin.get(userInput, 150, '\n');

    int start = 0;
    int end = strlen(userInput);
    int length = end;

    while (start < end)
    {
        char temp = userInput[start];
        userInput[start] = userInput[end];
        userInput[end] = temp;

        start++;
        end--;
    }

    for (int i = 0; i < length + 1; i++)
    {
        cout << userInput[i];
    }

    cout << endl;
}