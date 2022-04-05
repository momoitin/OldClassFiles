#include <iostream>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function Prototypes
void welcome();
void goodbye();
void creditReadout(int[], double[], double[]);
void exceededLimit(int[], double[], double[], double);
void sortArrays(int[], double[], double[]);
void outstanding(int[], double[], double[], double);

//Global Integers
const int customers = 8;
const float creditFee = 0.10;             //%

int main(int argc, char** argv) {
	
	//Parrellel Arrays
	int   cccNumber[customers]    = {135798, 193827, 857403, 375915, 586721, 349672, 456837, 884903};
	double creditLimit[customers] = {10000, 2000, 3500, 25000, 500, 12000, 5000, 22000},
		   currBalance[customers] = {7600.50, 3500.76, 220.75, 17.99, 0.00, 10254.76, 5089.93, 18940.94};
	
	double overdrawnBy = 0,		   			  //$
		   interestOwed = 0;				  //$
		   
	welcome();
////////////////////////////////////////////////////////////////////////////////////////////	

	//Credit Readout function is called displaying all credit information
	creditReadout(cccNumber, creditLimit, currBalance);
	
	
///////////////////////////////////////////////////////////////////////////////////////////////

	//function called to check customers that have exceeded their credit limit
	exceededLimit(cccNumber, creditLimit, currBalance, overdrawnBy);
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////
	
	//function called to sort the arrays
	sortArrays(cccNumber, creditLimit, currBalance);
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////	
	
	//calculates the intrest owed on the credit balance of each customer
	outstanding(cccNumber, creditLimit, currBalance, interestOwed);
	
	
/////////////////////////////////////////////////////////////////////////////////////////////////
	goodbye();	
	return 0;
}

void welcome()
{
	cout << "\n\n\t\tWELCOME TO THE CREDITCARD CALCULATION PROCESS\n\n";
}

void creditReadout(int cccNumber[], double creditLimit[], double currBalance[])
{
	//Full Credit Card information readout with formatting
	cout << "Card Number:" << setw(20)
		 << "Card Limit: "  << setw(20)
		 << "Current Balance:\n";
	//Readoutput
	for(int i = 0; i < customers; i++)
	{
		cout << setprecision(2)<< fixed
			 << cccNumber[i]   << setw(24)
			 << creditLimit[i] << setw(20)
			 << currBalance[i] << "\n";	
	}	
}

void exceededLimit(int cccNumber[], double creditLimit[], double currBalance[], double overdrawnBy)
{
	
	cout << "\n\nCustomers who have exceeded their credit limit:\n\n";
	cout << "Card Number:    " << setw(20)
		 << "Card Limit:     " << setw(20)
		 << "Current Balance:" << setw(20)
		 << "Overdrawn By:   " << endl;
	for(int i = 0; i < customers; i++)
	{
		if(currBalance[i] > creditLimit[i])
		{	
			overdrawnBy = currBalance[i] - creditLimit[i];
			//readoutput
			cout << setprecision(2)<< fixed 
				 << cccNumber[i]   << setw(24)
				 << creditLimit[i] << setw(25)
				 << currBalance[i] << setw(17)
				 << overdrawnBy    << "\n";			
		}
	}	
}

void sortArrays(int cccNumber[], double creditLimit[], double currBalance[])
{
	//Variables to sort with
	int startScan;
	int minIndex;
	int minValue;
	int temp;
	//starts scanning arrays to change variables	
	for (startScan = 0; startScan < (customers - 1); startScan++)    //Moves through the elements
	{
	    minIndex = startScan;
	    minValue = creditLimit[startScan];
	    temp = currBalance[startScan];
		
	    int index = 0;

	    for (index = startScan + 1; index < customers; index++)  //Compares the elements
	    {
	        if (creditLimit[index] > minValue)
	        {
	            minValue = creditLimit[index];
	            minIndex = index;
	            temp = currBalance[index];
	        }
	    }
	//Swaps Variables to Indexed variables to mirror parrellel arrays
		swap(currBalance[minIndex], currBalance[startScan]);
		swap(creditLimit[minIndex], creditLimit[startScan]);
		swap(cccNumber[minIndex]  , cccNumber[startScan]);
	}	
}

void outstanding(int cccNumber[], double creditLimit[], double currBalance[], double interestOwed)
{
	//readout of customers in order with formatting	and calculation of credit fee
	cout << "\n\nCustomer in order of credit card balance:\n\n";
	cout << "Card Number:" << setw(20)
		 << "Card Limit: "  << setw(20)
		 << "Current Balance:" << setw(20)
		 << "Interest Owed:\n";


	for(int i = 0; i < customers; i++)
	{
		int	temp = 0;
		interestOwed = currBalance[i] * creditFee;
		//readoutput
		cout << setprecision(2)<< fixed
			 << cccNumber[i]   << setw(24)
			 << creditLimit[i] << setw(20)
			 << currBalance[i] << setw(20)
			 << interestOwed << endl;
	}
}

void goodbye()
{
	cout << "\n\n\t\tTHANK YOU FOR USING THE PROGRAM DESIGNED BY BLANK\n"
		 << "\t\tIF YOU HAVE ANY ISSUES WITH THE PROGRAM PLEASE CONTACT\n"
		 << "\t\t(555)-555-5555";
}
