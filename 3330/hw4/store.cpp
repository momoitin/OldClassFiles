#include <iostream>
#include <cstring>
#include "store.h"
#include "book.h"

using namespace std;

/*  Private Data
    double money; //stores the amount of money in the store cash register

    Book *inventoryList; //pointer to dynamic array of books
    unsigned int size;   // size of our array, allocation of the array is always size + 1

    void Resize(int newsize);
*/

Store::Store(/* args */)
{
    money = 0; //set money to 0
    size = 0;  //set size of book array to 0

    //declare a new inventoryList of size 0
    inventoryList = new Book[size];
}
Store::~Store()
{
    delete[] inventoryList; //delete the array, not the pointer
}

void Store::addBook(const char *t, const char *a, Genre g, double p)
{
    int i = Store::Resize(size + 1);
    inventoryList[i - 1].Set(t, a, g, p);
}

void Store::sellBook(const char *x)
{
    //returns position of the flagged book
    int position = Store::findBook(x);

    if (position >= 0)
    {
        //add the sale price of the book to the register
        money += inventoryList[position].GetPrice();

        //delete book in "position", then shift all other books to the left and delete old array
        for (int i = position; i < size; i++)
        { //starting at position, shift books to the left
            inventoryList[i] = inventoryList[i + 1];
        }

        //resize the array
        Store::Resize(size - 1);
    }
}

double Store::getMoney() const
{
    return money;
}

int Store::getSize() const
{
    return size;
}

int Store::listBooks() const
{
    for (int i = 0; i < size; i++)
    {
        inventoryList[i].Display();
    }
    return size;
}

int Store::findBook(const char *x) const
{
    int position = 0;
    bool trigger = false;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(inventoryList[i].GetAuthor(), x) == 0)
        {
            inventoryList[i].Display();
            trigger = true;
        }
    }

    if (trigger == false)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(inventoryList[i].GetTitle(), x) == 0)
            {
                inventoryList[i].Display();
                position = i;
                trigger = true;
            }
        }
    }

    if (trigger == false)
    {
        return -1;
    }

    return position;
}

int Store::findGenere(Genre g, double &totalPrice) const
{
    int totalBooks = 0;

    for (int i = 0; i < size; i++)
    {
        if (inventoryList[i].GetGenre() == g)
        {
            totalPrice += inventoryList[i].GetPrice();
            totalBooks++;
        }
    }
    return totalBooks;
}

int Store::Resize(int newsize)
// current data is in "inventoryList", current size is "size"
{

    cout << "Array being rezied from " << size << " too " << newsize << " slots\n";

    Book *temp = new Book[newsize]; //create a new array of books using newsize

    for (int i = 0; i < size && i < newsize; i++) //copy the origional data
        temp[i] = inventoryList[i];

    delete[] inventoryList; //delete the old array data
    inventoryList = temp;   //set the temp pointer to the inventorylist pointer
    size = newsize;         //set the size to the new size

    cout << "Array resize complete, inventoryList is now " << size << " slots\n";

    return size;
}