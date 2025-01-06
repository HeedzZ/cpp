/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:25:57 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 17:25:57 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void): _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

AForm::~AForm()
{
}

void AForm::execute(Bureaucrat const &executor)const
{
	(void)executor;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
    _isSigned = true;
}

const std::string	AForm::getName(void)const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void)const
{
	return (this->_isSigned);
}

int	AForm::getSignGrade(void)const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void)const
{
	return (this->_execGrade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
};

char const	*AForm::InvalidFormException::what(void) const throw()
{
	return ("Form doesn’t exist");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName() <<
	":\nsign-grade:\t" << form.getSignGrade() <<
	"\nexec-grade:\t" << form.getExecGrade() <<
	"\nis signed:\t" << form.getIsSigned() << "\n" << std::endl;
	return (os);
}
