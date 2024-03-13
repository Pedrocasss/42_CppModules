#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm " << _name << " destroyed" << std::endl;
}

AForm & AForm::operator=( AForm const & src )
{
    this->_signed = src.getSigned();

    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool    AForm::getSigned() const
{
    return _signed;
}

int     AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int     AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
  if (bureaucrat.getGrade() > this->_gradeToSign)
    throw GradeTooLowException();
  this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, AForm &form)
{
  os << "AForm " << form.getName() << " is ";
  if (!form.getSigned())
  {
    os << "not ";
  }
  os << "signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << ".";
  return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();
}
