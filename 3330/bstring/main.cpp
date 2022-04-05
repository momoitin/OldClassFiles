#include <iostream>
#include "bstring.h"

using namespace std;

int main()
{
    BString s1;          // build an object with default constructor
    BString s2("Hello"); // build object using c-string constructor

    cout << "s1 = " << s1 << '\n';
    cout << "s2 = " << s2 << '\n';
}