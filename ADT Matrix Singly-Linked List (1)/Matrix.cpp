#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nr_of_lines, int nr_of_cols) {

    this->head= nullptr;
	if(nr_of_lines<=0 || nr_of_cols<=0)
        throw exception();
	this->nr_of_lines=nr_of_lines;
    this->nr_of_cols=nr_of_cols;
}
//Theta(1)

int Matrix::nrLines() const {
	return this->nr_of_lines;
}
//Theta(1)

int Matrix::nrColumns() const {
    return this->nr_of_cols;
}
//Theta(1)

TElem Matrix::element(int i, int j) const {

    if(i<0 || i>nr_of_lines-1 || j<0 || j>nr_of_cols-1)
        throw exception();

    Node* current_node = this->head;
    while(current_node != nullptr && (current_node->line !=i || current_node->column !=j))
    {
        current_node=current_node->next;
    }
    if(current_node == nullptr)
        return NULL_TELEM;
    else
        return current_node->info;
}
//O(n)

TElem Matrix::modify(int i, int j, TElem e) {

    if(i<0 || i>nr_of_lines-1 || j<0 || j>nr_of_cols-1)
        throw exception();

    Node* current_node= this->head;
    if(this->head== nullptr)
    {
        if(e !=0)
        {
            Node* new_node= new Node;
            new_node->line=i;
            new_node->column=j;
            new_node->info=e;
            new_node->next= nullptr;
            this->head=new_node;
            return NULL_TELEM;
        }
        return NULL_TELEM;
    }

    Node* previous_node= nullptr;

    while(current_node != nullptr)
    {
        if(current_node->line ==i && current_node->column ==j)
        {
            if(e!=0)
            {
                TElem old_value;
                old_value=current_node->info;
                current_node->info=e;
                return old_value;
            }
            else
            {

                TElem old_value;
                old_value=current_node->info;

                if(current_node==this->head)
                    this->head=current_node->next;
                else {
                    previous_node->next = current_node->next;
                }
                return old_value;

            }
        }
        else
        {

            if(current_node->line >i || (current_node->column>j && current_node->line==i))
            {
                if(e!=0)
                {
                Node* new_node= new Node;
                new_node->line=i;
                new_node->column=j;
                new_node->info=e;

                if(current_node==this->head)
                {
                    this->head=new_node;
                    new_node->next=current_node;

                }
                else {
                    new_node->next = current_node;
                    previous_node->next = new_node;
                }
                }

                return NULL_TELEM;
            }

        }
        previous_node=current_node;
        current_node=current_node->next;
    }

    if(e!=0) {
        Node *new_node = new Node;
        new_node->line = i;
        new_node->column = j;
        new_node->info = e;

        previous_node->next = new_node;
        new_node->next = nullptr;
    }
	return NULL_TELEM;
}
//O(n)
void Matrix::setMainDiagonal(TElem elem) {

    if(this->nrLines() != this->nrColumns())
        throw exception();
    else {
        for (int i = 0; i < nrLines(); i++)
            for (int j = 0; j < nrColumns(); j++) {
                if (i == j) {
                    modify(i, j, elem);
                }

            }
    }

    }
//Theta(n^2)













//
//   Node* current_node = this->head;
//        while(current_node != nullptr)
//        {
//            if(current_node->line==current_node->column)
//                //modify(current_node->line,current_node->column,elem);
//                current_node->info=elem;
//            current_node=current_node->next;
//        }