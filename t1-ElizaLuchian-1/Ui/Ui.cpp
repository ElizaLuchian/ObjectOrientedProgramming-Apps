//
// Created by 40745 on 02/04/2024.
//

#include <iostream>
#include "Ui.h"

Ui::Ui() :controller(){

}

void Ui::addUi() {
    char description[100];
    int day, month, year;
    int duration;
    //Date deadline;
cout<<"description:  ";
cin.getline(description,100);
cout<<"duration:  ";
cin>>duration;
cout<<"day:  ";
cin>>day;
cout<<"month";
cin>>month;
cout<<"year";
cin>>year;
controller.addController(Task(description,duration,day,month,year));

}

void Ui::display() {
vector<Task> array=controller.getArrayController();
for(int i=0; i<array.size(); i++) {
    cout<<endl;
    cout << array[i].getDescription() << "|" << array[i].getDuraton() << "|";
    cout<<array[i].getDeadline().day<<"|";
    cout<<array[i].getDeadline().month<<"|";
    cout<<array[i].getDeadline().year<<"|"<<endl;

}

}

void Ui::menu() {
cout<<"input\n";
cout<<"1.add Task\n";
cout<<"2.show tasks\n";
cout<<"3.filter tasks\n";
cout<<"0. Exit\n";
}

void Ui::generate() {
controller.generate();
}

void Ui::filterUi() {
    int day, month, year;
    int time=0;
    Date d1;
    cout<<"day:  ";
    cin>>day;
    cout<<"month:  ";
    cin>>month;
    cout<<"year";
    cin>>year;
    d1.day=day;
    d1.month=month;
    d1.year=year;
vector<Task>array=controller.filter(d1,time);
    for(int i=0; i<array.size(); i++) {
        cout << array[i].getDescription() << "|" << array[i].getDuraton() << "|";
        cout<<array[i].getDeadline().year<<"|";
        cout<<array[i].getDeadline().month<<"|";
        cout<<array[i].getDeadline().day<<"|"<<endl;

    }

cout<<time;
}
