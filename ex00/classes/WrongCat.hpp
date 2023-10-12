// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongCat.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 14:43:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 15:50:40 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat(void);
	WrongCat(const WrongCat &inst);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat& inst);
	//void makeSound() const;

};

#endif
