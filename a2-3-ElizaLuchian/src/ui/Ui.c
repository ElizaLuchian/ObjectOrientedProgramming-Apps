//
// Created by 40745 on 15/03/2024.
//

#include "Ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

MaterialUI *CreateUi()
{
    MaterialUI *ui= (MaterialUI*)malloc(sizeof(MaterialUI));
    if(ui==NULL)
        return NULL;
    ui->controller = CreateController();
    if (ui->controller== NULL) {
        free(ui);
        return NULL;

    }
    return ui;
}
void printAll(DynamicArray *arr) {
    for (int i = 0; i < getSize(arr); i++) {
        Material *material = elemAtIndex(arr, i);
        printf(" | ");
        printf("%s", getName(material));
        printf(" | ");
        printf("%s", getSupplier(material));
        printf(" | ");
        printf("%d", getQuantity(material));
        printf(" | ");
        printf("%d/", getExpirationDay(material));

        printf("%d/", getExpirationMonth(material));

        printf("%d\n", getExpirationYear(material));

        DestroyMaterial(material);
    }
    printf("\n\n");
}

void Menu() {
    printf("Menu\n");
    printf("Choose one option:\n");
    printf("1. Add one material\n");
    printf("2. Delete one material\n");
    printf("3. Update one material\n");
    printf("4. See all available materials\n");
    printf("5. print the array\n");
    printf("6. display from the supplier\n");
    printf("7. Undo\n");
    printf("8. Redo\n");

    printf("0. Exit");
    printf(">:");
}

void addUI(MaterialUI *ui) {
    char name[100], supplier[100];
    int quantity;
    int day, month, year;

    printf("provide the name of the material:\n");
    scanf("%s", name);
    printf("provide the name of the supplier:\n");
    scanf("%s", supplier);
    printf("provide the expiration date:\n");
    scanf("%d %d %d", &day, &month, &year);

    if((day>31 || day<1) || (month>12 || month<1) || year<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }

        printf("provide the quantity of the material:\n");

    scanf("%d", &quantity);
    if(quantity<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }

    addController(ui->controller, name, supplier, quantity, day, month, year);
}

void Generate(MaterialUI *ui) {
    srand(time(NULL));

    char *Supplier[] = {"Popescu", "Florescu", "Negoita", "Coco", "Cosmin", "Catalin", "Cacalin", "Dobrescu",
                        "Floricica", "Sobolici", "Bandula", "Labo", "Nikole"};
    char *Name[] = {"paine", "lapte", "branza", "zahar", "miere", "faina", "malai", "ciocolata", "seminte", "oua",
                    "unt"};

    for (int i = 0; i < 10; i++) {
        char *name1 = Name[rand() % 10];
        char *supplier = Supplier[rand() % 10];
        int quantity = rand() % 100;
        int day = rand() % 28 + 1;
        int month = rand() % 12 + 1;
        int year = 2024;
        addController(ui->controller, name1, supplier, quantity, day, month, year);
    }
    printAll(getMaterials(getRepo(ui->controller)));
}

void deleteUI(MaterialUI *ui) {
    char name[100], supplier[100];
    int day, month, year;

    printf("provide the name of the material:\n");
    scanf("%s", name);

    printf("provide the name of the supplier:\n");
    scanf("%s", supplier);
    printf("provide the expiration date:\n");
    scanf("%d %d %d", &day, &month, &year);
    if((day>31 || day<1) || (month>12 || month<1) || year<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }
    deleteController(ui->controller, name, supplier, day, month, year);
}

void updateUI(MaterialUI *ui) {
    char name[100], supplier[100];
    int quantity;
    int day, month, year;

    printf("provide the name of the material:\n");
    scanf("%s", name);
    printf("provide the name of the supplier:\n");
    scanf("%s", supplier);
    printf("provide the expiration date:\n");
    scanf("%d %d %d", &day, &month, &year);
    if((day>31 || day<1) || (month>12 || month<1) || year<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }
    printf("read the quantity for update: ");
    scanf("%d", &quantity);
    if( quantity<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }
    updateController(ui->controller, name, supplier, quantity, day, month, year);
}

void filterUI(MaterialUI *ui) {
    int day, month, year, Filtermethod;
    char s1[100];
    printf("provide a new date:\n");
    scanf("%d %d %d", &day, &month, &year);

    if((day>31 || day<1) || (month>12 || month<1) || year<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }
    printf("provide a filter type:\n");
    scanf("%d", &Filtermethod);
    printf("provide a string:\n");
    fgetc(stdin); //iau urmatorul caracter ca sa nu imi ia \n ca string
    fgets(s1, 100, stdin);
    s1[strlen(s1) - 1] = 0;
    DynamicArray  *arr=tryFilter(ui->controller, day, month, year, s1, Filtermethod);
    printAll(arr);
    DestroyArray(arr);


}

void displayFromGivenSupplierUI(MaterialUI *ui) {
    char s1[100];
    int Quantity;
    int typeSort;
    printf("provide the searched supplier:\n");
    scanf("%s", s1);
    printf("provide the quantity for comparison:\n");
    scanf("%d", &Quantity);
    if(Quantity<0)
    {
        printf("Invalid input. Try using another one!");
        return;
    }
    printf("provide the type of the Sort supplier:\n");
    scanf("%d", &typeSort);
    DynamicArray *arr = DisplayFromSupplierController(ui->controller, s1, Quantity, typeSort);
    printAll(arr);
    DestroyArray(arr);
}

void destroyUI(MaterialUI *ui) {
    destroyController(ui->controller);
    free(ui);
}

void undoUI(MaterialUI *ui) {
    UndoOperations(ui->controller);
}

/*void trySort(DynamicArray *arr, SorthingMethod sorthingMethod)
{
    sorthingMethod(arr);
}*/
void redoUI(MaterialUI *ui)
{
    RedoOperations(ui->controller);
}

