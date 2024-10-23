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

int main(void)
{
	std::cout << "Test #1\n" << std::endl;
	Bureaucrat test;
	/*for (size_t i = 0; i < 149; i++)
	{
		test.incrementGrade();
	}*/
	Bureaucrat test1 = test;
	std::cout << &test1 << std::endl;
	std::cout << "Test #2\n" << std::endl;
	try
	{
	test.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Incrementing grade of " << test.getName() <<
		" failed: " << e.what() << std::endl;
	}
	std::cout << &test;
	try
	{
	test.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decrementing grade of " << test.getName() <<
		" failed: " << e.what() << std::endl;
	}
	std::cout << &test;
	try
	{
	test.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decrementing grade of " << test.getName() <<
		" failed: " << e.what() << std::endl;
	}
	std::cout << &test << std::endl;
	std::cout << "Test #3\n" << std::endl;
	
	Bureaucrat *test2 = NULL;
	try
	{
		test2 = new Bureaucrat("Ruddy", -1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Construction failed: " <<
		e.what() << std::endl;
	}
	if (test2 != NULL)
	{
		std::cout << test2;
		delete test2;
	}
	std::cout << std::endl;
	try
	{
		test2 = new Bureaucrat("Ruddy", 150);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Construction failed: " <<
		e.what() << std::endl;
	}
	if (test2 != NULL)
	{
		std::cout << test2;
		delete test2;
	}
	std::cout << std::endl;
	std::cout << "Test #4\n" << std::endl;
	try
	{
		test2 = new Bureaucrat("Ruddy", 150);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Construction failed: " <<
		e.what() << std::endl;
	}
	
	Bureaucrat *test3;
	try
	{
		test3 = new Bureaucrat(*test2);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Construction failed: " <<
		e.what() << std::endl;
	}
	if (test2 != NULL &&  test3 != NULL)
	{
		delete test2;
		std::cout << test3;
		delete test3;
	}
	std::cout << std::endl;

	return 0;
}
