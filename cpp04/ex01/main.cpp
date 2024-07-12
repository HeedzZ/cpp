/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:06:30 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 14:06:30 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main( void )
{
    /*const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;*/

    Dog basic;
    {
    Dog tmp = basic;
    }
    

    /*const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ )
        delete animals[i];*/

    return 0;
}