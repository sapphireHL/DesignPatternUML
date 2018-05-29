#pragma once
#include <iostream>
#include <string>
using namespace std;

class Singleton {
public:
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}

	void hello() {
		cout << "singleton:hello" << endl;
	}

private:
	Singleton() {};

	static Singleton* instance;
};

Singleton* Singleton::instance;