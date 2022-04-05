#include <iostream>
#include <string>		//gives access to string class
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct bankAccount
{
	string Balance;
	string Deposits;
	string Interest;
};

int main(int argc, char** argv) {
	
	//I created instances of the string when I made a new object called dunlap
	
	bankAccount dunlap;							//creates string objects under the name dunlap
	
	dunlap.Balance = "3.26";
	dunlap.Balance.c_str();						//changes dunlap.Balance to a c-string
	cout << dunlap.Balance << endl;
	
	dunlap.Deposits = "1.12";
	dunlap.Deposits.clear();					//removes the value from the given string
	dunlap.Deposits = "5.23";
	cout << dunlap.Deposits << endl;

	cout << dunlap.Interest.empty() << endl;	//returns true if nothing is stored in the string
	
	cout << dunlap.Balance.capacity();			//returns the size of the string
	
	
	/*
		The code is reuseable by giving an object that can be created as many
		times as it needs to be.
		
		encapsulation is used to hide data. making it only accessible through
		other objects inside the class. 
	*/
	
	return 0;
}
