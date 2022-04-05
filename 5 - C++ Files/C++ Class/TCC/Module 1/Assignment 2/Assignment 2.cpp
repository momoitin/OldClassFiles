#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function prototypes
void welcome();
void vacation(long int, int, int);
void contact();

int main(int argc, char** argv) {
	
	//vars
	long int ID;
	int plan, dependents;
	
	//call welcome
	welcome();
	
	//ID Grab
	cout << "Please enter the employee's ID ";
	cin >> ID;
	
	//Plan Grab
	cout << "what is the desired vacation plan? input 1, 2, or 3 for plan A, B, or C respectivly. ";
	cin >> plan;
	
	//if statements for plan rates
	
	
	//dependents Grab
	cout << "Please input the number of dependents. ";
	cin >> dependents;
	
	//call vacation
	vacation(ID, plan, dependents);
	
	//call contact info
	contact();
	
	return 0;
}

void welcome()
{
	cout << "Welcome! \n" << endl;
}

void vacation(long int ID, int plan, int dependents)
{
	//in function vars
	char cplan = 0;
	float cost = 0;
	const float PlanA = 7.50, PlanB = 9.75, PlanC = 14.25;
	
	//if statements declaring plan type
	if(plan == 1)
	{
		cost = PlanA;
		cplan = 'A';
	}
		
	if(plan == 2)
	{
		cost = PlanB;
		cplan = 'B';
	}
		
	if(plan == 3)
	{
		cost = PlanC;
		cplan = 'C';
	}
	
	//final output of plan status
	cout << "\n ID: " << ID << "\n Plan " << cplan << "\n Dependents: " << dependents << "\n Monthly Cost: $" << cost << endl;
	
}

void contact()
{
	cout << "\n For any problems regarding this program please call 850-694-6179";
}
