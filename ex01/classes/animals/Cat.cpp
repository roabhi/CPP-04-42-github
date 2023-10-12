// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cat.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 19:59:59 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 20:30:45 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
	return ;
}

Cat::Cat(const Cat &inst)
{
	this->_brain = inst._brain != NULL ? new Brain( *inst._brain ) : new Brain();
	*this = inst;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat detructor called" << std::endl;
	if ( this->_brain != NULL )
		delete this->_brain;
	return ;
}

Cat &Cat::operator=(const Cat& inst)
{
	(void)inst;
	//this->_type = _type;
	this->_type = inst.getType();
	if ( this->_brain != NULL )
			delete this->_brain;
	this->_brain = inst._brain != NULL ? new Brain( *inst._brain ) : new Brain();
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

void Cat::setIdeas(std::string const &ideas) const
{
	_brain->setIdeas(ideas);
}

void Cat::showIdeas() const
{
	_brain->showIdeas();
}
