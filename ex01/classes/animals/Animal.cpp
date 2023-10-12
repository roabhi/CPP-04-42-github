// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Animal.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:04:33 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 19:15:49 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "I am just an Animal";
	std::cout << "Animal Defult constructor called for " << this->_type << std::endl;

	return ;
}

Animal::Animal(const Animal &inst)
{
	this->_type = "I am just an Animal";
	std::cout << "Animal Copy constructor called for " << this->_type << std::endl;
	*this = inst;
}

Animal& Animal::operator=(const Animal &inst)
{
	this->_type = inst.getType();
	std::cout << "Animal Assgiment constructor called for " << this->_type << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called for " << this->_type << std::endl;
	return ;
}

void Animal::makeSound() const
{
	std::cout << "I am an animal without a proper sound. For real..." << std::endl;
}


std::string Animal::getType() const
{
	return (this->_type);
}


