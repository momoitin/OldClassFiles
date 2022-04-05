#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"

using namespace std;

int main()
{
    //create objects to store data
    Stack<char> s1;
    char input[101];          //stores input data
    char noPunct[101];        //stores input with no punctuation and all uppercase
    int count = 0;            //tracker variable for position in noPunct Array
    bool isPalindrome = true; //tracks current validation of the palindrome
    char temp;                //holds the currently popped variable

    cout << "Please enter a string: ";
    cin.getline(input, 100, '\n');

    //pushes the corretly formatted string into the stack in reverse order
    for (int i = 0; i < strlen(noPunct); i++)
    {
        if (isalpha(input[i]))
        {
            noPunct[count] = toupper(input[i]);
            s1.push(noPunct[count]);
            noPunct[count + 1] = '\0';
            count++;
        }

        //checks each node
        s1.pop(temp);
        if (noPunct[i] != temp)
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        cout << '"' << input << '"' << " IS a palindrome" << endl;
    }
    else
    {
        cout << '"' << input << '"' << " is NOT a palindrome" << endl;
    }
}