#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal constructor called"<< std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor Has been called" << std::endl;
}

Animal &Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Animal assignment operator did his job" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound()
{
    std::cout << "Generic animal sound" << std::endl;
}

std::string const & Animal::getType() const
{
    return this->type;
}
