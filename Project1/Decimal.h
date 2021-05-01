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

	Decimal operator+(Decimal);
	Decimal operator-(Decimal);
	Decimal operator*(Decimal);
	Decimal operator/(Decimal);
	Decimal& operator+=(Decimal);
	Decimal& operator-=(Decimal);
	Decimal& operator*=(Decimal);
	Decimal& operator/=(Decimal);
	Decimal operator-();
	Decimal& operator=(Decimal&);
	Decimal& operator=(Decimal&&);
	bool operator>(Decimal);
	bool operator<(Decimal);
	bool operator>=(Decimal);
	bool operator<=(Decimal);
	bool operator==(Decimal);
	bool operator!=(Decimal);
	friend istream& operator>>(istream& is, Decimal& to) { return is; }
	friend ostream& operator<<(ostream& os, Decimal from) { return os; }
	
	bool is_int();
	void simplefy(); // ¬ù¤À

	static Decimal factorial(Decimal);
	static Decimal power(Decimal, Decimal);

	static bool test() { return false; }
};