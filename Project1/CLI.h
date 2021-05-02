#pragma once

#include <iostream>
#include <string>
#include "Calculator.h"
#include "NumberObject.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CLI {
	const string prefix = ">>> ";
	const string unknow_error /*division_zero*/ = "無意義";
	const string  illegal_character = "含有不合法字元";
	const string  Power_error = "冪次須為0.5的倍數";
	const string  variable_error = "變數名稱不可為關鍵字";
//含有不合法字元
//
//無意義
//
//冪次須為0.5的倍數
//
//變數名稱不可為關鍵字
//
//數字不可為變數名稱之字首
public:
	void start() {
		run_once();
		while (loop());
	}
	void run_once() {
		cout << "Big Number Calculatot CLI" << endl;
	}
	bool loop() {
		try {
			cout << prefix;
			string cmd;
			if (!getline(cin, cmd))return false;
			if (validate()) {
				cout << Calculator::evaluate(cmd) << endl;
			}
			else
			{
				cout << "Invalid input." << endl;
			}
		}
		catch (...) {
			cout << unknow_error << endl;
		}

		return true;
	}
	static bool validate() {
		return true;
	}
};

