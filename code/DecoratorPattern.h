#pragma once
#include <iostream>
#include <string>
using namespace std;

class Beverage {
public:
	virtual string getDescription() {
		return description;
	}

	virtual double cost() = 0;

protected:
	string description;
};

class CondimentDecorator :public Beverage {
public:
	virtual string getDescription() = 0;
};

class Espresso :public Beverage {
public:
	Espresso(){
		description = "Espresso";
	}

	double cost() {
		return 1.99;
	}
};

class HouseBlend :public Beverage {
public:
	HouseBlend(){
		description = "HouseBlend";
	}

	double cost() {
		return 0.89;
	}
};

class Mocha :public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Mocha(Beverage* b) :beverage(b) {

	}

	string getDescription() {
		return beverage->getDescription() + ",Mocha";
	}

	double cost() {
		return 0.2 + beverage->cost();
	}
};

class Whip :public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Whip(Beverage* b) :beverage(b) {

	}

	string getDescription() {
		return beverage->getDescription() + ",Whip";
	}

	double cost() {
		return 0.5 + beverage->cost();
	}
};