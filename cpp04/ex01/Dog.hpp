/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:30:24 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 13:30:24 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;

public:
    Dog( void );
    ~Dog( void );

    Dog( const Dog& src );
    Dog& operator=( const Dog& rhs );

    void   makeSound( void ) const;
};

#endif