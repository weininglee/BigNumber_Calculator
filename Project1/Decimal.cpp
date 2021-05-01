#include"Decimal.h"
#include<iostream>

Decimal::Decimal() {
	sign = 1;
	numerator.Int.push_back(0);
	denominator.Int.push_back(1);
	power_numerator.Int.push_back(0);
	power_denominator.Int.push_back(1);
}

Decimal::Decimal(string s) {

}

Decimal::Decimal(Decimal& from) {
	sign = from.sign;
	numerator = from.numerator;
	denominator = from.denominator;
	power_numerator = from.power_numerator;
	power_denominator = from.power_denominator;
}

Decimal::Decimal(Decimal&& from) {
	sign = from.sign;
	numerator = from.numerator;
	denominator = from.denominator;
	power_numerator = from.power_numerator;
	power_denominator = from.power_denominator;
}

Decimal::Decimal(Integer& from) {
	sign = from.flag;
	numerator = from;
	denominator = Integer("1");
	power_numerator = from;
	power_denominator = Integer("1");
}

Decimal::Decimal(Integer&& from) {
	sign = from.flag;
	numerator = from;
	denominator = Integer("1");
	power_numerator = from;
	power_denominator = Integer("1");
}

Decimal Decimal::operator+(Decimal plusDec) {
	if (sign == 1 && plusDec.sign == -1) {
		plusDec.sign = 1;
		return (*this) - plusDec;
	}
	else if (sign == -1 && plusDec.sign == 1) {
		Decimal a = (*this);
		a.sign = 1;
		return plusDec - a;
	}
	else if (sign == -1 && plusDec.sign == -1) {
		Decimal a = (*this);
		a.sign = 1;
		plusDec.sign = 1;
		a += plusDec;
		a.sign = -1;
		return a;
	}
	else {
		Decimal a = (*this);
		a.numerator *= plusDec.denominator;
		a.numerator += (plusDec.numerator * (*this).denominator);
		a.denominator *= plusDec.denominator;
		a.simplefy();
		return a;
	}
}

Decimal Decimal::operator-(Decimal diffDec) {
	if (sign == 1 && diffDec.sign == -1) {
		diffDec.sign = 1;
		return (*this) + diffDec;
	}
	else if (sign == -1 && diffDec.sign == -1) {
		Decimal a = (*this);
		a.sign = 1;
		diffDec.sign = 1;
		return diffDec - a;
	}
	else if (sign == -1 && diffDec.sign == 1) {
		Decimal a = (*this);
		a.sign = 1;
		a += diffDec;
		a.sign = -1;
		return a;
	}
	else if ((*this) < diffDec) {
		diffDec -= (*this);
		diffDec.sign = -1;
		return diffDec;
	}
	else {
		Decimal a = (*this);
		a.numerator *= diffDec.denominator;
		a.numerator -= (diffDec.numerator * (*this).denominator);
		a.denominator *= diffDec.denominator;
		a.simplefy();
		return a;
	}
}

Decimal Decimal::operator*(Decimal multiDec) {
	multiDec.sign = (*this).sign * multiDec.sign;
	multiDec.numerator *= (*this).numerator;
	multiDec.denominator *= (*this).denominator;
	multiDec.simplefy();
	return multiDec;
}

Decimal Decimal::operator/(Decimal divDec) {
	divDec.sign = (*this).sign * divDec.sign;
	divDec.numerator = (*this).numerator * divDec.denominator;
	divDec.denominator = (*this).denominator * divDec.numerator;
	divDec.simplefy();
	return divDec;
}

Decimal& Decimal::operator+=(Decimal plusDec) {
	(*this) = (*this) + plusDec;
	return (*this);
}

Decimal& Decimal::operator-=(Decimal diffDec) {
	(*this) = (*this) - diffDec;
	return (*this);
}

Decimal& Decimal::operator*=(Decimal multiDec) {
	(*this) = (*this) * multiDec;
	return (*this);
}

Decimal& Decimal::operator/=(Decimal divDec) {
	(*this) = (*this) / divDec;
	return (*this);
}

Decimal Decimal::operator-() {
	sign = -1;
	return (*this);
}

Decimal& Decimal::operator=(Decimal& assignDec) {
	sign = assignDec.sign;
	numerator = assignDec.numerator;
	denominator = assignDec.denominator;
	power_numerator = assignDec.power_denominator;
	power_denominator = assignDec.power_denominator;
	return *this;
}

Decimal& Decimal::operator=(Decimal&& assignDec) {
	sign = assignDec.sign;
	numerator = assignDec.numerator;
	denominator = assignDec.denominator;
	power_numerator = assignDec.power_denominator;
	power_denominator = assignDec.power_denominator;
	return *this;
}

bool Decimal::operator>(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator > compareDec.numerator * (*this).denominator) return true;
	return false;
}

bool Decimal::operator<(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator < compareDec.numerator * (*this).denominator) return true;
	return false;
}

bool Decimal::operator>=(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator < compareDec.numerator * (*this).denominator) return false;
	return true;
}

bool Decimal::operator<=(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator > compareDec.numerator * (*this).denominator) return false;
	return true;
}

bool Decimal::operator==(Decimal compareDec) {
	if ((*this).numerator * compareDec.denominator == compareDec.numerator * (*this).denominator) return true;
	return false;
}

bool Decimal::operator!=(Decimal compareDec) {
	if ((*this) == compareDec) return false;
	return true;
}

istream& operator>>(istream& is, Decimal& to) { return is; }
ostream& operator<<(ostream& os, Decimal from) { return os; }

bool Decimal::is_int() {
	Integer zero("0");
	if (numerator / denominator == zero) return true;
	return false;
}

void Decimal::simplefy() { // ¬ù¤À
	numerator /= gcd(numerator, denominator);
	denominator /= gcd(numerator, denominator);
}

Integer Decimal::gcd(Integer a, Integer b) {
	Integer zero("0");
	return b == zero ? a : gcd(b, a % b);
}

Decimal Decimal::factorial(Decimal) {

}

Decimal Decimal::power(Decimal lower, Decimal upper) { // upper.denominator = 1 or 2
	Integer one("1");
	Integer multinum = lower.numerator;
	Integer multiden = lower.denominator;
	for (Integer count = upper.numerator; count > one; count -= one) {
		lower.numerator *= multinum;
		lower.denominator *= multiden;
	}

}

bool Decimal::test() { return false; }