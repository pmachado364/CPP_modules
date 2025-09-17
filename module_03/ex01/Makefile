NAME     = ScavTrap
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := main.cpp ClapTrap.cpp
INCLUDE := ClapTrap.hpp

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compiling Module_03 ex01.."
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "✅ Build successful."
clean:
	@rm -f $(NAME)
	@echo "Clean done."
fclean: clean
	@rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re
