#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I love bones!");

    Dog dog2(dog1);
    std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog1.getBrain()->setIdea(0, "I love treats!");
    std::cout << "Dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Testing Polymorphic Deletion ===" << std::endl;
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    delete dog;
    delete cat;

    std::cout << "\n=== Creating Array of 100 Animals ===" << std::endl;
    Animal *animals[100];
    
    std::cout << "Creating 50 dogs..." << std::endl;
    for (int i = 0; i < 50; i++)
        animals[i] = new Dog();

    std::cout << "Creating 50 cats..." << std::endl;
    for (int i = 50; i < 100; i++)
        animals[i] = new Cat();
        
    std::cout << "Deleting all animals..." << std::endl;
    for (int i = 0; i < 100; i++)
        delete animals[i];
}