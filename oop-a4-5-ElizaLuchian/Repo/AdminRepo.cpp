//
// Created by 40745 on 24/03/2024.
//

#include "AdminRepo.h"

int AdminRepo::get_size_repo()const {
    return this->events.getSize();
}

void AdminRepo::addRepo( const Event& event) {
    this->events.add(event);
}

void AdminRepo::deleteRepo(const std::string& title) {
    this->events.deleteEvent(title);
}
DynamicArray<Event> AdminRepo::getAllElements()const {
    return events;
}

AdminRepo::AdminRepo() : events(1) {
}

void AdminRepo::updateRepo(const std::string &title, const Event &event) {
this->events.updateEvent(title, event);

}

Event AdminRepo::getElemwithTitle(const std::string& title) const {
    int index=events.isFound(title);

    return events.eventAtIndex(index);

}








