#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int SIZE = 20,
		ASCII = 48;

	char userinput[SIZE];
	
	int sum = 0,
		temp;

		

	//gets the users input
	cout << "Please enter a string of digits with no spaces no more than " 
		 << SIZE - 1 << " characters long:\n";
	cin.getline(userinput, SIZE);
	
	//removes any non numeric variables
	for(int i = 0; i < SIZE; i++)
	{
		if(isalpha(userinput[i]))
		{
			userinput[i] = '0';
		}
	}

	for(int i = 0; userinput[i] != '\0'; i++)
	{
		//turns the char value into int ASCII value
		temp = userinput[i];
		//subtract 48 from ascii code
		temp = temp - ASCII;
		//Get the sum from ascii code
		sum += temp;	 	
	}

	cout << "The sum of the entered string is: " << sum;
	
	//Please dont hate me for using ascii values, I was about to rip my hair out otherwise
	//and it works so yeah...
	
	return 0;
}
