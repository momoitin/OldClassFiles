/* Name: (Evan Dunlap)
Date: (2/22/2021)
Section: (Online)
Assignment: (Assignment#3)
Due Date: (2/25/2021)
About this project: (program finds superpartient numbers and checks if they are co prime or not,
listing out all the common factors if they are not co prime)
Assumptions: (program assumes all inputs are valid int variables greater than 3)

All work below was performed by Evan Dunlap*/

#include <iostream>

using namespace std;

int gcd(int, int);
void factors(int, int);

int main()
{
    int denominator;
    cout << "Please enter the denominator: ";
    cin >> denominator;
    //closes the program is the denominator is more than 3
    if (denominator < 3)
    {
        cout << "Denominator is less than 3, ending program.\n";
        return 0;
    }

    cout << "The possible numbers are:\n";
    double superpartient;
    for (int i = 1; i < denominator; i++)
    {
        //does a bit of math to make sure that the superpartient is less than 2
        superpartient = ((double)denominator + i) / (double)denominator;
        //checks if the superpartient is under 2 which it should be.
        if(superpartient < 2)
        {
            //displays the step that the program is on
            cout << denominator + i << " - ";
            //checsk the GCD, and if it equals 1 then its a match. the numbers are coprime
            if(gcd(denominator, denominator + i) == 1)
            {
                cout << denominator+i << "/" << denominator << endl;
            }
            else //if the GCD is not 1, this finds the common denominators
            {
                //puts the 2 numbers that are not co-prime into the testing function
                factors((denominator),(denominator+i));
                //final output
                cout << "common\n";
            }
            
        }
    }
    
    return 0;
}

//im a wizard
//GCD calculator bc I cant use one that is already made for some reason
//sends back the GCD... but I want all the denominators so what to do...???
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }

    return a;
}

//function to find the common factors of 2 numbers excluding 1.
void factors(int a, int b)
{
    //makes sure that a and b are less than the count
    for (int i = 1; i <= a && i <= b; ++i)
    {
        //checks to make sure the remainders are 0, if so its a common factor
        //excluding 1 since its a common factor of everything.
        if(a%i==0 && b%i==0 && i!=1)
        {
            cout << i << ", ";
        }
    }
}