# BankersAlgorithm

This project includes a C++ implementation of the Banker's Algorithm for deadlock avoidance. This implementation is meant to determine whether a system is in a deadlocked state through the input of a text file showing the current state.

## Requirements
- Linux environment (Testing was done on Ubuntu in VirtualBox)
- GCC Compiler
- Terminal

## Usage & Installation

1. Clone the repository OR download the files by navigating to the folder titled "C++"
2. Open the folder in your Linux terminal
3. Make sure to have GCC up to date (gcc --version)
4. Compile using a command:
  - gcc bankersalgorithm.cpp
5. Input the name of the input file you would like to use
  - ex: `input.txt` or `input-2.txt`
  - Do not include quotation marks
6. Success!

## What this program is intended to do
The banker's algorithm is a deadlock avoidance algorithm. It is based on the real-world banking system, taking inspiration on how they decide whether to grant a loan or not. The idea is that there are N account holders at a bank, and the sum of all of their money is S. Every time a loan is granted, they subtract the loan amount from the total money the bank has. If the resulting value is greater than S, that means they have enough money to grant the loan even if all of the account holders draw out their money.

In regards to operating systems, the banker's algorithm must decide when they can or can not lend out a resource to a process or processes. Since there are limited resources in the system, the system is in an unsafe state if the needed resources are greater than the available resources. In terms of the bank, the money being requested exceeds the amount the bank has in its possession.

In order to avoid this in this particular implementation, the 
