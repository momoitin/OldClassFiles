/*
    This program was made with love by Evan Dunlap
    on 2/19/2021 :)
*/

#include<iostream>

using namespace std;

int main()
{
    double upperLimit, lowerLimit, sum;

    cout << "Please enter the upper limit: ";
    cin >> upperLimit;

    cout << "Please enter the lower limit: ";
    cin >> lowerLimit;

    cout << "Enter 10 Numbers\n";
    for (int i = 0; i < 10; i++)
    {
        double input;
        cin >> input;

        if(input > lowerLimit && input < upperLimit)
        {
            sum += input;
        }
    }
    
    cout << "The sum is " << sum << endl;

    

    return 0;
}