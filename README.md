Note:
This is my first semester project in computer science.

# Z-SAT-Bank-System
Z-SAT Bank System is a console-based C++ project simulating ATM functions like balance inquiry, deposits, withdrawals, CNIC-verified account creation, PIN change, chatbot help, loan checks, and currency conversion using only the iostream library.
✅ Language & Environment
Programming Language: C++

Library Used: #include <iostream> (for console input/output)
Used things:array ,switch,loops,if else 

Project Type: Console-based banking management system

📂 Main Functional Modules
1. Menu System
When the program starts, it displays a main menu with the following options:

markdown
Copy
Edit
1. ATM System
2. Create New Account
3. Manage Account
4. Currency Converter
5. Loan Eligibility
6. ChatBot Assistance
7. Exit
Each option is connected to a specific function in the system. The user is asked to choose a number, and the related functionality runs.

2. ATM System
This is the core of the program where a user logs into their account and performs basic ATM actions.

➤ Login Process
The user must enter:

Account Number

PIN

The system searches the arrays to validate this information.

Users have a maximum of 3 attempts to enter the correct PIN.

➤ After Successful Login
The user can:

Check Balance: Displays the account balance.

Deposit Amount: Asks for an amount and adds it to the balance.

Withdraw Amount: Deducts the amount if sufficient balance is available.

3. Account Creation System
Used to create a new bank account.

➤ Steps:
User enters:

Name

CNIC (must be 13 digits and unique)

Initial deposit amount

The system:

Generates a unique Account Number

Creates a random 4-digit PIN

Stores the data in arrays:

names[10]

cnics[10]

pins[10]

accountNumbers[10]

balances[10]

Maximum of 10 accounts can be created due to array size.

➤ Note: If CNIC is already used, account creation is denied.
4. Account Management System
Allows users to manage existing accounts. Three sub-options:

🔹 A. View All Accounts
Displays full details of all created accounts:

Name

CNIC

Account Number

Balance

PIN (only for debugging or admin view)

🔹 B. Change PIN
User enters CNIC.

If found, system asks for a new PIN and updates it.

🔹 C. Delete Account
User enters CNIC.

If found, the account data is deleted by:

Replacing it with the last account in the array

Decreasing the total count

Confirmation is shown after successful deletion.

5. Currency Converter (Planned Feature)
A future module that will:

Convert local currency (PKR) to foreign currencies (USD, EUR, etc.)

Take amount in PKR and show conversions using fixed or API-based exchange rates.



6. Loan Eligibility Checker (Planned Feature)
A feature that will:

Ask for monthly income and expenses

Calculate if the user is eligible for a loan based on a certain formula or threshold

Display result as:

"Eligible" or "Not Eligible"



7. ChatBot Assistance (Planned Feature)
A simple console chatbot that:

Helps users understand how to use the system

Responds to FAQs like:

"How to create an account?"

"What is the minimum balance?"



🔧 Technical Concepts Used
Concept	Description
Arrays	Store user data: names, CNICs, balances, etc.
Loops (for/while)	Repeating actions like searching for users or showing menu again
If-else statements	Decision making (e.g., PIN check, account found or not)
Functions	Code is divided into multiple functions like atmSystem(), createAccount(), etc.
Switch statement	For handling menu choices efficiently
🔐 Security Features
3 Attempt Lock: After 3 incorrect PIN attempts, user is locked out of ATM system.

CNIC Validation: CNIC must be 13 digits and unique.

Random PIN Generation: Makes each account secure.

🧪 Limitations
No permanent data storage (no file handling or database).

Maximum of 10 users (due to fixed-size arrays).

No encryption or password masking.

No GUI or mouse interaction – all text-based.

🎓 Educational Value
This project is perfect for students learning:

Basic to intermediate C++ concepts

Real-world application of arrays and conditionals

Logical structuring of a multi-feature program

🧾 Example Use Case
Zaq opens the system.

Chooses Option 2 to create a new account.

Enters:

Name: Zaq

CNIC: 1234512345123

Deposit: 1000

Gets:

Account Number: 10001

PIN: 3256

Now chooses Option 1 (ATM System).

Logs in with Account 10001 and PIN 3256.

Chooses to check balance, deposit more, or withdraw.
