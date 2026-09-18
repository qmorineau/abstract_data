# Compiler
CCPP = g++

# Flags
CPPFLAGS = -Wall -Wextra -Werror -MMD -g -std=c++98
# Project Paths
SRC_DIR = srcs
OBJ_DIR = .obj
INC_DIR = include

# Include Paths
INCLUDES = -I $(INC_DIR) \
			

SRC_CPP = $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_CPP = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_CPP))
ALL_OBJS = $(OBJ_CPP)
DEP = $(ALL_OBJS:.o=.d)

NAME = trainsim

all: $(NAME)

$(NAME): $(GLFW_LIB) $(OBJ_DIR) $(OBJ_CPP)
	@$(CCPP) $(CPPFLAGS) $(INCLUDES) $(OBJ_CPP) -o $(NAME)
	@echo "$(NAME) compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CCPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

re:	fclean all

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clear objects files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.result
	@echo "Clear binary file"

test: all
	./$(NAME) file1 file2

.PHONY: all re clean fclean test

-include $(DEP)