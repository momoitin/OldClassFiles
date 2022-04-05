#include <iostream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void welcome();
void goodbye();

//Evan Dunlap
//COP2221
//This program was made to calculate various aspects of an array


int main(int argc, char** argv) {
	
	welcome();
	
	//declares array size
	const int SIZE = 10;
	
	//CAT ARRAY
	double weight[SIZE] = {13, 9.5, 8, 14, 21, 12, 16, 15.2, 11.8, 20};
	
	//additive var initilazation
	double sum = 0,
		   average = 0,
		   max = weight[0],
		   min = weight[0];

	//sum calculator
	for (int i = 0; i < SIZE; i++)
	{
		sum += weight[i];
	}
	
	//average calculatiron
	average = sum / SIZE;
	
	//Find the max value
	for (int i = 0; i < SIZE; i++)
	{
		if (weight[i] > max)
			max = weight[i];
	}
	
	//find the min value
	for (int i = 0; i < SIZE; i++)
	{
		if (weight[i] < min)
			min = weight[i];
	}

	cout << setprecision(1) << fixed	
		 << "Total:   " << sum << endl
		 << "Average: " << average << endl
		 << "Highest: " << max << endl
		 << "Lowest:  " << min << endl;
	
	goodbye();
	
	return 0;
}

void welcome()
{
	cout << "\tWelcome to the Cat Calculator!\n\n";
}

void goodbye()
{
	cout << "\n\tThank you for using the Cat Calculator!\n\n";
}
