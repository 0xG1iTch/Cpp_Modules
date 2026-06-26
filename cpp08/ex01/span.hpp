#include <iostream>
#include <iterator>
#include <vector>
#include <stdexcept>

class Span {
    private:
        unsigned int capacity;
        std::vector<int> v;
    public:
        Span();
        Span(const Span& obj);
        Span(unsigned int n);
        Span& operator=(const Span& obj);
        ~Span();
        void addNumber(int num);
        unsigned long longestSpan();
        unsigned long shortestSpan();

        template <typename T>
        void addNumbers(T begin, T end)
        {
            if (v.size() + std::distance(begin, end) > capacity)
                throw std::runtime_error("Error: Container reached the limit");
            for (; begin != end; begin++)
                addNumber(*begin);
        }
};