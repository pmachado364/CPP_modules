NAME     = weird
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
INCLUDE := ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compiling Module_03 ex03.."
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
