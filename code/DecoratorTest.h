#pragma once
#include "DecoratorPattern.h"
void print(Beverage* coffee) {
	cout << coffee->getDescription() + " $" + to_string(coffee->cost()) << endl;
}

void DecoratorTest() {
	Beverage* coffee = new Espresso();
	print(coffee);
	coffee = new Mocha(coffee);
	print(coffee);
	coffee = new Mocha(coffee);
	print(coffee);
	coffee = new Whip(coffee);
	print(coffee);
}