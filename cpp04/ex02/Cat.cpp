#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called"<< std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain();
    *brain = *other.brain;
    std::cout << "Cat copy constructor Has been called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        delete brain;
        brain = new Brain();
        *brain = *other.brain;
        Animal::operator=(other);
    }
    std::cout << "Cat assignment operator did his job" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "Meaow Meaowww" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}
