#include <assert.h>
#include "Matrix.h"

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);
}

void testSetMainDiagonal()
{
    Matrix m(10, 10);

    m.setMainDiagonal(9);
    assert(m.element(0,0)==9);

    for (int i = 0; i < m.nrLines(); i++)
        for (int j = 0; j < m.nrColumns(); j++)
        {
            if(i!=j){
                assert(m.element(i,j)==NULL_TELEM);
            }
        }

    for (int i = 5; i < m.nrLines(); i++)
        for (int j = 5; j < m.nrColumns(); j++)
            m.modify(i,j,6);

    m.setMainDiagonal(7);
    assert(m.element(1,1)==7);

    assert(m.element(2,1)==NULL_TELEM);
    assert(m.element(6,8)==6);
    assert(m.element(2,2)==7);

}