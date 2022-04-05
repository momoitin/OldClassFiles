#include <iostream>
#include "friends.h"

using namespace std;

Friend::Friend()
{
    setName("Bob", "Myers");
}

Friend::Friend(string f, string l)
{
    setName(f, l);
}

void Friend::show()
{
    cout << firstName << " " << lastName << endl;
}

void Friend::setName(string f, string l)
{
    firstName = f;
    lastName = l;
}

BestFriend::BestFriend()
{
    setName("test", "test");
    birthDay = 1;
    birthMonth = 1;
    birthYear = 2000;
}

BestFriend::BestFriend(string f, string l, int d, int m, int y)
{
    setName(f, l);
    birthDay = d;
    birthMonth = m;
    birthYear = y;
}

void BestFriend::show()
{
    Friend::show();
    BestFriend::showBirthday();
}

void BestFriend::showBirthday() const
{
    cout << birthMonth << "/" << birthDay << "/" << birthYear;
}
