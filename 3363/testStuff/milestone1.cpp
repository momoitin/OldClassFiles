#include <iostream>

using namespace std;

int main()
{
    cout <<"Are you entering data for a rectangle or a circle?\n";
    cout <<"Enter C for circle or R for rectangle: ";


    char input;
    cin >> input;

    double totalCircle;
    double totalRectangle;

    while(input == 'C' || input == 'R')
    {
        
        switch (input)
        {
        case 'C':
            double radius;
            cout << "what is the radius? ";
            cin >> radius;

            cout << "the area is: " << 3.14 * radius * radius << endl;
            totalCircle += (3.14 * radius * radius);

            break;
        
        case 'R':
            double length, width;
            cout << "what is the length? ";
            cin >> length;
            cout << "what is the width? ";
            cin >> width;

            cout << "the area is: " << length * width << endl;
            totalRectangle += (length * width);

            break;

        default:
            break;
        }
        cout << "enter next shape: ";
        cin >> input;
    }

    cout << "Total Circle Area: " << totalCircle << endl;
    cout << "Total Rectangle Area: " << totalRectangle << endl;
    

    return 0;
}