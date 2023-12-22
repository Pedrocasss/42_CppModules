#ifndef ANIMAL_HPP
# define ANIMAL_HPP


#include <iostream>

class   Animal
{
    protected:
    std::string type;
    public:
        Animal();
        Animal(Animal const &src);
        Animal& operator=(Animal const &src);
        virtual ~Animal();
        std::string getType() const;
        void setType(const std::string& newType);
        virtual void makeSound() const;
};
#endif