#pragma once
#include "CompositePattern.h"

void CompositeTest() {
	MenuComponent* menu = new Menu("DinerMenu");
	MenuComponent* submenu = new Menu("SubMenu");
	MenuComponent* submenu2 = new Menu("SubMenu2");
	MenuComponent* item1 = new MenuItem("meat", 20.0);
	MenuComponent* item2 = new MenuItem("fish", 15.0);
	MenuComponent* item3 = new MenuItem("vegetable", 10.0);

	submenu->add(item1);
	submenu2->add(item2);
	menu->add(submenu);
	menu->add(submenu2);
	menu->add(item3);

	Waitress wait(menu);
	wait.printMenu();
}