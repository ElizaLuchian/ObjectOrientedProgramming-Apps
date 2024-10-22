//
// Created by 40745 on 15/03/2024.
//
#pragma once

#ifndef A2_3_ELIZALUCHIAN_MATERIAL_H
#define A2_3_ELIZALUCHIAN_MATERIAL_H


#include "Date.h"

/*
 * Struct that stores a material
 * */
typedef struct {
    char *name;
    char *supplier;
    int quantity;
    Date expiration_date;

} Material;

/*
 * Function that creates a Material object and allocates memory for it and implicitly for its fields.
 * :name: pointer to char (can be a name for the material)"
 * :supplier: pointer to char
 * :date: Date variable
 * :quantity: int
 * return: pointer to a Material object
 * */
Material *CreateMaterial(char *name, char *supplier, int quantity, Date date);

/*Copies a Material object and returns it
 * return a pointer to a Material object**/

Material *CopyMaterial(Material *material);

/*Function that destroys an Offer object and deallocates its memory and implicitly its fields.
 * :offer: pointer to o Material Object*/

void DestroyMaterial(Material *material);

/*
 * Getter for the name, supplier, quantity field of the Material struct
 * :offer: pointer to a Material object
 * return: pointer to const char
 * */
char *getName(Material *material);

char *getSupplier(Material *material);

int getQuantity(Material *material);

/*
 * Getters for the day, month, year of the expirationdate field  of the Material struct
 * :offer: pointer to a Data object
 * return: pointer to int
 * */
int getExpirationDay(Material *material);

int getExpirationMonth(Material *material);

int getExpirationYear(Material *material);

void setQuantity(Material *material, int newQuantity);

/*
 * Function that creates a description string containing information about all the fields of a Material object.
 * */
void toString(Material *material, char p[] );

Date ExpirationDate(Material *mat);
#endif //A2_3_ELIZALUCHIAN_MATERIAL_H
