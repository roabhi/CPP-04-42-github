#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:07:01 by rabril-h          #+#    #+#              #
#    Updated: 2023/10/15 15:07:25 by rabril-h         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = Abstract

SRCS = main.cpp \
				./classes/animals/AAnimal.cpp \
				./classes/animals/Dog.cpp \
				./classes/animals/Cat.cpp \
				./classes/Brain.cpp \



HEADERS = ./classes/animals/AAnimal.hpp \
				./classes/animals/Dog.hpp \
				./classes/animals/Cat.hpp \
				./classes/Brain.hpp \


CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

%.o: %.cpp Makefile ${HEADERS}
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}

${NAME}:: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	@echo "All files compiled"

all:
		@$(MAKE) ${NAME} 

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
