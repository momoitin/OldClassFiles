/* Name: (Evan Dunlap)
Date: (3/10/2021)
Section: (Your section)
Assignment: (Assignment#4)
Due Date: (3/11/2021)
About this project: (finds the sum of e-lambda summation from k=0 to x of 
lambda^k / k!)
Assumptions: (assumes all inputs are integers and correct)

All work below was performed by (Evan Dunlap :) */ 

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


long double factorial(double);
long double sum(double, long double);

int main()
{
    double x=1;
    double lambda;
    

    cout << "Enter the expected number of customers: ";
    cin >> lambda;

    //continues the loop so long as x >= 0
    while(x >= 0)
    {
        cout << "Enter the actual number of customers: ";
        cin >> x;

        if(x < 0) //stops the program when x is less than 0
        {
            return 0;
        }

        //calculates the summation of x and lambda
        double finalSum = sum(x, lambda);

        //sets the decimal point to the tenthousandth place
        // finalSum *= 10000;
        // finalSum += 0.5;
        // finalSum = (int)finalSum;
        // finalSum = (double)finalSum / 10000;

        cout << "Probability of less than " << x;
        cout << " customers was " << finalSum << endl;

        if(finalSum < 0.5)
        {
            cout << "Under optimum performance" << endl;
        }
    }

    return 0;
}

long double factorial(double x)
{
    long double factorial = 1;
    //runs from 1 to the input number x, multiplies factorial by i untill input is reaches
    //the final falue is x!
    for(int i=1; i<=x; i++)
    {
        factorial *= i;
    }
    //shows output of each factorial
    cout << "Factorial of " << x << ": " << setprecision(6000) << factorial << endl;

    return factorial;
}

long double sum(double x, long double lambda)
{
    double summation, finalSum;
    double e = 2.71828;

    //summation from k=0 to x of lambda^k / k!
    for (int i = 0; i <= x; i++)
    {
        summation += pow(lambda, i) / factorial(i);
    }
    //e^-lambda * summation
    finalSum = pow(e, -lambda) * summation;

    return finalSum;
}