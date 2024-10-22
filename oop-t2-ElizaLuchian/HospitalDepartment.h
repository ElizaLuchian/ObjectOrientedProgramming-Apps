//
// Created by 40745 on 23/04/2024.
//

#ifndef OOP_T2_ELIZALUCHIAN_HOSPITALDEPARTMENT_H
#define OOP_T2_ELIZALUCHIAN_HOSPITALDEPARTMENT_H

#include <string>

using namespace std;
class HospitalDepartment {
protected:
    string hospitalName;
    int numberOfDoctors;
public:
    HospitalDepartment(string hospitalName, int numberofDoctors);
    virtual ~HospitalDepartment();
    virtual bool isEfficient()=0;
    string getName();

    virtual string toString();

};


#endif //OOP_T2_ELIZALUCHIAN_HOSPITALDEPARTMENT_H
