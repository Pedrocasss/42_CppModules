#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    AForm::operator=(src);
    _target = src._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  if (!getSigned() || executor.getGrade() > getGradeToExecute())
  {
    throw GradeTooLowException();
  }
  std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}