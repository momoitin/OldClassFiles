#include <iostream>
#include "time.h"

using namespace std;

/*Private Data
unsigned int days, hours, minutes, seconds;
*/

//operator overload as stand alone
Time operator+(const Time &t1, const Time &t2)
{
    Time r;

    r.days = t1.days + t2.days;
    r.hours = t1.hours + t2.hours;
    r.minutes = t1.minutes + t2.minutes;
    r.seconds = t1.seconds + t2.seconds;

    r = timeCalculator(r);
    return r;
}
Time operator-(const Time &t1, const Time &t2)
{
    Time r;

    r.days = t1.days - t2.days;
    r.hours = t1.hours - t2.hours;
    r.minutes = t1.minutes - t2.minutes;
    r.seconds = t1.seconds - t2.seconds;

    r = timeCalculator(r);

    return r;
}
Time operator*(const Time &t, const int &x)
{
    Time r;
    r.seconds = t.seconds * x;
    r.minutes = t.minutes * x;
    r.hours = t.hours * x;
    r.days = t.days * x;

    r = timeCalculator(r);

    return r;
}

ostream &operator<<(ostream &os, const Time &t) //prints in form days~hh:mm:ss
{
    os << t.days << "~";
    if (t.hours < 10)
    {
        os << "0" << t.hours << ":";
    }
    else
    {
        os << t.hours << ":";
    }
    if (t.minutes < 10)
    {
        os << "0" << t.minutes << ":";
    }
    else
    {
        os << t.minutes << ":";
    }
    if (t.seconds < 10)
    {
        os << "0" << t.seconds;
    }
    else
    {
        os << t.seconds;
    }

    return os;
}
istream &operator>>(istream &is, Time &t) //same input format as output
{
    //garbage char to catch the ~, and : characters
    char gb;
    is >> t.days >> gb >> t.hours >> gb >> t.minutes >> gb >> t.seconds;
    if (t.days < 0 || t.hours < 0 || t.minutes < 0 || t.seconds < 0)
    {
        t = 0;
    }
    //double checks the input to make sure its the correct format
    t = timeCalculator(t);

    return is;
}

//comparison operator overloads
bool operator==(const Time &t1, const Time &t2)
{
    if ((t1 >= t2) && (t1 <= t2))
    {
        return true;
    }
    return false;
}
bool operator!=(const Time &t1, const Time &t2)
{
    return !(t1 == t2);
}
bool operator<(const Time &t1, const Time &t2)
{ //As long as each variable is not equal, compares which one if smaller.
    //returns 0 if t1 is larger, returns 1 if t2 is larger.
    if (t1.days != t2.days)
    {
        // cout << t1.days << " < " << t2.days << " = " << (t1.days < t2.days) << " ";
        return (t1.days < t2.days);
    }

    if (t1.hours != t2.hours)
    {
        // cout << t1.hours << " < " << t2.hours << " = " << (t1.hours < t2.hours) << " ";
        return (t1.hours < t2.hours);
    }

    if (t1.minutes != t2.minutes)
    {
        // cout << t1.minutes << " < " << t2.minutes << " = " << (t1.minutes < t2.minutes) << " ";
        return (t1.minutes < t2.minutes);
    }

    if (t1.seconds != t2.seconds)
    {
        // cout << t1.seconds << " < " << t2.seconds << " = " << (t1.seconds < t2.seconds) << " ";
        return (t1.seconds < t2.seconds);
    }

    return false;
}
bool operator>(const Time &t1, const Time &t2)
{
    return (t2 < t1);
}
bool operator<=(const Time &t1, const Time &t2)
{
    return !(t1 > t2);
}
bool operator>=(const Time &t1, const Time &t2)
{
    return !(t1 < t2);
}

//Time calculator as non member that accepts time variable
Time timeCalculator(Time t)
{
    //checks to make sure no value is above bounds
    while (t.seconds >= 60)
    {
        t.minutes++;
        t.seconds -= 60;
    }
    while (t.minutes >= 60)
    {
        t.hours++;
        t.minutes -= 60;
    }
    while (t.hours > 24)
    {
        t.days++;
        t.hours -= 24;
    }
    //checks if any values are negative
    while (t.hours < 0)
    {
        t.days--;
        t.hours += 24;
    }
    while (t.minutes < 0)
    {
        t.hours--;
        t.minutes += 60;
    }
    while (t.seconds < 0)
    {
        t.minutes--;
        t.seconds += 60;
    }
    //if any values are still negative, zero out the variable
    if (t.days < 0 || t.hours < 0 || t.minutes < 0 || t.seconds < 0)
    {
        return t = 0;
    }

    return t;
}

Time::Time() //default constructor initalizes object at 0
{
    *this = Time::timeDefault(*this);
}
Time::Time(int s) //constructor in terms of seconds, if negative set time object to 0
{
    if (s <= 0)
    {
        *this = Time::timeDefault(*this);
        return;
    }
    else
    {
        *this = Time::timeDefault(*this);
        seconds = s;
        *this = Time::timeCalculatorOne(*this);
        return;
    }
}
Time::Time(int s, int m, int h, int d) //if any values are negative, set the time object to 0
{
    //if any of the values are 0, this is invalid. Default all values to 0~0:0:0
    if (s < 0 || m < 0 || h < 0 || d < 0)
    {
        s = 0;
        m = 0;
        h = 0;
        d = 0;
    }
    else
    {
        seconds = s;
        minutes = m;
        hours = h;
        days = d;

        *this = Time::timeCalculatorOne(*this);
    }
}

Time::~Time()
{
}

//mutator changes all calculable time to seconds, then calcualtes time in proper orders
Time Time::timeCalculatorOne(Time t)
{
    //calls non member function with member data
    //bc I couldnt figure out how to call member function using a non member function
    t = timeCalculator(t);
    return t;
}

//set all values to zero to begin with to avoid issues
Time Time::timeDefault(Time r)
{
    r.days = 0;
    r.hours = 0;
    r.minutes = 0;
    r.seconds = 0;

    return r;
}

//overloads as member functions
Time Time::operator++() //pre incrememnt addition
{                       //increment and return new value
    seconds++;
    *this = Time::timeCalculatorOne(*this);

    return *this;
}
Time Time::operator++(int) //post increment addition
{                          //increment and return old value
    Time r = *this;

    seconds++;
    *this = Time::timeCalculatorOne(*this);

    return r;
}

Time Time::operator--() //pre increment subtraction
{                       //decrement and return new value
    seconds--;
    *this = Time::timeCalculatorOne(*this);

    return *this;
}
Time Time::operator--(int) //post increment subtraction
{                          //decrement and return old value
    Time r = *this;

    seconds--;
    *this = Time::timeCalculatorOne(*this);

    return r;
}