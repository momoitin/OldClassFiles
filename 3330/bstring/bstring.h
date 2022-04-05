#include <iostream>
using namespace std;

class BString
{
    friend BString operator+(const BString &x, const BString &y);

    friend bool operator<(const BString &x, const BString &y);
    friend bool operator>(const BString &x, const BString &y);
    friend bool operator<=(const BString &x, const BString &y);
    friend bool operator>=(const BString &x, const BString &y);
    friend bool operator==(const BString &x, const BString &y);
    friend bool operator!=(const BString &x, const BString &y);

    friend ostream &operator<<(ostream &os, const BString &s);
    friend istream &operator>>(istream &is, BString &s);
    friend istream &getline(istream &is, BString &s);
    friend istream &getline(istream &is, BString &s, char delim);

public:
    BString();              // default constructor -- sets to empty string
    BString(const char *s); // conversion constructor (from c-string)
    BString(int x);         // conversion from type int (to a BString)
    ~BString();             // destructor for final cleanup

    // these are for deep copy
    BString(const BString &s);            // copy constructor
    BString &operator=(const BString &s); // assignment operator

    BString &operator+=(const BString &s); // concatenation+assignment

    char &operator[](unsigned int index);
    const char &operator[](unsigned int index) const;

    int GetSize() const; // return the size

    BString Substring(int start, int length);

private:
    char *str;         // pointer to a dynamic array of characters
    unsigned int size; // size (or length) of our string
                       // allocation of array will always be size+1
                       //  so that we can store interally AS a c-string

    void Resize(int newsize);
};