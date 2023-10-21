// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/18 20:40:06 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 23:34:06 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &inst)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL)
			delete materias[ i ];
		this->materias[i] = NULL;
		if (inst.materias[ i ] != NULL)
			this->materias[i] = inst.materias[i]->clone();
	}	
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource copy desstructor called" << std::endl;

	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL)
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource& inst)
{
	std::cout << "MateriaSource assigment operator called" << std::endl;

	if (this != &inst)
	{
			for(int i = 0; i < 4; i++)
        	{
		        if (this->materias[i] != NULL)
			        delete this->materias[i];
			    this->materias[i] = NULL;
				if (inst.materias[i] != NULL)
					this->materias[i] = inst.materias[i]->clone();

	        }
	}

	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
		{
			this->materias[i] = m;
			return ;
		}
		if (i + 1 == 4)
		{
			delete m;
		}
	}

	std::cout << "There is no room for more materia!" << std::endl;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL)
		{
			//std::string _type = this->materias[i]->getType();
			if (this->materias[i]->getType().compare(type) == 0)
				return (this->materias[i]->clone());
		}
	}
	return (0);
}

void MateriaSource::printMaterias() const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL)
		{
			std::cout << "MateriaSource " << " materia " << i << " is " << this->materias[i]->getType() << std::endl;
		}
	}
}
