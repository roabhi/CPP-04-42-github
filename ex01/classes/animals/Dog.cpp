// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:40:53 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 20:31:04 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";	
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog &inst)
{
	this->_brain = inst._brain != NULL ? new Brain( *inst._brain ) : new Brain();
	*this = inst;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog detructor called" << std::endl;
	if ( this->_brain != NULL )
		delete this->_brain;
	return ;
}

Dog &Dog::operator=(const Dog& inst)
{
	(void)inst;
	//this->_type = _type;
	this->_type = inst.getType();
	if ( this->_brain != NULL )
			delete this->_brain;
	this->_brain = inst._brain != NULL ? new Brain( *inst._brain ) : new Brain();

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

void Dog::setIdeas(std::string const &ideas) const
{
	_brain->setIdeas(ideas);
}

void Dog::showIdeas() const
{
	_brain->showIdeas();
}
