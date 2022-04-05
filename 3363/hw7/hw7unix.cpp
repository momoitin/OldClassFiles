#include <iostream>
using namespace std;
int main()
{

    int x = 10;   //Declare an inetger
    int *p = &x;  //Declare a pointer. Initialize it with teh address of x
    int **q = &p; //Declare a double pointer, initialize it with the address of p

    cout << "X: " << x << endl;   //prints value of x
    cout << "&x: " << &x << endl; //prints the address of x
    cout << "p: " << p << endl;   //prints the value of p, which is the address of x
    cout << "&p: " << &p << endl; //Prints the address of p
    cout << "*p: " << *p << endl; //Prints p dereferenced, which is the value of x

    cout << "Q: " << q << endl;     //prints q, which is the address of p
    cout << "&Q: " << &q << endl;   //prints the address of q
    cout << "*Q: " << *q << endl;   //Prints Q dereferenced, which is the value of p, which is the address of x
    cout << "**Q: " << **q << endl; //printd Q double dereferenced, which is dereferenced p, which is the value of x

    return 0;
}