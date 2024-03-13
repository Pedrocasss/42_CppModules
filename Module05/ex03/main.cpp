#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
  AForm *b = NULL;
  AForm *c = NULL;

  try
  {
    srand(time(0));
    Bureaucrat a("Emperor", 45);
    Intern z;
    b = z.makeForm("RobotomyRequestForm", "Bender");
    c = z.makeForm("ShrubberyCreationForm", "Christmas");
    std::cout << a << std::endl << *b << std::endl << *c << std::endl;
    b->beSigned(a);
    a.signForm(*c);
    std::cout << *b << std::endl << *c << std::endl;

    for (int i = 0; i < 10; i++)
      b->execute(a);

    a.executeForm(*c);
  }
  catch (Bureaucrat::GradeTooHighException &exception)
  {
    std::cerr << "Caught GradeTooHighException: " << exception.what() << std::endl;
  }
  catch (Bureaucrat::GradeTooLowException &exception)
  {
    std::cerr << "Caught GradeTooLowException: " << exception.what() << std::endl;
  }
  catch (std::exception &exception)
  {
    std::cerr << "Caught exception: " << exception.what() << std::endl;
  }

  delete b;
  delete c;

  return 0;
}