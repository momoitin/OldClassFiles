#include <iostream>
#include <cmath>
#include "diamond.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//                      Diamond Class
////////////////////////////////////////////////////////////////////////////////////

/* Private Data
int length;
char border;
char fill;
*/

//Constructor
Diamond::Diamond(int l, char b, char f) //constructor for Diamond(Length, Border, Fill)
{
    if (l < 1)
    {
        l = 1;
    }
    if (l > 39)
    {
        l = 39;
    }
    length = l;
    border = b;
    fill = f;
}

//Getters
int Diamond::GetSize() const //returns the size of a side
{
    return length;
}
double Diamond::Perimeter() const //returns the perimeter of the diamond
{
    return length * 4;
}
double Diamond::Area() const //returns the area of the diamond
{
    return (pow(length, 2) * sqrt(3)) / 2;
}

//Setters
void Diamond::SetBorder(char b)
{
    if (b < 33 || b > 126)
    {
        return;
    }
    border = b;
}
void Diamond::SetFill(char f)
{
    if (f < 33 || f > 126)
    {
        return;
    }
    fill = f;
}

//mutators
void Diamond::Grow() //increases the size of the diamond by 1 (range 1-39)
{
    if (length == 39)
    {
        return;
    }
    length++;
}
void Diamond::Shrink() //decreases the size of the diamond by 1 (range 1-39)
{
    if (length == 1)
    {
        return;
    }
    length--;
}

//display
void Diamond::Draw() const //displays a picture of the diamond
{
    cout << "Diamond looks like:" << endl;

    // makes top half of triangle
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= (length - i); j++)
        {
            //makes the border spaces
            cout << " ";
        }

        for (int k = 1; k <= i * 2 - 1; k++)
        {
            if (k == 1 || k == i * 2 - 1)
            { //multiplys to find other side of the border
                cout << border;
            }
            else
            { //if its not the border, fills every other with the fill
                if (k % 2 == 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << fill;
                }
            }
        }
        cout << endl;
    }
    //makes bottom half of triangle
    for (int i = length - 1; i >= 1; i--)
    {
        for (int j = (length - i); j >= 1; j--)
        {
            //makes the border spaces
            cout << " ";
        }
        for (int k = i * 2 - 1; k >= 1; k--)
        { //multiplys to find other side of the border
            if (k == 1 || k == i * 2 - 1)
            {
                cout << border;
            }
            else
            { //if its not the border, fills every other with the fill
                if (k % 2 == 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << fill;
                }
            }
        }

        cout << endl;
    }
}
void Diamond::Summary() const //displays size, perimeter, area, and picture of the diamond
{
    cout << "Size of diamond's side = " << Diamond::GetSize() << " units.\n";
    cout << "Perimeter of diamond = " << Diamond::Perimeter() << " units.\n";
    cout << "Area of diamond = " << Diamond::Area() << " units.\n";
    Diamond::Draw();
}
