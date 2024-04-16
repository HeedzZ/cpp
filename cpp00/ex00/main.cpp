/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:42:27 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/15 10:42:27 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
	std::string text;
    for (size_t i = 1; i < argc; ++i)
	{
        text = argv[i];
    for (size_t j = 0; j < text.length(); ++j)
            text[j] = std::toupper(text[j]);
	std::cout << text;
	}
    std::cout << std::endl;
    return (0);
}