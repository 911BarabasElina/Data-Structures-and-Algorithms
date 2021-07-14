#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
    this->m=10;
    this->nr_of_elements=0;
	this->relation=r;
	this->load_factor=0.7;

    this->hash_table = new Node*[this->m];

    for (int index = 0; index < this->m; index++)
        this->hash_table[index] = nullptr;

}
//Theta(m)

vector<TValue> SortedMultiMap::search(TKey c) const {

    vector<TValue> values_key_c;
    int key_modulo_m = this->hash_function(c);

    Node* new_node;
    new_node=this->hash_table[key_modulo_m];
    while(new_node!= nullptr)
    {
        if(new_node->key==c)
            values_key_c.push_back(new_node->value);
        new_node=new_node->next;
    }

    return values_key_c;
}
//Theta(n), where n is the number of nodes from one SLL

bool SortedMultiMap::remove(TKey c, TValue v) {

    int key_modulo_m;
    key_modulo_m= this->hash_function(c);

    Node* current_node, *previous_node;

    previous_node= nullptr;

    current_node=this->hash_table[key_modulo_m];

    if(current_node == nullptr) //empty position in hash table
        return false;

    if(current_node->key == c && current_node->value == v) //the searched pair (key,value) is the
    {                                          // head of the SLL corresponding to the returned value from the hash table
        this->hash_table[key_modulo_m] = current_node->next;
        delete current_node;
        this->nr_of_elements--;
        return true;
    }

    while(current_node!= nullptr)
    {
        if(current_node->value==v && current_node->key==c)
        {
            previous_node->next=current_node->next;
            delete current_node;
            this->nr_of_elements--;
            return true;
        }
        previous_node=current_node;
        current_node=current_node->next;
    }

    return false;
}
// O(n), where n is the number of nodes from one SLL


int SortedMultiMap::size() const {
	return this->nr_of_elements;
}
// Theta(1)

bool SortedMultiMap::isEmpty() const {
    return this->nr_of_elements==0;
}
// Theta(1)

SortedMultiMap::~SortedMultiMap() {
    for (int index = 0; index < this->m; index++) {
        Node* current_node=this->hash_table[index];
        while(current_node!=nullptr)
        {
            Node* old_node= current_node;
            current_node=current_node->next;
            delete old_node;
        }
    }
    delete[] this->hash_table;
}
//Theta(m+nr_of_elements)


int SortedMultiMap::hash_function(TKey key) const {
    return abs(key % this->m);
}
//Theta(1)

void SortedMultiMap::add(TKey c, TValue v) {
    this->nr_of_elements++;

    int key_modulo_m=this->hash_function(c);

    Node* new_node= new Node;
    new_node->key=c;
    new_node->value=v;
    new_node->next= nullptr;

    Node* current_node=this->hash_table[key_modulo_m]; //it can be nullptr or not depending the case

    if(current_node== nullptr) {      //the case in which the position of the hash table is initially empty
        this->hash_table[key_modulo_m] = new_node;
    }
    else if(this->relation(c, current_node->key)) //the new node becomes the head of the current SLL
    {
        new_node->next=current_node;
        this->hash_table[key_modulo_m] = new_node;
    }
    else // the case in which the new element is inserted between 2 already existing nodes
    {
        Node* next_node=current_node->next;
        while(next_node != nullptr && !this->relation(c,next_node->key))
        {
            current_node=next_node;
            next_node=current_node->next;
        }
        new_node->next=next_node;
        current_node->next=new_node;
    }

    if((double(this->nr_of_elements)/this->m)>this->load_factor)
        this->resize_hash_table();
}

// O(n), where n is the number of nodes from a SLL

void SortedMultiMap::resize_hash_table() {
    nr_of_elements = 0;
    m *= 2;
    auto old_hash_table = hash_table;
    hash_table = new Node* [m];
    for(int i = 0; i < m; i++)
        hash_table[i] = nullptr;

    for(int i = 0; i < m / 2; i++) {
        auto current_old_node = old_hash_table[i];
        while(current_old_node != nullptr) {
            add(current_old_node->key, current_old_node->value);
            auto deleted_node = current_old_node;
            current_old_node = current_old_node->next;
            delete deleted_node;
        }
    }
    delete[] old_hash_table;

}
// Theta(m)

ValueIterator SortedMultiMap::iterator_values(TKey k) {
    return ValueIterator(*this,k);
}
// Theta(1)

SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}
// Theta(1)