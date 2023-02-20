#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void binaryConv(int dNum) { //dNum contains a valid decimal number
	
	int remainder;
	vector<int> bNum; //Uses a vector to store the decimal number in a stack to be displayed as a binary number later. (LIFO)
	int i = 0;

	if (dNum > 0) {

		int temp; //Used to hold and modify the value of dNum without changing dNum
		do {
		temp = (dNum % 2); //Sets temp to the modulo of dNum and 2
			if (temp == 0) { //If temp is 0 then set the remainder to half of dNum (i.e. dNum == 4, 4%2 == 0, then remainder = 4/2, remainder = 2)
				remainder = dNum / 2;
				dNum = remainder;
				bNum.push_back(temp); //Pushes the bit (value 0) of the binary value into the stack.
			}
			else if (temp == 1) { //Similar functionality as the above if statement, but stores 1 instead of 0.
				remainder = (dNum - 1) / 2;
				dNum = remainder;
				bNum.push_back(temp); //Pushes the bit (value 0) of the binary value into the stack.
			}
			i++; //this i++ is used to keep track of the length of the binary version for output purposes in the for loop on line 31
		} while (dNum != 0);
	}
		for (int j = i; j >= 0; j--) { //Sets j to the value of i (i being the number of bits in the binary number created) and loops until j is not greater than or equal to 0.
			if (j - 1 < 0) {
				return; //I am writing this note late at night and several weeks after I have written this for loop, I have no idea why this specific return is necessary, but the program crashes after converting without it lol
			}
			cout << bNum[j-1]; //This outputs the binary bit value (0 or 1) held in the jth place of the stack.
		}
}


void decConv(int bNum) { //bNum contains a valid binary number

	vector<int>dNum; //Holds the binary number in order to convert it to a decimal 
	
	int iCount = 0; //Keeps track of how many times a bit has been stored in the queue
	int j = 0; //j is used to hold the value we want to put the binary bit to the power of.
	int remainder; //remainder holds the bit when we're seperating each bit for conversion.
	int number = bNum; //number holds the binary number
	int holding = 0; //holding is used to hold the decimal number as the binary number is converted.

	do { //Puts each bit from the binary number into a queue using modulo to take each individual bit
		remainder = number % 10; //Takes the remainder of
		number = number - remainder; //Subtracts the remainder (1 or 0) from the number (We've already stored the bit in remainder)
		number = number / 10; //Divides the number by 10 (won't lose any bits due to the above subtraction)
		dNum.push_back(remainder); //Pushes the remainder into the queue for later conversion.

		iCount++;
	} while (number != 0);

	for (int i = 0; i < iCount; i++) { //For every time a bit was stored holding (starts at 0) will add (bit value * 2) to the power of j (number of times the for loop has run) to itself
		if(dNum[i] != 0) //Unless dNum[i] is 0, otherwise skip to j++
 		holding += pow((dNum[i]*2), j);
		j++;
	}
	cout << holding << "\n"; //Outputs the final decimal value.
}