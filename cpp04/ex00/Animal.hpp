#pragma once
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
 		Animal& operator=(const Animal& other );
		virtual ~Animal();

		virtual void makeSound();
		std::string const & getType() const;
};