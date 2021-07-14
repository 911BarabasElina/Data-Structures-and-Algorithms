#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
    nodes=new Node*[map.m];
    first();
}
// Theta(m)

void SMMIterator::find_current_minimum() {
    current_minimum_position = 0;
    for(int i = 1; i < nr_nodes; i++) {
        if(map.relation(nodes[i]->key, nodes[current_minimum_position]->key))
            current_minimum_position = i;
    }
}
// Theta(nr_of_nodes)

void SMMIterator::first(){

//    nodes.clear();
    this->nr_nodes=0;

    for(int i = 0; i < map.m; i++)
        if(map.hash_table[i] != nullptr) {
            nodes[nr_nodes]=map.hash_table[i];
            nr_nodes++;
        }

    find_current_minimum();
}
// Theta(m)


void SMMIterator::next(){
    if(!valid())
        throw exception();

    nodes[current_minimum_position] = nodes[current_minimum_position]->next;
    if(nodes[current_minimum_position] == nullptr) {
            nodes[current_minimum_position] = nodes[nr_nodes - 1];
            nr_nodes--;
    }
    find_current_minimum();
}
// Theta(nr_of_nodes)

bool SMMIterator::valid() const{
    return nr_nodes!=0;
}
// Theta(1)

TElem SMMIterator::getCurrent() const{
    if(!valid())
        throw exception();

    return make_pair(nodes[current_minimum_position]->key, nodes[current_minimum_position]->value);
}
//Theta(1)



