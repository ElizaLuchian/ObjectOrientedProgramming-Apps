//
// Created by 40745 on 02/04/2024.
//

#include <algorithm>
#include <iostream>
#include "Controller.h"

Controller::Controller() :repo(){

}
//this function ads a task in the array accessed by the controller with the repo
//input an object of type Task
//output None
void Controller::addController(Task task) {
repo.addRepo(task);
}
int Calculdate(Date date)
{
    int sum=date.year*365000 +date.month*1200 +date.day;
    return sum;
}
bool Compare(Task t1, Task t2){
    return (Calculdate(t1.getDeadline()) > Calculdate(t2.getDeadline()));
}
vector<Task> Controller::getArrayController() {
    vector<Task>array=repo.getArray();
    vector<Task>arr;
    for(int i=0; i<array.size(); i++)
        arr.push_back(array[i]);
    sort(arr.begin(), arr.end(),Compare);
    return arr;

}

void Controller::generate() {
    repo.addRepo(Task("Solve OOP", 120, 26,4,2023));
    repo.addRepo(Task("Respond to emails", 45, 28,4,2023));
    repo.addRepo(Task("Eat sushi", 30, 15,3,2023));
    repo.addRepo(Task("Visit parent", 240, 1,5,2023));
    repo.addRepo(Task("Buy a jacket", 120, 28,4,2023));

}
//this function returns an array with the tasks with a given date and calculates the total time for those tasks
//input ---a given date and a variable where we store the calculated time
//output-----return the array
vector<Task> Controller::filter(Date date, int &time) {
    vector<Task>array=repo.getArray();
    vector<Task>arr;
    for(int i=0; i<array.size(); i++)
        if(Calculdate(array[i].getDeadline()) == Calculdate(date))
        { arr.push_back(array[i]);
            time=time+array[i].getDuraton();}
    return arr;
}
