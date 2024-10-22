//
// Created by 40745 on 23/04/2024.
//

#include <fstream>
#include "Controller.h"
#include "NeonatalUnit.h"
#include "Surgery.h"
#include "Exceptions/AlreadyExistsException.h"
#include <algorithm>

Controller::Controller(): hospitals(0) {

}

vector<HospitalDepartment *> Controller::getAllDepartments() {
    return hospitals;
}

Controller::~Controller() {
for(auto &elem: hospitals)
    delete elem;
}

void Controller::addDepartment(HospitalDepartment *hospital) {
    hospitals.push_back(hospital);
    //throw AlreadyExistsException();

}

vector<HospitalDepartment *> Controller::getEfficientDepartments() {
    vector<HospitalDepartment *> arr;
    for(auto &elem: hospitals)
    {
        if(elem->isEfficient())
            arr.push_back(elem);
    }
    return arr;
}
bool compare(HospitalDepartment* h1, HospitalDepartment *h2)
{
    return(h1->getName()<h2->getName());
}
void Controller::writeToFile(string filename) {
ofstream fout(filename);
    vector<HospitalDepartment *> arr=this->getEfficientDepartments();
    sort(arr.begin(), arr.end(), compare);
for(auto &elem: arr)
    fout<<elem->toString()<<"  " <<"is efficient:  "<<"true"<<"\n";
fout.close();
}

void Controller::generate() {

    NeonatalUnit *n1= new NeonatalUnit("Regina Maria", 100, 10);
    Surgery *s1 = new Surgery("Health Happiness", 200, 50);
    NeonatalUnit *n2= new NeonatalUnit("Beauty of health", 300, 9);


    hospitals.push_back(n1);
    hospitals.push_back(s1);
    hospitals.push_back(n2);

}
