//
// Created by User on 18/05/2021.
//

#include <algorithm>
#include "ValueIterator.h"
#include "SortedMultiMap.h"


void ValueIterator::first_vi() {
    this->current_position=0;

}
//Theta(m) or Theta(1)

void ValueIterator::next_vi() {
    if(!valid_vi())
        throw exception();
    this->current_position++;
}
//Theta(1)

bool ValueIterator::valid_vi() const {
    if(this->current_position<this->values_of_key_it.size() && !this->values_of_key_it.empty())
        return true;
    return false;
}
//Theta(1)

TValue ValueIterator::getCurrent_vi() const {
    if(!valid_vi())
        throw exception();
    return this->values_of_key_it.at(this->current_position);
}
//Theta(1)

bool ValueIterator::add_values_of_key()  {

    vector<TValue> values= this->map.search(this->key);

    for(auto& value: values)
    {
        this->values_of_key_it.push_back(value);

    }

    if(this->values_of_key_it.empty())
        return false;

    int i;


//    for(i=0; i<values.size()-1; i++)
//    {
//     for(int j=i+1; j<values.size(); j++)
//     {
//         if(!map.relation(this->values_of_key_it.at(i),this->values_of_key_it.at(j)))
//         {
//             TValue aux;
//             aux=this->values_of_key_it[i];
//             this->values_of_key_it[i]=this->values_of_key_it[j];
//             this->values_of_key_it[j]=aux;
//         }
//     }
//    }

    sort(this->values_of_key_it.begin(), this->values_of_key_it.end(), map.relation);

    return true;

}
//O(n*log n)

ValueIterator::ValueIterator(const SortedMultiMap& smm, TKey c): map(smm), key(c){
    this->values_of_key_it.clear();

//    Node* new_node=map.hash_table[this->key%map.m];
//    while(new_node!= nullptr)
//    {
//        if(new_node->key==this->key)
//        {
//            this->values_of_key_it.push_back(new_node->value);
//        }
//        new_node=new_node->next;
//    }

    if(!add_values_of_key()) {
        this->current_position =this->values_of_key_it.size();
    }
    this->current_position=0;

//    if(this->values_of_key_it.empty()) {
//        this->current_position =this->values_of_key_it.size();
//    }
//    this->current_position=0;
}
//Theta(1);


