#pragma once

#include <vector>
#include <string>
#include "../Repository/Repository.h"

using namespace std;

class Service {
private:
    Repository* repository;
public:
    Service(Repository* _repository) : repository{_repository} {}

    vector<Courier> getCouriers();
    vector<Package> getPackages();

    void addPackage(Package aPackage);


    void deliverPackage(string name);
};

