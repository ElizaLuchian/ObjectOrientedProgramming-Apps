//
// Created by 40745 on 06/04/2024.
//

#include "UserRepo.h"

UserRepo::UserRepo():eventlist() {

}

DynamicArray<Event> UserRepo::getEventList() const {
    return eventlist;
}


void UserRepo::addEventUser( Event event) {
    this->eventlist.add(event);


}

void UserRepo::removeEventUser(std::string title) {
    this->eventlist.deleteEvent(title);

}




