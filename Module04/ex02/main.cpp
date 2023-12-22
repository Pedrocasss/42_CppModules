#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const AAnimal*	dog = new Dog();
	const AAnimal*	cat = new Cat();
	// The next example doesn't compile because class is abstract
	//const AAnimal*	other = new AAnimal();

	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;
}