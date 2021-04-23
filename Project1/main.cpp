#define TEST

#include <iostream>
#include <map>
#include <string>
#include "BigNum.h"
#include "CLI.h"

using namespace std;

bool test() {
	map<string, bool(*)()> tests{
		{"Integer" , &(Integer::test)},
		{"Decimal" , &(Decimal::test)}
	};
	bool test_pass = true;
	for (const auto& f : tests) {
		if (!(*f.second)()) {
			cout << "Test " << f.first << " fail." << endl;
			test_pass = false;
		}
	}
	return test_pass;
}

int main() {

#ifdef TEST
	if (test()) {
		cout << "Test pass." << endl;
	}
	else {
		cout << "Test fail." << endl;
	}
	cout << endl;
#endif // TEST

	CLI cli;
	cli.start();

}

