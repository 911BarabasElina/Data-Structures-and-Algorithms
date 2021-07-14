#pragma once
#include "Set.h"
#include <exception>

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	int current;
	SetIterator(const Set& s);

	//TODO - Representation

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


