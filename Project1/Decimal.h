#pragma once

#include "NumberObject.h"

class Decimal : NumberObject {
public:

	Integer denominator, numerator;
	//Decimal power;

	Decimal();
	Decimal(string);
	Decimal(Decimal&);

	Decimal operator+(Decimal);
	Decimal operator-(Decimal);
	Decimal operator*(Decimal);
	Decimal operator/(Decimal);
	Decimal operator+=(Decimal);
	Decimal operator-=(Decimal);
	Decimal operator*=(Decimal);
	Decimal operator/=(Decimal);
	Decimal operator-();
	Decimal& operator=(Decimal);
	bool operator>(Decimal);
	bool operator<(Decimal);
	bool operator>=(Decimal);
	bool operator<=(Decimal);
	bool operator==(Decimal);
	bool operator!=(Decimal);
	//friend istream& operator>>(istream&, Decimal&);
	//friend ostream& operator<<(ostream&, Decimal&);
	
	static bool test() { return false; }
};