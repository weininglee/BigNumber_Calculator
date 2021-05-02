#pragma once
#include "Integer.h"
#include "Decimal.h"

struct Number {
	enum { INTEGER, DECIMAL } type;
	union {
		Integer integer;
		Decimal decimal;
	};
	Number(Integer i) {
		type = INTEGER;
		new (&integer) Integer(i);
	}
	Number(Decimal d) {
		type = DECIMAL;
		new (&decimal) Decimal(d);
	}
	Number(Number& n) {
		type = n.type;
		if (n.type == INTEGER) {
			new (&integer) Integer(n.integer);
		}
		else {
			new (&decimal) Decimal(n.decimal);
		}
	}
	Number(Number&& n) {
		type = n.type;
		if (n.type == INTEGER) {
			new (&integer) Integer(n.integer);
		}
		else {
			new (&decimal) Decimal(n.decimal);
		}
	}
	~Number() {
		if(type ==INTEGER)integer.~Integer();
		else decimal.~Decimal();
	};

	Number& operator = (Number& n) noexcept {
		type = n.type;
		if (n.type == INTEGER) {
			decimal.~Decimal();
			new (&integer) Integer(n.integer);
		}
		else {
			integer.~Integer();
			new (&decimal) Decimal(n.decimal);
		}
		return *this;
	}
	Number& operator = (Number&& n) noexcept {
		type = n.type;
		if (n.type == INTEGER) {
			decimal.~Decimal();
			new (&integer) Integer(n.integer);
		}
		else {
			integer.~Integer();
			new (&decimal) Decimal(n.decimal);
		}
		return *this;
	}

	Number operator+(Number a) {
		if (type == INTEGER)return integer + a.integer;
		else return decimal + a.decimal;
	}

	Number operator-(Number a) {
		if (type == INTEGER)return integer - a.integer;
		else return decimal - a.decimal;
	}

	Number operator*(Number a) {
		if (type == INTEGER)return integer * a.integer;
		else return decimal * a.decimal;
	}
	
	Number operator/(Number a) {
		if (type == INTEGER)return integer / a.integer;
		else return decimal / a.decimal;
	}

	friend ostream& operator<<(ostream& os, Number n) {
		if (n.type == Number::INTEGER)os << n.integer;
		else os << n.decimal;
		return os;
	}
};
