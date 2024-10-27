/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:26:01 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 17:26:01 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
		AForm(void);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		AForm(const std::string name, int sign_grade, int exec_grade);
		virtual	~AForm();

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const &executor)const = 0;
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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class InvalidFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif