//
// Created by 40745 on 02/04/2024.
//

#ifndef T1_ELIZALUCHIAN_1_CONTROLLER_H
#define T1_ELIZALUCHIAN_1_CONTROLLER_H


#include "../Repository/Repo.h"

class Controller {
private:
    Repo repo;
public:
    Controller();
    void addController(Task task);
    vector<Task> getArrayController();
    void generate();
    vector<Task> filter(Date date, int &time);
};



#endif //T1_ELIZALUCHIAN_1_CONTROLLER_H
