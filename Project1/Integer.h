#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NumberObject.h"

using std::string;
using std::vector;
using std::istream;
using std::ostream;

class Integer : public NumberObject {
public:
	
	vector<int> Int;
	int flag = 1;

	Integer();
	Integer(string);
	Integer(Integer&);
	Integer(Integer&&);
	
	Integer operator+(Integer plusInt);
	Integer operator-(Integer diffInt);
	Integer operator*(Integer multiInt);
	Integer operator/(Integer divInt);
	Integer operator%(Integer remDec);
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
	Integer operator-();
	friend istream& operator>>(istream&, Integer&);
	friend ostream& operator<<(ostream&, Integer);

	static Integer factorial(Integer fac);
	static Integer powor(Integer lower, Integer upper);

	static bool test();
};

