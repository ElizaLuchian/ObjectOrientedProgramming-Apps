//
// Created by 40745 on 25/03/2024.
//

#include <iostream>
#include "ui.h"
#include <utility>
#include <cstdlib>



using namespace std;

ui::ui() : controller() {

}

void deleteBuffer() {
    cin.clear();
    cin.ignore(100, '\n');
}

void ui::admin_menu() {
    cout << "Choose a command by typing its corresponding number:\n"
            "1. Add an event into the database.\n"
            "2. Remove an event from the database.\n"
            "3. Update an event from the database.\n"
            "4. Display all the events.\n"
            "0. Exit\n";
    cout << endl;
}

void ui::user_menu() {
    cout<<"Choose one of the options below:  \n";
    cout<<"1. See the events in the database:  \n";
    cout<<"3. Delete an event form the personal list: \n";
    cout<<"4. See his own personal list: \n";
    cout<<"0. Exit. \n";

}
void ui::addAdmin() {
    try {
        char title[100], description[100], link[100];
        int nrPeople, day, month, year, minutes, hour;
        cout << "provide title of the event:  ";
        if (!(cin.getline(title, 100))) {
            deleteBuffer();
            throw exception();
        }


        cout << "provide description of the event:  ";
        if (!(cin.getline(description, 100))) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide link to the event";
        if (!(cin.getline(link, 100))) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide number of people at the event:  ";
        if (!(cin >> nrPeople)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide day: ";
        if (!(cin >> day)) {
            deleteBuffer();
            throw exception();
        }

        cout << "provide month: ";
        if (!(cin >> month)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide year: ";
        if (!(cin >> year)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide the minutes: ";
        if (!(cin >> minutes)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide the hour: ";
        if (!(cin >> hour)) {
            deleteBuffer();
            throw exception();
        }

        Event event = Event(title, description, nrPeople, link, day, month, year, minutes, hour);

        controller.addController(event);
    }
    catch (exception &exception) {
        cout << "Error while trying to add new event.\n";
    }
}
void ui::updateAdmin() {
    try {
        char title[100], description[100], link[100];
        int nrPeople, day, month, year, minutes, hour;
        cout << "provide title of the event:  ";
        if (!(cin.getline(title, 100))) {
            deleteBuffer();
            throw exception();
        }


        cout << "provide description of the event or empty space to not change it:  ";
        if (!(cin.getline(description, 100))) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide link to the event or empty space to not change it: ";
        if (!(cin.getline(link, 100))) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide number of people at the event or -1 to not change it:  ";
        if (!(cin >> nrPeople)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide day or -1 to not change it: ";
        if (!(cin >> day)) {
            deleteBuffer();
            throw exception();
        }

        cout << "provide month or -1 to not change it: ";
        if (!(cin >> month)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide year or -1 to not change it: ";
        if (!(cin >> year)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide the minutes or -1 to not change it: ";
        if (!(cin >> minutes)) {
            deleteBuffer();
            throw exception();
        }
        cout << "provide the hour or -1 to not change it: ";
        if (!(cin >> hour)) {
            deleteBuffer();
            throw exception();
        }

        Event event = Event(title, description, nrPeople, link, day, month, year, minutes, hour);

        controller.updateController(title, event);
    }
    catch (exception &exception) {
        cout << "Error while trying to update event.\n";
    }
}

void ui::deleteAdmin() {
    try {
        string title;
        cout << "provide the title for searching: ";
        cin >> title;
        controller.deleteController(title);
    }
    catch (exception &exception) {
        cout << "error while trying to delete a new event"<<endl;
    }

}

void ui::displayAdmin() {
    DynamicArray<Event> array = controller.getAllElemsController();
    for (int i = 0; i < controller.get_size_Controller(); i++) {
        cout << "title: " << array.eventAtIndex(i).getTitle() << endl;
        cout << "description: " << array.eventAtIndex(i).getDescription() << endl;
        cout << "link: " << array.eventAtIndex(i).getLink() << endl;
        cout << "number of people: " << array.eventAtIndex(i).getNumberOfPeople() << endl;
        cout << "date:" << array.eventAtIndex(i).getDay() << " " << array.eventAtIndex(i).getMonth() << " "
             << array.eventAtIndex(i).getYear() <<" "<<"time:  "<<array.eventAtIndex(i).getHours()<<":"<<array.eventAtIndex(i).getMinutes()<< endl << endl;

    }
}
void ui::generateDatabase() {
    controller.generateController();
    displayAdmin();
}


void ui::remove_user() {
    char title[100];

    cout<<"provide the title of the event you want to remove:  ";
    cin.getline(title,100);
    controller.removeEventController(title);
}

void ui::displayPersonalEventlist() {
    DynamicArray<Event> array = controller.getAllEventsController();
    for (int i = 0; i < array.getSize(); i++) {
        cout << "title: " << array.eventAtIndex(i).getTitle() << endl;
        cout << "description: " << array.eventAtIndex(i).getDescription() << endl;
        cout << "link: " << array.eventAtIndex(i).getLink() << endl;
        cout << "number of people: " << array.eventAtIndex(i).getNumberOfPeople() << endl;
        cout << "date:" << array.eventAtIndex(i).getDay() << " " << array.eventAtIndex(i).getMonth() << " "
             << array.eventAtIndex(i).getYear() <<" "<<"time:  "<<array.eventAtIndex(i).getHours()<<":"<<array.eventAtIndex(i).getMinutes()<< endl << endl;

    }

}
void ui::start() {
    char input[100];
    int number, month, choice, choicetoendit=1;
    generateDatabase();
    while (1) {
        try {
            cout << "provide option(admin/user):    ";
            cin >> input;

            if (string(input) == "admin") {
                admin_menu();
                cout << "provide option(number between 1-4 or 0):    ";

                if (!(cin >> number)) {
                    deleteBuffer();
                    throw exception();
                }
                cin.get();
                if (number == 1)
                    addAdmin();
                else if (number == 2)
                    deleteAdmin();
                else if (number == 3)
                    updateAdmin();
                else if (number == 4)
                    displayAdmin();
                else if (number == 0)
                    return;
                else {
                    cout << "number should be between 1-4" << endl;
                    continue;
                }


            } else if (string(input) == "user") {
                user_menu();
                cout << "provide option(number between 1-3 or 0):    ";
                if (!(cin >> number)) {
                    deleteBuffer();
                    throw exception();
                }
                cin.get();
                if (number == 1) {
                    cout << "please introduce the month after you are searching:   ";
                    cin >> month;
                    DynamicArray<Event> list = controller.getEventsbyMonth(month);

                    if (list.getSize() == 0) {
                        cout << "there are no events in that month\n";
                        return;
                    }
                    choicetoendit=1;
                    while (choicetoendit) {
                        for (int i = 0; i < list.getSize(); i++) {
                            cout << "title: " << list.eventAtIndex(i).getTitle() << endl;
                            cout << "description: " << list.eventAtIndex(i).getDescription() << endl;

                            cout << "number of people: " << list.eventAtIndex(i).getNumberOfPeople() << endl;
                            cout << "date:" << list.eventAtIndex(i).getDay() << " " << list.eventAtIndex(i).getMonth()
                                 << " "
                                 << list.eventAtIndex(i).getYear() << " " << "time:  "
                                 << list.eventAtIndex(i).getHours()
                                 << ":" << list.eventAtIndex(i).getMinutes() << endl << endl;
                            cout << "link: " << list.eventAtIndex(i).getLink() << endl;
                            string command = "start " + list.eventAtIndex(i).getLink();
                             system(command.c_str());
                           // ShellExecute(NULL,"open", list.eventAtIndex(i).getLink().c_str(),NULL,NULL,SW_SHOWNORMAL);


                            if(list.getSize()!=controller.getAllEventsController().getSize())
                            { cout << "do you wish to add this event to your event list?Write 1 if you want\n";
                            cin >> choice;
                            if (choice == 1)
                                controller.addUserController(list.eventAtIndex(i));}
                            else
                                cout<<"you added all the events to your list\n";
                            cout << "do you wish to continue, choose 0 if not:\n";
                            cin >> choicetoendit;
                            if (choicetoendit == 0)
                                break;


                        }
                    }
                    continue;
                }
                   else if(number==3)
                        remove_user();
                   else if(number==4)
                        displayPersonalEventlist();
                   else if (number == 0)
                        break;
                }
            else
                cout << "try again writing admin or user" << endl;



            }

            catch (exception & exception)
            {
                cout << "Some error occurred\n";
            }
        }

    }












