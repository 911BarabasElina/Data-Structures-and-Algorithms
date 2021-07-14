#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <bits/stdc++.h>

SortedSet::SortedSet(Relation r) {
	this->relation=r;
	this->number_of_elements=0;
	this->root= nullptr;
}
//Theta(1)

bool SortedSet::add(TComp elem) {

    auto* new_node= new BST_node;

    new_node->info=elem;
    new_node->left= nullptr;
    new_node->right= nullptr;

    if(this->root== nullptr){
        this->root=new_node;
        this->number_of_elements++;
        return true;
    }

    BST_node* current_node=this->root;
    while(current_node!= nullptr)
    {
        if(current_node->info==elem)
            return false;

        if(this->relation(current_node->info,new_node->info) and current_node->right!= nullptr) //we need to go on right
        {
            current_node=current_node->right;
        }
        else if(this->relation(current_node->info,new_node->info))
        {
            current_node->right= new_node;
            this->number_of_elements++;
            return true;
        }
        else if(this->relation(new_node->info,current_node->info) and current_node->left!= nullptr) //we need to go on left
        {
            current_node=current_node->left;
        }
        else if(this->relation(new_node->info,current_node->info))
        {
            current_node->left=new_node;
            this->number_of_elements++;
            return true;
        }
    }

	return false;
}
//O(n)

bool SortedSet::remove(TComp elem) {

    BST_node* current_node = this->root;
    BST_node* parent_node = this->root;
    bool found = false;
    while (current_node != nullptr && !found)
    {
        if (current_node->info == elem)
            found = true;
        else if (this->relation(current_node->info, elem))
        {
            parent_node = current_node;
            current_node = current_node->right;
        }
        else
        {
            parent_node = current_node;
            current_node = current_node->left;
        }
    }

    if (!found)
        return false;


    this->number_of_elements--;
    if (current_node == this->root)
    {
        if (current_node->left == nullptr && current_node->right != nullptr)
        {
            this->root = this->root->right;
        }
        else if (current_node->left != nullptr && current_node->right == nullptr)
        {
            this->root = this->root->left;
        }
        else if (current_node->left != nullptr && current_node->right != nullptr)
        {
            BST_node* minimum_node = this->root->right;
            BST_node* parent_minimum = this->root;
            while (minimum_node->left != nullptr)
            {
                parent_minimum = minimum_node;
                minimum_node = minimum_node->left;
            }
            this->root->info = minimum_node->info;
            if (parent_minimum == this->root)
                this->root->right = nullptr;
            else
                parent_minimum->left = nullptr;

        }
        else
        {
            this->root =nullptr;
            this->number_of_elements=0;
        }
    }
    else
    {
        if (current_node->left == nullptr && current_node->right == nullptr)
        {
            if (parent_node->right == current_node)
                parent_node->right = nullptr;
            else
                parent_node->left = nullptr;
        }
        else if (current_node->left ==nullptr && current_node->right != nullptr)
        {
            parent_node->right = current_node->right;
        }
        else if (current_node->left != nullptr && current_node->right == nullptr)
        {
            parent_node->left = current_node->left;
        }
        else
        {
            BST_node* minimum_node = current_node->right;
            BST_node* parent_minimum = current_node;
            while (minimum_node->left != nullptr)
            {
                parent_minimum = minimum_node;
                minimum_node = minimum_node->left;
            }
            current_node->info = minimum_node->info;
            parent_minimum->left = nullptr;
            if (parent_minimum == current_node)
                current_node->right = nullptr;
            else
                parent_minimum->left =nullptr;

        }
    }

    return true;
}
//O(n)

bool SortedSet::search(TComp elem) const {

    BST_node* current_node=this->root;
    while(current_node!= nullptr)
    {
        if(current_node->info==elem)
            return true;

        if(this->relation(current_node->info,elem))
            current_node=current_node->right;
        else
            current_node=current_node->left;
    }

    return false;
}
//O(n)

int SortedSet::size() const {
	return this->number_of_elements;
}
//Theta(1)


bool SortedSet::isEmpty() const {
	return this->number_of_elements==0;
}
//Theta(1)

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}
//Theta(1)


int SortedSet::get_maximum() const{
    int max;
    max=INT_MIN;
    if(this->root== nullptr)
    {
        return max;
    }

    SortedSetIterator it=this->iterator();
    it.first();
    while(it.valid())
    {
        if(it.getCurrent()>max)
            max=it.getCurrent();
        it.next();
    }
    return max;

}
//O(nr_of_elements)

int SortedSet::get_minimum() const{
    int min;
    min=INT_MAX;
    if(this->root== nullptr)
    {
        return min;
    }

    SortedSetIterator it=this->iterator();
    it.first();
    while(it.valid())
    {
        if(it.getCurrent()<min)
            min=it.getCurrent();
        it.next();
    }
    return min;
}
//O(nr_of_elements)

int SortedSet::getRange() const {
    if(this->isEmpty())
        return -1;
    int min,max;
    min=this->get_minimum();
    max=this->get_maximum();
    return max-min;

}
//O(nr_of_elements)

SortedSet::~SortedSet() {
    BST_node** my_stack = new BST_node*[this->number_of_elements];
    int current_position = -1;

    BST_node* node = this->root;

    while(node != nullptr){
        if(node->right != nullptr){
            current_position++;
            my_stack[current_position] = node->right;
        }

        current_position++;
        my_stack[current_position] = node;
        node = node->left;
    }

    while(current_position >= 0){

        node = my_stack[current_position];
        current_position--;
        if(current_position >= 0 && node->right == my_stack[current_position]){

            my_stack[current_position] = node;
            node = node->right;
        }
        else{
            delete node;
            node = nullptr;
        }

        while(node != nullptr){
            if(node->right != nullptr){
                current_position++;
                my_stack[current_position] = node->right;

            }
            current_position++;
            my_stack[current_position] = node;
            node = node->left;
        }
    }
}
//Theta(n)