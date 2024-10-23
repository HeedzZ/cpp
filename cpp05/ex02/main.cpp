/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:38 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 13:58:38 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	//AForm *b = new AForm();
	Bureaucrat *a = new Bureaucrat("Ruddy", 50);
	ShrubberyCreationForm *form = new ShrubberyCreationForm("Ruddy");

	std::cout << a;
	std::cout << form;
	try
	{
		form->beSigned(*a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		form->execute(*a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete(a);
	delete(form);
	
	Bureaucrat *b = new Bureaucrat("Ruddy2", 45);
	RobotomyRequestForm *form2 = new RobotomyRequestForm("Ruddy2");
	std::cout << b;
	std::cout << form2;
	try
	{
		form2->beSigned(*b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		form2->execute(*b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		form2->execute(*b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete(b);
	delete(form2);


	
	Bureaucrat *c = new Bureaucrat("Ruddy3", 5);
	PresidentialPardonForm *form3 = new PresidentialPardonForm("Ruddy3");
	std::cout << c;
	std::cout << form3;
	try
	{
		form3->beSigned(*c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		form3->execute(*c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete(c);
	delete(form3);
}
