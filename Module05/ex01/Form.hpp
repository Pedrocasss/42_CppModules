#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const   std::string   _name;
        bool    _signed;
        int     _gradeToSign;
        int     _gradeToExecute;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const & src);
        ~Form();
        Form & operator=(Form const & src);
        std::string getName() const;
        bool    getSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form &form);
#endif