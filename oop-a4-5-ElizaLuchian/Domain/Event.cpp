//
// Created by 40745 on 24/03/2024.
//

#include "Event.h"
Event::Event() : title{""}, description{""}, link{""}, number_of_people{0}, date_time{0, 0, 0, 0, 0} {}

Event::Event(const std::string& title, const std::string& description, int number_of_people, const std::string& link,
             int day, int month, int year, int minutes, int hours)
        : title{title}, description{description}, number_of_people{number_of_people},
          date_time{day, month, year, minutes, hours}, link{link} {}

std::string Event::getTitle() const {
    return this->title;
}
std::string Event::getDescription()const{
    return this->description;
}

std::string Event::getLink()const{
    return this->link;
}
int Event::getNumberOfPeople()const
{
    return this->number_of_people;
}
DateTime Event::getDate()const
{
    return this->date_time;
}
int Event::getDay()const
{
    return this->date_time.getDay();
}

void Event::setDescription(const std::string &newDescription) {
    this->description=newDescription;
}
void Event::setLink(const std::string &newLink)
{
    this->link=newLink;
}
void Event::setNPeople(const  int number) {
    this->number_of_people = number;
}


int Event::getMonth()const {
    return this->date_time.getMonth();
}
int Event::getYear()const {
    return this->date_time.getYear();
}

int Event::getMinutes() const {
    return this->date_time.getMinutes();
}

int Event::getHours() const {
    return this->date_time.getHours();
}

void Event::setDay(int newDay) {
this->date_time.setDay(newDay);
}

void Event::setMonth(int newMonth) {
    this->date_time.setMonth(newMonth);
}

void Event::setYear(int newYear) {
    this->date_time.setYear(newYear);
}

void Event::setMinutes(int newMinutes) {
    this->date_time.setMinutes(newMinutes);
}

void Event::setHours(int newHours) {
    this->date_time.setHours(newHours);
}

void Event::setTitle(const std::string &title) {
this->title=title;
}







