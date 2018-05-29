#pragma once
#include <iostream>
#include <string>
using namespace std;

class Duck {
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck :public Duck {
public:
	void quack() {
		cout << "MallardDuck quack!" << endl;
	}

	void fly() {
		cout << "MallardDuck fly!" << endl;
	}
};

class Turkey {
public:
	void gobble(){
		cout << "Turkey gobble!" << endl;
	}

	void flyShort() {
		cout << "Turkey fly!" << endl;
	}
};

class TurkeyAdapter :public Duck {
public:
	void quack() {
		turkey->gobble();
	}

	void fly() {
		turkey->flyShort();
	}

private:
	Turkey* turkey;
};