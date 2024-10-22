//
// Created by 40745 on 15/03/2024.
//
#pragma once

#include "Date.h"

#ifndef A2_3_ELIZALUCHIAN_DYNAMICARRAY_H
#define A2_3_ELIZALUCHIAN_DYNAMICARRAY_H

typedef void *Telem;

typedef void (*DestroyMethod)(Telem);

typedef struct
{   int size;
    int capacity;
    Telem *elems;
    DestroyMethod destroyMethod;
}DynamicArray;

/*
 * Function that creates a DynamicArray object and allocates memory for it and implicitly for its fields.
 * return: pointer to a DynamicArray object.
 * */
DynamicArray *CreateArray(DestroyMethod destroyMethod);

/*
 * Function that doubles the capacity of the array when size reaches capacity. A new array with double capacity is
 * created;All the before elements from the previous array are copied into the new one and the initial one is destroyed.
 * :array: pointer to a DynamicArray object
 * return: pointer to a DynamicArray object
 * */

void doubleCapacity(DynamicArray *array);

/*
 * Getter for the size field of the DynamicArray struct
 * :offer: pointer to a DynamicArray object
 * return: int
 * */
int getSize(DynamicArray *array);

/*
 * Function that destroys a destroyArray object and deallocates its memory and implicitly its fields.
 * :array: pointer to a DynamicArray object
 * */
void DestroyArray(DynamicArray  *array);


/*
 * Function that implements the add functionality.
 * :array: pointer to a DynamicArray object
 * :elem: TElem
 * */
void  add(DynamicArray *array, Telem elem);

/*
 * Function that implements the update functionality.
 * :array: pointer to a DynamicArray object
 * :elem: TElem (updated content of the element)
 * */
void update(DynamicArray *array, Telem elem);
/*
 * Function that implements the delete functionality.
 * :array: pointer to a DynamicArray object
 * */
void deleteArr(DynamicArray *array, Telem elem);
/*
 * Function to search an element inside the dynamic array, If the element is found, we will return its position.
 * Otherwise, it will return -1.
 * :array: pointer to DynamicArray object
 * :elem: TElem
 * return: int - position, if element is found
 *               -1, otherwise*/
int SearchIndex(DynamicArray *array, Telem elem);

Telem elemAtIndex(DynamicArray *array, int index);

Telem opAtIndex(DynamicArray *array, int index);

void setAtIndex(DynamicArray* array, int index, Telem elem);

void AddElem(DynamicArray *array, Telem elem);

void clear(DynamicArray* array);
#endif //A2_3_ELIZALUCHIAN_DYNAMICARRAY_H

