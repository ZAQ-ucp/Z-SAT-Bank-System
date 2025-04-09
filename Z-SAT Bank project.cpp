/*
Zulqarnain Saeed 
zulqarnainsaeed2005@gmail.com
+92347-4897898

My 1st semester project as a student of  Computer science
*/
#include <iostream>

using namespace std;

int main() {
    //First i have 3 accounts by default
    char accountNames[10] = { 'A', 'B', 'C' };
    //These are accounts numbers
    int accountNumbers[10] = { 10001, 10002, 10003 };
    //These are pins for accounts
    int accountPins[10] = { 112, 113, 114 };
    //This is the amount in each account 
    double accountBalances[10] = { 20000.0, 30000.0, 40000.0 };
    //These are the CNIC for each account 
    long long accountCnics[10] = { 1234567890123, 2345678901234, 3456789012345 };  
    int totalAccounts = 3;
    
    cout << "Welcome to Z-SAT Bank!" << endl;//This is welcoming phrase

    int mainOption;

    do {
        //This is the main menu
        cout << "--- Main Menu ---" << endl;
        cout << "1. Use ATM" << endl;
        cout << "2. Account Creation" << endl;
        cout << "3. Account Management" << endl;
        cout << "4. Currency Converter" << endl;
        cout << "5. Check Loan Eligibility" << endl;
        cout << "6. Chatbot Assistance" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainOption;
        
        //The ATM:
        //It will gave you three attempts to enter you pin
        if (mainOption == 1) {

            int enteredAccountNumber, enteredPin, attempts = 3, accountIndex = -1;

            cout << "--- Login to ATM ---" << endl;
            cout << "Enter your account number (use any of these=10001, 10002, 10003): ";
            cin >> enteredAccountNumber;

            if (enteredAccountNumber==10001) {
                cout << "Your pin will be "<<accountPins[0] << endl;
            }
            if (enteredAccountNumber == 10002) {
                cout << "Your pin will be "<< accountPins[1] << endl;
            }
            if (enteredAccountNumber == 10003) {
                cout << "Your pin will be 114 "<< accountPins[2] << endl;
            }

            for (int i = 0; i < totalAccounts; i++) {
                if (enteredAccountNumber == accountNumbers[i]) {
                    accountIndex = i;
                    break;
                }
            }

            if (accountIndex == -1) {
                cout << "----\nInvalid account number. Returning to main menu...\n----" << endl;
                continue;
            }

            cout << "Enter your PIN: ";
            while (attempts > 0) {
                cin >> enteredPin;
                if (enteredPin == accountPins[accountIndex]) {
                    cout << "----\nPIN verified successfully!\n----" << endl;
                    break;
                }
                else {
                    attempts--;
                    cout << "----\nIncorrect PIN. You have \n" << attempts << " attempt(s) left.----" << endl;
                }
                if (attempts == 0) {
                    cout << "----\nToo many incorrect attempts. Returning to main menu...\n----" << endl;
                    continue;
                }
            }
            //Inside of ATM:

            int atmOption;
            do {
                cout << "--- ATM Menu ---" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit" << endl;
                cout << "3. Withdraw" << endl;
                cout << "4. Exit ATM" << endl;
                cout << "Enter your option: ";
                cin >> atmOption;

                switch (atmOption) {
                case 1:
                    cout << "----Your current balance is: Rs " << accountBalances[accountIndex]<<"----" << endl;
                    break;

                case 2:
                {
                    double depositAmount;
                    cout << "Enter deposit amount: Rs ";
                    cin >> depositAmount;
                    if (depositAmount > 0) {
                        accountBalances[accountIndex] += depositAmount;
                        cout << "----Deposit successful! Your new balance is: Rs " << accountBalances[accountIndex]<<"----" << endl;
                    }
                    else {
                        cout << "----Invalid amount. Deposit failed.----" << endl;
                    }
                }
                break;

                case 3:
                {
                    double withdrawAmount;
                    cout << "Enter withdrawal amount: Rs ";
                    cin >> withdrawAmount;
                    if (withdrawAmount > 0 && withdrawAmount <= accountBalances[accountIndex]) {
                        accountBalances[accountIndex] -= withdrawAmount;
                        cout << "----Withdrawal successful! Your new balance is: Rs " << accountBalances[accountIndex]<<"----" << endl;
                    }
                    else if (withdrawAmount > accountBalances[accountIndex]) {
                        cout << "----Insufficient balance.----" << endl;
                    }
                    else {
                        cout << "----Invalid amount. Withdrawal failed.----" << endl;
                    }
                }
                break;

                case 4:
                    cout << "----Exiting ATM. Returning to main menu...----" << endl;
                    break;

                default:
                    cout << "----Invalid option. Try again.----" << endl;
                }
            } while (atmOption != 4);
        }
        //This is account creation option:
        //Maximum 9 account can be created in our bank
        else if (mainOption == 2) {

            if (totalAccounts < 10) {
                char newName;
                double newIncome;
                long long newCnic; 

                cout << "--- Create New Account ---" << endl;
                cout << "Enter your name (first letter only): ";
                cin >> newName;

                cout << "Enter your monthly income: Rs ";
                cin >> newIncome;

                
                bool validCnic = false;
                while (!validCnic) {
                    cout << "----Enter your CNIC (13 digits without dashes): ----";
                    cin >> newCnic;

                    long long tempCnic = newCnic;
                    int digitCount = 0;

                    
                    while (tempCnic > 0) {
                        tempCnic /= 10;
                        digitCount++;
                    }

                    if (digitCount == 13) {
                       
                        bool isUnique = true;
                        for (int i = 0; i < totalAccounts; i++) {
                            if (accountCnics[i] == newCnic) {
                                isUnique = false;
                                break;
                            }
                        }
                        if (isUnique) {
                            validCnic = true;
                        }
                        else {
                            cout << "----CNIC already exists. Please try again.----" << endl;
                        }
                    }
                    else {
                        cout << "----Invalid CNIC. CNIC must be exactly 13 digits. Please try again.----" << endl;
                    }
                }

                int newAccountNumber = 10000 + totalAccounts + 1;
                int newPin = 112 + totalAccounts;

                accountNumbers[totalAccounts] = newAccountNumber;
                accountPins[totalAccounts] = newPin;
                accountNames[totalAccounts] = newName;
                accountBalances[totalAccounts] = 0;
                accountCnics[totalAccounts] = newCnic;

                totalAccounts++;

                cout << "Account created successfully!" << endl;
                cout << "Your account number is: " << newAccountNumber << endl;
                cout << "Your PIN is: " << newPin << endl;
            }
            else {
                cout << "----Account limit reached. Cannot create more accounts.----" << endl;
            }
        }
        //Account management option:
        //We can do alot funtions there
        if (mainOption == 3) {

            int enteredAccountNumber, enteredPin, accountIndex = -1;

            cout << "--- Account Management ---" << endl;
            cout << "Enter your account number (use any of these=10001, 10002, 10003): ";
            cin >> enteredAccountNumber;
            if (enteredAccountNumber == 10001) {
                cout << "Your pin will be " << accountPins[0] << endl;
            }
            if (enteredAccountNumber == 10002) {
                cout << "Your pin will be " << accountPins[1] << endl;
            }
            if (enteredAccountNumber == 10003) {
                cout << "Your pin will be 114 " << accountPins[2] << endl;
            }
            for (int i = 0; i < totalAccounts; i++) {
                if (enteredAccountNumber == accountNumbers[i]) {
                    accountIndex = i;
                    break;
                }
            }

            if (accountIndex == -1) {
                cout << "----Invalid account number. Returning to main menu...----" << endl;
                continue;
            }

            cout << "Enter your PIN: ";
            cin >> enteredPin;

            if (enteredPin != accountPins[accountIndex]) {
                cout << "----Invalid PIN. Returning to main menu...----" << endl;
                continue;
            }

            int accountManagementOption;
            do {
                cout << "--- Account Management Menu ---" << endl;
                cout << "1. View Account Details" << endl;
                cout << "2. Change PIN" << endl;
                cout << "3. Delete Account" << endl;
                cout << "4. Exit Account Management" << endl;
                cout << "Enter your option: ";
                cin >> accountManagementOption;

                switch (accountManagementOption) {
                case 1:
                    cout << "--- Account Details ---" << endl;
                    cout << "Name: " << accountNames[accountIndex] << endl;
                    cout << "Account Number: " << accountNumbers[accountIndex] << endl;
                    cout << "Account PIN: " << accountPins[accountIndex] << endl;
                    cout << "Balance: Rs " << accountBalances[accountIndex] << endl;
                    cout << "CNIC: " << accountCnics[accountIndex] << endl;
                    break;

                case 2:
                {
                    int newPin;
                    cout << "----Enter new PIN:---- ";
                    cin >> newPin;
                    accountPins[accountIndex] = newPin;
                    cout << "----PIN changed successfully!----" << endl;
                }
                break;

                case 3: 
                {
                    char confirmation;
                    cout << "----Are you sure you want to delete this account? (y/n):---- ";
                    cin >> confirmation;
                    if (confirmation == 'y' || confirmation == 'Y') {
                        
                        for (int i = accountIndex; i < totalAccounts - 1; i++) {
                            accountNames[i] = accountNames[i + 1];
                            accountNumbers[i] = accountNumbers[i + 1];
                            accountPins[i] = accountPins[i + 1];
                            accountBalances[i] = accountBalances[i + 1];
                            accountCnics[i] = accountCnics[i + 1];
                        }
                        totalAccounts--;
                        cout << "----Account deleted successfully!----" << endl;
                        accountManagementOption = 4; 
                    }
                    else {
                        cout << "----Account deletion cancelled.----" << endl;
                    }
                }
                break;

                case 4:
                    cout << "----Exiting Account Management.----" << endl;
                    break;

                default:
                    cout << "----Invalid option. Try again.----" << endl;
                }
            } while (accountManagementOption != 4);
        }

        else if (mainOption == 4) {
            double amount;
            int currencyOption;

            cout << "--- Currency Converter ---" << endl;
            cout << "Select the currency you want to convert from:" << endl;
            cout << "1. USD (US Dollar)" << endl;
            cout << "2. EUR (Euro)" << endl;
            cout << "3. GBP (British Pound)" << endl;
            cout << "4. INR (Indian Rupee)" << endl;
            cout << "Enter your choice: ";
            cin >> currencyOption;

            cout << "Enter the amount to convert: ";
            cin >> amount;

            double conversionRate;
            switch (currencyOption) {
            case 1:
                conversionRate = 160.0; 
                cout << amount << " ----USD is equal to " << amount * conversionRate << " PKR----" << endl;
                break;
            case 2:
                conversionRate = 175.0; 
                cout << amount << "---- EUR is equal to " << amount * conversionRate << " PKR----" << endl;
                break;
            case 3:
                conversionRate = 200.0; 
                cout << amount << "---- GBP is equal to " << amount * conversionRate << " PKR----" << endl;
                break;
            case 4:
                conversionRate = 2.2; 
                cout << amount << " ----INR is equal to " << amount * conversionRate << " PKR----" << endl;
                break;
            default:
                cout << "----Invalid option!----" << endl;
            }
        }

        else if (mainOption == 5) {
            double income;
            int age;

            cout << "--- Loan Eligibility ---" << endl;
            cout << "Enter your monthly income: Rs ";
            cin >> income;
            cout << "Enter your age: ";
            cin >> age;

            if (income >= 30000 && age > 19) {
                cout << "----You are eligible for a loan.----" << endl;
            }
            else {
                cout << "----You are not eligible for a loan. For eligibility you must be over 20 years old with 30000 or more income.----" << endl;
            }
        }

        else if (mainOption == 6) {
            int chatbotOption;
            do {
                cout << "--- Chatbot Assistance ---" << endl;
                cout << "Hello! How can I assist you today?" << endl;
                cout << "1. What is Z-SAT Bank?" << endl;
                cout << "2. How to create a new account?" << endl;
                cout << "3. How to check loan eligibility?" << endl;
                cout << "4. What is an ATM?" << endl;
                cout << "5. How to check your balance?" << endl;
                cout << "6. How to change your PIN?" << endl;
                cout << "7. Exit Chatbot" << endl;
                cout << "Enter your choice: ";
                cin >> chatbotOption;

                switch (chatbotOption) {
                case 1:
                    cout << "----Z-SAT Bank is a reliable and efficient banking service offering a variety of services...----" << endl;
                    break;
                case 2:
                    cout << "----To create a new account, visit the bank and provide necessary details like your name and monthly income.----" << endl;
                    break;
                case 3:
                    cout << "----Loan eligibility is based on income and age. A minimum income of Rs 30,000 and minimum age of 20 or more is required.----" << endl;
                    break;
                case 4:
                    cout << "----ATM stands for Automated Teller Machine, which allows you to perform basic banking transactions...----" << endl;
                    break;
                case 5:
                    cout << "----To check your balance, simply use the ATM or log in to your online banking account.----" << endl;
                    break;
                case 6:
                    cout << "----To change your PIN, go to the account management section in the ATM or online banking.----" << endl;
                    break;
                case 7:
                    cout << "----Goodbye! Thank you for using the chatbot.----" << endl;
                    break;
                default:
                    cout << "----Invalid option. Try again.----" << endl;
                }
            } while (chatbotOption != 7);
        }

    } while (mainOption != 7);

    cout << "****Thank you for using Z-SAT Bank! Goodbye.****" << endl;

    return 0;
}