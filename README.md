# Bank Management System

## Overview
This **Bank Management System** allows users to register, log in, and manage their bank accounts, including making transactions such as sending or depositing money. It provides functionality to track recent transactions, update balances, and perform account-related actions securely. The system is built using C++ with file handling to store user data.

## Features
- **Registration:** Users can create an account by providing their name, age, place of birth, and setting a password.
- **Login:** Users can log in using their name and password. Account details are stored in a text file named after the user.
- **Transaction Management:** Users can send money to other users or deposit money into their account.
- **Balance Tracking:** The system keeps track of the user's balance and ensures that transactions cannot exceed the available balance.
- **Recent Transactions:** The system stores and displays the last three transactions for each user.
- **Data Persistence:** Account information, balance, and transaction history are stored in text files for each user, making the data persistent across sessions.

## Functionalities
### Main Menu Options
Login: Users can log in to their account by entering their name and password.
Register: New users can register by entering their name, age, place of birth, password, and an initial deposit.
Make a Transaction: Logged-in users can perform transactions by sending money to another registered user or depositing money into their own account.
Exit: Exits the system.
### Transaction Options
Send Money: Users can transfer funds to another registered user, provided they have sufficient balance.
Deposit Money: Users can deposit money into their account.
## Account Information
After logging in, users can view their:

Name
Age
Place of Birth
Current Balance
Recent Transactions

## File Structure
Person.h: Header file containing the Person class declaration and function prototypes.
Implementation.cpp: Main implementation file that defines the functionality of the Person class and manages user interactions, file I/O, and transactions.

## Data Storage
Each user has their own file named after them, e.g., John.txt. This file stores:
Password
Age
Place of Birth
Balance
Recent Transactions
