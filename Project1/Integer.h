#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NumberObject.h"

using std::string;
using std::vector;

class Integer : NumberObject {
public:
	
	vector<int> Int;
	int flag = 1;

	Integer();
	Integer(string);
	Integer(Integer&);

	
	Integer operator+(Integer plusInt);
	Integer operator-(Integer diffInt);
	Integer operator*(Integer multiInt);
	Integer operator/(Integer divInt);
	bool operator>(Integer compareInt);
	bool operator<(Integer compareInt);
	bool operator>=(Integer compareInt);
	bool operator<=(Integer compareInt);
	bool operator==(Integer compareInt);
	bool operator!=(Integer compareInt);
	Integer& operator+=(Integer plusInt);
	Integer& operator-=(Integer diffInt);
	Integer& operator*=(Integer multiInt);
	Integer& operator/=(Integer Int);
	Integer& operator=(Integer& assignInt);
	Integer& operator=(Integer&& assignInt);
	//friend istr


	static bool test();
};

