// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongAnimal.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 14:24:48 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 14:58:54 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WRONGANIMAL_HPP
# define  WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &inst);
	WrongAnimal &operator=(const WrongAnimal &inst);
	virtual ~WrongAnimal(void);

	void makeSound() const;
	std::string getType() const;

protected:

	std::string _type;

};

std::ostream& operator<<(std::ostream& os, const WrongAnimal& inst);

#endif
