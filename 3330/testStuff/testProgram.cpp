#include <iostream>
#include "classes.h"

using namespace std;

int main()
{
    // Circle c1; //declares object c1 with default constructor

    // Circle c2(15); //declares object c2 with the one param constructor instead

    // c1.SetRadius(20);
    // c1.SetCenter(10, 15);

    // double area = c1.GetArea();

    // c1.Draw();

    // Fraction f1(1, 4);
    // f1.Show();

    Character testCharacter("Lewis Brindley");
    testCharacter.getName();
    testCharacter.setAllStats(8, 12, 13, 16, 10, 9);
    testCharacter.setRace("Human");

    testCharacter.getCharacterSheet();

    Character flist[100];
    Character *gList;

    *gList = flist[0];

    // for (int i = 0; i < 100; i++)
    // {
    //     flist[i].getName();
    // }

    (*gList[1]).getName();
    return 0;
}
