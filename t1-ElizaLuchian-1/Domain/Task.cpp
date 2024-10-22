//
// Created by 40745 on 02/04/2024.
//

#include "Task.h"

Task::Task(): description(" "), duration(0), deadline() {

}

Task::Task(std::string description, int duration, int day, int month, int year) {
this->duration=duration;
this->description=description;
Date date;
date.day=day;
date.month=month;
date.year=year;
this->deadline=date;
}

std::string Task::getDescription() {
    return this->description;
}

int Task::getDuraton() {
    return this->duration;
}

Date Task::getDeadline() {
    return this->deadline;
}
