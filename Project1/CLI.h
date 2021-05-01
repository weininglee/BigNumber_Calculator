#pragma once

#include <iostream>
#include <string>
#include <strstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CLI {
	const string prefix = ">>> ";
public:
	void start() {
		run_once();
		loop();
	}
	void run_once() {
		cout << "Big Number Calculatot CLI" << endl
			<< prefix;
	}
	void loop() {
		string cmd;
		while (getline(cin, cmd)) {
			/*cout << cmd << endl;*/
			std::strstream ci;
			ci << cmd;
			Integer a, b;
			ci >> a >> b;
			cout << "+= " << a + b << endl 
				<< "-= " << a - b << endl 
				<< "*= " << a * b << endl
				<< "/= " << a / b << endl;
			
			cout << prefix;
		}
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
