#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date d1, d2(12, 13, 19);
    // d2.SetFormat('T');

    cout << "The date d1 is: ";
    d1.Show();

    cout << "The date d2 is: ";
    d2.Show();
    d2.SetFormat('D');

    // d2.Input();

    d2.Increment();
    cout << "The date d2 is now: ";
    d2.Show();

    d2.Increment(364);
    cout << "The date d2 is now: ";
    d2.Show();
    d2.SetFormat('T');

    d2.Increment();
    cout << "The date d2 is now: ";
    d2.Show();

    d1.Set(1, 1, 2000);
    d2.Set(2, 12, 2000);

    cout << "return should be -1: " << d1.Compare(d2) << endl;
    cout << "return should be 1:  " << d2.Compare(d1) << endl;
    cout << "return should be 0:  " << d2.Compare(d2) << endl;
}