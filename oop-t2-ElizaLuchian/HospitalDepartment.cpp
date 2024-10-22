//
// Created by 40745 on 23/04/2024.
//

#include "HospitalDepartment.h"

HospitalDepartment::HospitalDepartment(string hospitalName, int numberofDoctors) {
this->hospitalName=hospitalName;
this->numberOfDoctors=numberofDoctors;
}

HospitalDepartment::~HospitalDepartment() {

}

string HospitalDepartment::toString() {
    return " Hospital  name:  " + this->hospitalName + " ; Nr Doctors:  "+ to_string(this->numberOfDoctors);
}

string HospitalDepartment::getName() {
    return this->hospitalName;
}
