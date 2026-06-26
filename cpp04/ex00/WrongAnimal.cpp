#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called"<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "WrongAnimal copy constructor Has been called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongAnimal assignment operator did his job" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound()
{
    std::cout << "Generic WrongAnimal sound" << std::endl;
}

std::string const & WrongAnimal::getType() const
{
    return this->type;
}
