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
	for (const auto& f : tests) {
		cout << "Test " << f.first << " " << ((*f.second)() ? "pass" : "fail") << "." << endl;
	}
	return true;
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

