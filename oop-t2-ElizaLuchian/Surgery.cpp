//
// Created by 40745 on 23/04/2024.
//

#include "Surgery.h"

Surgery::Surgery(string hospitalName, int numberofDoctors, int numberOfPatients): HospitalDepartment(hospitalName, numberofDoctors) {
this->numberOfPatients=numberOfPatients;
}

Surgery::~Surgery() {

}

string Surgery::toString() {
    return HospitalDepartment::toString() +  "  ; Nr patients:  " + to_string(this->numberOfPatients);
}

bool Surgery::isEfficient() {
    return (this->numberOfPatients/this->numberOfDoctors>=2);
}
