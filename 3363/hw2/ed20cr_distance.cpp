/* Name: (Evan Dunlap)
Date: (2/7/2021)
Section: (Your section)
Assignment: (Assignment# 2)
Due Date: (2/9/2021 11:59 PM)
About this project: (finds the speed difference bettwen a car and a plane)
Assumptions: (assumes the user will enter proper data types and uppercase characters
             the reference letter.)

All work below was performed by (Evan Dunlap :) */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Car:     Code:\n"
         << "Blue   -   B  \n"
         << "Green  -   G  \n"
         << "Orange -   O  \n"
         << "White  -   W  \n"
         << "Red    -   R  \n"
         << "Yellow -   Y  \n\n"
         << "Please enter a colors code (case sensitive): ";

    //gets the car color from the table below
    char colorCode;
    cin >> colorCode;

    //gets the length of the runway in miles
    cout << "Enter the length of the runway (in miles): ";
    double chaseDistance;
    cin >> chaseDistance;

    //gets the duration of the case in minutes
    cout << "Please enter the duration of the chase (in minutes): ";
    double chaseTime;
    cin >> chaseTime;

    //declares the constant speed of the cars for easy editing
    const int carSpeedB = 340,
              carSpeedG = 440,
              carSpeedO = 430,
              carSpeedW = 410,
              carSpeedR = 420,
              carSpeedY = 383;
        
    //grabs the correct statement baised on what the value of colorCode is
    switch (colorCode)
    {
    case 'B':
        cout << "Estimated speed of airplane: ";
        cout << carSpeedB - (chaseDistance / (chaseTime/60));
        cout << " miles / hour\n";
        break;

    case 'G':
        cout << "Estimated speed of airplane: ";
        cout << carSpeedG - (chaseDistance / (chaseTime/60));
        cout << " miles / hour\n";
        break;

    case 'O':
        cout << "Estimated speed of airplane: ";
        cout << carSpeedO - (chaseDistance / (chaseTime/60));
        cout << " miles / hour\n";
        break;

    case 'W':
        cout << "Estimated speed of airplane: ";
        cout << carSpeedW - (chaseDistance / (chaseTime/60));
        cout << " miles / hour\n";
        break;

    case 'R':
        cout << "Estimated speed of airplane: ";
        cout << carSpeedR - (chaseDistance / (chaseTime/60));
        cout << " miles / hour\n";
        break;

    case 'Y':
        cout << "Estimated speed of airplane: ";
        cout << carSpeedY - (chaseDistance / (chaseTime/60));
        cout << " miles / hour\n";
        break;
    
    default:
        cout << "invalid reference letter for the car.\n";
        break;
    }

    return 0;
}