#include<iostream>
#include<cmath>

using namespace std;

double function(char, double);

int main()
{
    cout << "Enter a number: ";
    double number;
    cin >> number;

    cout << "Enter a Letter: ";
    char letter;
    cin >> letter;

    double output = function(letter, number);
    cout << "The result is: " << output;


    return 0;
}

double function(char letter, double number)
{
    switch (letter)
    {
    case 'S':
        number = sqrt(number);
        return number;
        break;
    
    case 'E':
        number = pow(number, 5);
        return number;
        break;
    
    default:
        return -1;
        break;
    }
    return 0;
}