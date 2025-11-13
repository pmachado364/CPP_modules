NAME     = converter
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Iinclude

SRC_DIR = src
HDR_DIR = include
SRC = main.cpp \
	   $(SRC_DIR)/ScalarConverter.cpp
	   $(SRC_DIR)/utils.cpp

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
	rm -f *_shrubbery
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re