NAME     = iter
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Iinclude

SRC_DIR = src
HDR_DIR = include
SRC = $(SRC_DIR)/main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Build successful."

%.o: %.cpp
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