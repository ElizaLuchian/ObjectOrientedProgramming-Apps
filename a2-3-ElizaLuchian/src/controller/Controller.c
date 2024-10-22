//
// Created by 40745 on 16/03/2024.
//

#include "Controller.h"
#include <string.h>
#include <stdlib.h>


void addController(MaterialController *controller, char *name, char *supplier, int quantity, int day, int month, int year) {
    Date date = CreateDate(day, month, year);
    Material *mat = CreateMaterial(name, supplier, quantity, date);
    int index = SearchIndex(getMaterials(controller->repo), mat);
    if (index != -1) {
        Material *existingMaterial = getMaterialatIndex(controller->repo, index);
        int newQuantity = getQuantity(existingMaterial) + quantity;
        setQuantity(mat, newQuantity);
        updateRepo(controller->repo, mat);
        Operation* operation = CreateOperation("update", existingMaterial, mat);
        AddElem(controller->repo->undoStack, (Telem *) operation);
        clear(controller->repo->redoStack);
        DestroyOperation(operation);
        DestroyMaterial(mat);
        DestroyMaterial(existingMaterial);
        return;
    }
    addRepo(controller->repo, mat);
    Operation* operation = CreateOperation("add", mat, mat);
    AddElem(controller->repo->undoStack, (Telem *) operation);
    clear(controller->repo->redoStack);
    DestroyMaterial(mat);
    DestroyOperation(operation);
}

DynamicArray *filterController(MaterialController *controller, int day, int month, int year, char *string) {
    Date date = CreateDate(day, month, year);
    if (getMaterials(controller->repo) == NULL || getElems(getMaterials(controller->repo))== NULL)
        return NULL;

    DynamicArray *arr = CreateArray((DestroyMethod) &DestroyMaterial);
    if (strcmp(string, "") != 0) {
        for (int i = 0; i < getSize(getMaterials(controller->repo)); i++) {
            Material *mat1 = (Material *) elemAtIndex(getMaterials(controller->repo), i);
            if ((((strstr(getName(mat1), string) != NULL || strstr(getSupplier(mat1), string)) != NULL)) &&
                IsGreaterDate(date, ExpirationDate(mat1)) == 1)
                add(arr, mat1);
            DestroyMaterial(mat1);
        }
        return arr;
    } else {
        for (int i = 0; i < getSize(getMaterials(controller->repo)); i++) {
            Material *mat1 = (Material *) elemAtIndex(getMaterials(controller->repo), i);
            if (IsGreaterDate(date, ExpirationDate(mat1)) == 1) {
                add(arr, mat1);
            }
            DestroyMaterial(mat1);
        }
        return arr;
    }
}

DynamicArray *filterController2(MaterialController *controller, int day, int month, int year, char *string) {
    Date date = CreateDate(day, month, year);
    if (getMaterials(controller->repo) == NULL || getElems(getMaterials(controller->repo))== NULL)
        return NULL;

    DynamicArray *arr = CreateArray((DestroyMethod) &DestroyMaterial);
    if (strcmp(string, "") != 0) {
        for (int i = 0; i < getSize(getMaterials(controller->repo)); i++) {
            Material *mat1 = (Material *) elemAtIndex(getMaterials(controller->repo), i);
            if ((((strstr(getName(mat1), string) == NULL || strstr(getSupplier(mat1), string)) == NULL)) &&
                IsGreaterDate(date, ExpirationDate(mat1)) == 1)
                add(arr, mat1);
            DestroyMaterial(mat1);
        }
        return arr;
    } else {
        for (int i = 0; i < getSize(getMaterials(controller->repo)); i++) {
            Material *mat1 = (Material *) elemAtIndex(getMaterials(controller->repo), i);
            if (IsGreaterDate(date, ExpirationDate(mat1)) == 1) {
                add(arr, mat1);
            }
            DestroyMaterial(mat1);
        }
        return arr;
    }
}

void destroyController(MaterialController *controller) {
    DestroyRepo(controller->repo);
    free(controller);
}

void deleteController(MaterialController *controller, char *name, char *supplier, int day, int month, int year) {
    Date date = CreateDate(day, month, year);
    Material *mat = CreateMaterial(name, supplier, 0, date);
    deleteRepo(controller->repo, mat);
    Operation* operation = CreateOperation("delete", mat, mat);
    AddElem(controller->repo->undoStack, (Telem *) operation);
    clear(controller->repo->redoStack);
    DestroyMaterial(mat);
    DestroyOperation(operation);
}

void updateController(MaterialController *controller, char *name, char *supplier, int quantity, int day, int month, int year) {
    Date date = CreateDate(day, month, year);
    Material *mat = CreateMaterial(name, supplier, quantity, date);
    int index = SearchIndex(getMaterials(controller->repo), mat);
    if (index != -1) {// get mat at index and save in OldMaterial
        Material *OldMaterial = (Material *) elemAtIndex(getMaterials(controller->repo), index);
        updateRepo(controller->repo, mat);
        // save operation with "update", OldMaterial, mat
        Operation* operation = CreateOperation("update", OldMaterial, mat);
        AddElem(controller->repo->undoStack, (Telem *) operation);
        clear(controller->repo->redoStack);
        DestroyOperation(operation);
        DestroyMaterial(OldMaterial);
    }
    DestroyMaterial(mat);
}

void SortbyQuantity(DynamicArray *array) {
    for (int i = 0; i < getSize(array) - 1; i++)
        for (int j = i; j < getSize(array); j++) {
            Material *mat1 = (Material *) elemAtIndex(array, i);
            Material *mat2 = (Material *) elemAtIndex(array, j);
            if (getQuantity(mat1) > getQuantity(mat2)) {
                setAtIndex(array, i, mat2);
                setAtIndex(array, j, mat1);
            }
            DestroyMaterial(mat1);
            DestroyMaterial(mat2);
        }
}
void SortbyQuantityDecrease(DynamicArray *array) {
    for (int i = 0; i < getSize(array) - 1; i++)
        for (int j = i; j < getSize(array); j++) {
            Material *mat1 = (Material *) elemAtIndex(array, i);
            Material *mat2 = (Material *) elemAtIndex(array, j);
            if (getQuantity(mat1) < getQuantity(mat2)) {
                setAtIndex(array, i, mat2);
                setAtIndex(array, j, mat1);
            }
            DestroyMaterial(mat1);
            DestroyMaterial(mat2);
        }
}

DynamicArray *DisplayFromSupplierController(MaterialController *controller, char *supplier, int quantity, int typeSort) {
    DynamicArray *arr = CreateArray((DestroyMethod) &DestroyMaterial);

    for (int i = 0; i < getSize(getMaterials(controller->repo)); i++) {
        Material *mat1 = (Material *) elemAtIndex(getMaterials(controller->repo), i);
        if (strcmp(mat1->supplier, supplier) == 0 && mat1->quantity < quantity)
            add(arr, mat1);
        DestroyMaterial(mat1);
    }
    if(typeSort==0)
    trySort(getMaterials(controller->repo), &SortbyQuantity);
    else
        trySort(getMaterials(controller->repo), &SortbyQuantityDecrease);

    return arr;
}

MaterialController *CreateController() {
    MaterialController *controller = (MaterialController *) malloc(sizeof(MaterialController));
    if (controller == NULL)
        return NULL;

    controller->repo = CreateMatRepo();
    if (controller->repo == NULL) {
        free(controller);
        return NULL;

    }
    return controller;
}

MaterialRepo *getRepo(MaterialController *controller) {
    return (controller->repo);
}

void UndoOperations(MaterialController *controller)
{
    if (getSize(controller->repo->undoStack) < 1)
        return;
    Operation *operation= (Operation *) getLastElementRepo(controller->repo->undoStack);
    if(strcmp(getType(operation), "add")==0)
        deleteRepo(controller->repo, operation->oldMat);
    else if(strcmp(getType(operation), "delete")==0)
        addRepo(controller->repo, operation->oldMat);
    else if(strcmp(getType(operation), "update")==0)
        updateRepo(controller->repo, operation->oldMat);

    push(controller->repo->redoStack, operation);
    pop(controller->repo->undoStack);
    DestroyOperation(operation);

}

void RedoOperations(MaterialController *controller)
{
    if (getSize(controller->repo->redoStack) < 1)
        return;
    Operation *operation= (Operation *) getLastElementRepo(controller->repo->redoStack);
    if(strcmp(getType(operation), "add")==0)
        addRepo(controller->repo, operation->oldMat);
    else if(strcmp(getType(operation), "delete")==0)
        deleteRepo(controller->repo, operation->oldMat);
    else if(strcmp(getType(operation), "update")==0)
        updateRepo(controller->repo, operation->newMat);

    push(controller->repo->undoStack, operation);
    pop(controller->repo->redoStack);
    DestroyOperation(operation);

}

void trySort(DynamicArray *arr, SortingMethod sortingMethod) {
    sortingMethod(arr);
}

DynamicArray* tryFilter(MaterialController *controller, int day, int month, int year, char *string, int FilterMethod) {
if(FilterMethod==0)
    return accessFilter(controller, day, month, year,string, &filterController);
else
    return accessFilter(controller, day, month, year, string, &filterController2);
}



DynamicArray *accessFilter(MaterialController *controller, int day, int month, int year, char *string, FilterMethod filterMethod) {
    return filterMethod(controller, day, month, year, string);
}
