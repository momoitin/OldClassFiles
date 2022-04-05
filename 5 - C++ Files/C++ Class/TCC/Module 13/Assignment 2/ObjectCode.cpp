#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Program By Evan Dunlap

class RetailItem
{
	private:
		string description;  // Item description
		int unitsOnHand;	 // Units on hand
		double price; 		 // Item price
	public:
		// Constructor
		RetailItem(string d, int u, double p)
			{ description = d; unitsOnHand = u; price = p; }
		// Mutators
		void setDescription(string d)
			{ description = d; }
		void setUnitsOnHand(int u)
			{ unitsOnHand = u; }
		void setPrice(double p)
			{ price = p; }
		// Accessors
		string getDescription()
			{ return description; }
		int getUnitsOnHand()
			{ return unitsOnHand; }
		double getPrice()
			{ return price; }
};

//Prototypes
void DisplayItem(RetailItem);
void DisplayDiscount(RetailItem);
string GrabD(string);
int    GrabU(int);
double GrabP(double);

int main(int argc, char** argv) {
	
	int SIZE  = 3;

	//Temp vars for filling in items
	string TempN = "Unit";	//Temporary Item Name for creating a database
	string TempD;	//Temporary description
	int    TempU;	//Temporary units on hand
	double TempP;	//Temporary price

//////////////////////////////////////////////////////////////////////////////////////////////
	//Copy and Pasteable Code to make objects and collect data
	cout << "Item: Unit1\n";		//Starts the input for the item
	TempD = GrabD(TempD);			//Calls for Description
	TempU = GrabU(TempU);			//Calls for Units
	TempP = GrabP(TempP);			//Calls for Price

	RetailItem Unit1(TempD, TempU, TempP);
//////////////////////////////////////////////////////////////////////////////////////////////	
	//Copy and Pasteable Code to make objects and collect data
	cout << "Item: Unit2\n";		//Starts the input for the item
	TempD = GrabD(TempD);			//Calls for Description
	TempU = GrabU(TempU);			//Calls for Units
	TempP = GrabP(TempP);			//Calls for Price

	RetailItem Unit2(TempD, TempU, TempP);
//////////////////////////////////////////////////////////////////////////////////////////////
	//Copy and Pasteable Code to make objects and collect data
	cout << "Item: Unit3\n";		//Starts the input for the item
	TempD = GrabD(TempD);			//Calls for Description
	TempU = GrabU(TempU);			//Calls for Units
	TempP = GrabP(TempP);			//Calls for Price

	RetailItem Unit3(TempD, TempU, TempP);
//////////////////////////////////////////////////////////////////////////////////////////////	
	
	//Displays Items
	cout << "\n\n"
		 << "List of Items:\n";
	DisplayItem(Unit1);
	DisplayItem(Unit2);
	DisplayItem(Unit3);
	
	//Displays Discounted Items
	cout << "\n"
		 << "Items with Discounted Price:\n";
	DisplayDiscount(Unit1);
	DisplayDiscount(Unit2);
	DisplayDiscount(Unit3);
	
	return 0;
}

string GrabD(string TempD)
{
	cout << "Enter Item Description: ";		//Holds temp description
	getline(cin >> ws, TempD);				//This literally took me 5 hours to figure out properly
	return TempD;	
}

int GrabU(int TempU)
{
	cout << "Enter Units on Hand:    ";		//Holds temp units on hand
	cin >> TempU;
	return TempU;	
}

double GrabP(double TempP)
{	
	cout << "Enter Item Price:       ";		//Holds temp Price
	cin >> TempP;
	return TempP;
}

void DisplayItem(RetailItem ItemInfo)
{
	cout << "Desc:   " << ItemInfo.getDescription() << "\n"
		 << "Units:  " << ItemInfo.getUnitsOnHand() << "\n"
		 << "Price: $" << ItemInfo.getPrice() << "\n\n";
}

void DisplayDiscount(RetailItem ItemInfo)
{
	ItemInfo.setPrice(ItemInfo.getPrice() * 0.75);
	cout << "Desc:   " << ItemInfo.getDescription() << "\n"
		 << "Units:  " << ItemInfo.getUnitsOnHand() << "\n"
		 << "Price: $" << ItemInfo.getPrice() << "\n\n";	
}
