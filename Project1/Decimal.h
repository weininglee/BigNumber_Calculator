#pragma once
#include "Integer.h"

class Decimal {
public:

	Integer denominator, numerator, power_denominator, power_numerator;
	int sign;

	Decimal();
	Decimal(string);
	Decimal(Decimal&);
	Decimal(Decimal&&);
	Decimal(Integer&);
	Decimal(Integer&&);

	Decimal operator+(Decimal plusDec);
	Decimal operator-(Decimal diffDec);
	Decimal operator*(Decimal multiDec);
	Decimal operator/(Decimal divDec);
	Decimal operator-();
	Decimal& operator+=(Decimal plusDec);
	Decimal& operator-=(Decimal diffDec);
	Decimal& operator*=(Decimal multiDec);
	Decimal& operator/=(Decimal divDec);
	Decimal& operator=(Decimal& assignDec);
	Decimal& operator=(Decimal&& assignDec);
	bool operator>(Decimal compareDec);
	bool operator<(Decimal compareDec);
	bool operator>=(Decimal compareDec);
	bool operator<=(Decimal compareDec);
	bool operator==(Decimal compareDec);
	bool operator!=(Decimal compareDec);
	friend istream& operator>>(istream& is, Decimal& to);
	friend ostream& operator<<(ostream& os, Decimal from);
	
	bool is_int();
	Decimal& simplefy(); 

	static Decimal factorial(Decimal);
	static Decimal power(Decimal, Decimal);
	static Integer gcd(Integer a, Integer b);

	static bool test();
};