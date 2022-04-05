#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int lotteryGeneration(int[], int);

int main(int argc, char** argv) {
	
	const int lot = 5;			 	 //constant amount of lottery numbers
	int Lottery[lot] = {}, 	 	 	 //Randomly generated lottery numbers
		user[lot] = {},	 			 //inputted values by user
		matching = 0;				 //number of matching lottery numbers
	
	for(int i = 0; i < lot; i++) 	 //Loop for user inputted numbers
	{
		cout << "Please enter a lottery number from 0 - 9 for lotto number " 
			 << i+1 << ": ";
		cin >> user[i];		
			
		while(user[i] > 9)  		 //while loop to verify input
		{
			cout << "Please enter a valid number for lotto number " 
				 << i+1 << ": "; 
			cin >> user[i];	
		}	
	}
	
	//Sends empty lottery array to fill with random numbers
	Lottery[lot] = lotteryGeneration(Lottery, lot);
	
	cout << "\n\nYour numbers are...      ";
	for(int i = 0; i < lot; i++)	 //displays the user inputted numbers for comparison
	{
		cout << user[i] << " ";
	}
	
	
	cout << "\n\nThe winning numbers are: ";
	for(int i = 0; i < lot; i++)	 //Shows Winning Numbers
	{
		cout << Lottery[i] << " ";
	}
	cout << "\n\n";
	
	for(int i = 0; i < lot; i++) 	//Finds number of matching lotto numbers
	{
		if(Lottery[i] == user[i])
		{
			matching += 1;
		}
	}
	
	if(matching == 5)				//find the amount of matching numbers
	{
		cout << "You are the grand prize winner!";
	}
	else
	{
		cout << "You matched " << matching << " lottery number(s)\n";
	}
	
	return 0;
}

int lotteryGeneration(int Lottery[], int lot )
{
	srand(time(0));					//function to generate random numbers
	for(int i = 0; i < lot; i++)
	{
		Lottery[i] = 1 + (rand() % 9);  
		//Lottery[i] = 5;				//temp code to test grand prize
	}
	
	return Lottery[lot];
}
