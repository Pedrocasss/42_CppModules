#include "ScavTrap.hpp"

int main()
{
	ScavTrap Pedro("Pedro");
	ScavTrap Eduardo("Eduardo");
	Pedro.attack("Eduardo");
	Eduardo.takeDamage(100);
	std::cout << "Eduardo Health points: " << Eduardo.getHP() << std::endl;
	//Eduardo.beRepaired(10);
	Eduardo.attack("Pedro");
	std::cout << "Eduardo Health points: " << Eduardo.getHP() << std::endl;
	std::cout << "Pedro Health points: " << Pedro.getHP() << std::endl;
	std::cout << "Eduardo Energy points: " << Eduardo.getEnergy() << std::endl;
	std::cout << "Pedro Energy points: " << Pedro.getEnergy() << std::endl;
	Pedro.guardGate();
	Eduardo.guardGate();
}
