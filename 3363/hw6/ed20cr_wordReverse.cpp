/* Name: (Evan Dunlap)
Date: (4/8/2021)
Section: (Your section)
Assignment: (Assignment#6)
Due Date: (4/8/2021)
About this project: (reverese a cstring array)
Assumptions: (all values must be the correct data types. no double spaces but that dont matter)

All work below was performed by (Evan Dunlap) */

#include <iostream>
#include <cstring>

using namespace std;

const int maxRows = 25;
const int maxColumns = 200;

void printText(char st[maxRows][maxColumns], int rows, int num);

int main()
{

    char matrix[maxRows][maxColumns];

    int itr = 0;
    cout << "Enter the text:\n";
    while (cin.getline(matrix[itr], maxColumns) && strlen(matrix[itr]) != 0)
    {
        //takes in the most recent line, checks if it the length of the last row is 0.
        //if the last line was not blank, sets the last entry in the cstring to newline
        //increase the itteration untill there are 2 enters in a row
        matrix[itr][strlen(matrix[itr])] = '\n';
        itr++;
    }

    printText(matrix, maxRows, itr);

    return 0;
}

void printText(char matrix[][maxColumns], int maxRows, int itr)
{
    for (int i = 0; i < itr; i++)
    {
        int pos = 0;
        int startIndex = 0;
        int endIndex = 0;

        do
        {
            if (matrix[i][pos] == ' ' || matrix[i][pos] == '\n' || matrix[i][pos] == '-')
            {
                endIndex = pos - 1;

                while (startIndex < endIndex)
                {
                    //swap inside here
                    char temp1 = matrix[i][startIndex],
                         temp2 = matrix[i][endIndex];

                    matrix[i][startIndex] = temp2;
                    matrix[i][endIndex] = temp1;

                    startIndex++;
                    endIndex--;
                }
                startIndex = pos + 1;
            }
            pos++;
        } while (matrix[i][pos] != '\n');
        cout << endl;
    }

    cout << "The reversed worded text is:\n";
    for (int i = 0; i < itr; i++)
    {
        cout << matrix[i];
    }
}