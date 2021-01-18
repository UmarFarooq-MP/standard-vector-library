
#include "vector.h"
//#include <vector>
//#include <iostream>

int main() {

    /**Our Vector testing**/
    svl::vector<int> test;
    std::cout << "Size: " << test.size() << "\t" << "Capacity: " << test.capacity() << "\n";

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    std::cout << "Size: " << test.size() << "\t" << "Capacity: " << test.capacity() << "\n";

    test.printVector();

    /**Standard Vector testing**/
    /*std::vector<int> test;
    std::cout << "Size: " << test.size() << "\t" << "Capacity: " << test.capacity() << "\n";
    std::cout << "Before Reserve capacity: " << test.capacity() << "\n";
    test.reserve(4);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    std::cout << "After Reserve capacity: " << test.capacity() << "\n";
    auto it = test.begin();
    test.insert(it, 200);
    for (auto i = 0; i < test.size(); i++){
        std::cout << test[i] << "\t";
    }*/

}