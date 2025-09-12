NAME     = ex01
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := main.cpp Fixed.cpp
INCLUDE := Fixed.hpp

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compiling Module_02 ex01.."
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
