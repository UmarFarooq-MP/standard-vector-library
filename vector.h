//
// Created by umar-cxx on 30/6/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <initializer_list>
#include <iostream>
#include <array>
#include <climits>

/** just to keep consistency of data type **/
typedef unsigned long size_u;
namespace svl {
    template<typename T>
    class vector {
        /** Data Types Here **/
        size_u m_size;
        size_u m_capacity;
        T *m_data;

    public:
        explicit vector(size_u size = 0) : m_capacity(size) {
            if (size < 0 || size > INT_MAX)
                throw std::out_of_range("Invalid Number For Allocation");
            m_data = new (std::nothrow) T[size];
            if (m_data)
                throw std::bad_alloc();
        }

        vector(T *start,T *end) {
            if (start == end){
                throw std::runtime_error("Fuck You bitches equal");
            } else if (start > end){
                throw std::runtime_error("Fuck You bitches");
            }
            m_capacity = m_size = (int)(end - start);
            m_data = new T [m_size];
            std::copy(start,end,m_data);
        }
        vector(const vector &obj) : m_size(obj.m_size), m_capacity(obj.capacity()) {
            std::cout << "Copy Constructor" << std::endl;
            m_data = new T[m_capacity];

            for (size_u i{0}; i < m_size; ++i) {
                m_data[i] = obj.m_data[i];
            }
        }

        vector(vector &&other) noexcept {

            std::cout << "move constructor \n";
            this->m_data = other.m_data;
            this->m_size = other.size();
            this->m_capacity = other.capacity();

            other.m_data = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }

        vector(const std::initializer_list<T> &args) {
            m_capacity = m_size = static_cast<T>(args.size());
            m_data = new T[m_size];
            int count{0};
            for (const auto &itr : args) {
                m_data[count++] = itr;
            }
        }

        friend std::ostream &operator<<(std::ostream &out, vector &vec) {
            for (size_u i = 0; i < vec.m_size; ++i) {
                out << vec.m_data[i] << " ";
            }
            out << "\n";
            return out;
        }

        vector &operator=(const vector &obj) {
            if (this->m_data != nullptr) {
                delete[] m_data;
            }
            std::cout << "assignment operator \n";
            m_data = new T[obj.m_capacity];
            m_capacity = obj.m_capacity;
            for (size_u i{0}; i < m_size; ++i) {
                m_data[i] = obj.m_data[i];
            }
        }

        T &operator[](int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("out of index");
            }
            return m_data[index];
        }

        ~vector() {
            delete[] m_data;
        }

        void insert(T value) {

        }

        void assign(const size_u count, const T value) {

            if (count < 0)
                throw std::runtime_error("Enter a valid count");

            if (m_capacity < count) {
                m_size = m_capacity = count;
                delete[] m_data;
                m_data = new T[count + 1];
            }
            for (size_u i{0}; i < count; ++i) {
                m_data[i] = value;
            }
        }

        void pop_back() {
            m_size--;
        }

        T &at(const T index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("out of index");
            }
            return m_data[index];
        }


        T back() const {
            return m_data[m_size - 1];
        }

        size_u capacity() const {
            return m_capacity;
        }

        size_u size() const {
            return m_size;
        }

        void push_back(const T value) {
            if (m_size == m_capacity) {
                reAllocate();
            }
            m_data[m_size] = value;
            ++m_size;
        }

        template<typename ... Args>
        void emplace_back(Args... args) {
            push_back(std::forward<T>(args)...);
        }

        void display() {
            for (int i = 0; i < m_size; ++i) {
                std::cout << m_data[i] << " ";
            }
            std::cout << "\n";
        }

        void clear() {
            delete[] m_data;
            m_size = 0;
            m_capacity = 0;
        }

        T *begin() const {
            return m_data;
        }

        T *end() const {
            return m_data+m_size;
        }

        T *rbegin() const {
            return m_data + m_size;
        }

        T *rend() const {
            return m_data;
        }


    private:

        void allocate(){}

        void reAllocate() {
            if (m_size == 0) {
                m_capacity = 1;
                T *temp  = new (std::nothrow) T[m_capacity];
                return;
            } else {
                m_capacity = m_size * 2;
            }
            T *temp  = new (std::nothrow) T[m_capacity];
            if (!temp) {
                throw std::runtime_error("Bad Allocation");
            }
            std::copy(m_data, m_data + m_size, temp);
            delete[] m_data;
            m_data = temp;
        }
    };
}
#endif //VECTOR_VECTOR_H
