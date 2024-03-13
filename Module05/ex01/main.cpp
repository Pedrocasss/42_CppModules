#include "Form.hpp"

int main(void)
{
  try
  {
    std::cout << "--------------------TEST 1--------------------" << std::endl;
    Bureaucrat Pedro("Pedro", 1);
    std::cout << Pedro << std::endl;
    Form form1("Form1", 1, 1);
    std::cout << form1 << std::endl;
    Pedro.signForm(form1);
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
    std::cout << "--------------------TEST 2--------------------" << std::endl;
    Form form2("Form2", 1, 1);
    Bureaucrat dumbledore("Dumbledore", 1);
    std::cout << dumbledore << std::endl;
    dumbledore.signForm(form2);
    std::cout << form2 << std::endl;
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
    std::cout << "--------------------TEST 3--------------------" << std::endl;
    Form form3("Form3", 160, 1);
    Bureaucrat voldemort("Voldemort", 160);
    std::cout << voldemort << std::endl;
    voldemort.signForm(form3);
    std::cout << form3 << std::endl;
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