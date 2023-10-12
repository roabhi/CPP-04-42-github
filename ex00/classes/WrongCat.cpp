// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongCat.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 15:15:22 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 15:47:19 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "Wrong Cat";
	std::cout << "Wrong Cat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& inst)
{
	std::cout << "Wrong Cat copy constuctor called" << std::endl;
	*this = inst;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat destructor calles" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& inst)
{
	std::cout << "Wrong Cat copy assigment operator called" << std::endl;
	(void)inst;
	this->_type = _type;
	return (*this);
}

//void WrongCat::makeSound() const
//{
//	std::cout << "Sound from the wrong cat here" << std::endl;
//}
