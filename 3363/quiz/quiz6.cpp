#include <iostream>

using namespace std;

int main()
{
    char input[100];

    cout << "Enter a string: \n";
    cin.getline(input, 100, '\n');

    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (int i = 0; i < sizeof(input); i++)
    {
        if (input[i] == 'a' || input[i] == 'A')
        {
            a++;
            cout << "Testing";
        }
        if (input[i] == 'e')
        {
            e++;
        }
        if (input[i] == 'i')
        {
            i++;
        }
        if (input[i] == 'o')
        {
            o++;
        }
        if (input[i] == 'u')
        {
            u++;
        }

        if (input[i] == ' ')
        {
            for (int j = i; j < sizeof(input); j++)
            {
                input[j] = input[j+1];
            }
        }
        
        
    }

    cout << "Number of a's: " << a << endl
         << "Number of e's: " << e << endl
         << "Number of i's: " << i << endl
         << "Number of o's: " << o << endl
         << "Number of u's: " << u << endl;

    return 0;
}