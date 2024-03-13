#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm();
        static int	result;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();
        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
        void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
};

#endif