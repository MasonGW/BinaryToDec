#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

bool numCheck(int num) {
	vector<int>givenNum;

	int number = num; //temp holds the original num so we can alter it
	int remainder; //remainder will hold the remaining value after finding the modulo of the given num
	int iCount = 0; //iCount keeps track of the number of iterations it took to completely parse the provided number

		while(number != 0) { //This loop will take the provided number and parse it so that each digit can be placed into a vector and procedurally examined to see if it is a binary number
			remainder = number % 10; //This will find the right most number in the given int.
			givenNum.push_back(remainder); //This stores the remainder into givenNum
			number = number / 10; //This removes the digit from the end of the number
			iCount++;
		}
		for (int i = iCount; i >= 1; i--) {
			//cout << "This is givenNum[" << i - 1 << "] -> " << givenNum[i - 1] << "\n";
			if (givenNum[i - 1] != 1 && givenNum[i - 1] != 0) {
				return false;
			}
		}
		cout << "\n";
		return true;
}

/*
number = 385
385 -> 380 remainder 5
5 is stored in givenNum
380 -> 38
38 -> 30 remainder 8
8 is stored in givenNum's next position
30 -> 3
3 -> 0 remainder 3
3 is stored in givenNum's next position
*/