#include <iostream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//vars to innitialize
	const int NUM_EMPLOYEES = 5;
	double packbonus, grossbonus, finalbonus;
	
	
	//
	string ID[NUM_EMPLOYEES] = {"H256", "B410", "K589", "M560", "S935"};
	int PACKAGES[NUM_EMPLOYEES] = {1567, 2050, 3560, 1100, 578};
	double GROSS[NUM_EMPLOYEES] = {14389.75, 18506.03, 35600.10, 9563.20, 6234.25};
	
	//Start of format
	cout << "Employee ID:\t" << "Packages Sold:\t"<<  "Gross Profits:\t" << "Sales Bonus:\n";
	
	
	for (int i = 0; i < NUM_EMPLOYEES; i++)
	{
		//calculate pack bonus
		if(PACKAGES[i] > 700)
			packbonus = 400 + (5 * PACKAGES[i]);
			else packbonus = 0;
		//calculate gross bonus
		if(GROSS[i] > 10000.00)
			grossbonus = GROSS[i] * 0.1;
			else grossbonus = 0;
			
		//calculate final bonus
		finalbonus = grossbonus + packbonus;
		
		//Final Output
		cout << setprecision(2) << fixed
		     << ID[i] << "\t\t"
			 << PACKAGES[i] << "\t\t"
			 << "$" << GROSS[i] << "\t"
			 << finalbonus << endl;
	}
	
	return 0;
}
