NAME = $(shell basename $(CURDIR))
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJ:.o=.d)

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -MMD -MP
CXXFLAGS_RELEASE = -g
CXXFLAGS_DEBUG = -g3 -fsanitize=address,undefined -fno-omit-frame-pointer

SRC_DIR = src
OBJ_DIR = obj

all: CXXFLAGS += $(CXXFLAGS_RELEASE)
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✔ Build successful.$(RESET)"

debug: CXXFLAGS += $(CXXFLAGS_DEBUG)
debug: re

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Full clean done."

re: fclean all

-include $(DEPS)
.PHONY: all debug clean fclean re