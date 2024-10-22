//
// Created by 40745 on 15/03/2024.
//

#include <stdlib.h>
#include "DynamicArray.h"
#include "Material.h"
#include "Operation.h"
#include <string.h>

DynamicArray *CreateArray(DestroyMethod destroyMethod) {
    DynamicArray *arr = (DynamicArray *) malloc(sizeof(DynamicArray));
    if (arr == NULL)
        return NULL;
    arr->size = 0;
    arr->capacity = 1;
    arr->destroyMethod = destroyMethod;
    Telem *elems = (Telem *) malloc(sizeof(Telem) * (arr->capacity));

    if (elems == NULL) {
        free(arr);
        return NULL;
    }
    arr->elems = elems;

    return arr;
}

void DestroyArray(DynamicArray *array) {
    if (array == NULL)
        return;
    for (int i = 0; i < array->size; i++)
        array->destroyMethod(array->elems[i]);

    free(array->elems);
    free(array);
}

void doubleCapacity(DynamicArray *array) {
    if (array == NULL)
        return;
    if (array->elems == NULL)
        return;
    array->capacity = (array->capacity) * 2;
    Telem *elements = realloc(array->elems, sizeof(Telem) * (array->capacity));

    array->elems = elements;
}

int getSize(DynamicArray *array) {
    if (array == NULL || array->elems == NULL)
        return -1;
    return array->size;
}

void add(DynamicArray *array, Telem elem) {
    if (array == NULL || array->elems == NULL)
        return;
    if (array->size == array->capacity)
        doubleCapacity(array);
    array->elems[array->size] = CopyMaterial(elem);
    array->size = array->size + 1;
}

int SearchIndex(DynamicArray *array, Telem elem) {
    if (array == NULL || array->elems == NULL)
        return -1;

    for (int i = 0; i < array->size; i++) {

        Telem current_el = array->elems[i];
        if (strcmp(getName(current_el), getName(elem)) == 0 &&
            strcmp(getSupplier(current_el), getSupplier(elem)) == 0 &&
            getExpirationDay(current_el) == getExpirationDay(elem) && getExpirationMonth(current_el) ==
                                                                      getExpirationMonth(elem) &&
            getExpirationYear(current_el) ==
            getExpirationYear(elem))
            return i;

    }
    return -1;
}

void update(DynamicArray *array, Telem elem) {
    int index = SearchIndex(array, elem);
    if (index != -1)
        setQuantity(array->elems[index], getQuantity(elem));

}


void deleteArr(DynamicArray *array, Telem elem) {
    int index = SearchIndex(array, elem);
    if (index != -1) {
        array->destroyMethod(array->elems[index]);
        for (int i = index; i < array->size - 1; i++)
            array->elems[i] = array->elems[i + 1];
        array->size--;

    }
}

Telem elemAtIndex(DynamicArray *array, int index) {
    if (index < 0 || index + 1 > array->size)
        return NULL;
    return CopyMaterial(array->elems[index]);

}

Telem opAtIndex(DynamicArray *array, int index) {
    if (index < 0 || index + 1 > array->size)
        return NULL;
    return CopyOperation(array->elems[index]);

}

void setAtIndex(DynamicArray *array, int index, Telem elem) {
    if (index < 0 || index + 1 > array->size || elem == NULL)
        return;
    array->destroyMethod(array->elems[index]);
    array->elems[index] = CopyMaterial(elem);
}

void AddElem(DynamicArray *array, Telem elem)
{
    if(array==NULL ||  elem==NULL)
        return;

    if(array->size==array->capacity)
        doubleCapacity(array);

    array->elems[getSize(array)]= CopyOperation(elem);
    array->size++;
}

void clear(DynamicArray *array) {
    for(int i = 0; i < array->size; ++i)
        array->destroyMethod(array->elems[i]);
    array->size = 0;
}




