#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :AForm(src), _target(src._target)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    AForm::operator=(src);
    _target = src._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned() || executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::ofstream ofs((getName() + "Shrubbery").c_str());
    if (!ofs.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    ofs << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
  ofs << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
  ofs << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
  ofs << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
  ofs << "        {/{/(_)/}{\\{/)_\\}\\{\\(_){/}/}/}/}" << std::endl;
  ofs << "         {\\{/(_\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
  ofs << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_)\\{\\/}\\}" << std::endl;
  ofs << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
  ofs << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  ofs << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
  ofs << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
  ofs << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
  ofs << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
  ofs << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
  ofs << "          (_)\\{/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
  ofs << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
  ofs << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
  ofs << "              {)\\{\\/}{\\/} \\}\\}" << std::endl;
  ofs << "              (_)  \\.- .-/" << std::endl;
  ofs << "                    | -.- |" << std::endl;
  ofs << "                    | -.- |" << std::endl;
  ofs << "                    |. -._|" << std::endl;
  ofs << "                    |  -. |" << std::endl;
  ofs << "                    | -_.-|" << std::endl;
  ofs << "                    |-._ -|" << std::endl;
  ofs << "                    | - .-|" << std::endl;
  ofs << "                    `-._.- " << std::endl;
  ofs.close();
}
std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}
