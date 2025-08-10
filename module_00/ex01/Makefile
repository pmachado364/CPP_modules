# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 11:24:09 by pmachado          #+#    #+#              #
#    Updated: 2025/08/10 16:55:42 by pmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = phonebook
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRCS := $(wildcard src/*.cpp)
HDRS := $(wildcard include/*.hpp)

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	@:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
