// BinaryToDecimalConv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//Decimal to Binary functions
void binaryConv(int);
void decConv(int);

//Binary to Decimal functions
bool numCheck(int);
void choice(char);

int main()
{
    char option;
    cout << "Please select one of the following options: \n B) decimal to binary \n D) binary to decimal\n";
    cin >> option;

    choice(option);
}