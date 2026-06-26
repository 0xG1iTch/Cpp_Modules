#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& obj){
    numbers = obj.numbers;
}

RPN& RPN::operator=(const RPN& obj)
{
    numbers = obj.numbers;
    return *this;
}

RPN::~RPN(){}

bool checkOverflow(long num)
{
    int res = num;
    if(num == res)
        return true;
    else return false;
}
void RPN::apply_operator(char op)
{
    if (numbers.size() < 2)
        throw std::runtime_error("Error");
    long first = numbers.top(); numbers.pop();
    long second = numbers.top(); numbers.pop();
    if (op == '+'){
        if(checkOverflow(second + first))
            numbers.push(second + first);
        else throw std::runtime_error("Error: intiger overflow");
    }
    else if (op == '-'){
        if(checkOverflow(second - first))
            numbers.push(second - first);
        else throw std::runtime_error("Error: intiger overflow");
    }
    else if (op == '*')
    {
        if(checkOverflow(second * first))
            numbers.push(second * first);
        else throw std::runtime_error("Error: intiger overflow");
    }
    else if (op == '/')
    {
        if (first == 0)
            throw std::runtime_error("Error: division by zero");
        if(checkOverflow(second / first))
            numbers.push(second / first);
        else throw std::runtime_error("Error: intiger overflow");
    }
    else
        throw std::runtime_error("Error");
}

void RPN::process_input(std::string list)
{
    for (int i = 0; list[i]; i++)
    {
        if (std::isdigit(list[i]))
            numbers.push(list[i] - '0');
        else if (list[i] == ' ')
            continue;
        else
            apply_operator(list[i]);
    }
    if (numbers.size() == 1)
        std::cout << numbers.top() << std::endl;
    else
        throw std::runtime_error("Error");
}