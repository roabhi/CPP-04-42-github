#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 17:59:49 by rabril-h          #+#    #+#              #
#    Updated: 2023/10/12 15:38:13 by rabril-h         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Polymorphism

SRCS = main.cpp \
				./classes/Animal.cpp \
				./classes/Dog.cpp \
				./classes/Cat.cpp \
				./classes/WrongAnimal.cpp \
				./classes/WrongCat.cpp \


HEADERS = ./classes/Animal.hpp \
				./classes/Dog.hpp \
				./classes/Cat.hpp \
				./classes/WrongAnimal.hpp \
				./classes/WrongCat.hpp \

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

%.o: %.cpp Makefile ${HEADERS}
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}

${NAME}:: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	@echo "All files compiled"

all:
		@$(MAKE) ${NAME} 

-include ${DEPS}

clean:
			@${RM} ${OBJS} ${DEPS}
			@echo "Objects cleaned"

fclean: clean 
			@${RM} ${OBJS} ${DEPS} ${NAME}
			@echo "All compilation files removed"

re: 
			@$(MAKE) fclean 
			@$(MAKE) all 

.PHONY: all clean fclean re
