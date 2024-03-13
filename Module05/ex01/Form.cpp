#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form " << _name << " created" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form & Form::operator=( Form const & src )
{
	this->_signed = src.getSigned();

	return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool    Form::getSigned() const
{
    return _signed;
}

int     Form::getGradeToSign() const
{
    return _gradeToSign;
}

int     Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
  if (bureaucrat.getGrade() > this->_gradeToSign)
    throw GradeTooLowException();
  this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Form &form)
{
  os << "Form " << form.getName() << " is ";
  if (!form.getSigned())
  {
    os << "not ";
  }
  os << "signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << ".";
  return os;
}