//
// Created by 40745 on 17/03/2024.
//

#include "Tests.h"
#include "../repository/MaterialRepo.h"
#include "../controller/Controller.h"

void Tests()
{
    TestDomain();
    TestRepo();
    TestController();
}

void TestDomain() {
    Material *material = CreateMaterial("paine", "Eliza", 34, CreateDate(12, 12, 2004));
    assert(strcmp(getName(material), "paine") == 0);
    assert(strcmp(getSupplier(material), "Eliza") == 0);
    assert(getQuantity(material) == 34);
    assert(getExpirationDay(material) == 12);
    assert(getExpirationMonth(material) == 12);
    assert(getExpirationYear(material) == 2004);
    DestroyMaterial(material);
}

void TestRepo()
{   Material *material= CreateMaterial("paine1", "Eliza", 34, CreateDate(12, 2, 2004));
    MaterialRepo *repo= CreateMatRepo();
    addRepo(repo, material);
    assert(getSize(repo->array)==1);
    DestroyMaterial(material);
    Material *mat = (Material*) elemAtIndex(repo->array,0);
    assert(strcmp(getName(mat), "paine1") == 0);
    assert(strcmp(getSupplier(mat), "Eliza") == 0);
    assert(getQuantity(mat) == 34);
    assert(getExpirationDay(mat) == 12);
    assert(getExpirationMonth(mat) == 2);
    assert(getExpirationYear(mat) == 2004);
    DestroyMaterial(mat);
    DestroyRepo(repo);

}

void TestController()
{

    MaterialController *controller=CreateController();
    addController(controller,"paine1", "Eliza", 34, 12, 2, 2004);
    assert(getSize(getMaterials(getRepo(controller)))==1);
    Material *mat = (Material*) elemAtIndex(getMaterials(getRepo(controller)),0);
    assert(strcmp(getName(mat), "paine1") == 0);
    assert(strcmp(getSupplier(mat), "Eliza") == 0);
    assert(getQuantity(mat) == 34);
    assert(getExpirationDay(mat) == 12);
    assert(getExpirationMonth(mat) == 2);
    assert(getExpirationYear(mat) == 2004);
    DestroyMaterial(mat);
    addController(controller,"paine1", "Eliza", 40, 12, 2, 2004);
    mat = (Material*) elemAtIndex(getMaterials(getRepo(controller)), 0);
    assert(getSize(getMaterials(getRepo(controller)))==1);
    assert(getQuantity(mat) == 74);
    DestroyMaterial(mat);
    updateController(controller, "paine1", "Eliza", 50, 12, 2, 2004);
    mat = (Material*) elemAtIndex(getMaterials(getRepo(controller)), 0);
    assert(getQuantity(mat)==50);
    DestroyMaterial(mat);
    deleteController(controller, "paine1", "Eliza", 12, 2, 2004);
    assert(getSize(getMaterials(getRepo(controller)))==0);
    addController(controller,"paine1", "Eliza", 34, 12, 2, 2004);
    addController(controller,"paine2", "Eliza", 20, 12, 4, 2004);
    DynamicArray *array=filterController(controller,12, 3, 2004,"pain");
    assert(getSize(array)==1);
    DestroyArray(array);
    DynamicArray *arr=DisplayFromSupplierController(controller,"Eliza", 50, 0);
    assert(getSize(arr)==2);
    SortbyQuantity(arr);
    Material *mat1 = (Material*) elemAtIndex(arr,1);
    assert(strcmp(getName(mat1),"paine1")==0);
    DestroyMaterial(mat1);
    DestroyArray(arr);

    destroyController(controller);

}
