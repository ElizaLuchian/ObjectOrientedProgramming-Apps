//
// Created by 40745 on 02/04/2024.
//

#ifndef T1_ELIZALUCHIAN_1_REPO_H
#define T1_ELIZALUCHIAN_1_REPO_H


#include "../Domain/Task.h"
#include<vector>
using namespace std;
class Repo {
private:
    vector<Task> array;
public:
    Repo();
    void addRepo(Task task);
    vector<Task> getArray();
    int isFound(std::string description);
};


#endif //T1_ELIZALUCHIAN_1_REPO_H
