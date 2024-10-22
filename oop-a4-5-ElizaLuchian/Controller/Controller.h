//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_CONTROLLER_H
#define OOP_A4_5_ELIZALUCHIAN_CONTROLLER_H


#include "AdminRepo.h"
#include "UserRepo.h"

class Controller {
private:
    AdminRepo repo;
    UserRepo repo_user;
public:
    Controller();
    AdminRepo get_admin_repo();
    UserRepo get_user_repo();

    void addController(const Event& event);

    void deleteController(const std::string &title);

    void generateController();

    int get_size_Controller()const;

    DynamicArray<Event> getAllElemsController()const;
    void updateController(const std::string &title, const Event& event);
    void addUserController(const Event& event);
    void removeEventController(const std::string &title);
    DynamicArray<Event> getEventsbyMonth(int month)const;
    DynamicArray<Event> getAllEventsController()const;


};


#endif //OOP_A4_5_ELIZALUCHIAN_CONTROLLER_H
