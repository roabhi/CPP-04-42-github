// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongAnimal.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 14:25:00 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 15:31:42 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "Wrong Animal";
	std::cout << "Wrong Aninal default constructor called" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &inst)
{
	this->_type = "Wrong Animal";
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = inst;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &inst)
{
	this->_type = inst.getType();
	std::cout << "Wrong Animal copy assigment opertor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal destructor called" << std::endl;
	return ;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I am making a sound too weird for an animal, like pfffffffff" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

