#include "Form.hpp"

int main()
{
  try
  {
    Bureaucrat salazar("Salazar", 1);
    std::cout << salazar << std::endl;

    Form form1("Form1", 1, 1);
    std::cout << form1 << std::endl;

    salazar.signForm(form1);
    std::cout << form1 << std::endl;
  }
  catch (Bureaucrat::GradeTooHighException &exception)
  {
    std::cerr << "Caught Bureaucrat::GradeTooHighException: " << exception.what() << std::endl;
  }
  catch (Bureaucrat::GradeTooLowException &exception)
  {
    std::cerr << "Caught Bureaucrat::GradeTooLowException: " << exception.what() << std::endl;
  } 
  catch (std::exception &exception)
  {
    std::cerr << "Caught exception: " << exception.what() << std::endl;
  }
  std::cout << std::endl;
  try
  {
    Form form1("Form1", 1, 1);
    Bureaucrat dumbledore("Dumbledore", 1);
    std::cout << dumbledore << std::endl;

    dumbledore.signForm(form1);
    std::cout << form1 << std::endl;
  }
  catch (Bureaucrat::GradeTooHighException &exception)
  {
    std::cerr << "Caught Bureaucrat::GradeTooHighException: " << exception.what() << std::endl;
  }
  catch (Bureaucrat::GradeTooLowException &exception)
  {
    std::cerr << "Caught Bureaucrat::GradeTooLowException: " << exception.what() << std::endl;
  }
  catch (std::exception &exception)
  {
    std::cerr << "Caught exception: " << exception.what() << std::endl;
  }

  return 0;
}