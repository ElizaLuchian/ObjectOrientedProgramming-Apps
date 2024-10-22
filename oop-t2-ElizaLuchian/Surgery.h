//
// Created by 40745 on 23/04/2024.
//

#ifndef OOP_T2_ELIZALUCHIAN_SURGERY_H
#define OOP_T2_ELIZALUCHIAN_SURGERY_H


#include "HospitalDepartment.h"

class Surgery: public HospitalDepartment{
private:
    int numberOfPatients;
public:
    Surgery(string hospitalName, int numberofDoctors, int numberOfPatients);
    bool isEfficient() override;
    string toString() override;
    ~Surgery()override;

};


#endif //OOP_T2_ELIZALUCHIAN_SURGERY_H
