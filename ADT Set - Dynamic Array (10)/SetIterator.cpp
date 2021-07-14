#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->current=0;
}
// Theta (1)


void SetIterator::first() {
    this->current=0;
}
// Theta (1)

void SetIterator::next() {

    if(this->current >=this ->set.nrElem)
    {
        throw exception();
    }
    else{
        this->current++;
    }
}
// Theta (1)

TElem SetIterator::getCurrent()
{
    if(this->current >=this ->set.nrElem)
    {
        throw exception();
    }
    else{
        return this->set.elements[this->current];
    }
}
// Theta (1)
bool SetIterator::valid() const {
    if(this->current < this->set.nrElem)
    {
        return true;
    }
    else{
        return false;
    }
}
// Theta (1)


