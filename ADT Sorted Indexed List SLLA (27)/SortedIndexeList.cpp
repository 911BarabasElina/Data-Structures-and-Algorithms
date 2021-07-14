#include "ListIterator.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
    this->capacity = 1;
    this->length = 0;
    this->head = -1;
    this->first_empty = 0;
    this->relation = r;
    this->slla = new node[1];
    this->slla[this->first_empty].next=-1;
}
//Theta(1)
int SortedIndexedList::size() const {
    return this->length;
}
//Theta(1)
bool SortedIndexedList::isEmpty() const {
    return this->length == 0;
}
//Theta(1)
TComp SortedIndexedList::getElement(int pos) const{
    if(pos<0 || pos>=this->length)
        throw exception();

    int position_of_the_current_node;
    position_of_the_current_node=this->head;
    int counter;
    counter=0;

    while(counter!=pos)
    {
        position_of_the_current_node=this->slla[position_of_the_current_node].next;
        counter++;
    }

    return this->slla[position_of_the_current_node].info;
}
//O(n)
TComp SortedIndexedList::remove(int pos) {
    if(pos<0 || pos>=this->length)
        throw exception();

    if(pos == 0)
    {
        TComp removed;
        removed=this->slla[this->head].info;

        int reclaimed_node = this->head;
        this->head=this->slla[this->head].next;

        this->slla[reclaimed_node].next = this->first_empty;
        this->first_empty = reclaimed_node;

        this->length--;
        return removed;
    }

    int previous_node = this->head;
    while(pos > 1) {
        previous_node = this->slla[previous_node].next;
        pos--;
    }

    int reclaimed_node = this->slla[previous_node].next;
    this->slla[previous_node].next = this->slla[reclaimed_node].next;

    this->slla[reclaimed_node].next = this->first_empty;
    this->first_empty = reclaimed_node;

    this->length--;
    return this->slla[reclaimed_node].info;
}
//O(n)
int SortedIndexedList::search(TComp e) const {
    int searched_position;
    int position_of_the_current_node;

    position_of_the_current_node=this->head;
    searched_position=0;

    while(position_of_the_current_node!=-1 && this->slla[position_of_the_current_node].info!=e)
    {
        searched_position++;
        position_of_the_current_node=this->slla[position_of_the_current_node].next;
    }

    if(position_of_the_current_node==-1)
        return -1;
    return searched_position;
}
//O(n)
void SortedIndexedList::add(TComp e) {

    if(this->length==this->capacity-1)
        this->resize();

    if(this->length==0)
    {
        this->head=this->first_empty;
        this->first_empty=this->slla[first_empty].next;
        this->slla[this->head].info=e;
        this->slla[this->head].next=-1;
    }
    else if(this->relation(e, this->slla[this->head].info))
    {
        int position_of_new_node;
        position_of_new_node=this->first_empty;
        this->first_empty=this->slla[first_empty].next;
        this->slla[position_of_new_node].next= this->head;
        this->slla[position_of_new_node].info=e;
        this->head=position_of_new_node;
    }
    else {
        int position_of_current_node = this->head;
        int position_of_next_node = this->slla[position_of_current_node].next;

        while(position_of_next_node != -1 && !this->relation(e, this->slla[position_of_next_node].info)) {
            position_of_current_node = position_of_next_node;
            position_of_next_node = this->slla[position_of_current_node].next;
        }

        int position_of_new_node = first_empty;
        first_empty = this->slla[first_empty].next;

        this->slla[position_of_new_node].info=e;
        this->slla[position_of_new_node].next=position_of_next_node;

        this->slla[position_of_current_node].next = position_of_new_node;
    }

    this->length++;
}
//O(n)
ListIterator SortedIndexedList::iterator(){
    return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
    delete[] this->slla;
}

void SortedIndexedList::resize() {
    this->capacity = this->capacity * 2;
    auto resized_array = new node[this->capacity];
    for(int i = 0; i < this->capacity / 2; i++)
        resized_array[i] = this->slla[i];

    delete[] this->slla;
    this->slla = resized_array;

    this->slla[this->capacity - 1].next = this->first_empty;
    for(int current_new_node = this->capacity - 2; current_new_node >= this->capacity / 2; current_new_node--) {
        this->slla[current_new_node].next = current_new_node + 1;
    }

    this->first_empty = this->capacity / 2;
}
//Theta(n)