#include <iostream>
#include "vector.h"
int main (){
    svl::vector<int> test(5);

    std::cout << "-------------------------------------\n";
    std::cout << "size = " <<test.size() << std::endl;
    std::cout << "capacity = "<< test.capacity() << std::endl;
    test.assign(5,10);
    test.display();
    std::cout << "-------------------------------------\n";
    std::cout <<"size = "<< test.size() << std::endl;
    std::cout <<"capacity = "<< test.capacity() << std::endl;
    test.assign(5,12);
    test.display();
}
