#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(Intern const &src)
{
    std::cout << "Intern copy construct created" << std::endl;
    *this = src;
}

Intern & Intern::operator=(Intern const &src)
{
    std::cout << "Intern assign. operator created" << std::endl;
    (void) src;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern deleated" << std::endl;
}
AForm *makePresident(const std::string target)
{
  return (new PresidentialPardonForm(target));
}

AForm *makeRobot(const std::string target)
{
  return (new RobotomyRequestForm(target));
}

AForm *makeShrubbery(const std::string target)
{
  return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string form_to_create, const std::string target_for_form)
{
  AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
  std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm",
                         "ShrubberyCreationForm"};

  for (int i = 0; i < 3; i++)
  {
    if (form_to_create == forms[i])
    {
      std::cout << "Intern creates " << form_to_create << " now" << std::endl;
      return (all_forms[i](target_for_form));
    }
  }

  std::cout << "Intern can not create a form called " << form_to_create << std::endl;
  return (NULL);
}