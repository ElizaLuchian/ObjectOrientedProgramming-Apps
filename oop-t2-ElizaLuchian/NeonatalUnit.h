//
// Created by 40745 on 23/04/2024.
//

#ifndef OOP_T2_ELIZALUCHIAN_NEONATALUNIT_H
#define OOP_T2_ELIZALUCHIAN_NEONATALUNIT_H


#include "HospitalDepartment.h"

class NeonatalUnit: public HospitalDepartment{
private:
    double averageGrade;
public:
    NeonatalUnit(string hospitalName, int numberofDoctors, double averageGrade);
    bool isEfficient() override;
    string toString() override;
    ~NeonatalUnit()override;

};


#endif //OOP_T2_ELIZALUCHIAN_NEONATALUNIT_H
