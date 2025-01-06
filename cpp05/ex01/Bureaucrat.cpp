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
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
		throw GradeTooHighException();
    if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string	Bureaucrat::getName(void)const
{
	return (_name);
}

int	Bureaucrat::getGrade(void)const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if(_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade(void)
{
	if(_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat " << bureaucrat.getName() << ":\ngrade: " << bureaucrat.getGrade() << std::endl;
    return os;
}

