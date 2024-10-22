#pragma once

#include <string>
#include <vector>

using namespace std;

class Courier {
private:
    string name;
    vector<string> streets;
    pair<int, int> zone;
public:
    const vector<string> &getStreets() const;
    void setStreets(const vector<string> &streets);

    const string &getName() const;
    void setName(const string &name);

    const pair<int, int> &getZone() const;
    void setZone(const pair<int, int> &zone);
};