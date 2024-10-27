/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:42 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 13:58:42 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() << " with grade of " << grade << std::endl;
		this->setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	_grade = src.getGrade();
	return *this;
}

const std::string	Bureaucrat::getName(void)const
{
	return (_name);
}

int	Bureaucrat::getGrade(void)const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
	this->setGrade(_grade + 1);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\ngrade: " << a->getGrade() << std::endl;
	return (o);
}
