//
// Created by 40745 on 02/04/2024.
//

#ifndef T1_ELIZALUCHIAN_1_UI_H
#define T1_ELIZALUCHIAN_1_UI_H


#include "../Controller/Controller.h"

class Ui {
private:
    Controller controller;
public:
    Ui();
    void addUi();
    void display();
    void menu();
    void generate();
    void filterUi();
};


#endif //T1_ELIZALUCHIAN_1_UI_H
