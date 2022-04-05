/* Name: (Evan Dunlap)
Date: (1/21/2021)
Section: (Your section)
Assignment: (Assignment# 1)
Due Date: (1/28/2021 11:59 PM)
About this project: (This program is to help Patrick take orders without using any brain power, not that he has any to begin with)
Assumptions: (assumes all inputs are integers within the bouds defined by the program)

All work below was performed by (Evan Dunlap :) */

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{   //Introduces and says hello as an output
    cout << "\n\nHello? No, this is patrick.\n";

    //declares the constant price of the menu items
    const float krabbyPatty = 4.19,
                fries       = 2.15,
                kelpShake   = 3.75,
                salesTax    = 0.0185; 
    
    //declares the variables for the number of each item the customer might order, in an int bc you cant order half of a sandwich at the Krusty Krab
    int KrabbyPattieNum,
        friesNum,
        kelpShakeNum;

    //Asks the customer to tell Patrick how many of each menu item they would like
    cout << "Enter the number Krabby Patties ";
    cin >> KrabbyPattieNum;

    cout << "Enter the number of Kelp Shakes ";
    cin >> kelpShakeNum;

    cout << "Enter the number of Fries ";
    cin >> friesNum;


    //declares and calculates the total of the order in one line. 
    //Then calcualtes the tax bc you need to find the total first to find the tax.
    float total = (KrabbyPattieNum * krabbyPatty) + (friesNum * fries) + (kelpShakeNum * kelpShake);
    total += total * salesTax;


    //declares and checks if the customer will split the check and with how many people
    int splitCheckTest,
        splitCheckAmount;


    //asks customer how many people will be splitting and gets that number.
    cout << "How many checks are there for this order? ";
    int checkNum;
    cin >> checkNum;


    //displays the total cost of the ticket per customer, if there are multiple, and rounds the digit to two decimal places
    cout << "your total then is " << fixed << setprecision(2) << total/checkNum << endl;

    return 0;
}