/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:13:44 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/03 16:13:44 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 25, 5), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 25, 5), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm("RobotomyRequestForm", 25, 5), _target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		_target = src._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::FormNotSignedException());
	else
	{
		if (std::rand() % 2 == 0)
			std::cout << "BZZZZZZZZZZZZZZZZ\n" << this->getTarget() << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	os << "Form " << form.getName() <<
	":\n\tsign-grade:\t" << form.getSignGrade() <<
	"\n\texec-grade:\t" << form.getExecGrade() <<
	"\n\tis signed:\t" << form.getIsSigned() <<
	std::endl;
	return (os);
}