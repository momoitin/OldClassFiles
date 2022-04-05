#include <iostream>
//This program will use functions to call menus for each choice that is input
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function prototypes
void showMenu();
int coverExtra(int);
int stairsExtra(int);
void showBill(int, float, float);
int thanks();


int main(int argc, char** argv) {
	
	//Holds value for user input
	int choice;
	
	//Constants for Menu Options
	const int MODEL_S = 1,
			  MODEL_M = 2,
			  MODEL_L = 3,
			  QUIT_CHOICE = 4;
			  
	//Constants for Model Cost and Shipping values in dollar amounts
	const int SMALL = 950,
			  MEDIUM = 1075,
			  LARGE = 1325;
			  
	//Constants for condo extras in percent ammounts (Change these in Bill function)
	const float COVER = 0.15,
				STAIRS = 0.1;
				
	//Grab Values for Cover and Stairs
	float cover_g = 2,
		  stairs_g = 2;


	do
	{
		//Display the Menu and get user input
		showMenu();
		cin >> choice;
		
		//Validate menu selection
		while(choice < MODEL_S || choice > QUIT_CHOICE)
		{
			cout << "Please enter a valid menu option: ";
			cin >> choice;
		}

	//If the customer wishes to quit, quit here.
	if(choice != QUIT_CHOICE)
	{
		//ask the customer if they wish to include a cover and stairs
		cover_g = coverExtra(cover_g);
		stairs_g = stairsExtra(stairs_g);
		
		
		//Display Bill Information Baised on input
		switch (choice)
		{
			case MODEL_S:
				 showBill(SMALL, cover_g, stairs_g);
				 break;
				 
			case MODEL_M:
				 showBill(MEDIUM, cover_g, stairs_g);
				 break;
			
			case MODEL_L:
				 showBill(LARGE, cover_g, stairs_g);
				 break;	
		}
	}
	
	//Calls function thanking user
	thanks();
	
	}while( choice != QUIT_CHOICE);
	
	

	
	return 0;
}

void showMenu()
{
	cout << "\n\t\tDoggie Condo Corp LLC\n\n"
		 << "This program will help you decide what kind of condo you need!\n"
		 << "Please enter the number that corrosponds with the condo you want.\n\n"
		 << "1. Small Condo (two dogs)\n"
		 << "2. Medium Condo (four dogs)\n"
		 << "3. Large Condo (seven dogs)\n"
		 << "4. Quit the program\n\n"
		 << "Enter your choice: ";
}

int coverExtra(int cover_g)
{
	do
	{
		//asks to include a cover
		cout << "Would you like to add a cover for the condo?\n"
			 << "1. Yes, include a cover\n"
			 << "2. No, don't include a cover\n";
		cin >> cover_g;
	//validates cover input
	}while(cover_g < 1 || cover_g > 2);
	
	return cover_g;
}

int stairsExtra(int stairs_g)
{
	do
	{
		//asks to include stairs
		cout << "Would you like to add a staircase to the condo?\n"
			 << "1. Yes, include a staircase\n"
			 << "2. No, don't include a staircase\n";
		cin >> stairs_g;
	//validates stairs input
	}while(stairs_g < 1 || stairs_g > 2);
	
	return stairs_g;
}

void showBill(int size, float cover_g, float stairs_g)
{
	
	//Constants for condo extras in percent ammounts 
	const float COVER = 0.15,
				STAIRS = 0.1;
	//Shipping Constant
	const int SHIPPING = 25;
	//Repeat variable for Bill
	int repeat;
	//Total cost Var
	float cost;
	
	//converts input value to useable value
	if(cover_g == 1){
		cover_g = COVER;}
		else{cover_g = 0;}
		
	if(stairs_g == 1){
		stairs_g = STAIRS;}
		else{stairs_g = 0;}
		
	cout << "your bill!!\n" << cover_g << "\n" << stairs_g;
	
	//Convert the percent values into dollar values
	cover_g = cover_g * size;
	stairs_g = stairs_g * size;
	
	//final calculation
	cost = size + stairs_g + cover_g + SHIPPING;

do{
	cout << "\n\t\tYour Bill:\n"
		 << "\tCondo Size: $" << size << endl
		 << "\tStairs:     $" << stairs_g << endl
		 << "\tCover:      $" << cover_g << endl
		 << "\tShipping:   $" << SHIPPING << endl << endl
		 << "\tTotal Cost: $" << cost << endl << endl
		 << "If you would like to see your bill again please press 0...\n"
		 << "otherwise enter any key\n"
		 << "Repeat Bill? ";
		 cin >> repeat;
		 
  }while(repeat == 0);
  	 
}

int thanks()
{
	cout << "\n\nThank you for using this program by Doggie Condo Corp LLC"
		 << "\nif you have any problems or would like to call "
		 << "\nfor assistance please dial (850)694-6179"
		 << "\n have a wonderful day!\n";
	return 0;
}
