#include <iostream>
#include "iter.hpp"

int main()
{
    int arr[5] = {2, 6, 7, 3, 8};
    iter(arr, 5, print<int>);
    std::string words[3] = {"hello", "world", "test"};
    iter(words, 3, print<std::string>);
}