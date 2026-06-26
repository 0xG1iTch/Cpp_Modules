#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN {
    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        void process_input(std::string list);
        ~RPN();
    private:
        void apply_operator(char op);
        std::stack<int> numbers;
};

#endif