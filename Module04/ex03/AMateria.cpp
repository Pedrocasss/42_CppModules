#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
	std::cout << "AMateria Constructor called" << std::endl;
	this->_type = type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}