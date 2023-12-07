#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap Diogo("Diogo");
	FragTrap Pedro("Pedro");
	FragTrap Eduardo("Eduardo");

	Pedro.attack("Eduardo");
	Eduardo.takeDamage(Pedro.getAttackDamage());
	std::cout << "Eduardo Health points: " << Eduardo.getHP() << std::endl;
	Eduardo.beRepaired(10);
	Eduardo.attack("Pedro");
    Pedro.takeDamage(Eduardo.getAttackDamage());
	std::cout << "Eduardo Health points: " << Eduardo.getHP() << std::endl;
	std::cout << "Pedro Health points: " << Pedro.getHP() << std::endl;
	std::cout << "Eduardo Energy points: " << Eduardo.getEnergy() << std::endl;
	std::cout << "Pedro Energy points: " << Pedro.getEnergy() << std::endl;
    std::cout << std::endl;
    Diogo.highFivesGuys();
    std::cout << std::endl;


}
