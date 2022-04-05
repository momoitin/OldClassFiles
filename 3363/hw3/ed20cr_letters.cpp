/* Name: (Evan Dunlap)
Date: (2/22/2021)
Section: (Online)
Assignment: (Assignment#3)
Due Date: (2/25/2021)
About this project: (prints out letters for some reason)
Assumptions: (assumes that all inputs are correct and the correct type)

All work below was performed by Evan Dunlap*/

#include <iostream>

using namespace std;

int sizeCheckYuf(int);
char letterCheck(char);
int spaceInY(int);

int main()
{

    int tempSize;

    char continueCheck = 'Y';

    while(continueCheck == 'Y')
    {
        //gets the size of the letter
        cout << "Please enter the size of the letter: ";
        int letterSize = 0;

        cin >> letterSize;
        letterSize = sizeCheckYuf(letterSize);

        //gets the letter
        cout << "Enter the letter: ";
        char yufLetter;
        
        cin >> yufLetter;
        yufLetter = letterCheck(yufLetter);

        //temp code to check outputs
        //cout << "you entered: " << yufLetter << "\nat size: " << letterSize;

        switch (yufLetter)
        {
        case 'Y':
            //I dont want to do this anymore
            tempSize = letterSize;
            while((tempSize-2) != 1)
            {
                cout << "*";
                tempSize = spaceInY(tempSize);
                cout << "*\n";
            }
            for (int i = 0; i < (letterSize/2); i++)
            {
                for (int i = 0; i < (letterSize/2); i++)
                {
                    cout << " ";
                }
                cout << "*\n";
            }
            break;
            
        case 'U':
            for (int i = 0; i < (letterSize-1); i++)
            {
                cout << "*";
                for (int i = 0; i < (letterSize-2); i++)
                {
                    cout << " ";
                }
                cout << "*\n";
            }
            for (int i = 0; i < letterSize; i++)
            {
                cout << "*";
            }
            cout << endl;
            break;

        case 'F':
            for (int i = 0; i < letterSize; i++)
            {
                cout << "*";
            }
            cout << endl;
            for (int i = 0; i < ((letterSize/2)-1); i++)
            {
                cout << "*\n";
            }
            for (int i = 0; i < (letterSize/2); i++)
            {
                cout << "*";
            }
            for (int i = 0; i < ((letterSize/2)+1); i++)
            {
                cout << "*\n";
            }
            break;
        
        default:
            break;
        }


        //checks with the user if they have more inputs
        cout << "Would you like to continue? (Y or N): ";
        cin >> continueCheck;
    }

    return 0;
}

char letterCheck(char yuf)
{//checks the letter and if its not yuf it makes sure it is
    while(yuf != 'Y' && yuf != 'U' && yuf != 'F')
    {
        cout << "That is not a valid letter: ";
        cin >> yuf;
    }
    return yuf;
}

int sizeCheckYuf(int yuf)
{//makes sure the size of the letter is correct
    while(yuf < 7  || yuf%2 == 0)
    {
        cout << "Invalid size. Please enter a valid size: ";
        cin >> yuf;
    }

    return yuf;
}

int spaceInY(int yuf)
{
    if(yuf >= 1)
    {
        for (int i = 0; i < (yuf-2); i++)
        {
            cout << " ";
        }
        yuf -= 1;
    }
    return yuf;
}