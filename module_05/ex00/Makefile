NAME     = bureaucrat
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)
HDR = Bureaucrat.hpp

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Build successful."

%.o: %.cpp $(HDR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo ".obj files cleaned."
fclean: clean
	@rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re