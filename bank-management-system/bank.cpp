#include <iostream>
using namespace std;

// maximum number of accounts
const int MAX_ACCOUNTS = 100;

class bankAccount
{
private:
    string accountHolderName;
    int age;
    long long phoneNumber;
    double balance;

public:
    void initializeAccount(string accName, int accAge, long long accMobile, double initialBalance)
    {
        accountHolderName = accName;
        age = accAge;
        phoneNumber = accMobile;
        balance = initialBalance;
    }

    void deposit()
    {
        double amount;
        cout << "Enter amount to be deposited: ";
        cin >> amount;

        balance += amount;
        cout << "Amount deposited successfully. Updated balance: " << balance << endl;
    }

    void withdraw()
    {
        double amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn amount successfully. Updated balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance.";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void viewAccount()
    {
        cout << "\nViewing Account Details:\n";
        cout << "Name: " << accountHolderName << endl;
        cout << "Age: " << age << endl;
        cout << "Phone no.: " << phoneNumber << endl;
        cout << "Balance: " << getBalance() << endl;
    }
};

int main()
{
    bankAccount accounts[MAX_ACCOUNTS]; // fixed-size array for accounts
    int accountCount = 0;               // keep track of the number of accounts created

    string accName;
    int accAge;
    long long accMobile;
    double initialBalance;

    int choice;
    do
    {
        cout << "\nWelcome to Laxmi Chit Fund Bank\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. View Account\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (accountCount < MAX_ACCOUNTS) // Check if there's room for a new account
            {
                cout << "\nEnter Your Details:\n";
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, accName);
                cout << "Enter age: ";
                cin >> accAge;
                cout << "Enter phone no.: ";
                cin >> accMobile;
                cout << "Enter initial balance: ";
                cin >> initialBalance;

                accounts[accountCount].initializeAccount(accName, accAge, accMobile, initialBalance);

                accountCount++;

                cout << "\nPlease wait, initializing your account...\nAccount created successfully. Thank you for choosing Laxmi Chit Fund Bank!\n";
                cout << "Your alloted account number: " << accountCount << endl;
            }
            else
            {
                cout << "Account limit reached. No more accounts can be created." << endl;
            }
            break;

        case 2:
            int accountNumber;
            cout << "\nEnter account number: ";
            cin >> accountNumber;

            if (accountNumber > 0 && accountNumber <= accountCount)
            {
                accounts[accountNumber - 1].deposit();
            }
            else
            {
                cout << "No account found.";
            }
            break;

        case 3:
            cout << "\nEnter account number: ";
            cin >> accountNumber;

            if (accountNumber > 0 && accountNumber <= accountCount)
            {
                accounts[accountNumber - 1].withdraw();
            }
            else
            {
                cout << "No account found.";
            }
            break;

        case 4:
            cout << "\nEnter account number: ";
            cin >> accountNumber;

            if (accountNumber > 0 && accountNumber <= accountCount)
            {
                accounts[accountNumber - 1].viewAccount();
            }
            else
            {
                cout << "No account found.";
            }
            break;

        case 5:
            cout << "Exiting...";
            return 0;

        default:
            cout << "Invalid choice, please try again.";
            return 0;
        }
    } while (choice != 5);

    return 0;
}
