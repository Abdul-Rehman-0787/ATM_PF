#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <ctime>

#define  RSuccess   "Request successful. Thank you for using our service."

using namespace std;

char UE = 'U';

void printmenu() {
    system("cls");
    cout << "\x1b[33m" << "\t\t\t\t\t************************\n";
    cout << "\t\t\t\t\t*      Welcome In      *\n";
    cout << "\t\t\t\t\t*   Automated Teller   *\n";
    cout << "\t\t\t\t\t*    Machine  (ATM)    *\n";
    cout << "\t\t\t\t\t************************\n";
    cout << "\n===========================================================================================================\n" << "\x1b[37m";
}


void createAccount() {
    char name[50];
    string accountNumber, password, phoneno;
    double balance = 0.0;

    cout << "Enter Account Number : \t";
    cin >> accountNumber;
    cout << "Enter Password : \t";
    cin >> password;
    cout << "Enter Account Holder Name : \t";
    //cin >> accname;
    cin.ignore();
    cin.getline(name, 49);
    string accname(name);
    cout << "Enter Phone Number : \t";
    cin >> phoneno;
    cout << "Enter Balance : \t";
    cin >> balance;

    ofstream outFile(accountNumber + ".txt");
    outFile << accountNumber << endl;
    outFile << password << endl;
    /*int i = 0;
    while (name[i]=!'\0')
    {
        outFile << name[i];
        i++;
    }
    outFile << "\t";
    */
    outFile << accname << endl;
    outFile << phoneno << endl;
    outFile << balance << endl;
    outFile.close();

    cout << "Account created successfully!" << endl;
    Sleep(3000);
}

bool login(string& accountNumber) {
    string inputAccountNumber, inputPassword, password, accname, phoneno;
    double balance;

    cout << "Enter Account Number: ";
    cin >> inputAccountNumber;
    cout << "Enter Password: ";
    cin >> inputPassword;

    ifstream inFile(inputAccountNumber + ".txt");
    if (!inFile) {
        cout << "Account not found!" << endl;
        Sleep(2000);
        return false;
    }

    getline(inFile, accountNumber);
    getline(inFile, password);
    getline(inFile, accname);
    getline(inFile, phoneno);
    inFile >> balance;
    inFile.close();

    if (accountNumber == inputAccountNumber && password == inputPassword) {
        cout << "Login successful!" << endl;
        Sleep(2000);
        return true;
    }
    else {
        cout << "Incorrect account number or password!" << endl;
        Sleep(3000);
        return false;
    }
}

void checkBalance(const string& accountNumber) {
    string password, accname, phoneno;
    double balance;

    ifstream inFile(accountNumber + ".txt");
    getline(inFile, password);  // Read password, but we don't need it here
    getline(inFile, password);  // Read actual password
    getline(inFile, accname);
    getline(inFile, phoneno);
    inFile >> balance;
    inFile.close();

    cout << "Current balance: $" << balance << endl;
    Sleep(2000);
}

void printReceipt(const string& accountNumber, const string& transactionType, double amount) {
    cout << "\x1b[35m";
    time_t now = time(0);
    char* dt = ctime(&now);
    string password, accountname, phonenumber;
    double balance;
    ifstream inFile(accountNumber + ".txt");
    getline(inFile, password);  // Read account number
    getline(inFile, password);  // Read password
    inFile >> accountname;
    inFile >> phonenumber;
    inFile >> balance;
    inFile.close();
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\t=       Receipt      =\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t********************************************************" << endl;
    cout << "\t\t\t  Date and Time    : \t" << dt;
    cout << "\t\t\t  Account Number   : \t" << accountNumber << endl;
    cout << "\t\t\t  Account Holder   : \t" << accountname << endl;
    cout << "\t\t\t  Phone Number     : \t" << phonenumber << endl;
    cout << "\t\t\t  Transaction Type : \t" << transactionType << endl;
    cout << "\t\t\t  Amount           : \t$" << amount << endl;
    cout << "\t\t\t  New Balance      : \t$" << balance << endl;
    cout << "\t\t\t********************************************************" << endl;
    cout << "\t\t\t\t\tThank you for choosing us. Your trust means everything.\n";

    UE = _getch();
    cout << "\x1b[33m";

    {            //Record
        ofstream record;
        record.open("Record.txt", ios::app);
        if (record.is_open())
        {
            record << dt << "\t" << accountNumber << "\t" << transactionType  << "\t" << amount<< "$" << endl;
        }
        else cout << "\nError in Record!Reporting to Office!\n";
        record.close();
    }
}

void printReceipttt(const string& accountNumber, const string& transactionType, long long amount, long long ptr) {
    cout << "\x1b[33m";
    time_t now = time(0);
    char* dt = ctime(&now);
    string password, accountname, phonenumber;
    double balance;
    ifstream inFile(accountNumber + ".txt");
    getline(inFile, password);  // Read account number
    getline(inFile, password);  // Read password
    inFile >> accountname;
    inFile >> phonenumber;
    inFile >> balance;
    inFile.close();
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t\t\t=       Receipt      =\n";
    cout << "\t\t\t\t\t======================\n";
    cout << "\t\t\t**********************************************************" << endl;
    cout << "\t\t\t  Date and Time      : \t" << dt;
    cout << "\t\t\t  Account Number     : \t" << accountNumber << endl;
    cout << "\t\t\t  Account Holder     : \t" << accountname << endl;
    cout << "\t\t\t  Phone Number       : \t" << phonenumber << endl;
    cout << "\t\t\t  Transaction Type   : \t" << transactionType << endl;
    cout << "\t\t\t  Tranfer To Account : \t" << ptr << endl;
    cout << "\t\t\t  Transferred Amount : \t$" << amount << endl;
    cout << "\t\t\t  Current Balance    : \t$" << balance << endl;
    cout << "\t\t\t**********************************************************" << endl;
    cout << "\t\t\tThank you for choosing us. Your trust means everything.\n";

    UE = _getch();
    cout << "\x1b[37m";

    {            //Record
        ofstream record;
        record.open("Record.txt",ios::app);
        if (record.is_open())
        {
            record << dt << "\t" << accountNumber << "\t" << transactionType << "\t" << ptr << "\t" << amount << "$" << endl;
        }
        else cout << "\nError in Record!Reporting to Office!\n";
        record.close();
    }
}


void depositMoney(string& accountNumber) {
    string password, accname, phoneno;
    double balance, amount;

    cout << "Enter amount to deposit: $";
    cin >> amount;

    ifstream inFile(accountNumber + ".txt");
    getline(inFile, password);  // Read account number
    getline(inFile, password);  // Read password
    getline(inFile, accname);
    getline(inFile, phoneno);
    inFile >> balance;
    inFile.close();

    balance += amount;

    ofstream outFile(accountNumber + ".txt");
    outFile << accountNumber << endl;
    outFile << password << endl;
    outFile << accname << endl;
    outFile << phoneno << endl;
    outFile << balance << endl;
    outFile.close();

    cout << "Amount deposited successfully!" << endl;
    Sleep(2000);
    cout << "\n\n\n\nPress 1 if you want to print Receipt -Or- Any other key to close :  \t";
    string Riaz;       //Signature
    cin >> Riaz;
    if (Riaz == "1") {
        printReceipt(accountNumber, "Deposit", amount);
    }
}

void withdrawMoney(string& accountNumber) {
    string password, accname, phoneno;
    double balance, amount;

    cout << "Enter amount to withdraw: $";
    cin >> amount;

    ifstream inFile(accountNumber + ".txt");
    getline(inFile, password);  // Read account number
    getline(inFile, password);  // Read password
    getline(inFile, accname);
    getline(inFile, phoneno);
    inFile >> balance;
    inFile.close();

    if (amount <= balance) {
        balance -= amount;

        ofstream outFile(accountNumber + ".txt");
        outFile << accountNumber << endl;
        outFile << password << endl;
        outFile << accname << endl;
        outFile << phoneno << endl;
        outFile << balance << endl;
        outFile.close();

        cout << "Amount withdrawn successfully!" << endl;
        Sleep(2000);
        cout << "\n\n\n\nPress 1 if you want to print Receipt -Or- Any other key to close :  \t";
        string Riaz;       //Signature
        cin >> Riaz;
        if (Riaz == "1") {
            printReceipt(accountNumber, "Withdraw", amount);
        }
    }
    else {
        cout << "Insufficient balance!" << endl;
        Sleep(2000);
    }
}

void Billpay(string accountNumber) {
    system("cls");
    printmenu();
    cout << "\t\t\t\tBill-Pay\n";
    cout << "\tThis Service is Currently NOT-Available!\n";
    Sleep(3000);

}

void Transfermoney(string accountNumber) {
    system("cls");
    printmenu();
    cout << "\t\t\t\tOther-Transection\n\n";
    cout << "Please Enter the Account Number(To-Transfer) : \t";
    long long* ptr = new long long;
    cin >> *ptr;
    long long* ptr1 = new long long;
    cout << "Plaese Enter the Amount :\t";
    cin >> *ptr1;
    string* password = new string;
    string* accname = new string;
    string* phoneno = new string;
    long long* balance = new long long;
    ifstream inFile(accountNumber + ".txt");
    getline(inFile, *password);  // Read account number
    getline(inFile, *password);  // Read password
    getline(inFile, *accname);
    getline(inFile, *phoneno);
    inFile >> *balance;
    inFile.close();

    if (*ptr1 <= *balance) {
        *balance -= *ptr1;

        ofstream outFile(accountNumber + ".txt");
        outFile << accountNumber << endl;
        outFile << *password << endl;
        outFile << *accname << endl;
        outFile << *phoneno << endl;
        outFile << *balance << endl;
        outFile.close();
        cout << "\n\t";
        cout << RSuccess << endl;
        Sleep(2000);
        cout << "\n\n\n\nPress 1 if you want to print Receipt -Or- Any other key to close :  \t";
        string Riaz;       //Signature
        cin >> Riaz;
        if (Riaz == "1") {
            printReceipttt(accountNumber, "Other-Transaction", *ptr1, *ptr);
        }
    }
    else {
        cout << "Insufficient balance!" << endl;
        Sleep(2000);
    }

    delete ptr;
    delete ptr1;
    delete password;
    delete balance;
    delete phoneno;
    delete accname;
    password = NULL;
    balance = NULL;
    phoneno = NULL;
    accname = NULL;
    ptr1 = nullptr;
    ptr = nullptr;
}



int main() {
    int choice;
    string accountNumber;

    while (true) {
        printmenu();
        cout << "\x1b[32m" << "\t\t\t\tATM Menu\n";
        cout << "\t\t\t\t1. Create Account\n";
        cout << "\t\t\t\t2. Login\n";
        cout << "\t\t\t\t3. Check Balance\n";
        cout << "\t\t\t\t4. Deposit Money\n";
        cout << "\t\t\t\t5. Withdraw Money\n";
        cout << "\t\t\t\t6. Exit\n\n\n";
        cout << "Enter your choice : \t";
        cin >> choice;
        cout << "\x1b[37m";
        switch (choice) {
        case 1:
            printmenu();
            createAccount();
            break;
        case 2:
            printmenu();
            if (login(accountNumber)) {
                while (true) {
                    Sleep(2000);
                    system("cls");
                    printmenu();
                    cout << "\x1b[36m" << "\n\t\t\t\t1. Check Balance\n";
                    cout << "\t\t\t\t2. Deposit Money\n";
                    cout << "\t\t\t\t3. Withdraw Money\n";
                    cout << "\t\t\t\t4. Bill & Chalan \n";
                    cout << "\t\t\t\t5. Other Transection\n";
                    cout << "\t\t\t\t6. Logout\n";
                    cout << "Enter your choice : \t";
                    cin >> choice;
                    cout << "\x1b[37m";
                    if (choice == 1) checkBalance(accountNumber);
                    else if (choice == 2) depositMoney(accountNumber);
                    else if (choice == 3) withdrawMoney(accountNumber);
                    else if (choice == 4) Billpay(accountNumber);
                    else if (choice == 5) Transfermoney(accountNumber);
                    else if (choice == 6) break;
                    else cout << "Invalid choice!" << endl;
                }
            }
            break;
        case 3:
            printmenu();
            cout << "\x1b[31m" << "Please login first!" << "\x1b[37m" << endl;
            Sleep(3000);
            break;
        case 4:
            printmenu();
            cout << "\x1b[31m" << "Please login first!" << "\x1b[37m" << endl;
            Sleep(3000);
            break;
        case 5:
            printmenu();
            cout << "\x1b[31m" << "Please login first!" << "\x1b[37m" << endl;
            Sleep(3000);
            break;
        case 6:
            cout << "\x1b[33m" << "===========================================================================================================\n";
            cout << "\t\tThank you for choosing us. Your trust means everything.\n" << "\x1b[37m";
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
