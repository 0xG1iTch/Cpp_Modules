#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array{
    private:
        T *elements;
        size_t arr_size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &othrt);
        Array &operator=(Array const &other);
        T& operator[](size_t i);
        const T& operator[](size_t i) const;
        ~Array();

        size_t size() const;
};

template<typename T>
Array<T>::Array(): elements(NULL), arr_size(0){}

template<typename T>
Array<T>::Array(unsigned int n) : arr_size(n) {
    elements = new T[n]();
}

template<typename T>
Array<T> ::Array(Array<T> const &other): elements(new T[other.arr_size]), arr_size(other.arr_size)
{
    for (size_t i = 0; i < arr_size; i++) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Array<T>::~Array(){
    delete[] elements;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
    if (this == &other)
        return *this;
    arr_size = other.arr_size;
    delete[] elements;
    elements = new T[arr_size];
    for (size_t i = 0; i < arr_size; i++) {
        elements[i] = other.elements[i];
    }
	return *this;
}

template <typename T>
size_t Array<T>::size() const {
    return arr_size;
}

template <typename T>
T& Array<T>::operator[](size_t i)
{
    if (i >= arr_size)
        throw std::out_of_range("Index out of range of the Array");
    return elements[i];
}
template <typename T>
const T& Array<T>::operator[](size_t i) const
{
    if (i >= arr_size)
        throw std::out_of_range("Index out of range of the Array");
    return elements[i];
}

#endif