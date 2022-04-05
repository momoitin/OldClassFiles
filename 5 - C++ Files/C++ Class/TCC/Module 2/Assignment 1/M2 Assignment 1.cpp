#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function prototypes
void welcome();
int userinput(int, int);
void usercheck(int);
void goodbye();

int main(int argc, char** argv) {
	/*
		Evan Dunlap
		
		This program is to take user input, determine if it is positive or negative,
		and calculate how many inputs were positive then feedback a result.
		
		Jan 17, 2018
	*/
	
	//Vars init
	int count = 0, input = 0;
	
	//call welcome
	welcome();
	
	//call userinput
	count = userinput(input, count);
	
	//call usercheck
	usercheck(count);
	
	//call goodbye
	goodbye();
	
	return 0;
}

void welcome()
{
	cout << "Welcome! \n" << endl;
	cout << " This program will ask you to input multiple positive numbers. \n When you are finished you will input '0' \n" << endl;
}

int userinput(int input = 0, int count = 0)
{
	//Input function for numbers
	do{
		//input ask and grab
		cout << "Please enter a positive number... ";
		cin >> input;
		
		//check for positive or negative
		if(input > 0){
			cout << "input is positive \n";
			//accumiulator var accumilates
			++count;}
			
		if(input < 0){
			cout << "input is not positive \n";}

	}while(input != 0);
	
	return count;
}

void usercheck(int count)
{
	//Feedback how many integers were positive
	if(count <= 10){
		cout << "10 or fewer positive numbers were entered \n";
	}
		
	if(count > 10){
		cout << "More than 10 positive numbers were entered \n";
	}
	
}

void goodbye()
{
	cout << "\n Thank you for using my program\n If you have any problems please call 1-800-694-6179 for assistance.";
}
