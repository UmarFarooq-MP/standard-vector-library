
#include <iostream>
#include "vector.h"

#include <vector>

int main () {
    unsigned int x = 10;
    svl::vector<int> test(x);
    test.display();
    svl::vector<int>test1(std::move(test));
}
