#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void welcome();
int getWeight(string[], int[], int);
void catReport(string[], int[], int);
void goodbye();

int main(int argc, char** argv) {
	//Call welcome function
	welcome();
	
	//const int for amount of cats
	const int CATS = 5;
	
	//Array with the cats name and information
	string name[CATS] = {"Momo", "Sugar", "Eyepatch", "Mittens", "Snowball"};
	int food[CATS] = {};
	
	//Call sends to fatCat Function		Returns food array with weight
	food[CATS] = getWeight(name, food, CATS);
		
	//send values to the cat report
	catReport(name, food, CATS);
	
	//calls goodbye
	goodbye();
	
	return 0;
}

void welcome()
{
	cout << "\n\tWelcome to the program about KITTENS!\n\n";
}

//Gets the weight and stores it in food array
int getWeight(string name[], int food[], const int CATS)
{
	for(int i = 0; i < CATS; i++)
	{
			
		cout << "How much food does "
			 << name[i]
			 << " eat in pounts? ";
		
		cin >> food[i];
		//remove a sign if there is one
		food[i] = abs(food[i]);
	}
	
	return food[CATS];
}

//final report of the cats
void catReport(string name[], int food[], const int CATS)
{
	//running total
	int foodTotal = 0, 
		maxPounds = food[0],
		minPounds = food[0];
		
	const double price = 4.95;
	double totalCost = 0;
				 
	string title = "CAT REPORT", 
		   maxName = name[0],
		   minName = name[0];
	
	
	
	//Not my code I just thought it looked cool
    cout << "\n\n" << setfill (' ') << setw (29) << " " << setfill ('-')
         << setw(23) << "-"
		 <<"\n\n"<< setfill (' ') << setw(51) << "\n\n" 
         << setw((80+title.length())/2)
         << title << "\n\n"<< setw(42) << setiosflags (ios::fixed)
    	 << "\n\n" << setfill (' ') << setw (29) << " " << setfill ('-') 
         << setw(23) << "-"
     	 << "\n\n";
    
	
	for(int i = 0; i < CATS; i++)
	{
		//finds the fattest cat
		if (food[i] > maxPounds)
		{
		maxPounds = food[i];
		maxName = name[i];
		}

		if (food[i] < minPounds)
		{
		minPounds = food[i];
		minName = name[i];
		}
		
		//calculates the total weight in pounds
		foodTotal += food[i];
	}
	
		//find the total price the food costs
		totalCost = foodTotal * price;
	
	cout << "\t\t" << "Total amount of cat food in pounds per week: " << foodTotal << endl
		 << "\t\t" << "Total Price of cat food per pound: $" << setprecision(2) << totalCost << endl
		 << "\t\t" << maxName << " ate the most food with " << maxPounds << " pounds of food!\n"
		 << "\t\t" << minName << " ate the least food at " << minPounds << " pounds of food\n";
		 
}

void goodbye()
{
	cout << "\n\n\t\t\tGoodbye\n" 
		 << "\t\t\tThank you for using the cat calculator.\n" 
		 << "\t\t\tMade by the SPCA Shelter for adorable cats\n";
}

//Tutorial used for Cat Box layout https://youtu.be/dQw4w9WgXcQ
