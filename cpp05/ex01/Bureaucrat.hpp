/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:40 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/02 13:58:40 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string	_name;
		int					_grade;

    public:
        Bureaucrat( void );
        Bureaucrat( const Bureaucrat& src);
        Bureaucrat &operator=(const Bureaucrat &rhs);
		Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();

		const std::string getName(void)const;
		int getGrade(void)const;

		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(class Form& form);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif