/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:08:56 by ymostows          #+#    #+#             */
/*   Updated: 2024/09/03 16:08:56 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;
};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif

