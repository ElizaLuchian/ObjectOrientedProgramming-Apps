//
// Created by 40745 on 15/03/2024.
//

#ifndef A2_3_ELIZALUCHIAN_MATERIALREPO_H
#define A2_3_ELIZALUCHIAN_MATERIALREPO_H


#include "../domain/DynamicArray.h"
#include "../domain/Material.h"
#include "../domain/Operation.h"

typedef struct
{
    DynamicArray *array;
    DynamicArray *undoStack;
    DynamicArray *redoStack;
}MaterialRepo;

MaterialRepo *CreateMatRepo();

void DestroyRepo(MaterialRepo *repo);

void addRepo(MaterialRepo *repo, Material *mat);

void deleteRepo(MaterialRepo *repo, Material *mat);

void updateRepo(MaterialRepo *repo, Material *mat);

Material* getMaterialatIndex(MaterialRepo *repo, int  index);

DynamicArray *getMaterials(MaterialRepo *repo);
Telem *getElems(DynamicArray *array);
void push(DynamicArray *stack, Operation *operation);
void pop(DynamicArray *stack);
Telem *getLastElementRepo(DynamicArray *stack);
#endif //A2_3_ELIZALUCHIAN_MATERIALREPO_H
