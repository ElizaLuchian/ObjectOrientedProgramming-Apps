//
// Created by 40745 on 26/03/2024.
//

#include "Tests.h"
#include "../Controller/Controller.h"
#include "DynamicArray.h"
#include "Tests.h"
#include <cassert>



void testAdd() {
    Controller controller = Controller();

Event event=Event("EventTitle", "EventDescription", 90, "EventLink",3, 3, 2004, 20, 11);

    controller.addController(event);


    DynamicArray <Event>array = controller.getAllElemsController();


    assert(array.getSize() == 1);
    Event event1=Event("EventTitle", "EventDescription", 90, "EventLink",3, 3, 2004, 20, 11);
    try{    controller.addController(event1); assert(false);}
    catch(std::exception & exception){assert(true);}


}


void testDelete() {
    Controller controller;
    AdminRepo repo=controller.get_admin_repo();


    Event event=Event("Title", "Description", 80, "Link",15, 6, 2025, 35, 12);

    controller.addController(event);


    controller.deleteController("Title");


    DynamicArray<Event> arr = controller.getAllElemsController();


    assert(arr.getSize() == 0);
    try{    repo.deleteRepo("Title");
        assert(false);}
    catch(std::exception & exception){assert(true);
    }
}


void testUpdateEvent() {
    Controller controller = Controller();
    AdminRepo repo=controller.get_admin_repo();


    Event event=Event("Title", "Description", 400, "Link",2, 2, 2003, 30, 10);

    controller.addController(event);


    Event event1=Event("Title", "Description123", 200,"Link123", 2, 5, 2004, 0, 7);
    controller.updateController("Title", event1);

    // Retrieve all events
    DynamicArray<Event> events = controller.getAllElemsController();

    // Find the updated event
    int index = events.isFound("Title");
    assert(index != -1); // Event should exist

    // Retrieve the updated event
    Event updatedEvent = events.eventAtIndex(index);


    // Check if the event is updated correctly
    assert(updatedEvent.getDescription() == "Description123");
    assert(updatedEvent.getLink() == "Link123");
    assert(updatedEvent.getNumberOfPeople() == 200);

   assert(updatedEvent.getYear() == 2004);
 assert(updatedEvent.getMonth() == 5);
 assert(updatedEvent.getDay() == 2);
 assert(updatedEvent.getHours() == 7);
  assert(updatedEvent.getMinutes() == 0);

    try{    repo.updateRepo("123", event1); assert(false);}
    catch(std::exception & exception){assert(true);}
}

void testAddUser()
{
    Controller controller = Controller();
    UserRepo repo=controller.get_user_repo();
    Event event=Event("EventTitle", "EventDescription", 90, "EventLink",3, 3, 2004, 20, 11);
    controller.addController(event);
    controller.addUserController(event);


    DynamicArray <Event>array = controller.getAllEventsController();


    assert(array.getSize() == 1);

}
void testDeleteUser() {
    Controller controller;


    Event event=Event("Title", "Description", 80, "Link",15, 6, 2025, 35, 12);
    controller.addController(event);
    controller.addUserController(event);


    controller.removeEventController("Title");


    DynamicArray<Event> arr = controller.getAllEventsController();


    assert(arr.getSize() == 0);
}
void testGetEventsbyMont(){
    Controller controller;
    Event event=Event("Title2", "Description", 80, "Link",15, 6, 2025, 35, 12);
    Event event1=Event("Title1", "Description", 80, "Link",23, 7, 2025, 35, 12);
    Event event2=Event("Title", "Description", 80, "Link",15, 7, 2025, 35, 12);
    controller.addController(event);
    controller.addController(event1);
    controller.addController(event2);
    DynamicArray<Event>array=controller.getEventsbyMonth(7);
    assert(array.getSize()==2);

    assert(array.eventAtIndex(0).getTitle()=="Title1");
    assert(array.eventAtIndex(1).getTitle()=="Title");

    DynamicArray<Event>arr=controller.getEventsbyMonth(-1);
    assert(arr.getSize()==3);

    assert(arr.eventAtIndex(0).getTitle()=="Title2");
    assert(arr.eventAtIndex(1).getTitle()=="Title");
    assert(arr.eventAtIndex(2).getTitle()=="Title1");



}
void testSetTitle()
{
    Event event=Event("Title2", "Description", 80, "Link",15, 6, 2025, 35, 12);
    event.setTitle("Title");
    assert(event.getTitle()=="Title");
}
Tests::Tests()
{
    testAdd();
    testDelete();
    testUpdateEvent();
    testAddUser();
    testDeleteUser();
   testGetEventsbyMont();
   testSetTitle();

}