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

		virtual void makeSound() = 0;
		std::string const & getType() const;
};