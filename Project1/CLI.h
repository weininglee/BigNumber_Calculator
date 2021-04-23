#pragma once

#include <iostream>
#include <string>

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
			cout << cmd << endl;
			
			cout << prefix;
		}
	}
};