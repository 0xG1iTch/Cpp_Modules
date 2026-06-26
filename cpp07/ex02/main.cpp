#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;
    
    Array<int> arr(5);
    std::cout << "Arr size: " << arr.size() << std::endl;
    
    arr[0] = 42;
    arr[1] = 21;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    
    Array<int> copy(arr);
    copy[0] = 99;
    std::cout << "Original arr[0]: " << arr[0] << std::endl;
    std::cout << "Copy arr[0]: " << copy[0] << std::endl;
    
    Array<int> assigned(3);
    assigned = arr;
    assigned[0] = 77;
    std::cout << "Original arr[0]: " << arr[0] << std::endl;
    
    try
    {
        arr[100] = 5;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    const Array<int> carr(3);
    std::cout << "Const array[0]: " << carr[0] << std::endl;
    
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    
    return 0;
}