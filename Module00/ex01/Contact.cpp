#include "Contact.hpp"

void Contact::setAll(std::string _firstname, std::string _lastname, std::string _nickname, std::string _phonenumber, std::string _darkestsecret)
{
    if (!_firstname.empty()) firstname = _firstname;
    if (!_lastname.empty()) lastname = _lastname;
    if (!_nickname.empty()) nickname = _nickname;
    if (!_phonenumber.empty()) phonenumber = _phonenumber;
    if (!_darkestsecret.empty()) darkestsecret = _darkestsecret;
}

void Contact::printPrivate()
{
    std::cout << "Your first name: " << firstname << std::endl;
    std::cout << "Your last name: " << lastname << std::endl;
    std::cout << "Your nickname: " << nickname << std::endl;
    std::cout << "Your phone number: " << phonenumber << std::endl;
    std::cout << "Your darkest secret: " << darkestsecret << std::endl;
}

void Contact::getAll()
{
    std::string input;

    std::cout << "First name:" << std::endl;
    getline(std::cin, input);
    setAll(input, "", "", "", "");

    std::cout << "Last name:" << std::endl;
    getline(std::cin, input);
    setAll("", input, "", "", "");

    std::cout << "Nickname:" << std::endl;
    getline(std::cin, input);
    setAll("", "", input, "", "");

    std::cout << "Phone number:" << std::endl;
    getline(std::cin, input);
    setAll("", "", "", input, "");

    std::cout << "Darkest secret:" << std::endl;
    getline(std::cin, input);
    setAll("", "", "", "", input);
}
