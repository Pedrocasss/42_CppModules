#include "Zombie.hpp"


/*
Esta funçao retorna um ponteiro para um objeto do tipo Zombie.
A variavel zomb aloca diretamente na heap com a funçao new.
*/
Zombie* newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}