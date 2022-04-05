#include<iostream>
#include<random>

using namespace std;

bool verify(string);

int main()
{
    string input = "test";

    bool verification = verify(input);


    while (input != "exit")
    {
        cout<<"Rock, Paper or scissors?\nor type exit: ";
        cin >> input;


        int randomRollHand = rand() % 3 + 1;
        string rollHand = "error";
        if (verification == true)
        {
            switch (randomRollHand)
            {
            case 1:
                rollHand = "rock";
                break;

            case 2:
                rollHand = "paper";
                break;
            
            case 3:
                rollHand = "scissors";
                break;
            
            default:
                rollHand = "error";
                cout << rollHand;
                return 0;
                break;
            }
        }

        cout << "input:   " << input << endl;
        cout << "random:  " << randomRollHand << endl;
    
    }
    

    


    return 0;
}

bool verify(string input)
{
    if(input == "rock" || input == "paper" || input == "scissors")
    {
        return true;
    }
    else
    {
        return false;
    }
}