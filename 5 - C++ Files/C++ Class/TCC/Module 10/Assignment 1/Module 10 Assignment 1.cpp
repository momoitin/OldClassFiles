#include <iostream>
#include <cctype>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Global Vars
char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

//Prototypes
void mainMenu();
void inputString(char *userinput, int SIZE);
int calcVowels(char *userinput, int SIZE, int numVowels);
int collectTotal(char *userinput, int SIZE, int total);

int main(int argc, char** argv) {
	
	const int SIZE = 20;
	char *userinput;
	userinput = new char[SIZE];
	
	char choice;
	
	int numVowels,
		numConsonants,
		total = 0;

///////////////////////////////////////////////////////////////////////////////////////////////
	while(choice != 'E' || choice != 'e')
	{		
		//Calls String input
		inputString(userinput, SIZE);
		cin.getline(userinput, SIZE);
		
		//Calculate number of vowels
		numVowels = calcVowels(userinput, SIZE, numVowels);
		
		//Call total calculation
		total = collectTotal(userinput, SIZE, total);

		//finds the number of consonants given total letters and num vowels
		numConsonants = total - numVowels;

		//Calls choice menu
		mainMenu();
		cin >> choice;
		cout << "\n";		
	
		if(choice == 'A' || choice == 'a')
		{
			cout << "Number of Vowels: " << numVowels << "\n\n";
		}
		if(choice == 'B' || choice == 'b')
		{
			cout << "Number of Consonents: " << numConsonants << "\n\n";
		}
		if(choice == 'C' || choice == 'c')
		{
			cout << "Number of Vowels: " << numVowels << " "
				 << "Number of Consonents: " << numConsonants << "\n\n";
		}
		if(choice == 'D' || choice == 'd')
		{
			total = 0;
			numVowels = 0;
			numConsonants = 0;
			cin.getline(userinput, SIZE);			
		}
		if(choice == 'E' || choice == 'e')
		{
			return 0;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}

void mainMenu()
{
	cout << "\n"
		 << "a. Count the number of vowels\n"
		 << "b. Count the number of consonants\n"
		 << "c. Count both vowels and consonants\n"
		 << "d. Enter another string\n"
		 << "e. Exit program\n\n"
		 << "Please Choose an option on the screen: ";
}

void inputString(char *userinput, int SIZE)
{
	//input of c-string
	cout << "Please enter a string no larger than "
		 << (SIZE) << " characters: ";	
}

int calcVowels(char *userinput, int SIZE, int numVowels)
{
	//calculate the number of vowels in the string
	int count = 0;
	while(userinput[count] != '\0')
	{
		for(int i = 0; i < 10; i++)
		{
			if(userinput[count] == vowels[i])
			{
				numVowels += 1;
			}
		}
		count++;
	}
	
	return numVowels;
}

int collectTotal(char *userinput, int SIZE, int total)
{
	int count = 0;
	//collects total number of letters
	while(userinput[count] != '\0')
	{
		if(userinput[count] != '\0')
		{
			total += 1;
		}
		count++;
	}
	return total;	
}
