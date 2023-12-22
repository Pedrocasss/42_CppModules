#include "Character.hpp"

Character::Character(std::string name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_name = name;
	std::cout << "Character Constructor here!" << std::endl;
}

void Character::equip(AMateria* m) {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	this->_inventory[idx]->use(target);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	std::cout << "Character Destructor here" << std::endl;
}