#pragma once
#include "AdapterPattern.h"

void AdapterTest() {
	Duck* duck = new MallardDuck();
	duck->quack();
	duck->fly();
	duck = new TurkeyAdapter();
	duck->quack();
	duck->fly();
}