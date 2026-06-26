#ifndef ITER_HPP
#define ITER_HPP

template <typename A>
void print(A element) {
    std::cout << element << std::endl;
}

template <typename T, typename Func>
void iter(T* arr, const size_t length, Func f)
{
    for(size_t i = 0; i < length; i++)
        f(arr[i]);
}
#endif