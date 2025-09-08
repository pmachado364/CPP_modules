NAME     = ex04
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := main.cpp Replace.cpp
INCLUDE := Replace.hpp

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compiling ex04.."
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
