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

AForm::AForm(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm()
{
	std::cout << "Form Destructor for " << this->getName() << " called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_sign_grade)
        this->_is_signed = true;
	else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor)const
{
	(void)executor;
}

const std::string	AForm::getName(void)const
{
	return (this->_name);
}

const std::string	AForm::getIsSigned(void)const
{
	if (this->_is_signed)
		return ("True");
	else
		return ("False");
}

bool	AForm::getIsSignedBool(void)const
{
	return (this->_is_signed);
}

int	AForm::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void)const
{
	return (this->_exec_grade);
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

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "Form " << a->getName() <<
	":\nsign-grade:\t" << a->getSignGrade() <<
	"\nexec-grade:\t" << a->getExecGrade() <<
	"\nis signed:\t" << a->getIsSigned() << "\n" << std::endl;
	return (o);
}
