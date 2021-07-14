#include "Set.h"
#include "SetIterator.h"
#include <exception>

Set::Set() {

    this->capacity=10;
    this->nrElem=0;
    this->elements=new TElem[this->capacity];
}


bool Set::add(TElem elem) {

    if (search(elem))
        return false;
    if(this->nrElem== this->capacity)
    {
        this->capacity= this->capacity*2;
        auto* new_array= new TElem[this->capacity];
        for(int j=0; j<this->nrElem; j++) {
                new_array[j]= this->elements[j];
            }
        delete[] this->elements;
        this->elements=new_array;
    }
    this->elements[this->nrElem]=elem;
    this->nrElem++;

    return true;

}
// O(n)

bool Set::remove(TElem elem) {

    bool found=false;
    int position=-1;
    for(int i=0; i< this->nrElem; i++)
    {
        if(this->elements[i]==elem) {
            found = true;
            position = i;
        }
    }

    if (!found)
        return false;
    else
    {
     this->elements[position]= this->elements[nrElem-1];
     this->nrElem--;
     return true;
    }
}
// O(n)

bool Set::search(TElem elem) const {

    for(int i=0; i<this->nrElem; i++)
    {
        if(this->elements[i]==elem)
            return true;
    }

    return false;

}
// O(n)

int Set::size() const {
    return this->nrElem;
}
//Theta(1)

bool Set::isEmpty() const {

    if(this->nrElem==0) {
        return true;
    }
    else {
        return false;
    }
}
//Theta(1)

Set::~Set() {

    delete[] this->elements;
}
//Theta(1)

SetIterator Set::iterator() const {
	return SetIterator(*this);
}
//Theta(1)

