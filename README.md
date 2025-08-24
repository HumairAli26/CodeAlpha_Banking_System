# CodeAlpha_Banking_System
This C++ program is a simple bank management system that provides both admin and user functionalities. It uses a struct Account to store customer information such as name, CNIC, account number, PIN, date of birth, balance, and account status. A vector of Account objects serves as the main database for storing multiple user accounts.

For administrators, the system allows creation of new accounts, displaying all existing accounts, searching for an account by CNIC, modifying balances or PINs, and deleting accounts. When creating an account, the system assigns a randomly generated account number and requires PIN confirmation to ensure accuracy. Admins can also deactivate accounts when necessary.

For users, the system provides essential banking services such as depositing money, withdrawing funds, checking account balance, paying bills, transferring money (either within the same bank or to another bank), and deactivating their account. Access is protected through CNIC and PIN verification before a user can perform transactions.

The program includes additional features like bill payments and inter-bank transfers, where the system ensures that users cannot withdraw or transfer more money than their current balance. Error-handling messages guide users when invalid actions are attempted, such as insufficient balance or entering incorrect PINs.

The overall structure is menu-driven, allowing both admins and users to choose actions repeatedly until they exit. Each function is modularized to handle a specific task, making the system easy to extend or maintain.

In summary, this program demonstrates the use of structures, vectors, modular programming, and basic file handling logic (extendable) to implement a functional banking system. It provides a practical example of how object-oriented concepts and user interaction can be applied in financial applications.
