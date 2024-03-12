
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
  std::cout << "Enter a grade: ";
  int grade;
  std::cin >> grade;
  try 
  {
    Bureaucrat pedro("Pedro", grade);
    std::cout << pedro << std::endl;
    pedro.incrementGrade();
    std::cout << pedro.getName() << " incremented his grade to " << pedro.getGrade() << std::endl;
    pedro.decrementGrade();
    std::cout << pedro.getName() << " reseted his grade to " << pedro.getGrade() << std::endl;
    pedro.decrementGrade();
    std::cout << pedro.getName() << " decremented his grade to " << pedro.getGrade() << std::endl;
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
}