#pragma once
#include <iostream>
#include <string>
using namespace std;

class Light {
public:
	void on() {
		cout << "Light on!" << endl;
	}

	void off() {
		cout << "light off!" << endl;
	}
};

class Door {
public:
	void open() {
		cout << "Door open!" << endl;
	}

	void close() {
		cout << "Door close!" << endl;
	}
};

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class LightOnCommand :public Command {
public:
	LightOnCommand(Light* li) :light(li) {

	}

	void execute() {
		light->on();
	}

	void undo() {
		light->off();
	}
private:
	Light* light;
};

class LightOffCommand :public Command {
public:
	LightOffCommand(Light* li) :light(li) {

	}

	void execute() {
		light->off();
	}

	void undo() {
		light->on();
	}
private:
	Light* light;
};

class DoorOpenCommand :public Command {
public:
	DoorOpenCommand(Door* doo) :door(doo) {

	}

	void execute() {
		door->open();
	}

	void undo() {
		door->close();
	}
private:
	Door* door;

};

class DoorCloseCommand :public Command {
public:
	DoorCloseCommand(Door* doo) :door(doo) {

	}

	void execute() {
		door->close();
	}

	void undo() {
		door->open();
	}
private:
	Door* door;

};

class RemoteControl {
private:
	Command* onCommand;
	Command* offCommand;
public:
	RemoteControl() :onCommand(nullptr), offCommand(nullptr) {

	}

	void setCommand(Command* onCommand, Command* offCommand) {
		this->offCommand = offCommand;
		this->onCommand = onCommand;
	}

	void onButtonPushed() {
		if (onCommand) {
			onCommand->execute();
		}
	}

	void offButtonPushed() {
		if (offCommand) {
			offCommand->execute();
		}
	}
};