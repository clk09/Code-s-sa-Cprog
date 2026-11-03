/*
    CPROG 1 - Computer Programming 1
    Chapter IV Activity
    Program: Number Analysis System

    Features:
    1. Calculate factorial
    2. Check if a number is prime
    3. Reverse a number and check if it is a palindrome
    4. Print all prime numbers in a range
    5. Print a number pyramid
    6. Exit the program
*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Reads an integer and validates the input.
int getInteger(string prompt) {
    int number;

    while (true) {
        cout << prompt;

        if (cin >> number) {
            return number;
        }

        cout << "Invalid input! Please enter a whole number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Checks whether a number is prime.
bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i <= number / i; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

// 1. Calculates and displays the factorial.
void calculateFactorial() {
    int number;
    unsigned long long factorial = 1;

    number = getInteger("Enter a number (-10 to 20): ");

    if (number < -10 || number > 20) {
        cout << "Invalid number! Enter a number from -10 to 20.\n";
        return;
    }

    if (number < 0) {
        cout << "Factorial of a negative number (" 
             << number << ") is not defined.\n";
        return;
    }

    for (int i = 1; i <= number; i++) {
        factorial *= i;
    }

    cout << number << "! = " << factorial << endl;
}

// 2. Checks whether a number is prime.
void checkPrime() {
    int number = getInteger("Enter a number: ");

    if (isPrime(number)) {
        cout << number << " is a prime number.\n";
    } else {
        cout << number << " is not a prime number.\n";
    }
}

// 3. Reverses a number and checks if it is a palindrome.
void reverseAndCheckPalindrome() {
    int number = getInteger("Enter a number: ");

    long long original = number;
    long long temp = original;
    long long reversed = 0;
    int sign = 1;

    if (temp < 0) {
        sign = -1;
        temp = -temp;
    }

    while (temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    reversed *= sign;

    cout << "Reversed number: " << reversed << endl;

    if (original >= 0 && original == reversed) {
        cout << number << " is a palindrome.\n";
    } else {
        cout << number << " is not a palindrome.\n";
    }
}

// 4. Prints all prime numbers within a range.
void printPrimeRange() {
    int start, end;

    start = getInteger("Enter the starting number: ");
    end = getInteger("Enter the ending number: ");

    while (start > end) {
        cout << "Invalid range! The starting number must be "
             << "less than or equal to the ending number.\n";

        start = getInteger("Enter the starting number again: ");
        end = getInteger("Enter the ending number again: ");
    }

    cout << "Prime numbers from " << start
         << " to " << end << ":\n";

    bool found = false;

    for (int number = start; ; number++) {
        if (isPrime(number)) {
            cout << number << " ";
            found = true;
        }

        // Stop before the loop counter can overflow.
        if (number == end) {
            break;
        }
    }

    if (!found) {
        cout << "No prime numbers found.";
    }

    cout << endl;
}

// 5. Prints a centered number pyramid.
void printNumberPyramid() {
    int rows = getInteger("Enter number of rows (1-9): ");

    if (rows < 1 || rows > 9) {
        cout << "Invalid number of rows! Enter 1 to 9.\n";
        return;
    }

    for (int i = 1; i <= rows; i++) {

        // Print spaces to center the numbers.
        for (int j = 1; j <= rows - i; j++) {
            cout << "   ";
        }

        // Print numbers in the current row.
        for (int k = 1; k <= i; k++) {
            cout << k << "   ";
        }

        cout << endl;
    }
}

// Displays the main menu.
void displayMenu() {
    cout << "\n================================\n";
    cout << "      NUMBER ANALYSIS SYSTEM\n";
    cout << "================================\n";
    cout << "1. Calculate Factorial\n";
    cout << "2. Check Prime Number\n";
    cout << "3. Reverse Number and Check Palindrome\n";
    cout << "4. Print Prime Numbers in a Range\n";
    cout << "5. Print Number Pyramid\n";
    cout << "6. Exit\n";
    cout << "================================\n";
}

// Main function.
int main() {
    int choice;

    // Repeat the menu until the user selects Exit.
    do {
        displayMenu();

        choice = getInteger("Enter your choice (1-6): ");

        switch (choice) {
            case 1:
                calculateFactorial();
                break;

            case 2:
                checkPrime();
                break;

            case 3:
                reverseAndCheckPalindrome();
                break;

            case 4:
                printPrimeRange();
                break;

            case 5:
                printNumberPyramid();
                break;

            case 6:
                cout << "Thank you for using the program!\n";
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice! Please select 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}