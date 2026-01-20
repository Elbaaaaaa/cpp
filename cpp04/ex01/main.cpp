/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:16:05 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 16:30:06 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include <string>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << j->getType() << " " << std::endl;		
	j->makeSound();
	meta->makeSound();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;

	std::cout << "\n--- Brain test ---" << std::endl;
	Dog* d1 = new Dog();
	d1->setIdea(0, "Chasing squirrels");
	std::cout << "d1 idea[0]: " << d1->getIdea(0) << std::endl;

	Dog d2(*d1);
	std::cout << "d2 idea[0] (after copy): " << d2.getIdea(0) << std::endl;

	d1->setIdea(0, "Eating");
	std::cout << "d1 idea[0] (changed): " << d1->getIdea(0) << std::endl;
	std::cout << "d2 idea[0] (should be unchanged): " << d2.getIdea(0) << std::endl;

	delete d1;
	
	return 0;
}
