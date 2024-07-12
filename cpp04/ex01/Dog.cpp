/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:30:20 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 13:30:20 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << this->_type << " constructor called" << std::endl;
    try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation failed : " << e.what() << std::endl;
    }
}

Dog::~Dog( void )
{
    std::cout << this->_type << " destructor called" << std::endl;
    delete this->_brain;
}

Dog::Dog( const Dog& src ) : Animal("Dog")
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=( const Dog& rhs )
{
    std::cout << "Dog copy called." << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
        this->_brain = new Brain( *rhs._brain );
    }
    return *this;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woaf!" << std::endl;
}
