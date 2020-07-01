//
// Created by umar-cxx on 30/6/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <memory>
#include <cstdio>
#include <vector>

/** just to keep consistency of data type **/
typedef unsigned int size_u;

namespace svl {
    template<typename T>
    class vector {
        /** Data Types Here **/
        size_u m_size;
        size_u m_capacity;
        T *m_data;
        T *m_rear; //end

        void reAllocate() {
            m_capacity = m_size * 2;
            T *temp = new T[m_capacity];
            if (!temp) {
                throw std::runtime_error("memory allocation error");
            }
            std::copy(m_data, m_data + m_size, temp);
            delete[] m_data;
            m_data = temp;
            m_rear = m_data + (m_capacity - 1);
        }

    public:
        explicit vector(size_u capacity = 0) : m_capacity(capacity) {
            m_size = 0;
            m_data = new T[capacity];
            m_rear = m_data;
        }
        ~vector() {
            delete[] m_data;
        }
        void assign(const size_u count, const T value) {
            while ((m_size + count) > m_capacity) {
                reAllocate();
            }
            for (size_u i{0}; i < count; ++i, ++m_size) {
                m_data[m_size] = value;
                m_rear = m_data + m_size;
            }
        }
        T *at(const T index) {
            if (index > 0 && index < m_size - 1)
                return m_data + index;
            throw std::out_of_range("index out of rang");
        }
        T &operator[](int index){
            if (index <0 || index >= m_size){
                throw std::out_of_range("out of index");
            }
            return m_data[index];
        }
        T back() const{
            return m_data[m_size-1];
        }
        size_u capacity() const {
            return m_capacity;
        }
        size_u size() const {
            return m_size;
        }
        void push_back(const T value) {
            if (m_size == m_capacity){
                reAllocate();
            }
            m_data[m_size] = value;
            ++m_size;
        }
        void display() {
            for (int i = 0; i < m_size; ++i) {
                std::cout << m_data[i] << std::endl;
            }
        }

        void clear(){
            delete [] m_data;
            m_size = 0;
            m_capacity = 0;
            m_rear = nullptr;
        }

        T *begin() const {
            return m_data;
        }
        T *end() const {
            return m_rear;
        }
        T *rbegin() const {
            return m_data;
        }
        T *rend() const {
            return m_rear;
        }
    };
}
#endif //VECTOR_VECTOR_H
