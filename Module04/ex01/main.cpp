#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	{
		const	Animal*	bunch[6];
		for (int i = 0; i < 6; i++)
		{
			if (i % 2)
				bunch[i] = new Dog();
			else
				bunch[i] = new Cat();
		}
		for (int i = 0; i < 6; i++)
		{
			std::cout << i << ": ";
			bunch[i]->makeSound();
		}
		for (int i = 0; i < 6; i++)
			delete bunch[i];
	}
	{
		std::cout << std::endl << "Checking the copy constructors: " << std::endl;
		const 	Dog*	dog = new Dog;
        const   Cat*    cat = new Cat;
		const	Animal* other = new Dog(*dog);
        const	Animal* other1 = new Cat(*cat);
		dog->makeSound();
		other->makeSound();
        cat->makeSound();
        other1->makeSound();
		delete dog;
		delete other;
        delete cat;
        delete other1;
	}
}