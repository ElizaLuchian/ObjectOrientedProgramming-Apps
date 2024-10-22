//
// Created by 40745 on 23/04/2024.
//

#include "NeonatalUnit.h"

NeonatalUnit::NeonatalUnit(string hospitalName, int numberofDoctors, double averageGrade): HospitalDepartment(hospitalName, numberofDoctors) {
this->averageGrade=averageGrade;
}

bool NeonatalUnit::isEfficient() {
    return (this->averageGrade>8.5);
}

string NeonatalUnit::toString() {
    return HospitalDepartment::toString() + "  ; average Grade:  " + to_string(this->averageGrade);
}

NeonatalUnit::~NeonatalUnit() {

}
