#include <iostream>

using namespace std;

void factorPrint(int[], int, int);

int main()
{
    int arr[100];
    int arrSize;
    int differenceValue;

    cout << "Enter the number of elements: ";
    cin >> arrSize;

    cout << "Enter the Values: ";
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number: ";
    cin >> differenceValue;

    factorPrint(arr, arrSize, differenceValue);

    return 0;
}

void factorPrint(int arr[], int arrSize, int differenceValue)
{
    cout << "The paris are:\n";
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            if (differenceValue%i==0 && differenceValue%j==0)
            {
                cout << arr[i] << "," << arr[j] << endl;
            }
        }
    }
}