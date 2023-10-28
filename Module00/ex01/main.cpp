#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Contact {
public:
    Contact();
    void setFields(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    bool isEmpty() const;
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

class PhoneBook {
public:
    PhoneBook();
    void addContact();
    void searchContact() const;
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int numContacts;
};

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setFields(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}

bool Contact::isEmpty() const {
    return firstName.empty() && lastName.empty() && phoneNumber.empty() && darkestSecret.empty();
}

PhoneBook::PhoneBook() : numContacts(0) {}

void PhoneBook::addContact() {
    if (numContacts == MAX_CONTACTS) {
        std::cout << "Phone book is full. Oldest contact will be replaced." << std::endl;
        for (int i = 0; i < MAX_CONTACTS - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        numContacts--;
    }
    Contact contact;
    std::string input;
    while (true) {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.find_first_not_of(' ') != std::string::npos) {
            contact.setFields(input, "", "", "", "");
            break;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
        }
    }
    while (true) {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.find_first_not_of(' ') != std::string::npos) {
            contact.setFields(contact.getFirstName(), input, "", "", "");
            break;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
        }
    }
    while (true) {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty() || input.find_first_not_of(' ') != std::string::npos) {
            contact.setFields(contact.getFirstName(), contact.getLastName(), input, "", "");
            break;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string or leave it blank." << std::endl;
        }
    }
    while (true) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (input.find_first_not_of(' ') != std::string::npos && std::all_of(input.begin(), input.end(), ::isdigit)) {
            contact.setFields(contact.getFirstName(), contact.getLastName(), contact.getNickname(), input, "");
            break;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string containing only digits." << std::endl;
        }
    }
    while (true) {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty() || input.find_first_not_of(' ') != std::string::npos) {
            contact.setFields(contact.getFirstName(), contact.getLastName(), contact.getNickname(), contact.getPhoneNumber(), input);
            break;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string or leave it blank." << std::endl;
        }
    }
    contacts[numContacts] = contact;
    numContacts++;
}

void PhoneBook::searchContact() const {
    if (numContacts == 0) {
        std::cout << "Phone book is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First name" << "|" << std::setw(10) << "Last name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < numContacts; i++) {
        std::cout << std::setw(10) << i << "|" << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|" << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|" << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << "|" << std::endl;
    }
    std::string input;
    while (true) {
        std::cout << "Enter index of contact to display: ";
        std::getline(std::cin, input);
        if (input.find_first_not_of(' ') != std::string::npos && std::all_of(input.begin(), input.end(), ::isdigit)) {
            int index = std::stoi(input);
            if (index < 0 || index >= numContacts) {
                std::cout << "Invalid index, please...look the index!!." << std::endl;
            } else {
                Contact contact = contacts[index];
                std::cout << "First name: " << contact.getFirstName() << std::endl;
                std::cout << "Last name: " << contact.getLastName() << std::endl;
                std::cout << "Nickname: " << contact.getNickname() << std::endl;
                std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
                std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
                break;
            }
        } else {
            std::cout << "Invalid input. Please enter a non-empty string containing only digits." << std::endl;
        }
    }
}

int main() {
    PhoneBook phoneBook;
    std::string input;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);
        if (input == "ADD") {
            phoneBook.addContact();
        } else if (input == "SEARCH") {
            phoneBook.searchContact();
        } else if (input == "EXIT") {
            break;
        }
    }
    return 0;
}