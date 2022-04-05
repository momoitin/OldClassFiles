
#include <cstring>
#include "bstring.h"

/*
   char * str;		// pointer to a dynamic array of characters
   unsigned int size;	// size (or length) of our string
			// allocation of array will always be size+1
			//  so that we can store interally AS a c-string
*/

// friend function definitions here

BString operator+(const BString &x, const BString &y)
// concatenation of x and y, return result
{
}

bool operator<(const BString &x, const BString &y)
{
}

bool operator>(const BString &x, const BString &y)
{
}

bool operator<=(const BString &x, const BString &y)
{
}

bool operator>=(const BString &x, const BString &y)
{
}

bool operator==(const BString &x, const BString &y)
{
}

bool operator!=(const BString &x, const BString &y)
{
}

ostream &operator<<(ostream &os, const BString &s)
{
    /*
   for (int i = 0; i < s.size; i++)
      os << s.str[i];			// print out each letter
*/
    os << s.str; // direct output of c-string

    return os;
}

istream &operator>>(istream &is, BString &s)
{
}

istream &getline(istream &is, BString &s)
{
}

istream &getline(istream &is, BString &s, char delim)
{
}

// member functions here

BString::BString()
// default constructor -- sets to empty string
{
    size = 0;
    str = new char[size + 1]; // allocate to size 1
    str[0] = '\0';            // put null char in only array slot
}

BString::BString(const char *s)
// building a string object out of the incoming c-string s
{
    size = strlen(s);         // set size to length of c-string s
    str = new char[size + 1]; // allocate enough to store s
    strcpy(str, s);           // usable, ONLY if we are storing as c-string
}

BString::BString(int x)
{
}

BString::~BString()
{
    delete[] str;
}

BString::BString(const BString &s)
// copy constructor (for deep copy)
{
}

BString &BString::operator=(const BString &s)
// assignment operator (for deep copy)
{
}

BString &BString::operator+=(const BString &s)
{
}

char &BString::operator[](unsigned int index)
{
}

const char &BString::operator[](unsigned int index) const
{
}

int BString::GetSize() const
{
    return size;
}

BString BString::Substring(int start, int length)
{
}

void BString::Resize(int newsize)
// current data is in "str", current size is "size"
{
    char *temp = new char[newsize + 1];

    int i;
    for (i = 0; i < size && i < newsize; i++)
        temp[i] = str[i];

    temp[i] = '\0'; // put null char at end

    delete[] str;
    str = temp;
}