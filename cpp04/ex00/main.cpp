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

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << "getType : " << j->getType() << " " << std::endl;
std::cout << "getType : " << i->getType() << " " << std::endl;
j->makeSound();
i->makeSound();
meta->makeSound();
delete i;
delete j;
delete meta;

const WrongAnimal* wmeta = new WrongAnimal();
const WrongAnimal* wi = new WrongCat();
std::cout << "getType : " << wi->getType() << " " << std::endl;
wi->makeSound();
wmeta->makeSound();
delete wi;
delete wmeta;
return 0;
}