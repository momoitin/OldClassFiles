/* Name: (Evan Dunlap)
Date: (4/12/2021)
Section: (Your section)
Assignment: (Assignment#7)
Due Date: (4/15/2021)
About this project: (inputs data from files and reads, compares and finds the total sales)
Assumptions: (assumes all input data is in the correct format)

All work below was performed by (Evan Dunlap :) */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int openFilestream(ifstream &in, char *file);
void stringCompare(double &, char *, char *, int, double price);
void summaryOutput(ofstream &out, char *cuisine, double cost);

struct Item
{
    char name[50];
    char cuisine[50];
    char dayOfWeek[10];
    double price;
};

struct Date
{
    int day;
    int month;
    int year;
    double totalAmount;
} date[50];

struct Sale
{
    int saleMonth;
    int saleDay;
    int saleYear;
    char name[50];
    int saleQuantity;
};

int main()
{

    ofstream out;
    ifstream in;

    /*
            Items Section
    */
    //opens filestream and retrieves the size of the file
    int numLinesItems = openFilestream(in, (char *)"items.txt");
    //delcare the size of the item structure array

    Item *item = new Item[numLinesItems];

    for (int i = 0; i < numLinesItems; i++)
    { //takes in each section at a time, with delimiter in place for all but price.
        in.getline(item[i].name, 50, '*');
        in.getline(item[i].cuisine, 50, '*');
        in.getline(item[i].dayOfWeek, 50, '*');
        in >> item[i].price;
        in.ignore();
    }

    // for (int i = 0; i < numLinesItems; i++)
    // {
    //     cout << item[i].name << " "
    //          << item[i].cuisine << " "
    //          << item[i].dayOfWeek << " "
    //          << item[i].price;
    // }
    // closes file stream
    in.close();

    /*
            Sales Section
    */
    //open and find the size of numlines
    int numLinesSales = openFilestream(in, (char *)"sales.txt");
    //declare the size of the sale structure array
    Sale *sale = new Sale[numLinesSales];

    for (int i = 0; i < numLinesSales; i++)
    {
        int arrSize = 20;
        char *star;
        star = new char[arrSize];
        char garbage;

        in >> sale[i].saleMonth >> garbage >> sale[i].saleDay >> garbage >> sale[i].saleYear;
        
        in.getline(star, arrSize, '*');
        in.getline(sale[i].name, arrSize, '*');

        in >> sale[i].saleQuantity;

        delete star;
    }

    // for(int i = 0; i<numLinesSales;i++)
    // {
    //     cout << sale[i].saleMonth << "/"
    //          << sale[i].saleDay << "/"
    //          << sale[i].saleYear << " "
    //          << sale[i].name << " "
    //          << sale[i].saleQuantity << endl;
    // }
    in.close();

    //initalize total sales of each type
    double ClassicAmerican = 0,
           French = 0,
           Indian = 0,
           Irish = 0,
           Italian = 0,
           Japanese = 0,
           Mexican = 0,
           Spanish = 0,
           Thai = 0;

    //find how many sales of each type of cuisine
    for (int i = 0; i < numLinesSales; i++)
    {
        //declares a tempstring
        char *name = sale[i].name;

        for (int j = 0; j < numLinesItems; j++)
        {
            //declares a temp string
            char *itemName = item[j].name;
            char *cuisineName = item[j].cuisine;

            //function removes newlines from file. if no newlines are found does nothing
            if (strncmp(item[j].name, sale[i].name, strlen(sale[i].name)) == 0)
            {
                stringCompare(ClassicAmerican, cuisineName, (char *)"Classic American", sale[i].saleQuantity, item[j].price);
                stringCompare(French, cuisineName, (char *)"French", sale[i].saleQuantity, item[j].price);
                stringCompare(Indian, cuisineName, (char *)"Indian", sale[i].saleQuantity, item[j].price);
                stringCompare(Irish, cuisineName, (char *)"Irish", sale[i].saleQuantity, item[j].price);
                stringCompare(Italian, cuisineName, (char *)"Italian", sale[i].saleQuantity, item[j].price);
                stringCompare(Japanese, cuisineName, (char *)"Japanese", sale[i].saleQuantity, item[j].price);
                stringCompare(Mexican, cuisineName, (char *)"Mexican", sale[i].saleQuantity, item[j].price);
                stringCompare(Spanish, cuisineName, (char *)"Spanish", sale[i].saleQuantity, item[j].price);
                stringCompare(Thai, cuisineName, (char *)"Thai", sale[i].saleQuantity, item[j].price);
            }
        }
        // cout << endl;
    }

    out.open("summary.txt");
    // if (!out)
    // {
    //     cerr << "File can't be opened! " << endl;
    //     system("PAUSE");
    //     exit(1);
    // }
    summaryOutput(out, (char *)"Classic American", ClassicAmerican);
    summaryOutput(out, (char *)"French", French);
    summaryOutput(out, (char *)"Indian", Indian);
    summaryOutput(out, (char *)"Irish", Irish);
    summaryOutput(out, (char *)"French", French);
    summaryOutput(out, (char *)"Italian", Italian);
    summaryOutput(out, (char *)"Japanese", Japanese);
    summaryOutput(out, (char *)"Mexican", Mexican);
    summaryOutput(out, (char *)"Spanish", Spanish);
    summaryOutput(out, (char *)"Thai", Thai);
    out.close();


    

    //delete arrays
    delete item;
    delete sale;

    return 0;
}

int openFilestream(ifstream &in, char *file)
{
    in.open(file);
    // if (!in)
    // {
    //     cerr << "File can't be opened! " << endl;
    //     system("PAUSE");
    //     exit(1);
    // }

    int numLines = 0;
    char unused[250];
    while (in.getline(unused, 250))
    {
        ++numLines;
    }
    in.clear();
    in.seekg(0);

    return numLines;
}

void stringCompare(double &counter, char *test1, char *test2, int quantity, double price)
{
    if (strncmp(test1, test2, strlen(test1)) == 0)
    {

        counter += (quantity * price);
    }
}

void summaryOutput(ofstream &out, char *cuisine, double cost)
{
    if (cost == 0)
    {
        out << cuisine << "\n"
            << "Never Ordered"
            << "\n\n";
    }
    else
    {
        out << cuisine << "\n$" << cost << "\n\n";
    }
}