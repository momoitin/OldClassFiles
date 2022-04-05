#include <iostream>
#include "friends.h"

using namespace std;

int main()
{
    Friend *fl[2];

    char choice;

    for (int i = 0; i < 2; i++)
    {
        cout << "enter your choice of friend ";
        cin >> choice;

        if (choice == 'f')
        {
            fl[i] = new Friend("Lewis", "Brindley");
        }
        else if (choice = 'b')
        {
            fl[i] = new BestFriend("Drew", "Spaulding", 1, 1, 1996);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        fl[i]->show();
    }
    
}