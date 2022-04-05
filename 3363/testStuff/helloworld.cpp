#include <iostream>

using namespace std;

void testVoid();

int main()
{
    int input = 0;

    testVoid();

    cout << "Press 1 for yes\nPress 2 for no\n";
    cin >> input;

    if (input > 0 && input == 1)
    {
        cout << "You answered yes\n";
    }
    else if(input == 2)
    {
        cout << "You answered no\n";
    }
    else
    {
	cout << "please enter a valid option\n";
    }
    
    return 0;
}

void testVoid()
{
    cout << "this is from the void\n";    
}
