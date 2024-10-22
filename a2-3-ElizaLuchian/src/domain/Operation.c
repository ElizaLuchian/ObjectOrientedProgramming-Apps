//
// Created by 40745 on 18/03/2024.
//

#include <malloc.h>
#include <string.h>
#include "Operation.h"

Operation *CreateOperation(char *type, Material *oldMat, Material *newMat) {

    Operation *op=(Operation *)malloc(sizeof(Operation));
    if(op==NULL)
        return NULL;
    op->type= malloc(sizeof(char)*(strlen(type)+1));
    op->oldMat= CopyMaterial(oldMat);
    op->newMat= CopyMaterial(newMat);
    if(oldMat==NULL || newMat==NULL || type==NULL)
    {
        free(op);
        return NULL;
    }
    strcpy(op->type, type);
    return op;
}

void DestroyOperation(Operation *op)
{
    if(op==NULL)
        return;
    DestroyMaterial(op->oldMat);
    DestroyMaterial(op->newMat);
    free(op->type);
    free(op);
}

char *getType(Operation *op) {
    return op->type;
}

Operation *CopyOperation(Operation *op) {
    return CreateOperation(op->type, op->oldMat, op->newMat);
}


