
NAME     = zombieHorde
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRCS := main.cpp Zombie.cpp zombieHorde.cpp
HDRS := Zombie.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	@echo "creating zombies.."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "✅ More zombies."
clean:
	@:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
