#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
class SortedSetIterator;

struct BST_node
{
    TElem info;
    BST_node* left;
    BST_node* right;
    //BST_node* father;
};

class SortedSet {
	friend class SortedSetIterator;
private:

    Relation relation;
    BST_node* root;
    int number_of_elements;

public:
	//constructor
	explicit SortedSet(Relation r);

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TElem elem) const;


	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;


	// destructor
	~SortedSet();

	int get_maximum() const;
	int get_minimum() const;

    //returns the difference between the maximum and the minimum element (assume integer values)
    //if the SortedSet is empty the range is -1
    int getRange() const;


};
