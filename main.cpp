
#include "vector.h"

int main() {

    svl::vector<int> test(10);
    std::cout << test.size() <<"  " << test.capacity()<<std::endl;

    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);

    std::cout << test.size() <<"  " << test.capacity()<<std::endl;


    std::cout << test.end() << "\n";
    std::cout << test.rbegin() << "\n";
}