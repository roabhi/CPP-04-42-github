// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cat.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 19:59:59 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/11 20:01:45 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &inst)
{
	*this = inst;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat detructor called" << std::endl;
	return ;
}

Cat &Cat::operator=(const Cat& inst)
{
	(void)inst;
	//this->_type = _type;
	this->_type = inst.getType();
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Sweet sweet meow meow like no tomorrow..." << std::endl; 
}

std::string Cat::getType() const
{
	return (this->_type);
}
