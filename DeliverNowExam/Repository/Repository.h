
#pragma once

#include <vector>
#include <string>
#include "../Domain/Courier.h"
#include "../Domain/Package.h"
#include "../Service/Observer.h"

using namespace std;

class Repository : public Subject {
private:
    vector<Courier> couriers;
    vector<Package> packages;

    void readFromFile();
    void writeToFile();
public:
    Repository();
    vector<Courier> getCouriers();
    vector<Package> getPackages();

    void addPackage(Package aPackage);

    void deliverPackage(string name);
};
