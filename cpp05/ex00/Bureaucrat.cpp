#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) 
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this == &other)
        return (*this);
    this->_grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::increment(void)
{
    this->_grade--;
    if (this->_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement(void)
{
    this->_grade++;
    if (this->_grade > 150)
        throw GradeTooLowException();
}

const std::string& Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau)
{
    os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
    return os;
}
