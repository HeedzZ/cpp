/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:00:51 by ymostows          #+#    #+#             */
/*   Updated: 2024/10/16 19:00:51 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods
AForm	*Intern::makeForm(const std::string form_name, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cerr << "Intern couldn't creates " << form_name << std::endl;
	throw(AForm::InvalidFormException());
	return (NULL);
}