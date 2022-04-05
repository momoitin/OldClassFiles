/* Name: (Evan Dunlap)
Date: (3/22/2021)
Section: (Your section)
Assignment: (Assignment#5)
Due Date: (3/23/2021)
About this project: (makes an array of inputs and does things to it)
Assumptions: (all values must be the correct data types.)

All work below was performed by (Evan Dunlap) */

#include <iostream>

using namespace std;

void insertAfter(double[], double &, double &, int &);
void removeFirst(double[], double &, int &);
void alternateShift(double[], int &);
void sort(double[], int &);

int CAPACITY = 100;

int main()
{

    int userChoice = 10;
    double userArray[CAPACITY];

    //gets the number of array elements
    cout << "Enter the number of elements (max 100): ";
    int arraySize;
    cin >> arraySize;
    //reads in the inputs into the array
    cout << "Enter " << arraySize << " elements: ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> userArray[i];
    }

    while (userChoice != 6)
    {
        //takes the users menu input
        cout << "Please select a choice:\n"
             << "1. Insert an element\n"
             << "2. Remove an element\n"
             << "3. Print array\n"
             << "4. Alternate shift\n"
             << "5. sort the array\n"
             << "6. Exit\n";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            //gets the new element
            cout << "Enter the number to be inserted: ";
            double newElement;
            cin >> newElement;
            //asks the user where to insert it
            cout << "Enter the number after which to insert: ";
            double afterElement;
            cin >> afterElement;

            insertAfter(userArray, newElement, afterElement, arraySize);

            break;
        case 2:
            //remove the first instance of removeElement in userArray

            cout << "Enter the element to remove the first instance of: ";
            double removeElement;
            cin >> removeElement;

            removeFirst(userArray, removeElement, arraySize);

            break;
        case 3:
            cout << "\nHere is what you entered: ";
            for (int i = 0; i < arraySize; i++)
            {
                cout << userArray[i] << " ";
            }
            cout << endl;
            break;
        case 4:
            //My alternate shift does it backwards bc I thought it ment odd indexes in terms of
            //what the user would see not the actual array index value being odd, and I dont
            //want to change it bc my eyes are bleeding
            alternateShift(userArray, arraySize);
            cout << "Elements shifted" << endl;
            break;
        case 5:
            //bubble sort for decending order sort
            sort(userArray, arraySize);
            cout << "Elements sorted" << endl;
            break;

        case 6:
            cout << "Goodbye!";
            return 0;
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    return 0;
}

void insertAfter(double userArray[], double &insert, double &after, int &arraySize)
{

    bool insertedFlag = false;

    for (int i = 0; i < arraySize; i++)
    { //checks if the element in i equals the user input
        if (userArray[i] == after)
        { //if so moves all elements after the specified element 1 to the right
            //increases the size of the array by 1 every time this loop fires and adds a new value
            arraySize += 1;
            for (int k = arraySize; k >= (i + 1); k--)
            {
                userArray[k] = userArray[k - 1];
            }
            //and inserts the new value in the blank position
            userArray[i + 1] = insert;
            i++; //skips over the value just entered, as to not repeat it forever.
            insertedFlag = true;
        }
    }

    if (insertedFlag == true)
    {
        cout << "Element Inserted\n"
             << endl;
    }
    else
    {
        cout << "Unable to insert\n"
             << endl;
    }
}

void removeFirst(double userArray[], double &removeElement, int &arraySize)
{
    bool removedFlag = false;
    //cycles through the array
    for (int i = 0; i < arraySize; i++)
    { //checks if the element in i = the entered value to remove.
        if (userArray[i] == removeElement)
        {
            userArray[i] = 0;
            for (int k = i; k < arraySize; k++)
            {
                userArray[k] = userArray[k + 1];
            }
            removedFlag = true;
            break;
        }
    }

    if (removedFlag == true)
    {
        arraySize -= 1;
        cout << "Element removed\n"
             << endl;
    }
    else
    {
        cout << "Unable to remove\n"
             << endl;
    }
}

void alternateShift(double userArray[], int &arraySize)
{
    if (arraySize >= 3)
    {
        //holds the last odd index of the array if the arraySize is even,
        //otherwise holds the last index in the array
        int oddEnd = arraySize % 2 == 0 ? arraySize - 2 : arraySize - 1;
        double holdOdd = userArray[oddEnd];

        for (int i = oddEnd; i > 0; i -= 2)
        {
            userArray[i] = userArray[i - 2];
        }
        userArray[0] = holdOdd;

        if (arraySize >= 6)
        {
            //holds the first and second even indexes in the array
            double holdFirstEven = userArray[1];
            double holdSecondEven = userArray[3];

            cout << "FIRSTEVEN:  " << holdFirstEven << endl;
            cout << "SECONDEVEN: " << holdSecondEven << endl;

            for (int i = 1; i < arraySize; i += 2)
            { //cycles through each even index and sifts it left by two even index
                userArray[i] = userArray[i + 4];
            }

            //sets the last 2 even indexes to the origional first and second index
            if (arraySize % 2 == 0)
            { //if the array is even, second to last even index is (arraySize-3)
                //and last even index is (arraySize -1)
                userArray[arraySize - 3] = holdFirstEven;
                userArray[arraySize - 1] = holdSecondEven;
            }
            else
            { //if the array is odd, second to last even index is (arraySize - 4)
                //and last even index is (arraySize -2)
                userArray[arraySize - 4] = holdFirstEven;
                userArray[arraySize - 2] = holdSecondEven;
            }
        }
    }
}

void sort(double userArray[], int &arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int k = arraySize - 1; k > 0; k--)
        {
            if (userArray[k] > userArray[k - 1])
            {
                double hold = userArray[k];
                userArray[k] = userArray[k - 1];
                userArray[k - 1] = hold;
            }
        }
    }
}