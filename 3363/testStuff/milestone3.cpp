#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int ROWS, COLS = 20;
double findNorm(double mat[][20]);

int main()
{
    double mat[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << findNorm(mat);

    return 0;
}

double findNorm(double arr[][])
{
    double sum = 0;
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            sum + = pow
        }
        
    }
    
}