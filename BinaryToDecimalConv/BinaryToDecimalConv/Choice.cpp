#include <iostream>
#include "Header.h"

using namespace std;


void choice(char option) {
    int num;
    int i = 0;
    char newOp;

	if (option == 'b' || option == 'B') { //Convert from decimal to binary
             cout << "Please provide a decimal: \n";
             cin >> num;
             if (cin.fail()) { //If the provided "number" is not actually a number (i.e. a char). Don't need to check if it's a decimal because every binary number is also a decimal number
                 do {
                     cin.clear();
                     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                     cout << "Please provide a valid decimal number:\n";
                     cin >> num;
                     cout << "\n";
                 } while (cin.fail() != false);
             }
             cout << "\n\nThe number " << num << " is: ";
             binaryConv(num);
             cout << " in binary.";
             cout << "\nWould you like to enter another number? Y / N\n";
             cin >> option;
             if (option != 'Y' && option != 'y' && option != 'N' && option != 'n') {
                 do {
                     cout << "Please enter a valid choice: Y or N\n\n";
                     cin >> option;
                     cout << "\n";
                 } while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');
             }
             if (option == 'N' || option == 'n') {
                 cout << "\n\nEnding program...";
                 return;
             }
             else if (option == 'Y' || option == 'y') {
                 cout << "Please select one of the following options: \n B) decimal to binary \n D) binary to decimal\n";
                 cin >> newOp;
                 choice(newOp);
             }
	}
	else if (option == 'd' || option == 'D') { //convert from binary to decimal
        cout << "Please provide a binary number: \n";
        cin >> num;
        if (cin.fail()) { //If the provided "number" is not a number (i.e. a char)
            do {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Please provide a valid binary number:\n";
                cin >> num;
                cout << "\n";
            } while (cin.fail() != false);
        }
        do {
            if (numCheck(num) == true) { //If the provided number is not a binary number (i.e. decimal)
                cout << num << " in binary is ";
                decConv(num);
            }
            else { //Prompts the user for a valid binary number if a non-binary number was detected
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "You have provided a non-binary number please provide a valid binary number:\n";
                cin >> num;
                decConv(num);
                cout << "\n";
            }
            cout << "\nWould you like to enter another number? Y / N\n";
            cin >> option;
            if (option != 'Y' && option != 'y' && option != 'N' && option != 'n') { //Asks the user if they would like to continue, sends them back to option selection if they want to.
                do {
                    cout << "Please enter a valid choice: Y or N\n\n";
                    cin >> option;
                    cout << "\n";
                } while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');
            }
            if (option == 'N' || option == 'n') {
                cout << "\n\nEnding program...";
                return;
            }
            else if (option == 'Y' || option == 'y') {
                cout << "Please select one of the following options: \n B) decimal to binary \n D) binary to decimal\n";
                cin >> newOp;
                choice(newOp);
            }
        } while (numCheck(num) != true);
	}
}