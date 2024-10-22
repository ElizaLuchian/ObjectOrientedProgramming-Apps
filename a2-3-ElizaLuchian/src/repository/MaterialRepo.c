//
// Created by 40745 on 15/03/2024.
//

#include "MaterialRepo.h"
#include "../domain/Material.h"
#include <stdlib.h>

MaterialRepo *CreateMatRepo() {

    MaterialRepo *repo = (MaterialRepo *) malloc(sizeof(MaterialRepo));
    if (repo == NULL)
        return NULL;

    repo->array = CreateArray((DestroyMethod) &DestroyMaterial);
    repo->undoStack = CreateArray((DestroyMethod) &DestroyOperation);
    repo->redoStack = CreateArray((DestroyMethod) &DestroyOperation);
    if (repo->array == NULL) {
        free(repo);
        return NULL;

    }
    return repo;
}

void DestroyRepo(MaterialRepo *repo) {
    if (repo == NULL)
        return;
    DestroyArray(repo->array);
    DestroyArray(repo->undoStack);
    DestroyArray(repo->redoStack);
    free(repo);

}

Material *getMaterialatIndex(MaterialRepo *repo, int index) {
    return (Material*)elemAtIndex(repo->array, index);
}

void addRepo(MaterialRepo *repo, Material *mat) {
    add(repo->array, mat);
}

void deleteRepo(MaterialRepo *repo, Material *mat) {
    deleteArr(repo->array, mat);

}

void updateRepo(MaterialRepo *repo, Material  *mat) {
    update(repo->array, mat);
}



DynamicArray *getMaterials(MaterialRepo *repo) {

    return (repo->array);
}

Telem *getElems(DynamicArray *array) {
    return (array->elems);
}

void push(DynamicArray *stack, Operation *op) {
    AddElem(stack, op);
}

void pop(DynamicArray *stack)
{
    deleteArr(stack, stack->elems[getSize(stack)-1]);
}

Telem *getLastElementRepo(DynamicArray *stack) {
    return opAtIndex(stack, getSize(stack)-1);
}


