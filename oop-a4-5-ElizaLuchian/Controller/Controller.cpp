//
// Created by 40745 on 24/03/2024.
//

#include "Controller.h"

int CalculateDate(DateTime date)
{
int sum=date.getYear()*3650000+ date.getMonth()*12000+ date.getDay()*100+date.getHours()*10+date.getMinutes();
return sum;
}

AdminRepo Controller::get_admin_repo(){
    return repo;
}

void Controller::addController(const Event& event){
    repo.addRepo(event);
}


void  Controller::deleteController(const std::string &title) {
    repo.deleteRepo(title) ;
}
void Controller::generateController() {
    this->repo.addRepo(Event("Once upon a time in Hollywood", "club night with thematic", 300, "https://www.youtube.com/watch?v=ELeMaP8EPAA",24,3,2024,30,5));
    this->repo.addRepo(Event("Comedy with Jimmy", "comedy show",200, "https://www.youtube.com/watch?v=YuO26oJQLVs",25,3,2004,35,6));
    this->repo.addRepo(Event("Party House", "a club with multiple rooms",1000, "https://www.youtube.com/watch?v=U1fu_sA7XhE",26,3,2005,3,30));
    this->repo.addRepo(Event("Outside Theater", "Caragiale interpretation",100, "https://www.youtube.com/watch?v=oCjiNBiEUaQ",27,3,2024,10,2));
    this->repo.addRepo(Event("Movie Night", "Action",50, "https://www.youtube.com/watch?v=WAdJf4wTC5Y",28,3,2024,40,6));
    this->repo.addRepo(Event("Karting", "Vmax",30, "https://www.youtube.com/watch?v=tcdUhdOlz9M",29,4,2024,10,8));
    this->repo.addRepo(Event("Gameboards Night", "organised by hermes",20, "https://www.youtube.com/watch?v=EXeTwQWrcwY",30,3,2007,21,3));
    this->repo.addRepo(Event("Museum Visit", "History Treasures",7, "https://www.youtube.com/watch?v=iUZ3Yxok6N8",31,3,2024,38,2));
    this->repo.addRepo(Event("Treasure Hunt", "in Cluj",26, "https://www.youtube.com/watch?v=OPQkbvo99Ug",1,4,2024,12,4));
    this->repo.addRepo(Event("Escape Room", "infused wih mitology",5, "https://www.youtube.com/watch?v=1p3NnJ_oiE0",2,3,2024,27,3));
}
int Controller::get_size_Controller()const{
    return repo.get_size_repo();
}

DynamicArray<Event> Controller::getAllElemsController() const{

    return repo.getAllElements();
}

Controller::Controller() : repo(), repo_user() {

}
void Controller::updateController(const std::string& title, const Event& event) {
    Event newEvent = repo.getElemwithTitle(title);
    if(!event.getDescription().empty())
        newEvent.setDescription(event.getDescription());
    if(!event.getLink().empty())
        newEvent.setLink(event.getLink());
    if(event.getNumberOfPeople()!=-1)
        newEvent.setNPeople(event.getNumberOfPeople());
    if(event.getDay()!=-1)
        newEvent.setDay(event.getDay());
    if(event.getMonth()!=-1)
        newEvent.setMonth(event.getMonth());
    if(event.getYear()!=-1)
        newEvent.setYear(event.getYear());
    if(event.getMinutes()!=-1)
        newEvent.setMinutes(event.getMinutes());
    if(event.getHours()!=-1)
        newEvent.setHours(event.getHours());
    repo.updateRepo(title, newEvent);
}

UserRepo Controller::get_user_repo(){
    return repo_user;
}

void Controller::addUserController(const Event &event) {
    DynamicArray<Event>arr=repo.getAllElements();
    //Event event1=repo.getElemwithTitle(event.getTitle());
    repo_user.addEventUser(event);
    Event event1=arr.eventAtIndex(arr.isFound(event.getTitle()));
   event1.setNPeople(event.getNumberOfPeople()+1);

    repo.updateRepo(event.getTitle(),event1);

}

void Controller::removeEventController(const std::string& title) {
    DynamicArray<Event>arr=repo.getAllElements();
    Event event=repo.getElemwithTitle(title);
repo_user.removeEventUser(title);
    Event event1=arr.eventAtIndex(arr.isFound(title));
    event1.setNPeople(event.getNumberOfPeople()-1);
    repo.updateRepo(title,event1);
}


DynamicArray<Event> Controller::getEventsbyMonth(int month) const {
    DynamicArray<Event> array=repo.getAllElements();
    DynamicArray<Event> arr;
    Event aux;
    if(month!=-1)
    {for(int i=0; i<array.getSize(); i++)
        if(array.eventAtIndex(i).getMonth()==month)
            arr.add(array.eventAtIndex(i));
    return arr;}
    else
    {
        for(int i=0; i<array.getSize()-1; i++)
            for(int j=i+1; j<array.getSize(); j++)
                if(CalculateDate(array.eventAtIndex(i).getDate())> CalculateDate(array.eventAtIndex(j).getDate()))
                { aux=array.eventAtIndex(i);
                    array.setEventAtIndex(i,array.eventAtIndex(j));
                    array.setEventAtIndex(j,aux);
                }
        return array;
    }


}

DynamicArray<Event> Controller::getAllEventsController() const {
    return this->repo_user.getEventList();
}



