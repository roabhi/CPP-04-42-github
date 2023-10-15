// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 17:38:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 20:08:31 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"

Brain::Brain(void)
{
	std::string idea;
	unsigned int c;

	idea = "...";
	this->_idx = 0;

	c = 0;
	while (c < 100)
	{
		this->_ideas[c] = idea;
		c++;
	}
	
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &inst)
{
	std::cout << "Brain copy constuctor called" << std::endl;
	*this = inst;
}

Brain& Brain::operator=(const Brain &inst)
{
	unsigned int c;

	c = 0;
	while (c < 100)
	{
		this->_ideas[c] = inst._ideas[c];
		c++;
	}
	
	std::cout << "Brain copy assigment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::showIdeas() const
{
	unsigned int c;

	c = 0;
	while (c < 100)
	{
		if (this->_ideas[c] != "...")
			std::cout << this->_ideas[c] << std::endl;
		c++;
	}
	
}

void Brain::setIdeas(std::string const &ideas)
{
	if (this->_idx == 100)
		this->_idx = 0;
	this->_ideas[_idx] = ideas;
	this->_idx++;
}
