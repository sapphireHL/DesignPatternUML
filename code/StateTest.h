#pragma once
#include "StatePattern.h"

void StateTest() {
	GumballMachine* machine = new GumballMachine(3);
	machine->insertQuarter();
	machine->ejectQuarter();
	machine->turnCrank();
	machine->insertQuarter();
	machine->turnCrank();
}