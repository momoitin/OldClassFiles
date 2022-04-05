#include<iostream>

using namespace std;

int main()
{
    //declares the two input variables
    int num1, num2;

    //takes in the first input
    cout << "please enter a number: ";
    cin  >> num1;
    //takes in the second input
    cout << "please enter another number: ";
    cin  >> num2;

    //shows the difference between the second and first number as an integer
    cout << "The difference between your two numbers is: "
         << num2 - num1 << endl;

    return 0;

}