//
// Created by 40745 on 28/05/2024.
//

#ifndef TESTQT_TIMEINTERVAL_H
#define TESTQT_TIMEINTERVAL_H

#include <string>

using namespace std;
class TimeInterval {

public:
    int start, end, temperature, precipitation;
    string description;
    TimeInterval(int start, int end, int temperature, int precipitation, string description);

};


#endif //TESTQT_TIMEINTERVAL_H
