//
// Created by 40745 on 18/03/2024.
//

#ifndef A2_3_ELIZALUCHIAN_OPERATION_H
#define A2_3_ELIZALUCHIAN_OPERATION_H

#include "Material.h"

typedef struct
{
    char *type;
    Material *newMat;
    Material *oldMat;

}Operation;

Operation *CreateOperation(char *type,Material *oldMat, Material *newMat);
void DestroyOperation(Operation *op);
char *getType(Operation *op);
Operation *CopyOperation(Operation *op);

#endif //A2_3_ELIZALUCHIAN_OPERATION_H
