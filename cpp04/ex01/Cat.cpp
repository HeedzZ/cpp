/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:30:14 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 13:30:14 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << this->_type << " constructor called" << std::endl;
    try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation failed : " << e.what() << std::endl;
    }
}

Cat::~Cat( void )
{
    std::cout << this->_type << " destructor called" << std::endl;
    delete this->_brain;
}

Cat::Cat( const Cat& src ) : Animal("Cat")
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}


Cat& Cat::operator=( const Cat& rhs )
{
    std::cout << "<Cat.cpp:32> Cat copy called." << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
        this->_brain = new Brain( *rhs._brain );
    }
    return *this;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Woaf!" << std::endl;
}