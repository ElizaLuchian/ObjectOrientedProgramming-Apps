//
// Created by 40745 on 02/04/2024.
//

#ifndef T1_ELIZALUCHIAN_1_TASK_H
#define T1_ELIZALUCHIAN_1_TASK_H


#include <string>
#include "Struct.h"

class Task {
private:
    std::string description;
    int duration;
    Date deadline;
public:
    Task();
    Task(std::string description, int duration, int day, int month, int year);
    std::string getDescription();
    int getDuraton();
    Date getDeadline();


};


#endif //T1_ELIZALUCHIAN_1_TASK_H
