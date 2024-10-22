//
// Created by 40745 on 28/05/2024.
//

#ifndef TESTQT_SERVICE_H
#define TESTQT_SERVICE_H


#include <vector>
#include "TimeInterval.h"

class Service {

private:
    vector<TimeInterval> intervals;
public:
    Service();
    vector<TimeInterval> getAll();
    vector<TimeInterval> filter(int precipitation);
    vector<TimeInterval>weatherAndHour(string description, int time);
    int totalHours(string description, int time);
    void readFromFile();
    vector<string> split(string linie, char delim);
    ~Service();
};


#endif //TESTQT_SERVICE_H
