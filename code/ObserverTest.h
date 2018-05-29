#pragma once
#include "ObserverPattern.h"

void ObserverTest() {
	Subject* subject = new ConcreteSubject();
	Observer* o = new ConcreteObserver(subject);
	for (int i = 0; i < 5; ++i) {
		subject->stateChanged();
	}
}