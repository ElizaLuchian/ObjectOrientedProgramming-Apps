//
// Created by 40745 on 02/04/2024.
//

#include <cassert>
#include "Test.h"
#include "../Domain/Task.h"
#include "../Repository/Repo.h"
#include "../Controller/Controller.h"

void TestAddRepo(){
    Repo repo=Repo();

    Task t1=Task("description", 120,3,4,2005);
    repo.addRepo(t1);
    assert(repo.getArray().size()==1);
}
void TestAddController(){
    Controller controller=Controller();

    Task t1=Task("description", 120,3,4,2005);
    controller.addController(t1);
    assert(controller.getArrayController().size()==1);
}
void TestFilterController()
{ Controller controller=Controller();
    Date date;
    Task t1=Task("description1", 120,3,4,2005);
    Task t2=Task("description2", 45,3,4,2005);
    controller.addController(t1);
    controller.addController(t2);
    //assert(controller.getArrayController().size()==2);
    date.day=3;
    date.month=4;
    date.year=2005;
    int time=0;
    //vector<Task>array=controller.filter(date,time);
    assert(controller.filter(date,time).size()==2);
    assert(controller.filter(date,time)[0].getDescription()=="description1");
    assert(controller.filter(date,time)[1].getDescription()=="description2");


}
Test::Test() {
TestAddRepo();
TestAddController();
TestFilterController();
}
