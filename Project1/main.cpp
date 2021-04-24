#define TEST

#include <iostream>
#include <map>
#include <string>
#include "BigNum.h"
#include "CLI.h"

using namespace std;

bool test() {
	bool test_pass = true;

	if (!Integer::test()) {
		cout << "Test Integer fail." << endl;
		test_pass = false;
	}
	if (!Decimal::test()) {
		cout << "Test Decimal fail." << endl;
		test_pass = false;
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

