#include "Courier.h"

const vector<string> &Courier::getStreets() const {
    return streets;
}

void Courier::setStreets(const vector<string> &streets) {
    Courier::streets = streets;
}

const string &Courier::getName() const {
    return name;
}

void Courier::setName(const string &name) {
    Courier::name = name;
}

const pair<int, int> &Courier::getZone() const {
    return zone;
}

void Courier::setZone(const pair<int, int> &zone) {
    Courier::zone = zone;
}
