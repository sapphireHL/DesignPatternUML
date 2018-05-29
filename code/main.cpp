#include <iostream>
#include "StrategyTest.h"
#include "ObserverTest.h"
#include "DecoratorTest.h"
#include "FactoryTest.h"
#include "SingletonTest.h"
#include "CommandTest.h"
#include "AdapterTest.h"
#include "TemplateMethodTest.h"
#include "CompositeTest.h"


using namespace std;


int main() {
	StrategyTest();
	ObserverTest();
	DecoratorTest();
	FactoryTest();
	SingletonTest();
	CommandTest();
	AdapterTest();
	TemplateMethodTest();
	CompositeTest();
	return 0;
}