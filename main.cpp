
#include <iostream>
#include "vector.h"

int main () {
    unsigned int x = 10;
    svl::vector<int> test = {12,12,12,12,12,12,12,12,21,12,21,12,12,21,};
    test.display();

    svl::vector<int>test1(std::move(test));
}
