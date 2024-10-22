//
// Created by 40745 on 02/04/2024.
//
#include <iostream>
#include "Ui/Ui.h"
#include "Tests/Test.h"

using namespace std;
int main()
{   Test();
    Ui ui=Ui();
    int input;
    ui.generate();
    while(1)
    {
        try{
            ui.menu();
            cout<<endl<<"input:  ";
            cin>>input;
            cin.get();
            if(input==1)
                ui.addUi();
            else if(input==2)
                ui.display();
            else if(input==3)
                ui.filterUi();
            else if(input==0)
                break;
        }catch (runtime_error &exception){cout<<exception.what();};
    }
    return 0;
}