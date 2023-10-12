// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:00:53 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 15:44:20 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "./classes/Animal.hpp"
#include "./classes/Dog.hpp"
#include "./classes/Cat.hpp"
#include "./classes/WrongAnimal.hpp"
#include "./classes/WrongCat.hpp"

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

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongCat* catOneWrong = new WrongCat();
	const WrongCat* catTwoWrong = new WrongCat();

	wrongMeta->makeSound();
	catOneWrong->makeSound();
	catTwoWrong->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete catOneWrong;
	delete catTwoWrong;

	return (0);
}
