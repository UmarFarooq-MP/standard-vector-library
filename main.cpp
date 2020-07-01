#include <iostream>
#include "vector.h"

int main (){

    svl::vector<int> test(5);
    std::cout << "-------------------------------------\n";
    std::cout << "size = " <<test.size() << std::endl;
    std::cout << "capacity = "<< test.capacity() << std::endl;
    test.assign(5,10);
    test.push_back(12);
    test.display();
    std::cout << "size = " <<test.size() << std::endl;
    std::cout << "capacity = "<< test.capacity() << std::endl;
    std::cout << "at : " << test[5] <<"\n";
    std::cout <<"********************************************\n";
    test[5]= 111;
    test.display();

}
