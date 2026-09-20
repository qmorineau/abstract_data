# Compiler
CCPP = g++

# Flags
CPPFLAGS = -Wall -Wextra -Werror -MMD -g -std=c++98 -fsanitize=address
# Project Paths
SRC_DIR = srcs
OBJ_DIR = .obj
OBJ_DIR_FT = $(OBJ_DIR)/ft
OBJ_DIR_STD = $(OBJ_DIR)/std
INC_DIR = include

# Include Paths
INCLUDES = -I $(INC_DIR) \
			

SRC = $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FT = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR_FT)/%.o, $(SRC))
OBJ_STD = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR_STD)/%.o, $(SRC))
ALL_OBJS = $(OBJ_FT) $(OBJ_STD)
DEP = $(ALL_OBJS:.o=.d)

NAME = abstract_data
NAME_STD = abstract_data_std

all: $(NAME) $(NAME_STD)

$(NAME): $(OBJ_FT)
	@$(CCPP) $(CPPFLAGS) $(INCLUDES) $(OBJ_FT) -o $(NAME)
	@echo "$(NAME) compiled"

$(NAME_STD): $(OBJ_STD)
	@$(CCPP) $(CPPFLAGS) $(INCLUDES) $(OBJ_STD) -D STD -o $(NAME_STD)
	@echo "$(NAME_STD) compiled"

$(OBJ_DIR_FT)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CCPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_STD)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CCPP) $(CPPFLAGS) $(INCLUDES) -D STD -c $< -o $@

re:	fclean all

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clear objects files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_STD)
	@echo "Clear binary file"

test: all
	-./$(NAME)
	-./$(NAME_STD)

.PHONY: all re clean fclean test

-include $(DEP)