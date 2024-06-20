# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (signGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1)
        throw GradeTooHighException();

    if (execGrade > 150)
        throw GradeTooLowException();
    else if (execGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()), _isSigned(other.isSigned()) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this == &other)
        return (*this);
    this->_isSigned = other.isSigned();
    return (*this);
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    this->_isSigned = true;        
}

const std::string& AForm::getName(void) const
{
    return this->_name;
}

int AForm::getSignGrade(void) const
{
    return this->_signGrade;
}

int AForm::getExecGrade(void) const
{
    return this->_execGrade;
}

bool AForm::isSigned(void) const
{
    return this->_isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << AForm.getName() << ", AForm sign grade " << AForm.getSignGrade() << ", exec grade " << AForm.getExecGrade() << ".";
    return os;
}
