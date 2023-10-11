// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:40:53 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/11 18:52:29 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &inst)
{
	*this = inst;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog detructor called" << std::endl;
	return ;
}

Dog &Dog::operator=(const Dog& inst)
{
	(void)inst;
	//this->_type = _type;
	this->_type = inst.getType();
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof and so on *1.000..." << std::endl; 
}

std::string Dog::getType() const
{
	return (this->_type);
}
