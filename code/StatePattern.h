#pragma once
#include <iostream>
#include <string>
#include "GumballMachine.h"
using namespace std;

class State;
class NoQuarterState;
class HasQuarterState;
class SoldState;
class SoldOutState;
class GumballMachine;



class State {
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
};

class NoQuarterState :public State {
private:
	GumballMachine* machine;
public:
	NoQuarterState(GumballMachine* m) :machine(m) {

	}

	void insertQuarter() {
		cout << "you insert a coin" << endl;
		machine->setState(machine->getHasQuarterState());
	}

	void ejectQuarter() {
		cout << "Error" << endl;
	}

	void turnCrank() {
		cout << "Error" << endl;
	}

	void dispense() {
		cout << "Error" << endl;
	}
};

class HasQuarterState :public State {
private:
	GumballMachine* machine;
public:
	HasQuarterState(GumballMachine* m) :machine(m) {

	}

	void insertQuarter() {
		cout << "Error" << endl;
	}

	void ejectQuarter() {
		cout << "coin return" << endl;
		machine->setState(machine->getNoQuarterState());
	}

	void turnCrank() {
		cout << "turn crank" << endl;
		machine->setState(machine->getSoldState());
	}

	void dispense() {
		cout << "Error" << endl;
	}
};

class SoldState :public State {
private:
	GumballMachine* machine;
public:
	SoldState(GumballMachine* m) :machine(m) {

	}

	void insertQuarter() {
		cout << "Error" << endl;
	}

	void ejectQuarter() {
		cout << "Error" << endl;
	}

	void turnCrank() {
		cout << "Error" << endl;
	}

	void dispense() {
		machine->releaseBall();
		if (machine->getCount() > 0){
			machine->setState(machine->getNoQuarterState());
		}
		else {
			machine->setState(machine->getSoldOutState());
		}
	}
};

class SoldOutState :public State {
private:
	GumballMachine* machine;
public:
	SoldOutState(GumballMachine* m) :machine(m) {

	}

	void insertQuarter() {
		cout << "Sold out" << endl;
	}

	void ejectQuarter() {
		cout << "Sold out" << endl;
	}

	void turnCrank() {
		cout << "Sold out" << endl;
	}

	void dispense() {
		cout << "Sold out" << endl;
	}
};

class GumballMachine {
private:
	State* noQuarterState;
	State* hasQuarterState;
	State* soldState;
	State* soldoutState;
	State* state;
	int count = 0;

public:
	GumballMachine(int num) :
		noQuarterState(new NoQuarterState(this)),
		hasQuarterState(new HasQuarterState(this)),
		soldState(new SoldState(this)),
		soldoutState(new SoldOutState(this)),
		state(noQuarterState),
		count(num)
	{

	}

	void insertQuarter() {
		state->insertQuarter();
	}

	void ejectQuarter() {
		state->ejectQuarter();
	}

	void turnCrank() {
		state->turnCrank();
		state->dispense();
	}

	void setState(State* s) {
		state = s;
	}

	void releaseBall() {
		cout << "a ball comes out!" << endl;
		if (count != 0) {
			--count;
		}
	}

	State* getNoQuarterState() { return noQuarterState; }
	State* getHasQuarterState() { return hasQuarterState; }
	State* getSoldState() { return soldState; }
	State* getSoldOutState() { return soldoutState; }
	int getCount() { return count; }
};
