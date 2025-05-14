#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILE_NAME = "account_balance.txt";
const double INITIAL_BALANCE = 100.00;

double readBalance() 
{
    ifstream inFile(FILE_NAME);
    double balance = INITIAL_BALANCE;

    if (inFile) 
    { 
        inFile >> balance;
    }
    else 
    {
        ofstream outFile(FILE_NAME);
        outFile << fixed << setprecision(2) << INITIAL_BALANCE;
    }

    return balance;
}


void updateBalance(double balance) 
{
    ofstream outFile(FILE_NAME);
    if (!outFile) 
    {
        cout << "Error: Unable to update balance file!" << endl;
        return;
    }
    outFile << fixed << setprecision(2) << balance;
}

void displayMenu() 
{
    cout << "\nBank Account Menu\n";
    cout << "1. Check Your Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() 
{
    double balance = readBalance();
    int choice;
    do 
    {
        displayMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) 
        {
        case 1:
            std::cout << "Your balance: $" << std::fixed << setprecision(2) << balance << endl;
            break;

        case 2: 
        {
            double deposit;
            std::cout << "Enter deposit amount: $";
            cin >> deposit;

            if (cin.fail() || deposit <= 0) 
            {
                std::cout << "Invalid amount! Deposit must be positive.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else 
            {
                balance += deposit;
                updateBalance(balance);
                std::cout << "Deposit successful! New balance: $" << balance << endl;
            }
            break;
        }

        case 3: 
        {
            double withdraw;
            std::cout << "Enter withdrawal amount: $";
            cin >> withdraw;

            if (cin.fail() || withdraw <= 0) 
            {
                std::cout << "Invalid amount! Withdrawal must be positive.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else if (withdraw > balance) 
            {
                std::cout << "Insufficient funds! Your balance is: $" << balance << endl;
            }
            else 
            {
                balance -= withdraw;
                updateBalance(balance);
                std::cout << "Withdrawal successful! New balance: $" << balance << endl;
            }
            break;
        }

        case 4:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << " Enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}