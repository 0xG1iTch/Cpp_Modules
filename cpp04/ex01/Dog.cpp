#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called"<< std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain();
    *brain = *other.brain;
    std::cout << "Dog copy constructor Has been called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        delete brain;
        brain = new Brain();
        *brain = *other.brain;
        Animal::operator=(other);
    }
    std::cout << "Dog assignment operator did his job" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound()
{
    std::cout << "Woof Woof" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}