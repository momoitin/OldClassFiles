/* Name: (Evan Dunlap)
Date: (2/2/2021)
Section: (Your section)
Assignment: (Assignment# 2)
Due Date: (2/9/2021 11:59 PM)
About this project: (This program puts numbers in order and calculates the difference
                    between the numbers to see if any differences are the same)
Assumptions: (assumes all inputs are integers within the bouds defined by the program)

All work below was performed by (Evan Dunlap :) */

#include <iostream>
#include<iomanip>

using namespace std;

//prototype to reuse code
bool numbertest(double, double, double);
bool differenceCheck(double, double, double, double);
double ab(double);

int main()
{
    //declares the 4 variables that will be input by the user
    double var1,
          var2,
          var3,
          var4;

    //starts the process of entering the numbers
    cout<< "\n\nPlease enter 4 numbers:\nNumber 1: ";
    cin >> var1;

    cout<<"Number 2: ";
    cin >> var2;

    cout<<"Number 3: ";
    cin >> var3;

    cout<<"Number 4: ";
    cin >> var4;
    //ends the process of entering numbers


    //inputs the test variable and 2 others to compare to into a true/false function.
    //if the function returns false, the program ends stating that the 3 numbers were
    //equal, if it returns true, it continues to the next 3 numbers.
    //var1 numbertest
    if (!numbertest(var1, var2, var3)){
        return 0;
    }
    if (!numbertest(var1, var3, var4)){
        return 0;
    }
    
    //var2 numbertest
    if (!numbertest(var2, var1, var3)){
        return 0;
    }
    if (!numbertest(var2, var3, var4)){
        return 0;
    }
    
    //var 3 numbertest
    if (!numbertest(var3, var1, var2)){
        return 0;
    }
    if (!numbertest(var3, var2, var4)){
        return 0;
    }
    
    //var4 numbertest
    if (!numbertest(var4, var1, var2)){
        return 0;
    }
    if (!numbertest(var4, var2, var3)){
        return 0;
    }
    

    /*Starts the process of sorting out the digits one
    at a time, first by comparing the first 2, then if
    2 is less than one, they flip. bringing the smaller
    number in front, this continues with numbers 3 and 2,
    bringing the smaller one in front, then goes back to
    numbers 2 and 1 again to double check. then numbers
    4 and 3, then it goes through another check of 3 and 2,
    then 2 and 1 again to finish.
    */
    if (var2 < var1)
        swap(var1, var2);

    if (var3 < var2)
        swap(var2, var3);

    if (var2 < var1)
        swap(var1, var2);

    if (var4 < var3)
        swap(var3, var4);

    if (var3 < var2)
        swap(var2, var3);

    if (var2 < var1)
        swap(var1, var2);    

    cout << "\nYour numbers in order are: ";
    cout << var1 << ", " << var2 << ", " << var3 << ", " << var4 << endl;
    // ends number sorting, this could easily be sent through an int function
    //but this works fine and doesnt look terrible.



    //3 combinations
    //(var1 var2) (var3 var4)
    //(var1 var3) (var2 var4)
    //(var1 var4) (var2 var3)

    //sends variables in an order to check to see if the difference
    //between them is the same
    bool test1 = differenceCheck(var1, var2, var3, var4);
    if(test1 == true)
    {
        return 0;
    }

    bool test2 = differenceCheck(var1, var3, var2, var4);
    if(test2 == true)
    {
        return 0;
    }

    bool test3 = differenceCheck(var1, var4, var2, var3);
    if(test3 == true)
    {
        return 0;
    }
    //if none of them come back positive then it is assumed that there are no pairs
    if(!test1 &&  !test2 &&  !test3)
    {
        cout << "There are no pairs\n";
    }


    return 0;
}

//this method allows me to input a variable to compare 2 other variable too,
//then it tells me if 3 or more equal that same variable then returns false, and
//exits the program if that is the case.
//my other classes taught me to reuse code as much as possible and I dont know if
//we have gone over methods and function declration yet bc I havnt been paying attention
//but if this is against the law please let me know
bool numbertest(double testvar, double var1, double var2)
{
    if (testvar == var1 && testvar == var2)
    {
        cout << "Three values are the same, please try again\n";
        return 0;
    }
    return true;
}

//checks the difference of the numbers sent in orders (a,b) and (c,d)
bool differenceCheck(double a, double b, double c, double d)
{    
    //if you see this can you please explain to me why truncating a double into a float
    //would fix this? If I remove the (float) from this equation and run the same test
    //sample 2, it no longer works and says there is no pair.
    if((float)(a-b)==(float)(c-d))
    {
        //cout << (a-b) << endl << (c-d) << "\n\n";
        cout<<"The pairs are: (" <<a<< ", " <<b<< ") and (" <<c<< ", " <<d<< ")." << endl;
        return true;
    }
    return false;
}

//works the same as math.h abs() but I cant use that so I have to make my own
double ab(double number)
{
    if(number < 0)
    {
        return number * -1;
    } 
    else return number;
}