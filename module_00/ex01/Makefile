# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 11:24:09 by pmachado          #+#    #+#              #
#    Updated: 2025/08/07 11:26:45 by pmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------VARIABLES-------------#

CXX 			= c++
CXXFLAGS 		= -Wall -Wextra -Werror -std=c++98

#-------------SOURCES-------------#

NAME		= phonebook
SRC			= ${NAME}.cpp
OBJ			= ${SRC:.cpp=.o}

#-------------RULES-------------#

all:		${NAME}
${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
		rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
re:		fclean all

.PHONY:	all clean fclean re