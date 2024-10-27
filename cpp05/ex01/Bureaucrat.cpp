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

	this->_grade = src.getGrade();
	return *this;
}

const std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(Form& form) {
    try
	{
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } 
	catch (const Form::GradeTooLowException& e)
	{
        std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
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
	o << "Bureaucrat " << a->getName() << ":\ngrade: " << a->getGrade() << "\n" << std::endl;
	return (o);
}
