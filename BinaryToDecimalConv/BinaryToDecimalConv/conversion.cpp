#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void binaryConv(int dNum) { //dNum contains a valid decimal number
	
	int remainder;
	vector<int> bNum;
	int i = 0;

	if (dNum > 0) {

		int temp;
		do { //56
		temp = (dNum % 2);
			if (temp == 0) {
				remainder = dNum / 2;
				dNum = remainder;
				bNum.push_back(temp);
			}
			else if (temp == 1) {
				remainder = (dNum - 1) / 2;
				dNum = remainder;
				bNum.push_back(temp);
			}
			i++;
		} while (dNum != 0);
	}
		for (int j = i; j >= 0; j--) {
			if (j - 1 < 0) {
				return;
			}
			cout << bNum[j-1];
		}
}


void decConv(int bNum) { //bNum contains a valid binary number

	vector<int>dNum;
	
	int iCount = 0;
	int j = 0;
	int remainder;
	int number = bNum;
	int holding = 0;

	do {
		remainder = number % 10;
		number = number - remainder;
		number = number / 10;
		dNum.push_back(remainder);

		iCount++;
	} while (number != 0);

	for (int i = 0; i < iCount; i++) {
		//cout << dNum[i]*2 << "^" << j << " = " << pow((dNum[i]*2), j) << "\n";
		if(dNum[i] != 0)
 		holding += pow((dNum[i]*2), j);
		j++;
	}
	cout << holding << "\n";
}