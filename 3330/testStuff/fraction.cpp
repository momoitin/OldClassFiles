#include <iostream>
#include "fraction.h"

using namespace std;

/*  Private Data
int numerator;
int denominator;
*/

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(int n, int d)
{
    Fraction::setValue(n, d);
}
Fraction::~Fraction()
{
    cout << "Fraction " << numerator << "/" << denominator << " deleted" << endl;
}

//operator overload as non member function
Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction r;

    r.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
    r.denominator = f1.denominator * f2.denominator;

    return r;
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    Fraction r;

    r.numerator = -f2.numerator;
    r.denominator = f2.denominator;

    return f1 + r;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    Fraction r;

    r.numerator = f1.numerator * f2.numerator;
    r.denominator = f1.denominator * f2.denominator;

    return r;
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
}

bool operator<(const Fraction &f1, const Fraction &f2)
{
    if (f1.numerator * f2.denominator < f2.numerator * f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const Fraction &f1, const Fraction &f2)
{
    return f2 < f1;
}

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    return !(f2 > f1);
}

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    return !(f1 < f2);
}

bool operator==(const Fraction &f1, const Fraction &f2)
{
    if ((f1 >= f2) && (f1 <= f2))
    {
        return true;
    }
    return false;
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    return !(f1 == f2);
}

ostream &operator<<(ostream &os, const Fraction &f)
{
    os << f.numerator << '/' << f.denominator;
    return os;
}

ostream &operator>>(ostream &is, Fraction &f)
{
    char gb;
    is << f.numerator << '/' << f.denominator;
    is >> f.numerator >> gb >> f.denominator;
}

Fraction Fraction::operator++()
{ //increment and return new value
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{ //increment and return old value
    Fraction r;
    r.numerator = numerator;
    r.denominator = denominator;

    numerator += denominator;

    return r;
}

Fraction Fraction::operator--()
{ //decrement and return new value
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{ //decrement and return old value
    Fraction r;
    r.numerator = numerator;
    r.denominator = denominator;

    numerator -= denominator;

    return r;
}

//Standard input/output
void Fraction::Input() //input a fraction, denominator cannot be 0
{
    char divSign;
    do
    {
        if (denominator == 0)
        {
            cout << "Illegal Fraction. Try again: ";
        }
        cin >> numerator >> divSign >> denominator;
    } while (denominator == 0);
}

void Fraction::Show() const //displays a fraction
{
    cout << numerator << "/" << denominator << endl;
}

//accessors
int Fraction::getNumerator() const
{
    return numerator;
}
int Fraction::getDenominator() const
{
    return denominator;
}

//mutator
bool Fraction::setValue(int n, int d)
{
    if (d == 0)
    {
        d = 1;
    }
    numerator = n;
    denominator = d;
    return true;
}

double Fraction::Evaluate() const
{
    return false;
}