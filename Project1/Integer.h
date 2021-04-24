#pragma once
#include <iostream>
#include <string>
#include "NumberObject.h"
#include <vector>
using std::string;
using std::vector;

class Integer : NumberObject {
public:
	static bool test();

	Integer();
	Integer(vector<int> Int);

	vector<int> Int;

	Integer operator+(Integer plusInt);
	Integer operator-(Integer diffInt);
	Integer operator*(Integer multiInt);
};

