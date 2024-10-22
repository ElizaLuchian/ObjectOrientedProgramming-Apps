//
// Created by 40745 on 28/05/2024.
//

#include <algorithm>
#include <fstream>
#include <sstream>
#include "Service.h"

Service::Service() {

}
bool compute(TimeInterval t1, TimeInterval t2)
{
    return(t1.start<t2.start || (t1.start==t2.start && t1.end<t2.end));
}

vector<TimeInterval> Service::getAll() {
    vector<TimeInterval>arr=intervals;
    sort(arr.begin(), arr.end(), compute);
    return arr;

}

void Service::readFromFile() {
    ifstream fileInput("intervals.txt");

    string input;
    while(getline(fileInput, input))
    {
        vector<string> items=split(input, ';');


        TimeInterval t1=TimeInterval(stoi(items[0]),stoi(items[1]), stoi(items[2]), stoi(items[3]), items[4]);

        intervals.push_back(t1);
    }
}

vector<string> Service::split(string linie, char delim) {
    stringstream line{linie};
    string token;
    vector<string>tokens;
    while(getline(line, token, delim))
    {
        tokens.push_back(token);

    }
    return tokens;
}

Service::~Service() {

}

vector<TimeInterval> Service::filter(int precipitation) {
    vector<TimeInterval> arr;
    for(auto el: intervals)
    {
        if(el.precipitation<precipitation)
            arr.push_back(el);
    }
    return arr;
}

int Service::totalHours(string description, int time) {
    int sum=0;
    for(auto el: intervals)
    {
        if(el.description==description && el.end>time)
            sum=sum+ el.end-max(el.start, time);
    }
    return sum;
}

vector<TimeInterval> Service::weatherAndHour(string description, int time) {
    vector<TimeInterval> arr;
    for(auto el: intervals)
    {
        if(el.description==description && el.end>time)
            arr.push_back(el);
    }
    return arr;
}

