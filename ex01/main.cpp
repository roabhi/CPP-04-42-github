// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 17:09:23 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 20:40:11 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./classes/animals/Animal.hpp"
#include "./classes/animals/Dog.hpp"
#include "./classes/animals/Cat.hpp"



int main(void)
{
	{

	const Animal *animal = new Animal();
	const Animal* dog1 = new Dog();
	const Animal* cat1 = new Cat();

	animal->makeSound();
	dog1->makeSound();
	cat1->makeSound();

	delete animal;
	delete dog1;
	delete cat1;

	std::cout << std::endl << "++++++++++++++++++++++++++++++++++++++";
	std::cout << std::endl << std::endl;

	}

	{
		Animal* animals[10];


		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
			{
				animals[i] = new Dog();
				dynamic_cast<Dog *>(animals[ i ])->setIdeas("to bark");
			}			
			else
			{
				animals[i] = new Cat();
				dynamic_cast<Cat *>(animals[ i ])->setIdeas("to fuuurrrr");
			}			
		}

		static_cast<Dog *>(animals[ 3 ])->setIdeas("to biiiiite");
		static_cast<Dog *>(animals[ 3 ])->setIdeas("to eat bones");
		static_cast<Dog *>(animals[ 3 ])->setIdeas("to annoy neighboors");
		static_cast<Cat *>(animals[ 6 ])->setIdeas("to lick");
		

		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
			{
				std::cout << "---------------" <<  std::endl;
				std::cout << "Ideas for Animal " << i <<  " which is a " << animals[i]->getType() << std::endl << std::endl;
				dynamic_cast<Dog *>(animals[ i ])->showIdeas();
				std::cout << "---------------" <<  std::endl;
			}			
			else
			{
				std::cout << "---------------" <<  std::endl;
				std::cout << "Ideas for Animal " << i <<  " which is a " << animals[i]->getType() << std::endl << std::endl;
				dynamic_cast<Cat *>(animals[ i ])->showIdeas();
				std::cout << "---------------" <<  std::endl;
			}			
		}

	
		for (int i = 0; i < 10; i++)
			delete animals[i];		 		
		
	}

	return (0);
}
