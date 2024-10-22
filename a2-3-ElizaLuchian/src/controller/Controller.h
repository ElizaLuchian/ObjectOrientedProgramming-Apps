//
// Created by 40745 on 16/03/2024.
//

#ifndef A2_3_ELIZALUCHIAN_CONTROLLER_H
#define A2_3_ELIZALUCHIAN_CONTROLLER_H

#include "../repository/MaterialRepo.h"
#include "../domain/Date.h"
#include "../domain/Material.h"

typedef struct
{
    MaterialRepo *repo;
}MaterialController;

typedef void (*SortingMethod)(DynamicArray*);
typedef DynamicArray* (*FilterMethod)(MaterialController*, int, int, int, char*);

MaterialController *CreateController();

void addController(MaterialController *controller, char *name, char *supplier, int quantity, int day, int month, int year);

void destroyController(MaterialController *controller);

void deleteController(MaterialController *controller, char *name, char *supplier, int day, int month, int year);

void updateController(MaterialController *controller, char *name, char *supplier, int quantity, int day, int month, int year);
DynamicArray *filterController(MaterialController *controller,  int day, int month, int year, char *string);
DynamicArray *DisplayFromSupplierController(MaterialController *controller, char *supplier, int quantity, int typeSort);
void SortbyQuantity(DynamicArray* arr);
void SortbyQuantityDecrease(DynamicArray *array);
MaterialRepo *getRepo(MaterialController *controller);
void UndoOperations(MaterialController *controller);
void RedoOperations(MaterialController *controller);
void trySort(DynamicArray *arr, SortingMethod sortingMethod);
DynamicArray* tryFilter(MaterialController *controller, int day, int month, int year, char *string, int FilterMethod);
DynamicArray  *accessFilter(MaterialController *controller, int day, int month, int year, char *string, FilterMethod filterMethod);
#endif //A2_3_ELIZALUCHIAN_CONTROLLER_H
