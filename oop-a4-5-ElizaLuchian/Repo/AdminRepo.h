//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_ADMINREPO_H
#define OOP_A4_5_ELIZALUCHIAN_ADMINREPO_H
#include "DynamicArray.h"

class AdminRepo {
private:
    
    DynamicArray<Event> events;
public:
    AdminRepo();
    int get_size_repo()const;
    void addRepo(const Event& event);
    void deleteRepo(const std::string& title);
    DynamicArray<Event> getAllElements()const;
    void updateRepo(const std::string& title, const Event& event);
    Event getElemwithTitle(const std::string & title)const;

    //Event getEventAtIndex(int index)const;



};


#endif //OOP_A4_5_ELIZALUCHIAN_ADMINREPO_H
