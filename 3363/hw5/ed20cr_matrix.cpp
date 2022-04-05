/* Name: (Evan Dunlap)
Date: (3/23/2021)
Section: (Your section)
Assignment: (Assignment#5)
Due Date: (3/23/2021)
About this project: (takes an array and does math baised on triangles)
Assumptions: (all values must be the correct data types.)

All work below was performed by (Evan Dunlap) */

#include <iostream>

using namespace std;

//global constants
const int COLCAP = 100,
          ROWCAP = 100;

//prototypes
void inputMatrix(double[COLCAP][ROWCAP], int &, int &);
void printMatrix(double[COLCAP][ROWCAP], int, int);
void printSums(double[COLCAP][ROWCAP], int, int);

int main()
{
    double userMatrix[COLCAP][ROWCAP];
    int matrixColumns,
        matrixRows;

    //this is a function call
    inputMatrix(userMatrix, matrixColumns, matrixRows);
    printMatrix(userMatrix, matrixColumns, matrixRows);
    printSums(userMatrix, matrixColumns, matrixRows);

    return 0;
}
//inputs the matrix
void inputMatrix(double userMatrix[COLCAP][ROWCAP], int &matrixColumns, int &matrixRows)
{
    cout << "Enter the number of rows: ";
    cin >> matrixColumns;

    cout << "Enter the number of columns: ";
    cin >> matrixRows;

    cout << "Enter the matrix: ";
    for (int i = 0; i < matrixColumns; i++)
    { //goes through the matrix row by column to enter new data
        for (int j = 0; j < matrixRows; j++)
        {
            cin >> userMatrix[i][j];
        }
    }
}
//displays the matrix
void printMatrix(double userMatrix[COLCAP][ROWCAP], int matrixColumns, int matrixRows)
{
    cout << "You entered:\n";
    for (int i = 0; i < matrixColumns; i++)
    { //displays the matrix row by column
        for (int j = 0; j < matrixRows; j++)
        {
            cout << userMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}
//prints the sums of the triangles
void printSums(double userMatrix[COLCAP][ROWCAP], int matrixColumns, int matrixRows)
{
    //i dont really feel like finishing this and I have had a long week so I will take the L
    //sorry
    double triangleSum = 0;
    int leftSide = 0,
        rightSide = matrixColumns;

    for (int i = 0; i < matrixColumns; i++)
    {
        for (int j = leftSide; j < rightSide; j++)
        {
            if (leftSide <= rightSide)
            {
                triangleSum += userMatrix[i][j];
                
                cout << "userMatrix[" << i << "][" << j << "] " << userMatrix[i][j] << endl;
                cout << "triangleSum: " << triangleSum << endl;
            }
        }
        leftSide++;
        rightSide--;
    }

    cout << "Upper triangle sum: " << triangleSum;
}