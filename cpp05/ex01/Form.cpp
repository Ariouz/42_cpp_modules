# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
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

Form::Form(const Form& other) : _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()), _isSigned(other.isSigned()) {}

Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return (*this);
    this->_isSigned = other.isSigned();
    return (*this);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    this->_isSigned = true;        
}

const std::string& Form::getName(void) const
{
    return this->_name;
}

int Form::getSignGrade(void) const
{
    return this->_signGrade;
}

int Form::getExecGrade(void) const
{
    return this->_execGrade;
}

bool Form::isSigned(void) const
{
    return this->_isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", Form sign grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade() << ".";
    return os;
}
