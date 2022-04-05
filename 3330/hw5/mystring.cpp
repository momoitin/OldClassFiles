#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "mystring.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
//              Friend Functions
//////////////////////////////////////////////////////////////////////

ostream &operator<<(ostream &os, const MyString &s)
{
    os << s.str;
    return os;
}
istream &operator>>(istream &is, MyString &s)
{
    bool flag = false;
    MyString temp;
    temp.Resize(1);

    while (flag == false)
    {
        if (isspace(is.peek()))
            cin.ignore();
        else
        {
            for (int i = 0; !flag; i++)
            {
                temp.str[i] = is.get();
                if (isspace(is.peek()))
                {
                    flag = true;
                }
                else
                    temp.Resize(i + 2);
            }
        }
    }
    cin.ignore();
    s = temp;
    return is;
}
istream &getline(istream &is, MyString &s)
{
    getline(is, s, '\n');
    return is;
}
istream &getline(istream &is, MyString &s, char delim)
{
    bool flag = false;
    MyString temp;
    temp.Resize(1);

    while (flag == false)
    {
        if (isspace(is.peek()))
            cin.ignore();
        else
        {
            for (int i = 0; !flag; i++)
            {
                temp.str[i] = is.get();

                if (is.peek() == delim)
                {
                    flag = true;
                }
                else
                    temp.Resize(i + 2);
            }
        }
    }
    cin.ignore();
    s = temp;
    return is;
}

MyString operator+(const MyString &x, const MyString &y)
{
    //There is a double free somewhere here

    MyString temp;
    temp.Resize(x.getLength() + y.getLength());

    strcat(temp.str, x.str);
    strcat(temp.str, y.str);

    return temp;
}

bool operator<(const MyString &x, const MyString &y)
{
    bool flag = false;
    for (int i = 0; (i < x.size || i < y.size); i++)
    {
        if (x.str[i] < y.str[i])
        {
            flag = true;
        }
    }
    return flag;
}
bool operator>(const MyString &x, const MyString &y)
{
    return (y < x);
}
bool operator<=(const MyString &x, const MyString &y)
{
    return !(x > y);
}
bool operator>=(const MyString &x, const MyString &y)
{
    return !(x < y);
}
bool operator==(const MyString &x, const MyString &y)
{
    if ((x >= y) && (x <= y))
    {
        return true;
    }
    return false;
}
bool operator!=(const MyString &x, const MyString &y)
{
    return !(x == y);
}

//////////////////////////////////////////////////////////////////////
//              Member Functions
//////////////////////////////////////////////////////////////////////

MyString::MyString() // empty string
{
    size = 0;
    str = new char[size + 1]; // allocate to size 1
    str[0] = '\0';            // put null char in only array slot
}
MyString::MyString(const char *s) // conversion from c-string
{
    size = strlen(s);         // set size to length of c-string s
    str = new char[size + 1]; // allocate enough to store s
    strcpy(str, s);           // usable, ONLY if we are storing as c-string
}
MyString::MyString(int x) // conversion from int
{
    //make the new object
    size = 0;
    str = new char[size + 1];
    str[0] = '\0';
    //read in all the digits in reverse order to find the size
    int i;
    for (i = 0; x > 0; i++)
    {
        Resize(i + 1);
        int temp = x % 10;
        str[i] = temp + '0';

        x = x / 10;
    }
    //create a temporary cstring to hold the correct order
    char temp[size];

    int j = 0;
    for (int i = size - 1; i >= 0; i--)
    { //set the cstring in the correct order
        temp[j++] = str[i];
    }
    temp[i] = '\0';
    //overwrite the origional order;
    strcpy(str, temp);
}
MyString::~MyString() // destructor
{
    if (str != 0)
        delete[] str;
}
MyString::MyString(const MyString &s) // copy constructor
{
    size = 0;
    str = new char[size + 1];
    str[0] = '\0';
    Resize(s.getLength());
    strcpy(str, s.str);
}
MyString &MyString::operator=(const MyString &s) // assignment operator
{
    this->Resize(s.getLength());
    for (int i = 0; i < size; i++)
    {
        str[i] = s.str[i];
    }
    return *this;
}

MyString &MyString::operator+=(const MyString &s) // concatenation/assignment
{
    this->str = strcat(this->str, s.str);
    return *this;
}

// bracket operators to access char positions
char &MyString::operator[](unsigned int index)
{
    //checks to make sure the array is within range
    if (index > size + 1)
    {
        //holds the origional size
        int tempsize = size;
        //resizes the string
        Resize(index + 1);
        //cleans the blamk space in the string
        for (int i = tempsize; str[i] != '\0'; i++)
        {
            str[i] = ' ';
        }
    }
    //sends back position
    return str[index];
}
const char &MyString::operator[](unsigned int index) const
{
    return str[index];
}

// insert s into the string at position "index"
MyString &MyString::insert(unsigned int index, const MyString &s)
{
    //create a temporary cstring to hold the end of the sentence
    char *temp = new char[size - index + 1];

    int i;
    for (i = index; str[i] != '\0'; i++)
    {
        temp[i - index] = str[i];
    }
    temp[i] = '\0';

    //resize the string to the new, larger size;
    Resize(getLength() + s.getLength());

    //copy in the s.str string
    for (int i = index; i < size; i++)
    {
        str[i] = s.str[i - index];
    }

    //cat the end of the sentence on
    strcat(str, temp);
    //delete the temp value
    delete[] temp;
    //add null terminator
    str[size] = '\0';
    // Resize(size);

    return *this;
}

// find index of the first occurrence of s inside the string
//  return the index, or -1 if not found
int MyString::indexOf(const MyString &s) const
{
    char *location;
    location = strstr(str, s.str);

    if (location != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if (&str[i] == location)
            {
                return i;
            }
        }
    }

    return -1;
}

int MyString::getLength() const // return string length
{
    return strlen(str);
}
const char *MyString::getCString() const // return c-string equiv
{
    return str;
}

MyString MyString::substring(unsigned int x, unsigned int y) const
{
    //make new temp string
    MyString temp;
    //resize to the new size
    temp.Resize(y);
    //copy the correct data
    int i;
    for (i = 0; i < y; i++)
    {
        temp[i] = str[i + x];
    }
    //fill in null character
    temp[i] = '\0';

    return temp;
}
MyString MyString::substring(unsigned int x) const
{
    //pass data into substring(x, y) with y being the rest of the string
    return substring(x, size - x);
}

void MyString::Resize(int newsize)
// current data is in "str", current size is "size"
{
    char *temp = new char[newsize + 1]; //create new array of newsize + 1

    int i; //Deep copy the data into the new array size
    for (i = 0; i < size && i < newsize; i++)
        temp[i] = str[i];

    temp[newsize] = '\0'; // put null char at end

    delete[] str; //delete the old array from the pointer
    str = temp;
    size = newsize;
}