#pragma once
#include "StrategyPatern.h"

void StrategyTest() {
	Character* king = new King(), *queen = new Queen(), *knight = new Knight(), *troll = new Troll();
	king->fight();
	queen->fight();
	knight->fight();
	troll->fight();
}