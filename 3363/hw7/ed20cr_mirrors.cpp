/* Name: (Evan Dunlap)
Date: (4/11/2021)
Section: (Your section)
Assignment: (Assignment#7)
Due Date: (4/15/2021)
About this project: (dynamic array creation, reading and backtracking a path through the array)
Assumptions: (all values must be valid, * char mut be on top or left "wall" else function breaks.)

All work below was performed by (Evan Dunlap :) */
#include <iostream>

using namespace std;

void process(int, int);

int main()
{
    cout << "Enter the number of rows: ";
    int rows;
    cin >> rows;

    cout << "Enter the number of columns: ";
    int columns;
    cin >> columns;

    process(rows, columns);

    return 0;
}

void process(int rows, int columns)
{
    //allocates new space for the array called room, defined by the size
    char *room = new char[rows * columns];

    cout << "Enter the map:\n";

    //reads in each line
    for (int i = -1; i < rows; i++)
    {
        string line;
        //takes each line
        getline(cin, line);

        for (int k = 0; k < columns; k++)
        {
            room[(i * columns) + k] = line[k];
        }
    }

    //displays the room for human testing
    // cout << "\n\nRoom is:\n"; //used when displaying the room
    int rowPOS, columnPOS;
    char posCHAR, direction;
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < columns; k++)
        {
            // cout << room[(i * columns) + k]; //displays the room
            if (room[(i * columns) + k] == '*')
            { //seaches the array for the exhause port and marks the point, saves the location
                // cout << "exhaust at point [" << i << "][" << k << "]"; //human debugging lol
                columnPOS = i;
                rowPOS = k;
                posCHAR = room[(columnPOS * columns) + rowPOS];
            }
        }
        // cout << endl; //used when displaying the room
    }

    //finds the starting direction baised on set input criteria.
    if (rowPOS > columnPOS)
    {
        direction = 'D';
    }
    else
    {
        direction = 'R';
    }

    do
    {
        //used for debugging and finding current direction as a readout
        // cout << "moving in the direction: " << direction << endl;
        // cout << "Pos Char: " << posCHAR << endl;

        //if the direction hits forward mirror
        if (posCHAR == '/' && direction == 'R')
        {
            direction = 'U';
            columnPOS--;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (posCHAR == '/' && direction == 'D')
        {
            direction = 'L';
            rowPOS--;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (posCHAR == '/' && direction == 'L')
        {
            direction = 'D';
            columnPOS++;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (posCHAR == '/' && direction == 'U')
        {
            direction = 'R';
            rowPOS++;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        //end if the direction hits forward mirror
        
        //if the direction hits backwards mirror
        if (posCHAR == 92 && direction == 'R')
        {
            direction = 'D';
            columnPOS++;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (posCHAR == 92 && direction == 'D')
        {
            direction = 'R';
            rowPOS++;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (posCHAR == 92 && direction == 'L')
        {
            direction = 'U';
            columnPOS--;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (posCHAR == 92 && direction == 'U')
        {
            direction = 'L';
            rowPOS--;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        //end if the direction hits backwards mirror

        //if the direction does not hit a mirror
        if (direction == 'R')
        {
            rowPOS++;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (direction == 'D')
        {
            columnPOS++;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (direction == 'L')
        {
            rowPOS--;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        if (direction == 'U')
        {
            columnPOS--;
            posCHAR = room[(columnPOS * columns) + rowPOS];
        }
        //end if direction does not hit a mirror

        //finish the loop
    } while (posCHAR != 'x');

    cout << "The entry point is: [" << columnPOS << "][" << rowPOS << "]";
}