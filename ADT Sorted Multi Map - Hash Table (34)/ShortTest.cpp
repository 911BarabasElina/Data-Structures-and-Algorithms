#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());
}

void test_new_it()
{
    SortedMultiMap smm = SortedMultiMap(relation1);
    smm.add(1,2);
    smm.add(1,3);
    smm.add(2,6);
    smm.add(2,5);
    smm.add(2,4);
    smm.add(2,7);
    smm.add(3,3);
    ValueIterator it = smm.iterator_values(2);

    assert(it.getCurrent_vi()==4);
    it.next_vi();
    assert(it.getCurrent_vi()==5);
    it.next_vi();
    assert(it.getCurrent_vi()==6);

    it.first_vi();
    assert(it.getCurrent_vi()==4);
    it.next_vi();
    it.next_vi();
    assert(it.valid_vi()== true);

    ValueIterator it2 = smm.iterator_values(9);
    assert(it2.valid_vi()== false);

    cout<<endl<<"Test iterator of values"<<endl;
}