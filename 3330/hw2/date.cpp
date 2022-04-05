////////////////////////////////////////////////////////////////////////////////////
//      This Class was developed by Evan Dunlap
//      05/27/2021
//      Date Class
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "date.h"

using namespace std;

/*Private Data
unsigned int day;   //must be within range of (1-31)
unsigned int month; //must be within range of (1-12)
unsigned int year;  //must be a valid 4 digit date >0

char format;
*/
const string Date::monthName[] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
const int Date::monthMaxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() //default constructor with default date 1/1/2000
{
    Date::Default();
}

Date::Date(int m, int d, int y)
{ //calls the set function to check if date is legit, if not calls default date.
    bool catchCheck = Date::Set(m, d, y);
    if (catchCheck == false)
    {
        cout << "Invalid Date detected, using default\n";
        Date::Default();
    }
}

Date::~Date()
{
    // cout << "Deleting date ";
    // Date::Show();
}

//setter function
void Date::Default()
{
    month = 1;
    day = 1;
    year = 2000;
    format = 'D';
}

void Date::Input()
{ //inputs date from keyboard input, checks if the date is valid
    //assumes correct keyboard format
    char garbage;
    int m, d, y;
    cout << "Enter a date (month/day/year format): ";
    cin >> m >> garbage >> d >> garbage >> y;
    while (Date::Set(m, d, y) == false)
    {
        cout << "Invalid date format, enter a valid date (month/day/year format): ";
        cin >> m >> garbage >> d >> garbage >> y;
    }
}

bool Date::Set(int m, int d, int y)
{ //checks to make sure that the date is a real date, if so then sets the date
    if ((d > monthMaxDays[m - 1] || d < 1) || (m > 12 || m < 1) || (y < 1))
    {
        return false;
    }
    month = m;
    day = d;
    year = y;
    Date::SetFormat(format); //checks to make sure date is valid, uses default for form D
    return true;
}

bool Date::SetFormat(char f)
{ //changes the format of the date to display
    switch (f)
    {
    case 'T':
        format = 'T';
        return true;

    case 'L':
        format = 'L';
        return true;

    default:
        format = 'D';
        return true;
    }
    return false;
}

//mutator functions
void Date::Increment(int numDays)
{ //nested if statements increment the day by 1 and increases the month and year when needed
    for (int i = 0; i < numDays; i++)
    {
        if (day == monthMaxDays[month - 1])
        {
            if (month == 12)
            {
                month = 1;
                day = 1;
                year++;
            }
            else
            {
                month++;
                day = 1;
            }
        }
        else
        {
            day++;
        }
        // to test the output of the date to make sure its correctly counting
        // cout << "Number of days passed in loop: " << i + 1 << " out of: " << numDays << endl;
    }
    return;
}

//getter function
int Date::GetMonth() const
{
    return month;
}
int Date::GetDay() const
{
    return day;
}
int Date::GetYear() const
{
    return year;
}

void Date::Show() const
{

    switch (format)
    {
    case 'D':
        cout << month << "/" << day << "/" << year << endl;
        break;

    case 'T':
        if (month < 10)
        {
            cout << '0' << month << "/";
        }
        else
        {
            cout << month << "/";
        }
        if (day < 10)
        {
            cout << '0' << day << "/";
        }
        else
        {
            cout << day << "/";
        }
        if ((year % 1000) == 0)
        {
            cout << "00" << endl;
        }
        else
        {
            cout << year % 100 << endl;
        }
        break;

    case 'L':
        cout << monthName[month - 1] << " " << day << ", " << year << endl;
    default:
        cout << format << endl;
        break;
    }
}

int Date::Compare(const Date &d) const
{
    if (year < d.year)
    {
        return -1;
    }
    if (year > d.year)
    {
        return 1;
    }
    // If we got to this point then we know that the year is the same
    if (month < d.month)
    {
        return -1;
    }
    if (month > d.month)
    {
        return 1;
    }
    // If we got to this point we know that the month is the same
    if (day < d.day)
    {
        return -1;
    }
    if (day > d.day)
    {
        return 1;
    }
    // If we got to here then the day is the same
    return 0;
}