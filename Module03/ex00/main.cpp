#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Pedro("Pedro");

	Pedro.attack("Eduardo");
	Pedro.getEnergy();
	Pedro.takeDamage(0);
	std::cout << "Health points: " << Pedro.getHP() << std::endl;
	Pedro.beRepaired(10);
	std::cout << "Health points: " << Pedro.getHP() << std::endl;
	Pedro.getEnergy();
}