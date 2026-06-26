#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    std::cout << "Copy Constructor just Copied the 100 ideas" << std::endl;
}

Brain &Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "Assignement operator just Copied All your Ideas" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor destroyed everything" << std::endl;
}

void Brain::setIdea(int i, const std::string idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "Invalid index to set idea." << std::endl;
}

std::string Brain::getIdea(int i)
{
	if (i >= 0 && i < 100)
		return (this->ideas[i]);
	else
		std::cout << "Not valid index to set idea." << std::endl;
	return ("");
}