#include "main.hpp"

int main()
{
    // Table of pointers to the different functions.
    void (*functions[])(void) = {nullptr, mainQuestion1, mainQuestion2, mainQuestion3};
    int userInput = -1;
    do
    {
        try
        {
            cout << endl << "Type any number from 1 to 3 to see what the associated exercice main function does. ";
            cout << "Type any other key to exit." <<endl;
            cin >> userInput;

            if (userInput == 0)
                return 0;
            else if (userInput >0 && userInput <=3)
                functions[userInput]();
            else
                cout << "Invalid choice." << endl;
        }
        catch(const std::exception& e)
        {
            cerr << "Invalid command." << endl;
        }
        userInput = -1;
    } while (true);

    return 0;
}
