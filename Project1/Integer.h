#pragma once
#include <iostream>
#include <string>
#include "NumberObject.h"

using std::string;

class Integer : NumberObject {
public:
	static bool test();

	Integer();
	Integer(string Int);

	string Int;

	Integer operator+(Integer plusInt);
	Integer operator-(Integer plusInt);
	Integer operator*(Integer plusInt);
};

