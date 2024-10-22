//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_DYNAMICARRAY_H
#define OOP_A4_5_ELIZALUCHIAN_DYNAMICARRAY_H



#pragma once
#include "Event.h"
typedef Event TElem;


template <typename T>
class DynamicArray {
private:
    //A& A::operator=(const A& name); // assignment constructor with b=a
    // A::A(const A& name); // copy constructor from arguments of methods: method(a)
    int size, capacity;
    TElem *elems;
    void resize();
public:
    DynamicArray();
    explicit DynamicArray(int capacity);
    DynamicArray(const DynamicArray& array);
    ~DynamicArray();
    DynamicArray& operator=(const DynamicArray& array);
    void add(const TElem& elem);
    int getSize()const;
    int isFound(const std::string& title)const;
    void deleteEvent(const std::string& title);
    Event eventAtIndex(int index) const;
    void updateEvent(const std::string& title, const Event& event);
    void setEventAtIndex(int index,const Event& event)const;
};

template<typename T>
void DynamicArray<T>::setEventAtIndex(int index,const Event& event)const {

   /* elems[index].setTitle(event.getTitle());
    elems[index].setDescription(event.getDescription());
    elems[index].setNPeople(event.getNumberOfPeople());
    elems[index].setLink(event.getLink());
    elems[index].setDay(event.getDay());
    elems[index].setMonth(event.getMonth());
    elems[index].setYear(event.getYear());
    elems[index].setHours(event.getHours());
    elems[index].setMinutes(event.getMinutes());*/
   elems[index]=event;
}

template <typename  T>
DynamicArray<T>::DynamicArray::DynamicArray() {
    this->capacity = 1;
    this->size = 0;
    this->elems = new TElem[capacity];
}
template <typename T>
DynamicArray<T>::DynamicArray(int capacity) {
    this->capacity=capacity;
    this->size=0;
    this->elems=new TElem[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &array) {
    this->capacity=array.capacity;
    this->size=array.size;
    this->elems = new TElem[this->capacity];
    for (int i = 0; i <this->size ; ++i)
        this->elems[i]=array.elems[i];


}
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray &array){
    delete[] elems;
    this->capacity = array.capacity;
    this->size = array.size;
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < array.size; i++)
        this->elems[i] = array.elems[i];
    return *this;
}
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->elems;
}
template <typename T>

void DynamicArray<T>::resize() {
    this->capacity = this->capacity * 2;
    TElem* newArray = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++) {
        newArray[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = newArray;
}
template <typename T>
void DynamicArray<T>::add(const TElem& elem){
    int index=isFound(elem.getTitle());
    if(index!=-1)
        throw std::exception();
    if(this->size==this->capacity)
        resize();
    this->elems[this->size]=elem;
    this->size++;
}
template <typename T>
int DynamicArray<T>::getSize()const{
    return this->size;
}

template <typename T>
int DynamicArray<T>::isFound(const std::string& title)const{
    for(int i=0; i<this->size; i++)
        if(this->elems[i].getTitle()==title)
            return i;
    return -1;
}

template <typename T>
void DynamicArray<T>::deleteEvent(const std::string& title){
    int index=isFound(title);
    if(index==-1)
        throw std::exception();
    this->elems[index]=this->elems[getSize()-1];
    this->size--;
}

template <typename T>
Event DynamicArray<T>::eventAtIndex(int index) const {
    Event copyevent;
    copyevent=this->elems[index];
    return copyevent;
}

template <typename T>
void DynamicArray<T>::updateEvent(const std::string &title, const Event& event) {
    int index= isFound(title);
    if(index==-1)
        throw std::exception();
    elems[index] = event;


}




#endif //OOP_A4_5_ELIZALUCHIAN_DYNAMICARRAY_H
