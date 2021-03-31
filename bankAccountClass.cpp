#include <iostream>
#include <conio.h>
#include <cstdint>

using namespace std;

class ACCOUNT
{
    char name[20];
    int64_t acno;
    int64_t adno;
    char actype[4];
    float balance;

public:
    ACCOUNT() // Here is the Constructor
    {
        cout << "------------Welcome To The Bank Account-------------";
        cout << "\n********New Account*********\n";
        cout << "Enter the Name of the account holder: ";
        cin >> name;
        cout << "\nEnter the Account Number: ";
        cin >> acno;
        cout << "\nEnter the Account Type: (CURR / SAVG / FD) : ";
        cin >> actype;
        cout << "\nEnter your Aadhar Number : ";
        cin >> adno;
        cout << "\nEnter the Amount to Deposit: ";
        cin >> balance;
        cout << "\nACCOUNT CREATED SUCCESSFULLY WITH AMOUNT " << balance << "\n\n";
    }
    void init(); // Member Functions
    void deposit();
    void withdraw();
    void calSI();
    void disp_det();
};

//Defining functions of ACCOUNT class
void ACCOUNT::init()
{
    cout << "\n********New Account*********\n";
    cout << "Enter the Name of the account holder: ";
    cin >> name;
    cout << "\nEnter the Account Number: ";
    cin >> acno;
    cout << "\nEnter the Account Type: (CURR / SAVG / FD) : ";
    cin >> actype;
    cout << "\nEnter your Aadhar Number : ";
    cin >> adno;
    cout << "\nEnter the Amount to Deposit: ";
    cin >> balance;
    cout << "\nACCOUNT CREATED SUCCESSFULLY WITH AMOUNT " << balance << "\n\n";
}
void ACCOUNT::deposit()
{
    float more;
    cout << "\n********Depositing*********\n";
    cout << "Enter the amount to deposit: ";
    cin >> more;
    balance += more;
    cout << "SUCCESSFULLY DEPOSITED ";
}
void ACCOUNT::withdraw()
{
    float amt;
    cout << "\n*******Withdrawal********\n";
    cout << "Enter the amount to withdraw: ";
    cin >> amt;
    if (balance >= amt)
    {
        balance -= amt;
        cout << "SUCCESSFULLY WITHDRAWN ";
    }
    else
    {
        cout << "\n????????????????Insufficient Balance???????????????\n\n";
    }
}

void ACCOUNT::calSI()
{
    float p, r, t, si;
    float amt;
    cout << "\n Principle Amount : ";
    cin >> p;
    cout << "\n Rate of Interest : ";
    cin >> r;
    cout << "\n Number of years : ";
    cin >> t;
    si = (p * r * t) / 100;
    amt = si + p;
    cout << "\nSimple Interest : " << si << " & Total Amount (Principle + Interest) : " << amt << endl;
}

void ACCOUNT::disp_det()
{
    cout << "\n********Account Details*********\n";
    cout << "Name of the depositor : " << name << endl;
    cout << "Account Number        : " << acno << endl;
    cout << "Account Type          : " << actype << endl;
    cout << "Aadhar Number         : " << adno << endl;
    cout << "Balance               : Rs" << balance << endl;
}

// main function
int main(void)
{
    ACCOUNT obj;
    int choice = 1;
    while (choice != 0)
    {
        cout << "\n\n\nEnter 0 to exit \n1. Create a new account \n2. Deposit \n3. Withdraw \n4. Calculate Interest \n5. See A /c Status\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            obj.disp_det();
            cout << "EXITING PROGRAM.";
            break;
        case 1:
            obj.init();
            break;
        case 2:
            obj.deposit();
            break;
        case 3:
            obj.withdraw();
            break;
        case 4:
            obj.calSI();
            break;
        case 5:
            obj.disp_det();
            break;
        default:
            cout << "Choose Option " << endl;
        }
    }
    getch();
    return 0;
}