#include <iostream>
#include <iomanip>
using namespace std;

// Global constants
const int totalColumns = 5; // Number of columns in each array
const int totalRows = 4; 	// Number of rows in table1

//Function Protorypes
 int getTotal(const int [][totalColumns], double);
 int getAverage(const int [][totalColumns], double);
 int getRowTotal(const int [][totalColumns], double, int);
 int getColumnTotal(const int [][totalColumns], double, int);
 

 int main()
 {
	double total = 0,				//Vars
		average = 0,
		rowTotal = 0,
		columnTotal = 0,
		highestInRow = 0,
		lowestInRow = 0; 
		
	int userRow = 0,		//User input
		userColumn = 0;	

	//Array Initilazation
 	int arr[totalRows][totalColumns] = {{4, 24, 62, 91, 101}, 
 							 			{77, 0, 45, 33, 6}, 
										{56, 7, 1, 27, 211}, 
										{1, 4, 0, 22, 50}};
   
	total =	getTotal(arr, total);			//Calls getTotal
	cout << "The total of the array is: " << total << endl; //Displays total after grab
	
	average = getAverage(arr, average);				//Calls getAverage
	cout << "The average of the array is: " << average << endl; //Displays average after grab
		
	while(userRow >= 5 || userRow <=0)
	{
		cout << "\nWhat row would you like to check? ";   //Asks user which row to get total of
		cin >> userRow;
		
		while(userRow >=5 || userRow <= 0)				 //Confirms user input as valid 1-4
		{
			cout << "\nPlease enter a valid row: ";		 
			cin >> userRow;
		}
	}
	userRow -= 1; 									//+1 for Array format Fix
	rowTotal = getRowTotal(arr, rowTotal, userRow);
	cout << "The total of row " << userRow + 1 << " is: " << rowTotal << endl;
	
	while(userColumn >= 6 || userColumn <=0)
	{
		cout << "\nWhat column would you like to check? ";   //Asks user which column to get total of
		cin >> userColumn;
		
		while(userColumn >=6 || userColumn <= 0)				 //Confirms user input as valid 1-5
		{
			cout << "\nPlease enter a valid Column: ";		 
			cin >> userColumn;
		}
	}
	userColumn -= 1;
	columnTotal = getColumnTotal(arr, columnTotal, userColumn);	
	cout << "The total of column " << userColumn + 1 << " is: " << columnTotal << endl;
	
	
	return 0;
	}
	
int getTotal(const int arr[][totalColumns], double total)
{
	for (int x = 0; x < totalRows; x++)
	{
		for (int y = 0; y < totalColumns; y++)
 		{
 			cout << setw(4) << arr[x][y] << " "; //temp code to display entire array format
			total += arr[x][y];					 //gets total
		}
		cout << endl;
	}	
	return total;
}

int getAverage(const int arr[][totalColumns], double average)
{
	for (int x = 0; x < totalRows; x++)
	{
		for (int y = 0; y < totalColumns; y++)
 		{
			average += arr[x][y];					 //gets average
		}
	}
	average = average / (totalColumns * totalRows);
	return average;
}

int getRowTotal(const int arr[][totalColumns], double rowTotal, int userRow)
{
	for (int y = 0; y < totalColumns; y++)
	{
		rowTotal += arr[userRow][y];				 //gets rowTotal
	}

	return rowTotal;
}

int getColumnTotal(const int arr[][totalColumns], double columnTotal, int userColumn)
{
	for (int x = 0; x < totalColumns; x++)
	{
		columnTotal += arr[x][userColumn];			 //gets columnTotal
	}

	return columnTotal;	
}
