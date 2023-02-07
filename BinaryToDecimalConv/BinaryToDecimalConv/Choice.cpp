#include <iostream>
#include "Header.h"

using namespace std;


void choice(char option) {
    //int bNum;
    int dNum;
    int i = 0;
    char newOp;

	if (option == 'b' || option == 'B') { //Convert from decimal to binary
             cout << "Please provide a decimal: \n";
             cin >> dNum;
             if (cin.fail()) {
                 do {
                     cin.clear();
                     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                     cout << "Please provide a valid decimal number:\n";
                     cin >> dNum;
                     cout << "\n";
                 } while (cin.fail() != false);
             }
             cout << "\n\nThe number " << dNum << " is: ";
             binaryConv(dNum);
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
        cin >> dNum;
        if (cin.fail()) {
            do {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Please provide a valid binary number:\n";
                cin >> dNum;
                cout << "\n";
            } while (cin.fail() != false);
        }
        do {
            if (numCheck(dNum) == true) {
                cout << dNum << " in binary is ";
                decConv(dNum);
            }
            else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "You have provided a non-binary number please provide a valid binary number:\n";
                cin >> dNum;
                cout << "\n";
            }
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
        } while (numCheck(dNum) != true);
	}
}