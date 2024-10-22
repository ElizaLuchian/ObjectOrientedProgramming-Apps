#include "Service.h"

vector<Courier> Service::getCouriers() {
    return repository->getCouriers();
}

vector<Package> Service::getPackages() {
    return repository->getPackages();
}

void Service::addPackage(Package package) {
    repository->addPackage(package);
}

void Service::deliverPackage(string name) {
    repository->deliverPackage(name);
}
