#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){

    testAll();
    test_new_it();
    testAllExtended();
    std::cout<<std::endl<<"Finished SMM Tests!"<<std::endl;
	system("pause");

}
