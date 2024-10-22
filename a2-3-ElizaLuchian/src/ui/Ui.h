//
// Created by 40745 on 15/03/2024.
//

#ifndef A2_3_ELIZALUCHIAN_UI_H
#define A2_3_ELIZALUCHIAN_UI_H

#include "../controller/Controller.h"


#include "../domain/DynamicArray.h"
#include "../repository/MaterialRepo.h"
typedef struct
{
    MaterialController *controller;
}MaterialUI;

MaterialUI *CreateUi();

void printAll(DynamicArray *arr);
void Generate(MaterialUI *ui);
void Menu();
void addUI(MaterialUI *ui);
void deleteUI(MaterialUI *ui);
void updateUI(MaterialUI *ui);
void filterUI(MaterialUI *ui);
void displayFromGivenSupplierUI(MaterialUI *ui);
void destroyUI(MaterialUI *ui);

void undoUI(MaterialUI *ui);
void redoUI(MaterialUI *ui);
#endif //A2_3_ELIZALUCHIAN_UI_H
