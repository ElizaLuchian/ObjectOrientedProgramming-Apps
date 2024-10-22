#pragma once

#include <string>

using namespace std;

class Package {
private:
    string recipient;
    string address;
    pair<int, int> location;
    bool deliveryStatus;
public:
    const string &getRecipient() const;
    void setRecipient(const string &recipient);

    const string &getAddress() const;
    void setAddress(const string &address);

    const pair<int, int> &getLocation() const;
    void setLocation(const int x, const int y);

    bool isDelivered() const;
    void setDeliveryStatus(bool deliveryStatus);

    string toString();
};