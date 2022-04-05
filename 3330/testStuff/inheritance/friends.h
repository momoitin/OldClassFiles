#include <iostream>

using namespace std;

class Friend
{
public:
    Friend();
    Friend(string f, string l);

    //getter
    virtual void show();

    //setter functions;
    void setName(string f, string l);

private:
protected:
    string firstName, lastName;
};


class BestFriend : public Friend
{
public:
    BestFriend();
    BestFriend(string f, string l, int d, int m, int y);

    //getter functions
    void show();
    void showBirthday() const;

private:
    int birthDay, birthMonth, birthYear;

protected:
};
