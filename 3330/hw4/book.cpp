#include <iostream>
#include "book.h"
#include <cstring>

using namespace std;

/*  Private Data
  char title[31];	// may assume title is 30 characters or less
  char author[21];	// may assume author name is 20 characters or less
  Genre type;
  double price;
*/

Book::Book() // default constructor, sets up blank book object
{
    title[0] = '\0';
    author[0] = '\0';
    type = FICTION;
    price = 0;
}

void Book::Set(const char *t, const char *a, Genre g, double p)
{
    //Title c-string
    strcpy(title, t);
    //Author c-string
    strcpy(author, a);
    //Genre settings (name of var is type)
    type = g;
    //price setting
    price = p;
}

const char *Book::GetTitle() const // returns the title stored in the object
{
    return title;
}
const char *Book::GetAuthor() const // returns the author
{
    return author;
}
double Book::GetPrice() const // returns the price
{
    return price;
}
Genre Book::GetGenre() const // returns the genre
{
    return type;
}

void Book::Display() const // described below
{
    cout << title;
    cout << "\t\t" << author << "\t";

    switch (type)
    {
    case FICTION:
        cout << "Fiction";
        break;
    case MYSTERY:
        cout << "Mystery";
        break;
    case SCIFI:
        cout << "Scifi";
        break;
    case COMPUTER:
        cout << "Computer";
        break;
    default:
        cout << "No genere";
        break;
    }

    cout << "\t\t" << price << endl;
}