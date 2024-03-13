#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  try {
    srand(time(0));

    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("criminal");

    bob.signForm(shrubberyForm);
    bob.signForm(robotomyForm);
    bob.signForm(pardonForm);

    bob.executeForm(shrubberyForm);
    bob.executeForm(robotomyForm);
    bob.executeForm(pardonForm);
  } catch (Bureaucrat::GradeTooHighException &exception) {
    std::cerr << "Caught GradeTooHighException: " << exception.what()
              << std::endl;
  } catch (Bureaucrat::GradeTooLowException &exception) {
    std::cerr << "Caught GradeTooLowException: " << exception.what()
              << std::endl;
  } catch (std::exception &exception) {
    std::cerr << "Caught exception: " << exception.what() << std::endl;
  }
}