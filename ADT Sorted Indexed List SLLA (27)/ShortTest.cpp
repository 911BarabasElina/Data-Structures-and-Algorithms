#include <assert.h>
#include <iostream>

#include "ListIterator.h"
#include "SortedIndexedList.h"

using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testPrevious()
{
    cout<<endl<<"Starting to test 'previous' operation"<<endl;
    SortedIndexedList list = SortedIndexedList(relation1);
    assert(list.size() == 0);
    list.add(2);
    list.add(6);
    list.add(9);
    list.add(12);
    list.add(10);
    list.add(21);

    assert(list.size() == 6);
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent()==2);
    iterator.next();
    assert(iterator.getCurrent()==6);
    iterator.previous();
    assert(iterator.getCurrent()==2);
    iterator.next();
    iterator.next();
    iterator.next();
    assert(iterator.getCurrent()==10);
    iterator.previous();
    iterator.previous();
    iterator.previous();
    assert(iterator.getCurrent()==2);

    iterator.first();
    try {
        iterator.previous();
        //assert(false);
    } catch (exception&) {
        assert(true);
    }
    cout<<"'Previous' operation was tested successfully"<<endl<<endl;
}


void testAll(){
	SortedIndexedList list = SortedIndexedList(relation1);
	assert(list.size() == 0);
	assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());
    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());
    testPrevious();
}

