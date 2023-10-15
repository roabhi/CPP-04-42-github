// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AAnimal.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 14:41:17 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/15 14:56:29 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "../Brain.hpp"

class AAnimal {

public:

	AAnimal(void);
	AAnimal (const AAnimal &inst);
	AAnimal &operator=(const AAnimal &inst);
	virtual ~AAnimal(void);

	virtual void	    makeSound() const = 0;
	virtual std::string	getType() const = 0;
	virtual void        setIdeas(std::string const &ideas) const = 0;
	virtual void	    showIdeas() const = 0;


protected:

	std::string _type;;

};


#endif
