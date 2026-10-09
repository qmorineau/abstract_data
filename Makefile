# Compiler
CXX = c++

# Flags
CXXFLAGS = -Wall -Wextra -Werror -MMD -g -std=c++98 -pedantic -fsanitize=address,undefined
CXXFLAGS_BENCH = -Wall -Wextra -Werror -MMD -g -std=c++98 -O2
MAKEFLAGS += -j$(shell nproc)

# Project Paths
SRC_DIR = srcs
OBJ_DIR = .obj
INC_DIR = include
INC_TEST_DIR = test_include

# Include Paths
INCLUDES = -I $(INC_DIR) -I $(INC_TEST_DIR)
			
# Sources
SRC_TEST  = $(shell find $(SRC_DIR)/test $(SRC_DIR)/common -name "*.cpp" 2>/dev/null)
SRC_BENCH = $(shell find $(SRC_DIR)/bench $(SRC_DIR)/common -name "*.cpp" 2>/dev/null)

# Objects
OBJ_FT = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/test_ft/%.o, $(SRC_TEST))
OBJ_STD = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/test_std/%.o, $(SRC_TEST))
OBJ_BENCH_FT = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/bench_ft/%.o, $(SRC_BENCH))
OBJ_BENCH_STD =$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/bench_std/%.o, $(SRC_BENCH))

ALL_OBJS = $(OBJ_FT) $(OBJ_STD) $(OBJ_BENCH_FT) $(OBJ_BENCH_STD)
DEP = $(ALL_OBJS:.o=.d)

NAME = abstract_data
NAME_STD = abstract_data_std
BENCH = abstract_data_bench
BENCH_STD = abstract_data_bench_std

F_STD_OUT = output.std
F_FT_OUT = output.ft
F_STD_TIME = output.std.time
F_FT_TIME = output.ft.time
AWK_FILE = compare.awk

all: $(NAME) $(NAME_STD) $(BENCH) $(BENCH_STD)

$(NAME): $(OBJ_FT)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ_FT) -o $(NAME)
	@echo "$(NAME) compiled"

$(NAME_STD): $(OBJ_STD)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ_STD) -D STD -o $(NAME_STD)
	@echo "$(NAME_STD) compiled"

$(BENCH): $(OBJ_BENCH_FT)
	@$(CXX) $(CXXFLAGS_BENCH) $(INCLUDES) $(OBJ_BENCH_FT) -o $(BENCH)
	@echo "$(BENCH) compiled"

$(BENCH_STD): $(OBJ_BENCH_STD)
	@$(CXX) $(CXXFLAGS_BENCH) $(INCLUDES) $(OBJ_BENCH_STD) -D STD -o $(BENCH_STD)
	@echo "$(BENCH_STD) compiled"

$(OBJ_DIR)/test_ft/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/test_std/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -D STD -c $< -o $@

$(OBJ_DIR)/bench_ft/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS_BENCH) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/bench_std/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS_BENCH) $(INCLUDES) -D STD -c $< -o $@


re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clear objects files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_STD)
	@rm -rf $(BENCH)
	@rm -rf $(BENCH_STD)
	@echo "Clear binaries file"

test:
	$(MAKE) diff
	$(MAKE) benchmark

diff: $(NAME) $(NAME_STD)
	-./$(NAME) > $(F_FT_OUT)
	-./$(NAME_STD) > $(F_STD_OUT)
	-diff $(F_FT_OUT) $(F_STD_OUT)

benchmark: $(BENCH) $(BENCH_STD)
	./$(BENCH) > $(F_FT_TIME)
	./$(BENCH_STD) > $(F_STD_TIME)
	-awk -f $(AWK_FILE) $(F_FT_TIME) $(F_STD_TIME)

awkall:
	clear
	@-awk -v show_ok=1 -f $(AWK_FILE) $(F_FT_TIME) $(F_STD_TIME)

awk:
	clear
	@-awk -f $(AWK_FILE) $(F_FT_TIME) $(F_STD_TIME)

ft: $(NAME)
	clear
	./$(NAME)

std: $(NAME_STD)
	clear
	./$(NAME_STD)

.PHONY: all re clean fclean test diff benchmark ft std awk

-include $(DEP)