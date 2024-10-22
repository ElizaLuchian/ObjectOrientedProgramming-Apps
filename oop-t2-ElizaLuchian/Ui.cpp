//
// Created by 40745 on 23/04/2024.
//

#include <iostream>
#include <cstring>
#include "Ui.h"
#include "NeonatalUnit.h"
#include "Surgery.h"

Ui::Ui(): controller() {

}

void Ui::start() {
    int input, nrDoctors, Nrpatients;
    char name[100], Type[100], filename[100];
    double averageGrade;
    controller.generate();
    while(1)
    {
        cout<<"Choose option: \n";
        cout<<"1.Add a new department: \n";
        cout<<"2.Show all departments: \n";
        cout<<"3. Show efficient departments: \n";
        cout<<"4. Save to file efficient departments sorted: \n";
        cout<<"0. Exit\n";

        cout<<" input: ";
        cin>>input;
        cin.get();
        if(input==1)
        {
            cout<<"Hospital name:  ";
            cin.getline(name, 100);

            cout<<"Nr of Doctors:  ";
            cin>>nrDoctors;
            cin.get();
            cout<<" Type:  ";
            cin.getline(Type, 100);

            if(strcmp (Type, "Neonatal")==0)
            {
                cout<<"average Grade:  ";
                cin>>averageGrade;

                NeonatalUnit * n1 = new NeonatalUnit(name, nrDoctors, averageGrade);
                controller.addDepartment(n1);

            }
            else if(strcmp(Type, "Surgery")==0)
            {
                cout<<"NR Patients:  ";
                cin>>Nrpatients;

                Surgery * s1 = new Surgery(name, nrDoctors, Nrpatients);
                controller.addDepartment(s1);
            }

        }
        else if(input ==2)
        {
            vector <HospitalDepartment * > arr= controller.getAllDepartments();
            for(auto &elem: arr)
            {
                cout<<elem->toString()<<"\n";
            }
        }
        else if(input==3)
        {
            vector <HospitalDepartment * > arr= controller.getEfficientDepartments();
            for(auto &elem: arr)
            {
                cout<<elem->toString()<<"\n";
            }
        }
        else if(input==4)
        { cout<<"filename: ";
            cin.getline(filename, 100);



            controller.writeToFile(filename);
        }
        else if(input ==0)
            break;
    }

}
