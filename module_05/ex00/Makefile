NAME     = bureaucrat
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Bureaucrat.cpp
HDR = Bureaucrat.hpp

all:
	@echo "Compiling $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "✅ Build successful."

clean:
	@echo "Nothing to clean."

fclean:
	@rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re
