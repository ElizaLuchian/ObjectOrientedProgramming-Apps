#pragma once

#include <vector>

class Observer {
public:
    virtual void update() = 0;
};


class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }
    void notify() {
        for (auto observer : observers)
        {
            observer->update();
        }
    }
};
