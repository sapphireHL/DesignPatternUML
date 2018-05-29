#pragma once
#include "Factory.h"

void FactoryTest(){
	PizzaStore* nystore = new NYPizzaStore();
	PizzaStore* cgstore = new ChicagoPizzaStore();
	nystore->orderPizza();
	cgstore->orderPizza();
}