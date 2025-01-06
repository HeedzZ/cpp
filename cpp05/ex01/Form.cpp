/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:25:57 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 17:25:57 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void): _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(const std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
    _isSigned = true;
}

const std::string	Form::getName(void)const
{
	return (this->_name);
}

bool	Form::getIsSigned(void)const
{
	return (this->_isSigned);
}

int	Form::getSignGrade(void)const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void)const
{
	return (this->_execGrade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << " (sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecGrade() << ", signed: "
       << (form.getIsSigned() ? "yes" : "no") << ")";
    return os;
}
