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
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
		Form(void);
		Form(const Form &src);
		Form &operator=(const Form &src);
		Form(const std::string name, int sign_grade, int exec_grade);
		~Form();

		void beSigned(const Bureaucrat& bureaucrat);
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif