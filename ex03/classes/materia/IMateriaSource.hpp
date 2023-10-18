// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMateriaSource.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/18 20:29:01 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/18 21:51:18 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>

class AMateria;

class IMateriaSource {

public:

	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
	virtual void printMaterias() const = 0; // Can this be casted?
};

#endif
