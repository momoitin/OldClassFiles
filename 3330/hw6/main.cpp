#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "studentlist.h"

using namespace std;

void Menu();

int main()
{
    StudentList list;

    char userInput;

    Menu();
    while (userInput != 'Q')
    {
        char importFile[31];
        char exportFile[31];

        bool flag = true;

        cin >> userInput;
        userInput = toupper(userInput);

        switch (userInput)
        {
        case 'I':
            cout << "Enter filename: ";
            // getline(cin, importFile, '\n');
            cin.ignore();
            cin.getline(importFile, 30);

            flag = list.ImportFile(importFile);
            if (flag == false)
            {
                cout << "Invalid file. No data imported\n> ";
            }
            else if (flag == true)
            {
                cout << "Import complete\n> ";
            }
            break;

        case 'S':
            cout << "Last" << setw(26) << "First" << setw(22) << "Course\n";
            for (int i = 0; i < list.getSize(); i++)
            {
                // puts lastname to console
                cout << list.getLastName(i);
                //sets formatting then outputs firstname to console
                cout << setw(25 - (list.getLastName(i).length()) + list.getFirstName(i).length());
                cout << list.getFirstName(i);
                //sets formatting then outputs course to console
                cout << setw(20 - (list.getFirstName(i).length()) + list.getCourse(i).length());
                cout << list.getCourse(i) << endl;
                cout.clear();
            }
            cout << "\n> ";
            break;

        case 'E':
            cout << "Enter filename: ";
            cin.ignore();
            cin.getline(exportFile, 30);

            flag = list.CreateReportFile(exportFile);

            if (flag == false)
            {
                cout << "Invalid file. No data exported\n> ";
            }
            else if (flag == true)
            {
                cout << "Export complete\n> ";
            }

            break;

        case 'M':
            Menu();
            break;

        case 'Q':
            return 0;

        default:
            cout << "> ";
            break;
        }
    }
}

void Menu()
{
    cout << "\t\t\t\t*** Student List Menu ***\n\n"
         << "\tI\t\tImport students from a file\n"
         << "\tS\t\tShow student list (brief)\n"
         << "\tE\t\tExport a grade report (to file)\n"
         << "\tM\t\tShow this Menu\n"
         << "\tQ\t\tQuit Program\n"
         << "> ";
}
