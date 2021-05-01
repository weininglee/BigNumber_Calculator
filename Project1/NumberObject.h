#pragma once
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class NumberObject {
public:
	string type;
	virtual istream& input(istream& is) { return is; }
	virtual ostream& output(ostream& os) { return os; }
	friend istream& operator>>(istream& is, NumberObject& to) { return to.input(is); }
	friend ostream& operator<<(ostream& os, NumberObject from) { return from.output(os); }
	static bool test() { return false; }
};
