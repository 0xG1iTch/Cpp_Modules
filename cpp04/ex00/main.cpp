#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    Animal anml;
    Animal *anim_dog = new Dog();
    Animal *anim_cat = new Cat();
    Dog dog;
    Cat cat;

    anml.makeSound();
    anim_dog->makeSound();
    std::cout << anim_dog->getType() << std::endl;
    anim_cat->makeSound();
    std::cout << anim_cat->getType() << std::endl;
    dog.makeSound();
    cat.makeSound();
    delete anim_dog;
    delete anim_cat;
    std::cout << "---------------------------------------------------------------------" << std::endl;
    WrongAnimal wrAnml;
    WrongAnimal *wrng_anim_cat = new WrongCat();

    wrAnml.makeSound();
    wrng_anim_cat->makeSound();
    std::cout << wrng_anim_cat->getType() << std::endl;
    delete wrng_anim_cat;
}