#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
// #include "book.h"
#include "store.h"

using namespace std;

//prototypes
void menu();

int main()
{
    char menuSelection = ' ';
    Store library;
    menu();

    while (menuSelection != 'X')
    {
        cin >> menuSelection;

        int count = 0;
        int size = 0;
        double totalPrice = 0;
        int totalBooks = 0;

        switch (menuSelection)
        {
        case 'A': //add a book to the inventory list
            char titleT[31];
            char authorT[21];
            char genreT;
            Genre typeT;
            double priceT;

            //enter title and author using getline and set end of line to null terminator
            cout << "Enter the title: ";
            cin.ignore();
            cin.getline(titleT, 30, '\n');
            titleT[strlen(titleT)] = '\0';

            cout << "Enter the author: ";
            cin.getline(authorT, 20, '\n');
            authorT[strlen(authorT)] = '\0';

            //////////////////////////////////////////////////////

            cout << "Enter genre - (F)iction, (M)ystery, (S)cifi, (C)omputer: ";
            cin >> genreT;

            cout << "Enter the price: ";
            cin >> priceT;

            switch (genreT)
            {
            case 'F':
                typeT = FICTION;
                break;

            case 'M':
                typeT = MYSTERY;
                break;
            case 'S':
                typeT = SCIFI;
                break;
            case 'C':
                typeT = COMPUTER;
                break;
            default:
                break;
            }

            library.addBook(titleT, authorT, typeT, priceT);

            break;

        case 'F':
            char search[31];

            cout << "Enter a search string (title or author): ";
            cin.ignore();
            cin.getline(search, 30, '\n');
            search[strlen(search)] = '\0';
            //double checks the return to make sure a book was found
            if (library.findBook(search) == -1)
            {
                cout << "No book found with those search terms\n";
            }

            break;

        case 'S':
            char sale[31];
            cout << "Enter the title to purchase: ";
            cin.ignore();
            cin.getline(sale, 30, '\n');
            search[strlen(sale)] = '\0';

            library.sellBook(sale);

            break;

        case 'D':
            cout << "\n";
            size = library.getSize();

            if (size <= 0)
            {
                cout << "\nNo books currently in inventory";
            }
            else
            {
                cout << "**TITLE**\t\t\t**AUTHOR**\t\t**GENERE**\t**PRICE**\n";
                library.listBooks();
            }

            cout << "\nNumber of books = " << size << endl;
            cout << "Money in register = $" << setprecision(2) << fixed
                 << library.getMoney() << endl;
            break;

        case 'G':
            cout << "Enter genre - (F)iction, (M)ystery, (S)cifi, (C)omputer: ";
            cin >> genreT;

            totalBooks = library.findGenere(FICTION, totalPrice);

            cout << "Total books in this genre = " << totalBooks;
            cout << "\nTotal price of books in this genre = $" << setprecision(2) << fixed
                 << totalPrice << endl;

            break;

        case 'M':
            menu();
            break;

        case 'X':
            cout << "Money in register = $" << setprecision(2) << fixed
                 << library.getMoney() << endl
                 << "Goodbye!\n";

            return 0;

        default:
            cout << "Invalid entry. Please re-enter\n";
            break;
        }
    };
}

void menu()
{
    cout << "\n\n\t\t*** BOOKSTORE MENU ***\n"
         << "\tA\tAdd a Book to Inventory\n"
         << "\tF\tFind a book from Inventory\n"
         << "\tS\tSell a book\n"
         << "\tD\tDisplay the inventory list\n"
         << "\tG\tGenre summary\n"
         << "\tM\tShow this Menu\n"
         << "\tX\tExit Program\n\n"; //print out ifnal amount of money in register
}