#include "Contact.hpp"

void    Contact::setFirst(std::string _firstname)
{
   this->firstname = _firstname;
}

void    Contact::setLast(std::string _lastname)
{
    this->lastname = _lastname;
}

void    Contact::setNickname(std::string _nickname)
{
    this->nickname = _nickname;
}

void    Contact::setPhonenumber(std::string _phonenumber)
{
    this->phonenumber = _phonenumber;
}

void    Contact::setDarkestsecret(std::string _darkestsecret)
{
    this->darkestsecret = _darkestsecret;
}

std::string Contact::returnFirst()
{
    return this->firstname;
}

std::string Contact::returnLast()
{
    return this->lastname;
}

std::string Contact::returnNickname()
{
    return this->nickname;
}

std::string Contact::returnPhonenumber()
{
    return this->phonenumber;
}

std::string Contact::returnDarkestsecret()
{
    return this->darkestsecret;
}