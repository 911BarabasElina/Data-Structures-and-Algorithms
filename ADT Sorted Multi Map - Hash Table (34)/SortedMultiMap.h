#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
#include "ValueIterator.h"

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;

class ValueIterator;
typedef bool(*Relation)(TKey, TKey);


struct Node
{
    TKey key;
    TValue value;
    Node* next;
};


class SortedMultiMap {
	friend class SMMIterator;
	friend class ValueIterator;

    private:

    int m;
    int nr_of_elements;
    double load_factor;
    Node** hash_table;
    Relation relation;

    int hash_function(TKey key) const;
    void resize_hash_table();

    public:

    // constructor
    explicit SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    ValueIterator iterator_values(TKey key) ;

    // destructor
    ~SortedMultiMap();
};



