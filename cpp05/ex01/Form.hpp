/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:26:01 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 17:26:01 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

	public:
		Form(void);
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		Form(const std::string name, int signGrade, int execGrade);
		~Form();

		void beSigned(const Bureaucrat& bureaucrat);
		const std::string getName(void)const;
		bool getIsSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif