//
// Created by 40745 on 02/04/2024.
//

#include <stdexcept>
#include "Repo.h"

Repo::Repo():array(0) {

}
//this functions ads a task in the array from the repository
//input--an object of type Task
//output--None
void Repo::addRepo(Task task) {
if(isFound(task.getDescription())!=-1)
    throw runtime_error("error while trying to add");
array.push_back(task);
}

vector<Task> Repo::getArray() {
return array;
}

int Repo::isFound(std::string description) {
    for(int i=0; i<array.size(); i++)
        if(array[i].getDescription()==description)
            return i;
    return -1;
}
