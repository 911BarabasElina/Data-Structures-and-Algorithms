#pragma once

#include "SortedMultiMap.h"
#include <vector>

class SMMIterator{

	friend class SortedMultiMap;
private:
    int current_minimum_position;
    Node** nodes;
    int nr_nodes;

	const SortedMultiMap& map;
	explicit SMMIterator(const SortedMultiMap& map);

	//Finds and sets the current minimum
    void find_current_minimum();

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

