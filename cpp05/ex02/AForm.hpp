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
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

	public:
		AForm(void);
		AForm(const AForm &src);
		AForm &operator=(const AForm &rhs);
		AForm(const std::string name, int signGrade, int execGrade);
		virtual ~AForm();

		virtual void execute(Bureaucrat const &executor)const = 0;
		void beSigned(const Bureaucrat& bureaucrat);
		const std::string getName(void)const;
		bool getIsSigned(void)const;
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
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
