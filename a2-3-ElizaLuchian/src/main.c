#include <stdio.h>
#include <stdlib.h>
#include "tests/Tests.h"
#include "ui/Ui.h"

int main()
{
    Tests();
    MaterialUI *ui=CreateUi();
    Generate(ui);
    while(1)
    {

        Menu();
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1:
                addUI(ui);
                break;
            case 2:
                deleteUI(ui);
                break;
            case 3:
                updateUI(ui);
                break;
            case 4:
                filterUI(ui);
                break;
            case 5:
                printAll(getMaterials(getRepo(ui->controller)));
                break;
            case 6:
                displayFromGivenSupplierUI(ui);
                break;
            case 7:
                undoUI(ui);
                break;
            case 8:
                redoUI(ui);
                break;
            case 0:
                destroyUI(ui);
                return 0;
                break;
            default:
                break;
        }
    }
}















/*
 * #include <stdio.h>
#include <string.h>


/*Bakery
Mary runs her family's bakery, “Bread'n Bagel”.
 Every day she struggles with keeping up to
 date with available stocks of raw materials and would like a program
 to help her manage the business more effectively. Each Material used
 in the bakery must have: a name, a supplier, a quantity and the expiration date.
 Mary wants a software application that helps her in the following ways:

(a) Add, delete and update a material. A raw material is uniquely identified by
 its name, supplier and expiration date. If a material that already exists is added,
 its quantity will be modified (the new quantity is added to the existing one).
(b) See all available materials past their expiration date, containing a given
 string (if the string is empty, all materials past their expiration date will
 be considered).
(c) Display all materials from a given supplier, which are in short supply
 (quantity less than a user-provided value), sorted ascending by their quantities.
(d) Provide multiple undo and redo functionality. Each step will undo/redo
 the previous operation performed by the user.

typedef struct {
    Material List[100];
    int dimension;
} MatArrayRepo;


Material CreateMaterial(char name[100], char supplier[100], int quantity, Date date) {
    Material material;
    strcpy(material.name, name);
    strcpy(material.supplier, supplier);
    material.quantity = quantity;
    material.expiration_date = date;
    return material;
}

int SearchIndex(MatArrayRepo m, Material mat) {
    for (int i = 0; i < (m).dimension; i++)
        if ((m).List[i].expiration_date.year == mat.expiration_date.year &&
            (m).List[i].expiration_date.month == mat.expiration_date.month &&
            (m).List[i].expiration_date.day == mat.expiration_date.day &&
            strcmp((m).List[i].supplier, mat.supplier) == 0 && strcmp((m).List[i].name, mat.name) == 0)
            return i;

    return -1;
}

void add(MatArrayRepo *m, Material mat) {
    int index = SearchIndex((*m), mat);
    if (index != -1) {
        (*m).List[index].quantity = (*m).List[index].quantity + mat.quantity;
        return;
    }

    (*m).List[(*m).dimension] = mat;
    (*m).dimension++;
}

int Delete(MatArrayRepo *m, Material t) {
    int index = SearchIndex((*m), t);
    if (index != -1) {
        (*m).List[index] = (*m).List[(*m).dimension - 1];
        (*m).dimension--;
        return 1;
    }
    return 0;
}

//void ExpiredMaterials(MattArrayRepo *m, Date date,)
int Update(MatArrayRepo *m, Material p, int quantity) {
    int index = SearchIndex((*m), p);
    if (index != -1) {
        (*m).List[index].quantity = quantity;
        return 1;
    }


    return 0;

}

int IsGreaterDate(Date d1, Date d2) {
    int days1 = (d1.year) * 365 + (d1.month) * 31 + (d1.day);
    int days2 = (d2.year) * 365 + (d2.month) * 31 + (d2.day);
    if (days1 > days2)
        return 1;
    return 0;

}

MatArrayRepo ExpiredMaterial(MatArrayRepo *m, Date data1, char string[]) {
    MatArrayRepo subm;
    (subm).dimension = 0;
    if (strcmp(string, "") != 0) {
        for (int i = 0; i < (*m).dimension; i++)
            if (((strstr((*m).List[i].name, string) != NULL || strstr((*m).List[i].supplier, string) != NULL)) &&
                IsGreaterDate(data1, (*m).List[i].expiration_date) == 1) {
                (subm).List[(subm).dimension] = (*m).List[i];
                (subm).dimension++;
            }
        return subm;
    }
    else
    {
        for (int i = 0; i < (*m).dimension; i++)
            if ( IsGreaterDate(data1, (*m).List[i].expiration_date) == 1)
                 {
                (subm).List[(subm).dimension] = (*m).List[i];
                (subm).dimension++;
            }
        return subm;
    }
}

void afis(MatArrayRepo m) {
    for (int i = 0; i < m.dimension; i++) {
        printf("the name of the material is:  ");
        printf("%s\n", m.List[i].name);
        printf("the name of the supplier is:  ");
        printf("%s\n", m.List[i].supplier);
        printf("the quantity of the material is:  ");
        printf("%d\n", m.List[i].quantity);
        printf("the expiration date is: ");
        printf("%d ", m.List[i].expiration_date.day);

        printf("%d ", m.List[i].expiration_date.month);

        printf("%d\n\n", m.List[i].expiration_date.year);
    }
}




int main(int argc, char *argv[]) {
    MatArrayRepo v;
    v.dimension = 0;
    while (1) {
        int input;

        printf("Menu\n");
        printf("Choose one option:\n");
        printf("1. Add one material\n");
        printf("2. Delete one material\n");
        printf("3. Update one material\n");
        printf("4. See all available materials\n");
        printf("5. print the array\n");
        printf("0. Exit");
        printf(">:");
        scanf("%d", &input);
        if (input == 1) {
            char name[100], supplier[100];
            int quantity;
            int day, month, year;


            printf("provide the name of the material:\n");
            scanf("%s", name);
            printf("provide the name of the supplier:\n");
            scanf("%s", supplier);
            printf("provide the expiration date:\n");
            scanf("%d %d %d", &day, &month, &year);
            printf("provide the quantity of the material:\n");
            scanf("%d", &quantity);

            Material material = CreateMaterial(name, supplier, quantity, CreateDate(year, month, day));

            add(&v, material);

            afis(v);
        } else if (input == 2) {
            char name[100], supplier[100];
            int quantity;
            int day, month, year;

            printf("provide the name of the material:\n");
            scanf("%s", name);
            printf("provide the name of the supplier:\n");
            scanf("%s", supplier);
            printf("provide the expiration date:\n");
            scanf("%d %d %d", &day, &month, &year);

            Material material = CreateMaterial(name, supplier, 0, CreateDate(year, month, day));
            Delete(&v, material);


        } else if (input == 3) {
            char name[100], supplier[100];
            int quantity;
            int day, month, year;


            printf("provide the name of the material:\n");
            scanf("%s", name);
            printf("provide the name of the supplier:\n");
            scanf("%s", supplier);
            printf("provide the expiration date:\n");
            scanf("%d %d %d", &day, &month, &year);
            printf("read the quantity for update: ");
            scanf("%d", &quantity);
            Material material = CreateMaterial(name, supplier, 0, CreateDate(year, month, day));
            Update(&v, material, quantity);


        } else if (input == 4) {
            int day, month, year;
            MatArrayRepo var;
            char string[100];
            printf("provide the expiration date:\n");
            scanf("%d %d %d", &day, &month, &year);
            Date data1 = CreateDate(year, month, day);
            fgetc(stdin); //iau urmatorul caracter ca sa nu imi ia \n ca string
            fgets(string, 100, stdin);
            string[strlen(string)-1]=0;
            var = ExpiredMaterial(&v, data1, string);
            if ((var).dimension != 0)
                afis(var);
            else
                printf("doesn't exist");
        } else if (input == 5)
            afis(v);
        else if (input == 0)
            break;
    }
    return 0;
}
*/
