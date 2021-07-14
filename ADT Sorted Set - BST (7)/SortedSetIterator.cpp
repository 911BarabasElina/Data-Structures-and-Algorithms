#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    this->my_stack=new BST_node*[multime.number_of_elements];

    BST_node* node=multime.root;
    this->current_position=-1;
    while(node!= nullptr)
    {
        this->current_position++;
      this->my_stack[this->current_position]=node;

      node=node->left;
    }
    if(this->current_position>=0)
        this->current_node=this->my_stack[this->current_position];
    else {
       this-> current_node = nullptr;
    }
}
//O(n)

void SortedSetIterator::first() {

    BST_node* node=multime.root;
    this->current_position=-1;

    while(node!= nullptr)
    {
        this->current_position++;
        this->my_stack[this->current_position]=node;
        node=node->left;
    }

    if(this->current_position>=0)
        this->current_node=this->my_stack[this->current_position];
    else {
        current_node = nullptr;
    }
}
//O(n)

void SortedSetIterator::next() {
    if(!this->valid())
        throw exception();

    BST_node* node=this->my_stack[this->current_position];
    this->current_position--;

    if(node->right!= nullptr)
    {
        node=node->right;
        while(node!= nullptr)
        {
            this->current_position++;
            this->my_stack[this->current_position]=node;
            node=node->left;
        }
    }

    if(this->current_position>=0)
        this->current_node=this->my_stack[this->current_position];
    else
        this->current_node= nullptr;
}
//O(n)

TElem SortedSetIterator::getCurrent()
{
	if(!this->valid())
        throw exception();
    return this->current_node->info;
}
//Theta(1)

bool SortedSetIterator::valid() const {
	if (this->current_node == nullptr)
        return false;
    return true;
}
//Theta(1)
