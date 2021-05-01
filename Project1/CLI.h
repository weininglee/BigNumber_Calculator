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
public:
	void start() {
		run_once();
		while (loop());
	}
	void run_once() {
		cout << "Big Number Calculatot CLI" << endl;
	}
	bool loop() {
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

		return true;
	}
	static bool validate() {
		return true;
	}
};

//含有不合法字元
//
//無意義
//
//冪次須為0.5的倍數
//
//變數名稱不可為關鍵字
//
//數字不可為變數名稱之字首
//
