#pragma once
#include "SortedIndexedList.h"


//DO NOT CHANGE THIS PART
class ListIterator{
    friend class SortedIndexedList;
private:
    const SortedIndexedList& list;
    explicit ListIterator(const SortedIndexedList& list);
    int current;

public:
    void first();
    void next();
    bool valid() const;
    TComp getCurrent() const;

//
//    Make the iterator bidirectional. Add the following operation in the SortedListIterator class.
//
////changes the current element from the iterator to the previous element, or, if the current element was the first, makes the iterator invalid
////throws an exception if the iterator is not valid
    void previous();

};


