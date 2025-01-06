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
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 45, 30);

        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat alice("Alice", 30);

        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", 151);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 0, 150);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
