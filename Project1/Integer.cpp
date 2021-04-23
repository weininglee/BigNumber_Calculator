#include "Integer.h"
using std::reverse;

bool Integer::test() {
	return true;
}

Integer Integer::operator+(Integer plusInt) {
	Integer sum;
	reverse(Int.begin(), Int.end());
	reverse(plusInt.Int.begin(), plusInt.Int.end());

	int plus = 0, index = 0;
	for (index; index < std::min(Int.size(), plusInt.Int.size()); index++) {
		int x = (Int[index] - '0') + (plusInt.Int[index] - '0') + plus; // x = each digit sum

		sum.Int += (char)(x % 10 + '0');
		//cout << (char)(x % 10);
		//cout << sum.num << "";
		plus = x / 10;
	}
	if (Int.size() > plusInt.Int.size()) {
		for (index = plusInt.Int.size(); index < Int.size(); index++) {
			int x = (Int[index] - '0') + plus;
			sum.Int += (char)(x % 10 + '0');
			plus = x / 10;
		}
	}
	else if (Int.size() < plusInt.Int.size()) {
		for (index = Int.size(); index < plusInt.Int.size(); index++) {
			int x = (plusInt.Int[index] - '0') + plus;
			sum.Int += (char)(x % 10 + '0');
			plus = x / 10;
		}
	}
	if (plus) {
		sum.Int += (char)(plus + '0');
	}
	reverse(sum.Int.begin(), sum.Int.end());
	return sum;
}

Integer Integer::operator-(Integer plusInt) {

}

Integer Integer::operator*(Integer plusInt) {

}