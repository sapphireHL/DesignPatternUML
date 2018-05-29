#pragma once
#include <iostream>
#include <string>
using namespace std;

class CaffeineBeverage {
public:
	void prepareRecipe() {
		cout << "**********************" << endl;
		cout << "prepare...." << endl;
		boilWater();
		pourInCup();
		brew();
		addCondiments();
	}

	void boilWater() {
		cout << "boil water" << endl;
	}

	void pourInCup() {
		cout << "pour in cup" << endl;
	}

	virtual void brew() {};
	virtual void addCondiments() {};
};

class Coffee :public CaffeineBeverage {
public:
	void brew() {
		cout << "dripping coffee" << endl;
	}

	void addCondiments() {
		cout << "adding sugar and milk" << endl;
	}
};

class Tea :public CaffeineBeverage {
public:
	void brew() {
		cout << "steeping the coffee" << endl;
	}

	void addCondiments() {
		cout << "adding lemon" << endl;
	}
};