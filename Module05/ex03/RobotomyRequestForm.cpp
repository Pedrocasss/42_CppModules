#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::result = 0;


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobootmyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    AForm::operator=(src);
    _target = src._target;
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getSigned() || executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "Drilling noises..." << std::endl;
	std::string	outcomes[2] = \
				{" has been robotomized.", "'s robotomy has failed."};

	std::cout << _target << outcomes[result++ % 2] << std::endl;
}