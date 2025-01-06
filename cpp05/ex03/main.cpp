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
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat employee("Employee", 45);

        AForm *presForm = NULL;
        AForm *robotForm = NULL;
        AForm *shrubForm = NULL;

        try {
            presForm = someRandomIntern.makeForm("presidential pardon", "TargetA");
            robotForm = someRandomIntern.makeForm("robotomy request", "TargetB");
            shrubForm = someRandomIntern.makeForm("shrubbery creation", "TargetC");
        } catch (const std::exception &e) {
            std::cerr << "Exception caught during form creation: " << e.what() << std::endl;
        }

        if (presForm) {
            std::cout << *presForm << std::endl;
            boss.signForm(*presForm);
            boss.executeForm(*presForm);
            delete presForm;  // Suppression après utilisation
        }

        if (robotForm) {
            std::cout << *robotForm << std::endl;
            boss.signForm(*robotForm);
            boss.executeForm(*robotForm);
            delete robotForm;  // Suppression après utilisation
        }

        if (shrubForm) {
            std::cout << *shrubForm << std::endl;
            employee.signForm(*shrubForm);
            employee.executeForm(*shrubForm);
            delete shrubForm;  // Suppression après utilisation
        }

        // Tentative de créer un formulaire invalide
        try {
            AForm *invalidForm = someRandomIntern.makeForm("invalid form", "TargetD");
            if (invalidForm) {
                delete invalidForm;  // Suppression même en cas de formulaire invalide
            }
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
