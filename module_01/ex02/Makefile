
NAME     = ex02
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRCS := main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Creating many strings and pointers and references.."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "✅ built."
clean:
	@:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
