/*
    This program was made with love by Evan Dunlap
    on 2/5/2021 :)
*/

#include<iostream>

using namespace std;

int main()
{
    double num1, num2;

    cout << "Please enter 2 numbers:\nNumber 1: ";
    cin >> num1;
    cout << "Number 2: ";
    cin >> num2;

    if(num1 < 0 && num2 < 0)
    {
        double temp = (num1/num2) * 5;
        cout << temp;
    }
    else
    {
        double temp = (num1*num2) / 7;
        cout << temp;
    }


    return 0;
}