NAME     = violence
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := $(wildcard src/*.cpp)
INCLUDE := $(wildcard include/*.hpp)

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compiling ex03.."
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
