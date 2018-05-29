#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuComponent {
public:
	virtual void add(MenuComponent*) {};
	virtual void remove(MenuComponent*) {};
	virtual MenuComponent* getChild(int) { return nullptr; };

	virtual string getName() { return string(); };
	virtual void print() {};
};

class MenuItem :public MenuComponent {
private:
	string name;
	double price;
public:
	MenuItem(string n, double p) :name(n), price(p) {

	}

	string getName() {
		return name;
	}

	void print() {
		cout << getName() << "----" << to_string(price) << endl;
	}
};

class Menu :public MenuComponent {
private:
	vector<MenuComponent*> components;
	string name;
public:
	Menu(string n) :name(n) {

	}

	void add(MenuComponent* component) {
		components.push_back(component);
	}

	void remove(MenuComponent* component) {
		auto it = find(components.begin(), components.end(), component);
		if (it != components.end()) {
			components.erase(it);
		}
	}

	MenuComponent* getChild(int index) {
		if (index < components.size()) {
			return components[index];
		}
		return nullptr;
	}

	string getName() {
		return name;
	}

	void print() {
		cout << getName() << endl;
		cout << "----------------------" << endl;
		for (auto it = components.begin(); it != components.end(); ++it) {
			(*it)->print();
		}
	}
};

class Waitress {
public:
	Waitress(MenuComponent* m) :menu(m) {

	}

	void printMenu() {
		menu->print();
	}

private:
	MenuComponent* menu;
};