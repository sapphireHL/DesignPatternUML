#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Subject;
class Observer;

//观察者
class Observer {
public:
	virtual void update() {};
};

class Subject {
public:
	virtual void registerObserver(Observer* o) {};
	virtual void removeObserver(Observer* o) {};
	virtual void notifyObservers() {};
	virtual void stateChanged() {};
};



class ConcreteObserver : public Observer {
private:
	Subject* data;
public:
	ConcreteObserver(Subject* subjectData) : data(subjectData) {
		data->registerObserver(this);
	}

	void update() {
		cout << "Get new data!" << endl;
	}
};


class ConcreteSubject : public Subject {
private:
	vector<Observer*> observers;
public:
	void registerObserver(Observer* o) {
		observers.push_back(o);
	}

	void removeObserver(Observer* o) {
		auto it = find(observers.begin(), observers.end(), o);
		if (it != observers.end()) {
			observers.erase(it);
		}
	}

	void notifyObservers() {
		for (int i = 0; i < observers.size(); ++i) {
			observers[i]->update();
		}
	}

	//状态已改变
	void stateChanged() {
		notifyObservers();
	}
};

