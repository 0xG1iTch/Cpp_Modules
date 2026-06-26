#include "span.hpp"

Span::Span() : capacity(1) {}
Span::Span(const Span& obj) : capacity(obj.capacity), v(obj.v) {}
Span::Span(unsigned int n) : capacity(n) {
    v.reserve(n);
}

Span& Span::operator=(const Span& obj)
{
    capacity = obj.capacity;
    v = obj.v;
    return *this;
}
Span::~Span() {}

void Span::addNumber(int num)
{
    if(v.size() < capacity)
        v.push_back(num);
    else
        throw std::runtime_error("Error: Container reached the limit");
}

unsigned long Span::longestSpan()
{
    if (v.size() <= 1)
        throw std::runtime_error("Error: Container contain less than 2 values");
    int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());
    return (max - min);
}

unsigned long Span::shortestSpan()
{
    if(v.size() <= 1)
        throw std::runtime_error("Error: Container contain less than 2 values");
    std::vector<int> temp = v;
    std::sort(temp.begin(), temp.end());
    std::vector<int> spans;
    for (size_t i = 0; i < temp.size(); i++)
        if (i + 1 < temp.size())
            spans.push_back(temp[i+1] - temp[i]);
    return (*std::min_element(spans.begin(), spans.end()));
}