#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pizza {
protected:
	string name;
public:
	string getName() {
		return name;
	}
};

class NYCheesePizza :public Pizza {
public:
	NYCheesePizza(){
		name = "NYCheesePizza";
	}
};

class ChicagoCheesePizza :public Pizza {
public:
	ChicagoCheesePizza() {
		name = "ChicagoCheesePizza";
	}
};

class PizzaStore {
public:
	void orderPizza() {
		Pizza* pizza = createPizza();
		cout << "order " << pizza->getName() << endl;
	}

	virtual Pizza* createPizza() = 0;
};

class NYPizzaStore :public PizzaStore {
public:
	Pizza* createPizza() {
		Pizza* pizza = new NYCheesePizza();
		return pizza;
	}
};

class ChicagoPizzaStore :public PizzaStore {
public:
	Pizza* createPizza() {
		Pizza* pizza = new ChicagoCheesePizza();
		return pizza;
	}
};