//////////////////////////////////////////////////////////////////////////////////////////
//              Fraction Class
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Fraction
{
    //operator overload as stand alone
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);

    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);

    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator>(const Fraction &f1, const Fraction &f2);
    friend bool operator<=(const Fraction &f1, const Fraction &f2);
    friend bool operator>=(const Fraction &f1, const Fraction &f2);

    friend ostream &operator<<(ostream &os, const Fraction &f);
    friend istream &operator>>(istream &is, Fraction &f);

public:
    Fraction();
    Fraction(int n, int d = 1);
    ~Fraction();

    //operator overloads as members
    Fraction operator++();
    Fraction operator++(int);

    Fraction operator--();
    Fraction operator--(int);

    //Standard input/output
    void Input();      //input a fraction, denominator cannot be 0
    void Show() const; //displays a fraction

    //accessors
    int getNumerator() const;
    int getDenominator() const;

    //mutator
    bool setValue(int n, int d = 1);

    double Evaluate() const;

private:
    int numerator;
    int denominator;
};
