////////////////////////////////////////////////////////////////////////////////////
//      This Class was developed by Evan Dunlap
//      05/27/2021
//      Date Class
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Date
{
public:
    //constructors
    Date();
    Date(int m, int d, int y);
    ~Date();

    //setter function
    void Default();                //holds the default date information
    void Input();                  //inputs keyboard date
    bool Set(int m, int d, int y); //function sets the date to the values, if the given
                                   //value is invalid it aborts the function with return false

    bool SetFormat(char f); //sets the format of the listing (D, T, L) return true for success
                            //Default = M/D/Y
                            //Two Digit = mm/dd/yy
                            //Long = month D, Y

    //mutator functions
    void Increment(int numDays = 1); //move the date forward by the numDays

    //getter function
    int GetMonth() const;
    int GetDay() const;
    int GetYear() const;
    void Show() const;

    int Compare(const Date &d) const; //compare dates and return
                                      //-1 if calling object is first chronologically
                                      //0 if objects are the same date
                                      //1 if param object comes first chronologically

private:
    unsigned int day;   //must be within range of (1-31)
    unsigned int month; //must be within range of (1-12)
    unsigned int year;  //must be a valid 4 digit date >0

    char format;

    const static string monthName[12];
    const static int monthMaxDays[12];
};