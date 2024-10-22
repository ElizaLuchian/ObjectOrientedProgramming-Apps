#include "Repository.h"
#include <fstream>
#include <sstream>

vector<Courier> Repository::getCouriers() {
    return couriers;
}

vector<Package> Repository::getPackages() {
    return packages;
}

void Repository::readFromFile() {
    ifstream fin("couriers.txt");
    char line[500];
    while(fin.getline(line, 500))
    {
        Courier courier;
        string word;
        stringstream ss(line);

        getline(ss, word, '|');
        courier.setName(word);

        getline(ss, word, '|');
        int center = atoi(word.c_str());

        getline(ss, word, '|');
        int radius = atoi(word.c_str());

        courier.setZone(make_pair(center, radius));

        getline(ss, word, '|');

        stringstream ss2(word);

        vector<string> streets;

        while(getline(ss2, word, ','))
        {
            streets.push_back(word);
        }

        courier.setStreets(streets);

        couriers.push_back(courier);
    }

    ifstream fin2("packages.txt");
    while(fin2.getline(line, 500))
    {
        Package package;
        string word;
        stringstream ss(line);

        getline(ss, word, '|');
        package.setRecipient(word);

        getline(ss, word, '|');
        package.setAddress(word);


        getline(ss, word, '|');
        int x = atoi(word.c_str());

        getline(ss, word, '|');
        int y = atoi(word.c_str());

        package.setLocation(x, y);

        getline(ss, word, '|');
        bool deliveryStatus = atoi(word.c_str());

        package.setDeliveryStatus(deliveryStatus);

        packages.push_back(package);
    }
}

Repository::Repository() {
    readFromFile();
}
//Repository::repository(){}
void Repository::addPackage(Package aPackage) {
    for (auto package : packages)
        if (package.getRecipient() == aPackage.getRecipient())
            return;
    packages.push_back(aPackage);


    writeToFile();
    notify();
}

void Repository::deliverPackage(string name) {
    for (int i = 0; i < packages.size(); ++i)
        if(packages[i].getRecipient() == name)
            packages[i].setDeliveryStatus(true);

    writeToFile();
    notify();
}



void Repository::writeToFile() {
    ofstream fout("packages.txt");
    for (auto package : packages) {
        fout << package.getRecipient() << "|";
        fout << package.getAddress() << "|";
        fout << package.getLocation().first << "|";
        fout << package.getLocation().second << "|";
        auto isDeliveredText = package.isDelivered() ? 1 : 0;
        fout << isDeliveredText << "\n";
    }
}
