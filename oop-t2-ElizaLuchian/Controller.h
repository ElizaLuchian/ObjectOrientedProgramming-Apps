//
// Created by 40745 on 23/04/2024.
//

#ifndef OOP_T2_ELIZALUCHIAN_CONTROLLER_H
#define OOP_T2_ELIZALUCHIAN_CONTROLLER_H


#include <vector>
#include "HospitalDepartment.h"

class Controller {
private:
    vector<HospitalDepartment *> hospitals;
public:
    Controller();
    void addDepartment(HospitalDepartment * hospital);
    vector<HospitalDepartment *> getAllDepartments();
    vector<HospitalDepartment *> getEfficientDepartments();
    void writeToFile(string filename);
    void generate();
    ~Controller();

};


#endif //OOP_T2_ELIZALUCHIAN_CONTROLLER_H
