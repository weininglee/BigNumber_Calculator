#include "Integer.h"
#include <iostream>

using std::cout;
using std::endl;

Integer::Integer() {
	flag = 1;
	Int.push_back(0);
}

Integer::Integer(string s) {
	flag = 1;
	if (s[0] == '-') {
		flag = -1;
		s = s.substr(1, s.size() - 1);
	}
	if (s[0] == '+') {
		flag = 1;
		s = s.substr(1, s.size() - 1);
	}
	for (auto i = s.rbegin(); i != s.rend(); i++) {
		Int.push_back(*i - '0');
	}
}

Integer::Integer(Integer& from) {
	flag = from.flag;
	Int = from.Int;
}

Integer::Integer(Integer&& from) {
	flag = from.flag;
	Int = from.Int;
}

Integer Integer::operator+(Integer plusInt) {
	
	int plus = 0, index = 0;
	for (index; index < std::min(Int.size(), plusInt.Int.size()); index++) {

		int x = Int[index] + plusInt.Int[index] + plus; // x = each digit sum
		plusInt.Int[index] = x % 10;
		plus = x / 10;
	}
	if (Int.size() > plusInt.Int.size()) {
		for (index = plusInt.Int.size(); index < Int.size(); index++) {
			int x = Int[index] + plus;
			plusInt.Int.push_back(x % 10);
			plus = x / 10;
		}
	}
	else if (Int.size() < plusInt.Int.size()) {
		for (index = Int.size(); index < plusInt.Int.size(); index++) {
			int x = plusInt.Int[index] + plus;
			plusInt.Int[index] = x % 10;
			plus = x / 10;
		}
	}
	if (plus) {
		plusInt.Int.push_back(plus);
	}
	
	return plusInt;
}

Integer Integer::operator-(Integer diffInt) {

	int minus = 0, index = 0;
	if ((*this) > diffInt) {
		flag = 1; // flag = '+'
		for (index; index < diffInt.Int.size(); index++) {
			int x;
			if (Int[index] - diffInt.Int[index] - minus < 0) {
				diffInt.Int[index] = 10 + Int[index] - diffInt.Int[index] - minus; // x = each digit difference
				minus = 1;
			}
			else {
				diffInt.Int[index] = Int[index] - diffInt.Int[index] - minus;
				minus = 0;
			}			
		}

		for (index = diffInt.Int.size(); index < Int.size(); index++) {
			if (Int[index] - minus < 0) {
				diffInt.Int[index] = 10 + Int[index] - minus;
				minus = 1;
			}
			else {
				diffInt.Int[index] = Int[index] - minus;
				minus = 0;
			}
		}
	}
	else if ((*this) < diffInt) {
		flag = -1; // flag = '-'
		for (index; index < Int.size(); index++) {
			if (diffInt.Int[index] - Int[index] - minus < 0) {
				diffInt.Int[index] = 10 + diffInt.Int[index] - Int[index] - minus;
				minus = 1;
			}
			else {
				diffInt.Int[index] = diffInt.Int[index] - Int[index] - minus;
				minus = 0;
			}
		}

		for (index = Int.size(); index < diffInt.Int.size(); index++) {
			if (diffInt.Int[index] - minus < 0) {
				diffInt.Int[index] = 10 + diffInt.Int[index] - minus;
				minus = 1;
			}
			else {
				diffInt.Int[index] = diffInt.Int[index] - minus;
				minus = 0;
			}
		}
	}
	else {
		diffInt.flag = 1;
		diffInt.Int.clear();
		diffInt.Int.push_back(0);
	}

	for (int i = diffInt.Int.size() - 1; i > 0; i--) {

		if (diffInt.Int[i] == 0) {
			diffInt.Int.erase(diffInt.Int.begin() + i);
		}
		else {
			break;
		}
	}

	return diffInt;
}

Integer Integer::operator*(Integer multiInt) {
	Integer product;

	if ((Int.size() == 1 && Int[0] == 0) || (multiInt.Int.size() == 1 && multiInt.Int[0] == 0)) {
		//product.flag = 1;
		//product.Int.push_back(0);
		return product;
	}

	if (flag == multiInt.flag) product.flag = 1;
	else product.flag = -1;

	for (int indextotal = 0; indextotal < Int.size() + multiInt.Int.size() - 2; indextotal++) {
		product.Int.push_back(0);
	}

	for (int indexsecond = 0; indexsecond < multiInt.Int.size(); indexsecond++) {
		for (int index = 0; index < Int.size(); index++) {
			product.Int[index + indexsecond] += (Int[index] * multiInt.Int[indexsecond]);
		}
	}

	int plus = 0;
	for (int indextotal = 0; indextotal < Int.size() + multiInt.Int.size() - 1; indextotal++) {
		int x = (product.Int[indextotal] + plus);
		product.Int[indextotal] = x % 10;
		plus = x / 10;
	}
	
	if (plus) {
		product.Int.push_back(plus % 10);
		plus /= 10;
	}

	return product;
}

Integer Integer::operator/(Integer div) {
	Integer q("0"), a = (*this),one("1");
	int q_flag = flag * div.flag;

	while (a >= div) {
		a -= div;
		q += one;
	}

	q.flag = q_flag;
	return q;
}

bool Integer::operator>(Integer compareInt) {
	if (flag == 1 && compareInt.flag == -1) return true;
	if (flag == -1 && compareInt.flag == 1) return false;
	if (Int.size() > compareInt.Int.size()) return true;
	if (Int.size() < compareInt.Int.size()) return false;

	for (int i = Int.size() - 1; i >= 0; i--) {
		if (Int[i] > compareInt.Int[i]) return true;
		if (Int[i] < compareInt.Int[i]) return false;
	}
	return false; // ==
}

bool Integer::operator<(Integer compareInt) {
	if (flag == 1 && compareInt.flag == -1) return false;
	if (flag == -1 && compareInt.flag == 1) return true;
	if (Int.size() > compareInt.Int.size()) return false;
	if (Int.size() < compareInt.Int.size()) return true;

	for (int i = Int.size() - 1; i >= 0; i--) {
		if (Int[i] > compareInt.Int[i]) return false;
		if (Int[i] < compareInt.Int[i]) return true;
	}
	return false; // ==
}

bool Integer::operator>=(Integer compareInt) {
	if ((*this) < compareInt) return false;
	return true; 
}

bool Integer::operator<=(Integer compareInt) {
	if ((*this) > compareInt) return false;
	return true;
}

bool Integer::operator==(Integer compareInt) {
	if (flag != compareInt.flag) return false;
	if (Int.size() != compareInt.Int.size()) return false;

	for (int i = Int.size() - 1; i >= 0; i--) {
		if (Int[i] != compareInt.Int[i]) return false;
	}

	return true; // ==
}

bool Integer::operator!=(Integer compareInt) {
	if (*this == compareInt) return false;
	return true;
}

Integer& Integer::operator=(Integer& assignInt) {
	flag = assignInt.flag;
	Int = assignInt.Int;
	return *this;
}

Integer& Integer::operator=(Integer&& assignInt) {
	flag = assignInt.flag;
	Int = assignInt.Int;
	return *this;
}

Integer& Integer::operator+=(Integer plusInt) {
	(*this) = (*this) + plusInt;
	return *this;
}

Integer& Integer::operator-=(Integer diffInt) {
	(*this) = (*this) - diffInt;
	return *this;
}

Integer& Integer::operator*=(Integer multiInt) {
	(*this) = (*this) * multiInt;
	return *this;
}

Integer& Integer::operator/=(Integer divInt) {
	(*this) = (*this) / divInt;
	return *this;
}

Integer Integer::factorial(Integer fac) {
	fac.flag = 1;
	Integer plus("1");
	for (Integer count("1"); count < fac; count += plus) {
		fac *= count;
	}
	return fac;
}

Integer Integer::intPowor(Integer lower, Integer upper) {
	//if (lower.flag = -1 && upper.Int[0] % 2 == 0) lower.flag = 1;
	//else lower.flag = -1;
	Integer plus("1");
	Integer multi = lower;
	//multi.flag = 1;
	for (Integer count("1"); count < upper; count += plus) {
	lower *= multi;
	}
	return lower;
}

//integer input
istream& operator>>(istream& in, Integer& to) 
{
	return in;
}


//integer output
ostream& operator>>(ostream& out, Integer to)
{
	return out;
}

bool Integer::test() {
	bool test_pass = true;
	
	// test constructors
	Integer t;
	Integer a("999999999999999999999999999999999999999999999999999999999999999999999999999999999"),
		b("333333333333333333333333333333333333333333333333333333333333333333333333333333333");
	Integer d = a;
	t = Integer("3");

	d += d;
	if (d == a) {
		cout << "copy fail" << endl;
		test_pass = false;
	}
	d = a;

	// test compare
	if (!(a > b)) {
		cout << "> fail" << endl;
		test_pass = false;
	}
	if (!(b < a)) {
		cout << "< fail" << endl;
		test_pass = false;
	}
	if (!(d == a)) {
		cout << "== fail" << endl;
		test_pass = false;
	}
	if (!(a >= b)) {
		cout << ">= fail" << endl;
		test_pass = false;
	}
	if (!(b <= a)) {
		cout << "<= fail" << endl;
		test_pass = false;
	}
	if (!(a != b)) {
		cout << "!= fail" << endl;
		test_pass = false;
	}

	// test assign operator
	d = Integer("10000");
	t = d;
	if (!(t == Integer("10000"))) {
		cout << "= fail" << endl;
		test_pass = false;
	}


	// test operators
	if ((a + b) != Integer("1333333333333333333333333333333333333333333333333333333333333333333333333333333332")) {
		cout << "a + b fail" << endl;
		test_pass = false;
	}
	if ((a - b) != Integer("666666666666666666666666666666666666666666666666666666666666666666666666666666666")) {
		cout << "a - b fail" << endl;
		test_pass = false;
	}
	if ((a * b) != Integer("333333333333333333333333333333333333333333333333333333333333333333333333333333332666666666666666666666666666666666666666666666666666666666666666666666666666666667")) {
		cout << "a * b fail" << endl;
		test_pass = false;
	}
	if (!(a / b == Integer("3") &&
		Integer("5") / Integer("2") == Integer("2"))) {
		cout << "a / b fail" << endl;
		test_pass = false;
	}

	// test factorial
	Integer f("5");
	Integer ffac("120");
	Integer fac = factorial(f);
	if (fac != ffac) {
		cout << "factorial 5! fail" << endl;
		test_pass = false;
	}

	return test_pass;
}