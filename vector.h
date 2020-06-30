//
// Created by umar-cxx on 30/6/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <memory>
//#include <vector>
#include <cstdio>

namespace svl{
  template <typename T , typename allocator = std::allocator<T>>
  class vector{
  public:
      vector(const int size) {
          data = alloc.allocate(size);
      }

  private:
      allocator alloc;
      T* data;
  };
}



#endif //VECTOR_VECTOR_H
