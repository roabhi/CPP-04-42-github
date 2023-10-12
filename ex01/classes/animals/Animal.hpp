// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Animal.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:04:06 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 19:15:49 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "../Brain.hpp"

class Animal {

public:

	Animal(void);
	Animal (const Animal &inst);
	Animal &operator=(const Animal &inst);
	virtual ~Animal(void);

	virtual void makeSound() const;
	std::string getType() const;


protected:

	std::string _type;;

};

std::ostream& operator<<(std::ostream& os, const Animal& inst);


#endif
