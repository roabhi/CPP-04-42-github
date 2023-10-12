// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cat.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/11 19:58:53 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 18:34:36 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"


class Cat : public Animal {

public:

	Cat(void);
	Cat(const Cat &inst);
	~Cat(void);
	Cat& operator=(const Cat& inst);
	void makeSound() const;
	std::string getType() const;

	void setIdeas(std::string const &ideas) const;
	void showIdeas() const;

private:

	Brain *_brain;

};

#endif
