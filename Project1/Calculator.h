#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BigNum.h"

class Calculator
{
public:
	static int find_closing_parenthesis(string s, int open_index = 0) {
		int c = 0;
		for (int i = open_index + 1; i < s.size(); i++) {
			if (s[i] == '(')c++;
			else if (s[i] == ')') {
				if (c)c--;
				else return i;
			}
		}
		return -1;
	}

	static vector<string> divide(string raw) {
		for (int i = 0; i < raw.size(); i++)if (raw[i] == ' ')raw.erase(i,1);

		if (!raw.size())return vector<string>();
		bool is_operatee = true;
		vector<string> arg_list = {};
		for (int i = 0; i < raw.size();) {
			if (raw[i] == '(') {
				if (!is_operatee)arg_list.push_back("*");
				arg_list.push_back(
					raw.substr(
						i, 
						find_closing_parenthesis(
							raw, 
							i)
						- i + 1
					)
				);
				is_operatee = false;
				i = find_closing_parenthesis(raw, i) + 1;
			}
			else {
				if (is_operatee) {
					if (raw.size() - i - 1 > 7 &&
						(raw.substr(i, 5) == "Power" || raw.substr(i, 5) == "power")) {
						int c = 0,k;
						for (int j = i+6; j < raw.size(); j++) {
							if (raw[j] == '(')c++;
							else if (raw[j] == ',' && c == 0) {
								k = j;
							}
							else if (raw[j] == ')') {
								if (c)c--;
								else {
									arg_list.push_back(
										"((" + raw.substr(i + 6, k - (i + 6)) + ")^(" + raw.substr(k + 1, j - k -1) + "))"
									);
									i = j + 1;
									break;
								};
							}
						}
					}
					else if (raw.size() - i - 1 > 11 &&
						(raw.substr(i, 9) == "Factorial" || raw.substr(i, 9) == "Factorial")) {
						arg_list.push_back("(" + raw.substr(i + 9,
							find_closing_parenthesis(raw, i + 9) - (i + 9) + 1) + "!)");
						i = find_closing_parenthesis(raw, i + 9) + 1;
					}
					else {
						int sign = 1;
						while (raw[i] == '+' || raw[i] == '-') {
							if (raw[i] == '-')sign *= -1;
							i++;
						}
						int c = 0;
						while ((raw[i + c] >= '0' && raw[i + c] <= '9') || raw[i + c] == '.')
						{
							c++;
						}
						arg_list.push_back((sign == -1 ? "-" : "") + raw.substr(i, c));
						i += c;
					}
					is_operatee = false;
				}
				else {
					if (raw[i] == '+' || raw[i] == '-' || raw[i] == '*' ||
						raw[i] == '/' || raw[i] == '^') {
						arg_list.push_back(string{ raw[i] });
						is_operatee = true;
					}
					else if (raw[i] == '!') {
						arg_list.push_back(string{ raw[i] });
					}
					i++;
				}
			}
		}
		return arg_list;
	}
	
	static Integer evaluate(std::string form) {

		vector<string> arg_list = divide(form);
		
		for (auto& i : arg_list)std::cout << i << std::endl;

		return Integer("0");
	}

	static bool is_integer(string s) {
		if (s.empty())return false;
		if (!(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))return false;
		if (s.size() == 1 && !(s[0] >= '0' && s[0] <= '9'))return false;
		for (int i = 1; i < s.size(); i++) {
			if (!(s[i] >= '0' && s[i] <= '9'))return false;
		}
		return true;
	}

	static bool is_decimal(string s) {
		if (s.empty())return false;
		if (!(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))return false;
		if (s.size() == 1 && !(s[0] >= '0' && s[0] <= '9'))return false;

		bool dot_flag = false;
		for (int i = 1; i < s.size(); i++) {
			if (!((s[i] >= '0' && s[i] <= '9')||s[i]=='.'))return false;
			else if (s[i] == '.') {
				if (!dot_flag)dot_flag = true;
				else return false;
			}
		}
		return dot_flag;
	}

	static bool is_num(string s) {
		return is_integer(s) || is_decimal(s);
	}
};

