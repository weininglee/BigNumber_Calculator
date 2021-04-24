#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NumberObject.h"

using std::string;
using std::vector;

class Integer : NumberObject {
public:
	static bool test();

	Integer();
	Integer(string);
	Integer(Integer&);

	vector<int> Int;
	int flag;

	Integer operator+(Integer plusInt);
	Integer operator-(Integer diffInt);
	Integer operator*(Integer multiInt);
};

