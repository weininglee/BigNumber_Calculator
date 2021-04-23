#pragma once

#include <iostream>

using std::cout;
using std::endl;

class NumberObject {
	virtual bool test() {
		cout << "Not yet implemented." << endl;
		return false;
	};
};