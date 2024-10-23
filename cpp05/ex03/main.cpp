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

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		bob;
	AForm		*form;
	Bureaucrat	Ruddy("Ruddy", 5);

	try
	{
		form = bob.makeForm("robotomy request", "Alice");
		delete form;
		form = bob.makeForm("shrubbery creation", "Charlie");
		delete form;
		form = bob.makeForm("presidential pardon", "David");
		delete form;
		form = bob.makeForm("random request", "Elisa");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("shrubbery creation", "Fred");
	form->beSigned(Ruddy);
	Ruddy.executeForm(*form);
	delete form;
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("presidential pardon", "Georgia");
	Ruddy.signForm(*form);
	Ruddy.executeForm(*form);
	delete form;
	return (0);
}
