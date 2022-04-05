#include <iostream>
#include "book.h"

using namespace std;

class Store
{
public:
    Store(/* args */);
    ~Store();

    //mutator functions
    void addBook(const char *t, const char *a, Genre g, double p);
    void sellBook(const char *x);

    //getter functions
    double getMoney() const;
    int getSize() const;
    int listBooks() const;
    int findBook(const char *x) const;
    int findGenere(Genre g, double &totalPrice) const;

private:
    double money; //stores the amount of money in the store cash register

    Book *inventoryList; //pointer to dynamic array of books
    unsigned int size;   // size of our array, allocation of the array is always size + 1

    int Resize(int newsize); //increases the size of the array by 1
};
