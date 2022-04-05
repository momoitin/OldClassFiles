/* Name: (Evan Dunlap)
Date: (3/5/2021)
Section: (Your section)
Assignment: (Assignment#4)
Due Date: (3/11/2021)
About this project: (does math baised on inputs and flips some numbers)
Assumptions: (assumes all inputs are valid and in the correct forms)

All work below was performed by (Evan DUnlap :) */ 

#include<iostream>

using namespace std;


int flip(int);
int value(int,int);

int main()
{
    int avgInputTotal = 0;
    int numberOfInputs = 0;

    long int input = 1;
    while(input != 0)
    {
        cout << "Enter the Number (0 to exit): ";
        cin >> input;
        if (input == 0)
        {
            break;
        }
        
        //sends the input to the flipping function
        long int flippedInput = flip(input);
        // cout << "The input is: " << input << endl;
        // cout << "Flipped number: " << flippedInput << endl;

        long int flipsum = value(input, flippedInput);
        cout << "The flipped sum of " << input << " is: " << flipsum << endl;
        avgInputTotal += flipsum;
        numberOfInputs++;
    }

    if(avgInputTotal != 0)
    {
        cout << "The average flipped sum is: " << avgInputTotal/numberOfInputs; 
    }
    else
    {
        cout << "No valid data entered, ending program.\n";
    }
    
    return 0;
}

int flip(int input)
{
    int flippedInput = 0, remainder;
    //takes the input and finds the remainder when divided by 10 (shaving off the last digit)
    //saves that digit as the remainder then multiplies the flippedinput by 10, to add a 0 on the right
    //then adds the remainder to that spot in the single digit location.
    while(input != 0)
    {
        remainder = input%10;
        if (remainder == 6)
        {
            remainder = 9;
        }
        else if (remainder == 9)
        {
            remainder = 6;
        }
        
        flippedInput = flippedInput*10 + remainder;
        input /= 10;
    }
    return flippedInput;
}

int value(int input, int flippedInput)
{
    //adds both of the inputs
    int flipSum = input + flippedInput;
    //and returns it
    return flipSum;
}