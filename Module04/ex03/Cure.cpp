#include "Cure.hpp"

Cure::Cure() : AMateria() {
	std::cout << "Cure Constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const & src) : AMateria(src) {
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = src;
}

Cure &Cure::operator=(Cure const &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

AMateria* Cure::clone () const {
	return new Cure(*this);
}

void Cure::use (ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure () {
	std::cout << "Cure Destructor called" << std::endl;
}