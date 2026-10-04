# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -Wextra -Werror -MMD -g -std=c++98 -pedantic -fsanitize=address
# Project Paths
SRC_DIR = srcs
OBJ_DIR = .obj
OBJ_DIR_FT = $(OBJ_DIR)/ft
OBJ_DIR_STD = $(OBJ_DIR)/std
INC_DIR = include
INC_TEST_DIR = test_include

# Include Paths
INCLUDES = -I $(INC_DIR) \
			-I $(INC_TEST_DIR) \
			

SRC = $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FT = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR_FT)/%.o, $(SRC))
OBJ_STD = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR_STD)/%.o, $(SRC))
ALL_OBJS = $(OBJ_FT) $(OBJ_STD)
DEP = $(ALL_OBJS:.o=.d)

NAME = abstract_data
NAME_STD = abstract_data_std

F_STD_OUT = output.std
F_FT_OUT = output.ft
F_STD_TIME = output.std.time
F_FT_TIME = output.ft.time
AWK_FILE = compare.awk

SEUIL ?= 20

all: $(NAME) $(NAME_STD)

$(NAME): $(OBJ_FT)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ_FT) -o $(NAME)
	@echo "$(NAME) compiled"

$(NAME_STD): $(OBJ_STD)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ_STD) -D STD -o $(NAME_STD)
	@echo "$(NAME_STD) compiled"

$(OBJ_DIR_FT)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_STD)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -D STD -c $< -o $@

re:	fclean all

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clear objects files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_STD)
	@echo "Clear binary file"

test: all
	clear
	@make diff
	@make benchmark

diff: all
	-./$(NAME) > $(F_FT_OUT)
	-./$(NAME_STD) > $(F_STD_OUT)
	-diff $(F_FT_OUT) $(F_STD_OUT)

benchmark: all
	./$(NAME) benchmark > $(F_FT_TIME)
	./$(NAME_STD) benchmark > $(F_STD_TIME)
	-awk -v seuil=$(SEUIL) -f $(AWK_FILE) $(F_FT_TIME) $(F_STD_TIME)
	
ft: all
	clear
	./$(NAME)

std: all
	clear
	./$(NAME_STD)

.PHONY: all re clean fclean test diff benchmark ft std

-include $(DEP)