#pragma once
#include <iostream>
using namespace std;

class WeaponBehavior {
public:
	virtual void useWeapon() = 0;
};

class SwordBehavior : public WeaponBehavior {
public:
	void useWeapon() {
		cout << "Using sword!!!" << endl;
	}
};

class BowAndArrowBehavior : public WeaponBehavior {
public:
	void useWeapon() {
		cout << "Using bow and arrow!!!" << endl;
	}
};

class AxeBehavior : public WeaponBehavior {
public:
	void useWeapon() {
		cout << "Using axe!!!" << endl;
	}
};

class KnifeBehavior : public WeaponBehavior {
public:
	void useWeapon() {
		cout << "Using knife!!!" << endl;
	}
};


class Character {
protected:
	WeaponBehavior* weapon;
public:
	virtual void fight() {
		weapon->useWeapon();
	}

	void setWeapon(WeaponBehavior* w) {
		weapon = w;
	}
};

class King : public Character {
public:
	King() {
		weapon = new SwordBehavior();
	}
};

class Queen : public Character {
public:
	Queen() {
		weapon = new BowAndArrowBehavior();
	}
};

class Knight : public Character {
public:
	Knight() {
		weapon = new AxeBehavior();
	}
};

class Troll : public Character {
public:
	Troll() {
		weapon = new KnifeBehavior();
	}
};