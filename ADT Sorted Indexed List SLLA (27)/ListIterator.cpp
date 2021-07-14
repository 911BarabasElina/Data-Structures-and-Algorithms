#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
    this->current=list.head;
}
//Theta(1)
void ListIterator::first(){
    this->current=list.head;
}
//Theta(1)
void ListIterator::next(){
    if(!valid())
        throw exception();
    this->current=list.slla[this->current].next;
}
//Theta(1)
bool ListIterator::valid() const{
    return this->current!=-1;
}
//Theta(1)
TComp ListIterator::getCurrent() const{
    if(!valid())
        throw exception();
    return list.slla[this->current].info;
}
//Theta(1)

void ListIterator::previous() {

    if(!valid())
        throw exception();
    if(this->current==list.head) {
        this->current = -1;
        return;
    }
    int position_of_previous_element;
    position_of_previous_element=list.head;
    while(list.slla[position_of_previous_element].next!= this->current)
    {
        position_of_previous_element=list.slla[position_of_previous_element].next;
    }
    this->current=position_of_previous_element;
}
//O(n)

