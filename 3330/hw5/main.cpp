#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "mystring.h"

using namespace std;

int main()
{
    MyString s1 = "I love c++ kinda", s2, s3;

    cout << s1 << endl;

    // cout << "Input something: ";
    // cin >> s2;
    // cout << "This is what you input: " << s2 << endl;

    // cout << "Input something: ";
    // getline(cin, s3);
    // cout << "This is what you input: " << s3 << endl;

    // cout << s3.indexOf('o');

    // MyString s3 = "Hello World";
    // cout << s3 << endl;

    // s3.insert(6, "Cruel ");
    // cout << s3 << endl;

    cout << "test 1" << endl;
    MyString x = 12345678;
    cout << "test 2" << endl;

    cout << "x is: " << x << endl;
    cout << "test 3" << endl;

    x.insert(5, "Hello");
    cout << "x is now: " << x << endl;

    cin >> s1;
    getline(cin, s2);
    getline(cin, s3, '#');

    cout << s1 << endl
         << s2 << endl
         << s3 << endl;

    return 0;
}