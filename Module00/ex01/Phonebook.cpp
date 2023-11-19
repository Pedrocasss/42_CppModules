#include "Phonebook.hpp"

Phonebook::Phonebook(){
    this->index = 0;
}

Phonebook::~Phonebook() {
 
}
bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

bool checkWhiteSpaces(std::string& input) {
    for (std::string::size_type i = 0; i < input.length(); ++i) {
        if (!isSpace(input[i])) {
            return false;
        }
    }
    return true;
}

bool isNumber(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (*it < '0' || *it > '9') {
            return false;
        }
    }
    return true;
}
void    Phonebook::addAll(){
    std::string input;

    if (index > 7)
        index = 0;
    std::cout << "First name: "<< std::endl;
    getline(std::cin, input);
    if (input.size() == 0 || checkWhiteSpaces(input))
    {
        std::cout << "Error. Try again."<< std::endl;
        return ;
    }
    contacts[index].setFirst(input);
    std::cout << "Last name: "<< std::endl;
    getline(std::cin, input);
    if (input.size() == 0 || checkWhiteSpaces(input))
    {
        std::cout << "Error. Try again."<< std::endl;
        return ;
    }
    contacts[index].setLast(input);
    std::cout << "Nickname: "<< std::endl;
    getline(std::cin, input);
    if (input.size() == 0 || checkWhiteSpaces(input))
    {
        std::cout << "Error. Try again."<< std::endl;
        return ;
    }
    contacts[index].setNickname(input);
    std::cout << "Phone number: "<< std::endl;
    getline(std::cin, input);
    if (input.size() == 0 || (checkWhiteSpaces(input) && !isNumber(input)))
    {
        std::cout << "Error. Try again."<< std::endl;
        return ;
    }
    contacts[index].setPhonenumber(input);
    std::cout << "Darkest secret: "<< std::endl;
    getline(std::cin, input);
    if (input.size() == 0 || checkWhiteSpaces(input))
    {
        std::cout << "Error. Try again." << std::endl;
        return ;
    }
    contacts[index].setDarkestsecret(input);
    index++;
}

void    Phonebook::printInfo(int i){

    std::cout << "First name: " << contacts[i].returnFirst() << std::endl;
    std::cout << "Last name: " << contacts[i].returnLast() << std::endl;
    std::cout << "Nickname: " << contacts[i].returnNickname() << std::endl;
    std::cout << "Phone number: " << contacts[i].returnPhonenumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[i].returnDarkestsecret() << std::endl;
}

void    Phonebook::printTable(){

    int i = 0;
    int j;
    system("clear");
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|===========================================|" << std::endl;
	while (i < 8 && (Verify_contact(i) == true))
	{
		std::cout << '|' << std::setw(10) << i << '|';
		if (contacts[i].returnFirst().size() <= 10)
			std::cout << std::setw(10) << contacts[i].returnFirst().substr(0, 9) << '|';
		else
			std::cout << std::setw(9) << contacts[i].returnFirst().substr(0, 9) << '.' << '|';
		if (contacts[i].returnLast().size() <= 10)
			std::cout << std::setw(10) << contacts[i].returnLast().substr(0, 9) << '|';
		else
			std::cout << std::setw(9) << contacts[i].returnLast().substr(0, 9) << '.' << '|';
		if (contacts[i].returnNickname().size() <= 10)
			std::cout << std::setw(10) << contacts[i].returnNickname().substr(0, 9) << '|' << std::endl;
		else
			std::cout << std::setw(9) << contacts[i].returnNickname().substr(0, 9) << '.' << '|' << std::endl;
		std::cout << "|===========================================|" << std::endl;
		i++;
	}
	std::cout << "Write the index:" << std::endl;
	std::cin >> j;
	if (std::cin.fail())
		std::cout << "The input must be a number." << std::endl;
	else if (j < 0 || j > 7 || Verify_contact(j) == 0)
		std::cout << "Insert valid number or contact doesn't exist" << std::endl;
	else if (j >= 0 && j < i && Verify_contact(j) == 1)
		printInfo(j);
	std::cin.clear();
    std::cin.ignore(2147483648, '\n');
	return ;
}

bool	Phonebook::Verify_contact(int num)
{
	if (contacts[num].returnFirst() == "" || contacts[num].returnLast() == "" || \
	contacts[num].returnNickname() == "" || contacts[num].returnPhonenumber() == "" || \
	contacts[num].returnDarkestsecret() == "")
		return (false);
	return (true);
}