#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


	
struct TextbookInfo
{
	string titleText;						//Textbook Title
	int dateText;							//Textbook Date
	unsigned int costText;					//Textbook Cost
};

int main(int argc, char** argv) {
	
	const int NUM_TEXT = 1;
	TextbookInfo CourseMaterials[NUM_TEXT];		//text is a TextbookInfo Structure

//////////////////////////////////////////////////////////////

	for(int i = 0; i < NUM_TEXT; i++)
	{
		//Get the textbook title
		cout << "Enter the title of Textbook number " << i + 1 << ": ";
		cin.ignore('\0');
		cin >> CourseMaterials[i].titleText;
		
		//Get the textbook date
		cout << "Please enter the year date: ";
		cin >> CourseMaterials[i].dateText;
		
		//Get the textbook cost
		cout << "Please enter the cost: ";
		cin >> CourseMaterials[i].costText;
	}
	
	cout << "\n";
	for(int i = 0; i < NUM_TEXT; i++)
	{
		cout << "Textbook Name: "  << CourseMaterials[i].titleText << "\n"
			 << "Textbook Date: "  << CourseMaterials[i].dateText  << "\n"
			 << "Textbook Cost: $" << CourseMaterials[i].costText  << "\n\n";
	}



	return 0;
}
