#include "Package.h"

const string &Package::getRecipient() const {
    return recipient;
}

void Package::setRecipient(const string &recipient) {
    Package::recipient = recipient;
}

const string &Package::getAddress() const {
    return address;
}

void Package::setAddress(const string &address) {
    Package::address = address;
}

const pair<int, int> &Package::getLocation() const {
    return location;
}

void Package::setLocation(const int x, const int y) {
    Package::location = make_pair(x, y);
}

bool Package::isDelivered() const {
    return deliveryStatus;
}

void Package::setDeliveryStatus(bool deliveryStatus) {
    Package::deliveryStatus = deliveryStatus;
}

string Package::toString() {
    auto deliveredText = deliveryStatus == false ? "undelivered" : "delivered";

    return recipient + " | " + address + " | " + to_string(location.first) + " - " + to_string(location.second) + " | " + deliveredText;
}
