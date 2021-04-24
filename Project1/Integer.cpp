#include "Integer.h"
using std::reverse;

bool Integer::test() {
	return true;
}

Integer Integer::operator+(Integer plusInt) {
	Integer sum;
	
	int plus = 0, index = 0;
	for (index; index < std::min(Int.size(), plusInt.Int.size()); index++) {

		int x = Int[index] + plusInt.Int[index] + plus; // x = each digit sum
		sum.Int.push_back(x % 10);
		plus = x / 10;
	}
	if (Int.size() > plusInt.Int.size()) {
		for (index = plusInt.Int.size(); index < Int.size(); index++) {
			int x = Int[index] + plus;
			sum.Int.push_back(x % 10);
			plus = x / 10;
		}
	}
	else if (Int.size() < plusInt.Int.size()) {
		for (index = Int.size(); index < plusInt.Int.size(); index++) {
			int x = plusInt.Int[index] + plus;
			sum.Int.push_back(x % 10);
			plus = x / 10;
		}
	}
	if (plus) {
		sum.Int.push_back(plus);
	}
	
	return sum;
}

Integer Integer::operator-(Integer diffInt) {
	Integer difference;

	int minus = 0, index = 0;
	if (Int.size() > diffInt.Int.size()) {
		flag = '+';
		for (index; index < diffInt.Int.size(); index++) {
			int x;
			if (Int[index] - diffInt.Int[index] - minus < 0) {
				x = 10 + Int[index] - diffInt.Int[index] - minus; // x = each digit difference
				minus = 1;
			}
			else {
				x = Int[index] - diffInt.Int[index] - minus;
				minus = 0;
			}
			
			difference.Int.push_back(x);
		}

		for (index = diffInt.Int.size(); index < Int.size(); index++) {
			int x;
			if (Int[index] - minus < 0) {
				x = 10 + Int[index] - minus; 
				minus = 1;
			}
			else {
				x = Int[index] - minus;
				minus = 0;
			}

			difference.Int.push_back(x);
		}
	}
	else if (Int.size() < diffInt.Int.size()) {
		flag = '-';
		for (index; index < Int.size(); index++) {
			int x;
			if (diffInt.Int[index] - Int[index] - minus < 0) {
				x = 10 + diffInt.Int[index] - Int[index] - minus;
				minus = 1;
			}
			else {
				x = diffInt.Int[index] - Int[index] - minus;
				minus = 0;
			}

			difference.Int.push_back(x);
		}

		for (index = Int.size(); index < diffInt.Int.size(); index++) {
			int x;
			if (diffInt.Int[index] - minus < 0) {
				x = 10 + diffInt.Int[index] - minus;
				minus = 1;
			}
			else {
				x = diffInt.Int[index] - minus;
				minus = 0;
			}

			difference.Int.push_back(x);
		}
	}
	else {
		for (int i = Int.size() - 1; i > 0; i--) {
			if (Int[i] > diffInt.Int[i]) {
				flag = '+';
				for (index; index < diffInt.Int.size(); index++) {
					int x;
					if (Int[index] - diffInt.Int[index] - minus < 0) {
						x = 10 + Int[index] - diffInt.Int[index] - minus; 
						minus = 1;
					}
					else {
						x = Int[index] - diffInt.Int[index] - minus;
						minus = 0;
					}

					difference.Int.push_back(x);
				}
				break;
			}
			else if (Int[i] < diffInt.Int[i]) {
				flag = '-';
				for (index; index < Int.size(); index++) {
					int x;
					if (diffInt.Int[index] - Int[index] - minus < 0) {
						x = 10 + diffInt.Int[index] - Int[index] - minus;
						minus = 1;
					}
					else {
						x = diffInt.Int[index] - Int[index] - minus;
						minus = 0;
					}

					difference.Int.push_back(x);
				}
				break;
			}
		}
	}

	for (int i = difference.Int.size() - 1; i > 0; i--) {
		if (difference.Int[i] == 0) {
			difference.Int.erase(difference.Int.begin() + i);
		}
		else {
			break;
		}
	}

	return difference;
}

Integer Integer::operator*(Integer multiInt) {
	Integer product;

	return product;
}