# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void) other;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& bureau) const
{
    
    if (bureau.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::cout << "DRLLING NOISES..." << std::endl;
    
    
    if (std::rand() % 2 + 1 == 1)
    {
      std::cout << _target << " has been robotomized successfully." << std::endl;
      return ;
    }
    std::cout << "Robotomy failed" << std::endl;
}