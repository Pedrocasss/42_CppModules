#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Contact{
    private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;

    public:
    void    setAll(std::string _firstname, std::string _lastname, std::string _nickname, std::string _phonenumber, std::string _darkestsecret);
    void    printPrivate();
    void    getAll();
};
#endif