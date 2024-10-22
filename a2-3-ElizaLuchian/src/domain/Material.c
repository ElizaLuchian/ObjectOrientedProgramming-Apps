//
// Created by 40745 on 15/03/2024.
//
#include "Material.h"
#include "Date.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void DestroyMaterial(Material *material)
{
    if(material==NULL)
        return;


    free(material->supplier);
    free(material->name);
    free(material);
}
Material *CreateMaterial(char *name, char*supplier, int quantity,  Date date)
{ Material *mat;

    if(name==NULL || supplier==NULL)
        return NULL;
    mat=(Material *)malloc(sizeof(Material));
    if(mat==NULL)
        return NULL;
    mat->name=malloc(sizeof(char)*(strlen(name)+1));
    if(mat->name==NULL)
    {
        free(mat);
        return NULL;
    }
    strcpy(mat->name, name);
    mat->supplier=malloc(sizeof(char)*(strlen(supplier)+1));
    if(mat->supplier==NULL)
    {
        free(mat);
        return NULL;
    }
    strcpy(mat->supplier, supplier);
    mat->quantity=quantity;
    mat->expiration_date=date;

    return mat;

}
char *getName(Material*mat)
{
    if(mat==NULL)
        return NULL;
    return mat->name;
}
char *getSupplier(Material *mat)
{
  if(mat==NULL)
      return NULL;
  return mat->supplier;
}
int getQuantity(Material *mat)
{
    if(mat==NULL)
        return -1;
    return mat->quantity;
}
int getExpirationDay(Material *mat)
{
   if(mat==NULL)
       return -1;
   return mat->expiration_date.day;
}
int getExpirationMonth(Material *mat)
{
    if(mat==NULL)
        return -1;
    return mat->expiration_date.month;
}
int getExpirationYear(Material *mat)
{
    if(mat==NULL)
        return -1;
    return mat->expiration_date.year;
}
Date ExpirationDate(Material *mat)
{
    Date d1;
    d1.day= getExpirationDay(mat);
    d1.month = getExpirationMonth(mat);
    d1.year = getExpirationYear(mat);
    return d1;
}
Material *CopyMaterial(Material* mat)
{
    return CreateMaterial(getName(mat), getSupplier(mat), getQuantity(mat), CreateDate(getExpirationDay(mat),getExpirationMonth(mat),
                                                                                       getExpirationYear(mat)));
}

void toString(Material *mat, char str[])
{
    sprintf(str, "name: %s, supplier: %s, quantity: %d, date: %d %d %d\n", mat->name, mat->supplier, mat->quantity, mat->expiration_date.day, mat->expiration_date.month, mat->expiration_date.year);
}

void setQuantity(Material *material, int newQuantity) {
if(material==NULL)
    return;
material->quantity=newQuantity;

}
