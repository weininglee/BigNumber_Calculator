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

Integer Integer::operator-(Integer plusInt) {

}

Integer Integer::operator*(Integer plusInt) {

}