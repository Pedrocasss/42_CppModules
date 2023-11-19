#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
    int index;
    Contact contacts[8];
public:
    Phonebook();
    ~Phonebook();
    void    addAll();
    void    printInfo(int i);
    void    printTable();
    bool	Verify_contact(int num);
};


#endif