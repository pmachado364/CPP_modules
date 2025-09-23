NAME     = ex03
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC := main.cpp \
	   src/AMateria.cpp src/Character.cpp src/Cure.cpp \
	   src/Ice.cpp src/MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling Module_04 ex03.."
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Build successful."
clean:
	@rm -f $(OBJ)
	@echo "Clean done."
fclean: clean
	@rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

.PHONY: all clean fclean re
