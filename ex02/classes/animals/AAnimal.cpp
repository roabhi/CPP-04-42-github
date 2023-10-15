// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Animal.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:04:33 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/15 14:50:12 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "I am just an Animal";
	std::cout << "Animal Defult constructor called for " << this->_type << std::endl;

	return ;
}

AAnimal::AAnimal(const AAnimal &inst)
{
	this->_type = "I am just an Animal";
	std::cout << "Animal Copy constructor called for " << this->_type << std::endl;
	*this = inst;
}

AAnimal& AAnimal::operator=(const AAnimal &inst)
{
	this->_type = inst.getType();
	std::cout << "Animal Assgiment constructor called for " << this->_type << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal Destructor called for " << this->_type << std::endl;
	return ;
}



