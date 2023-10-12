// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 18:37:01 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 18:29:28 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal {

public:

	Dog(void);
	Dog(const Dog &inst);
	~Dog(void);
	Dog& operator=(const Dog& inst);
	void makeSound() const;
	std::string getType() const;

	void setIdeas(std::string const &ideas) const;
	void showIdeas() const;

private:

	Brain *_brain;

};

#endif
