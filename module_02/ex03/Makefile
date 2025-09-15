NAME     = ex03
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := main.cpp Fixed.cpp Point.cpp bsp.cpp
INCLUDE := Fixed.hpp Point.hpp

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compiling Module_02 ex03.."
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "✅ Build successful."
clean:
	@rm -f $(NAME)
	@echo "Removed binary."

fclean: clean
	@rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re
