#pragma once



#include "SortedMultiMap.h"
#include <vector>
#include <iostream>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);

class SortedMultiMap;

class ValueIterator{

public:
    //ValueIterator(const SortedMultiMap map, TKey i);
    explicit ValueIterator(const SortedMultiMap& map, TKey c);

    friend class SortedMultiMap;

private:

    TKey key;
    std::vector<TValue> values_of_key_it;
    const SortedMultiMap& map;
    int current_position;

    //ValueIterator(const SortedMultiMap& map);
    bool add_values_of_key();


public:

    void first_vi();
    void next_vi();
    bool valid_vi() const;
    TValue getCurrent_vi() const;
};