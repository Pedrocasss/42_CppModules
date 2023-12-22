#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
/*Sem o virtual no destructor, ao deletar um objeto da classe derivada através de um ponteiro da classe base, 
apenas o destructor da classe base seria chamado. Isso pode levar a vazamento de memória se a classe derivada alocou 
recursos que precisam ser liberados no seu destructor.*/

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &src);
        WrongAnimal& operator=(WrongAnimal const &src);
        virtual ~WrongAnimal();
        std::string getType() const;
        void setType(const std::string& newType);
        virtual void makeSound() const;
};

#endif