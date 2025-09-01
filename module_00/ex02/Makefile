# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 11:24:09 by pmachado          #+#    #+#              #
#    Updated: 2025/09/01 18:19:18 by pmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = account
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRCS := tests.cpp Account.cpp
HDRS := Account.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	@echo "Compiling Accounts.."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "✅ Build successful."
clean:
	@:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
