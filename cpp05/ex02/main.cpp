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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat highRank("HighRank", 1);
        Bureaucrat lowRank("LowRank", 50);
        Bureaucrat tooLowRank("TooLowRank", 150);
        
        PresidentialPardonForm pForm("TargetX");
        std::cout << pForm << std::endl;

        try {
            tooLowRank.signForm(pForm);
        } catch (std::exception &e) {
            std::cerr << "TooLowRank couldn't sign the Presidential form: " << e.what() << std::endl;
        }

        try {
            highRank.signForm(pForm);
        } catch (std::exception &e) {
            std::cerr << "HighRank couldn't sign the Presidential form: " << e.what() << std::endl;
        }

        try {
            lowRank.executeForm(pForm);
        } catch (std::exception &e) {
            std::cerr << "LowRank couldn't execute the Presidential form: " << e.what() << std::endl;
        }

        try {
            highRank.executeForm(pForm);
        } catch (std::exception &e) {
            std::cerr << "HighRank couldn't execute the Presidential form: " << e.what() << std::endl;
        }

        RobotomyRequestForm rForm("TargetY");
        std::cout << rForm << std::endl;

        try {
            lowRank.signForm(rForm);
        } catch (std::exception &e) {
            std::cerr << "LowRank couldn't sign the Robotomy form: " << e.what() << std::endl;
        }

        try {
            highRank.signForm(rForm);
        } catch (std::exception &e) {
            std::cerr << "HighRank couldn't sign the Robotomy form: " << e.what() << std::endl;
        }

        try {
            lowRank.executeForm(rForm);
        } catch (std::exception &e) {
            std::cerr << "LowRank couldn't execute the Robotomy form: " << e.what() << std::endl;
        }

        try {
            highRank.executeForm(rForm);
        } catch (std::exception &e) {
            std::cerr << "HighRank couldn't execute the Robotomy form: " << e.what() << std::endl;
        }

        ShrubberyCreationForm sForm("TargetZ");
        std::cout << sForm << std::endl;

        try {
            tooLowRank.signForm(sForm);
        } catch (std::exception &e) {
            std::cerr << "TooLowRank couldn't sign the Shrubbery form: " << e.what() << std::endl;
        }

        try {
            highRank.signForm(sForm);
        } catch (std::exception &e) {
            std::cerr << "HighRank couldn't sign the Shrubbery form: " << e.what() << std::endl;
        }

        try {
            lowRank.executeForm(sForm);
        } catch (std::exception &e) {
            std::cerr << "LowRank couldn't execute the Shrubbery form: " << e.what() << std::endl;
        }

        try {
            highRank.executeForm(sForm);
        } catch (std::exception &e) {
            std::cerr << "HighRank couldn't execute the Shrubbery form: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

