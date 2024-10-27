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
#include "Form.hpp"

int main(void)
{
	std::cout << "Test #1\n" << std::endl;
	Bureaucrat *a = new Bureaucrat();
	Form *b = new Form();
	std::cout << std::endl;

	std::cout << a;
	std::cout << b;

	try
	{
		a->signForm(*b);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
	}

	std::cout << b;
	std::cout << "Test #2\n" << std::endl;
	Form *c = new Form(*b);
	std::cout << std::endl;
	std::cout << c;
	delete a;
	delete b;
	delete c;
	std::cout << std::endl;
	std::cout << "Test #3\n" << std::endl;
	Bureaucrat new_employee("new employee", 150);
	Bureaucrat boss("the boss", 1);
	std::cout << &new_employee;
	std::cout << &boss;
	Form vform("Very important", 1, 1);
	std::cout << &vform;
	try
	{
		new_employee.signForm(vform);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << new_employee.getName() << " was not able to sign " << new_employee.getName() << ": " << e.what() << std::endl;
	}
	return 0;
}
