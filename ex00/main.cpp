// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:00:53 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/11 18:52:54 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "./classes/Animal.hpp"
#include "./classes/Dog.hpp"
#include "./classes/Cat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Dog* dogOne = new Dog();
	const Cat* catOne = new Cat();
	const Cat* catTwo = new Cat();

	std::cout << dogOne->getType() << " " << std::endl;
	std::cout << catOne->getType() << " " << std::endl;
	std::cout << catTwo->getType() << " " << std::endl;
	
	meta->makeSound();
	dogOne->makeSound();
	catOne->makeSound();
	dogOne->makeSound();
	catTwo->makeSound();
	meta->makeSound();

	delete meta;
	delete dogOne;
	delete catOne;
	delete catTwo;

	return (0);
}
