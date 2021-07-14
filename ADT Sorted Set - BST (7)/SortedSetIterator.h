#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	explicit SortedSetIterator(const SortedSet& m);

	BST_node** my_stack;
	BST_node* current_node;
	int current_position;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};

