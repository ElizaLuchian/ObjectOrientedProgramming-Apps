//
// Created by 40745 on 06/04/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_USERREPO_H
#define OOP_A4_5_ELIZALUCHIAN_USERREPO_H


#include "Event.h"
#include "DynamicArray.h"

class UserRepo {
private:
    DynamicArray <Event> eventlist;
public:
    UserRepo();

    DynamicArray<Event> getEventList()const;
    void addEventUser( Event event);
    void removeEventUser(std::string title);




};


#endif //OOP_A4_5_ELIZALUCHIAN_USERREPO_H
