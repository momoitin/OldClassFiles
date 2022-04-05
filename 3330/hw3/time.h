#include <iostream>

using namespace std;

class Time
{
    //operator overload as stand alone
    friend Time operator+(const Time &t1, const Time &t2);
    friend Time operator-(const Time &t1, const Time &t2);
    friend Time operator*(const Time &t, const int &x);

    friend ostream &operator<<(ostream &os, const Time &t); //prints in form days~hh:mm:ss
    friend istream &operator>>(istream &is, Time &t);       //same input format as output

    //comparison operator overloads
    friend bool operator==(const Time &t1, const Time &t2);
    friend bool operator!=(const Time &t1, const Time &t2);
    friend bool operator<(const Time &t1, const Time &t2);
    friend bool operator>(const Time &t1, const Time &t2);
    friend bool operator<=(const Time &t1, const Time &t2);
    friend bool operator>=(const Time &t1, const Time &t2);

    friend Time timeCalculator(Time t);

public:
    Time();                           //default constructor initalizes object at 0
    Time(int s);                      //constructor in terms of seconds, if negative set time object to 0
    Time(int s, int m, int h, int d); //if any values are negative, set the time object to 0
    ~Time();

    //mutator
    Time timeCalculatorOne(Time t);
    Time timeDefault(Time r);

    //overloads as member functions
    Time operator++();    //pre increment addition
    Time operator++(int); //post incrememnt addition

    Time operator--();    //pre increment subtraction
    Time operator--(int); //post increment subtraction

private:
    int days, hours, minutes, seconds;
};